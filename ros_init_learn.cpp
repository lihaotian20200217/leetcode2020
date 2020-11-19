/*
	ROS程序的初始化-ros::init()

	ros::init()函数的声明在：./src/ros_comm/roscpp/include/ros/init.h

	重载为以下三种形式：
	void init(int &argc, char **argv, const std::string& name, uint32_t options = 0);
	void init(const M_string& remappings, const std::string& name, uint32_t options = 0);
	void init(const VP_string& remapping_args, const std::string& name, uint32_t options = 0);

	具体实现在：./src/ros_comm/roscpp/src/libros/init.cpp中
*/
	void init(const M_string& remappings, const std::string& name, uint32_t options)
	{
		if (!g_atexit_registered)
		{
			g_atexit_registered = true;
			atexit(atexitCallback);
		}
		if (!g_global_queue)
		{
			g_global_queue.reset(new CallbackQueue);
		}
		//上面做了一些预处理
		if (!g_initialized)
		{
			g_init_options = options;
			g_ok = true;

			ROSCONSOLE_AUTOINIT; // 在console.h 中的一段宏定义：Initializes the rosconsole library.
#ifndef WIN32
			signal(SIGPIPE, SIG_IGN);
#endif
			network::init(remappings); // 初始化网络，实现在network.cpp中
			master::init(remappings);  // 初始化master
			// this_node 初始化命名空间
			this_node::init(name, remappings, options); // 初始化当前节点
			file_log::init(remappings);
			param::init(remappings);
			g_initialized = true; // 置上初始化标记！
		}
	}
	/*
		ROS程序的初始化函数ros::init()主要调用了以下几个函数完成初始化：
		network::init(remappings);
		master::init(remappings);
        this_node::init(name, remappings, options);
        file_log::init(remappings);
        param::init(remappings);

	*/

/*
	1.network::init()
	实现在：./src/ros_comm/roscpp/src/libros/network.cpp
*/
void init(const M_string& remappings) // 该函数在init.cpp中被调用
{	
	// 模块1.
	M_string::const_iterator it = remappings.find("__hostname");
	if (it != remappings.end())
	{
		g_host = it->second;
	}
	else
	{
		it = remappings.find("__ip");
		if (it != remappings.end())
		{
			g_host = it->second;
		}
	}
	// 模块2.
	it = remappings.find("__tcpros_server_port");
	if (it != remappings.end())
	{
		try
		{
			g_tcpros_server_port = boost::lexical_cast<uint16_t>(it->second);
		}
		catch (boost::bad_lexical_cast&)
		{
			throw ros::InvalidPortException("__tcpros_server_port [" + it->second + "] was not specified as a number within the 0-65535 range");
		}
	}
	// 模块3
	if (g_host.empty())
	{
		g_host = determineHost();
	}
}

/*
	补充1：
	数据类型M_string
	定义在: ./src/roscpp_core/cpp_common/include/ros/datatypes.h
	该文件定义了ROS实现用到的若干种数据类型
	namespace ros {
		typedef std::vector<std::pair<std::string, std::string> > VP_string;
		typedef std::vector<std::string> V_string;
		typedef std::set<std::string> S_string;
		typedef std::map<std::string, std::string> M_string;
		typedef std::pair<std::string, std::string> StringPair;
		typedef boost::shared_ptr<M_string> M_stringPtr;
	}

	解决了数据类型M_string的问题，我们细看代码。模块1主要是对g_host进行赋值
	// 查找remappings中键为"__hostname"的元素
	M_string::const_iterator it = remappings.find("__hostname");
	// 如果找到了，则将该元素的值赋给"g_host"
	if (it != remappings.end())
	{
		g_host = it->second;
	}
	// 如果没有找到
	else
	{
		// 查找键为"__ip"的元素
		it = remappings.find("__ip");
		// 如果找到了，则将该元素的值赋给"g_host"
		if (it != remappings.end())
		{
			g_host = it->second;
		}
	}
	// g_host是一个std::string类型的变量，在network.cpp文件的一开头就已定义。 std::string g_host;
	//
	
	// 模块2.
	// 查找键为"__tcpros_server_port"的元素
	it = remappings.find("__tcpros_server_port");
	if (it != remappings.end())
	{
		try // 尝试将对应元素的值(std::string)转换为uint16_t类型
		{
			g_tcpros_server_port = boost::lexical_cast<uint16_t>(it->second);
		}
		catch (boost::bad_lexical_cast&)
		{
			throw ros::InvalidPortException("__tcpros_server_port [" + it->second + "] was not specified as a number within the 0-65535 range");
		}
	}
	
	补充2：
	关于类型转换器boost::lexical_cast
	比如将一个字符串"712"转换成整数712,代码如下
	string s = "712";
	int a = lexical_cast<int>(s);

	以上模块就是用boost::lexical_cast进行转换（该函数包含在头文件boost/lexical_cast.hpp中），然后捕捉bad_lexical_cast异常。
	该模块的作用是为变量g_tcpros_server_port赋值,该变量的定义在network.cpp的开头，且默认值为0;
	uint16_t g_tcpros_server_port = 0;

	// 模块3.
	// 当g_host为空的时候，调用函数determineHost()为其赋值
	if (g_host.empty())
	{
		g_host = determineHost();
	}
	
	这段代码所调用的determineHost()也定义在 ./src/ros_comm/roscpp/src/libros/network.cpp中
	总之，network::init()主要完成了g_host和g_tcpros_server_port两个变量的赋值

*/

2.master::init()
定义在./src/ros_comm/roscpp/src/libros/master.cpp

void init(const M_string& remappings)
{
	// 构建迭代器，查找remappings中键为"__master"的节点
	M_string::const_iterator it = remappings.find("__master");
	// 如果找到了，则将该节点对应的值赋给g_uri
	if (it != remappings.end())
	{
		g_uri = it->second;
	}
	// 如果g_uri没有被赋值
	if (g_uri.empty())
	{
		char *master_uri_env = NULL;
        #ifdef _MSC_VER
			_dupenv_s(&master_uri_env, NULL, "ROS_MASTER_URI");
		#else
			master_uri_env = getenv("ROS_MASTER_URI");
		#endif

		if (!master_uri_env)
		{
			ROS_FATAL("----");
			ROS_BREAK();
		}

		g_uri = master_uri_env;

        #ifdef _MSC_VER
			free(master_uri_env);
		#endif
	}
	// 对g_uri进行解析，把g_uri中去掉协议部分赋值给g_host，并将端口赋值给g_port。
	if (!network::splitURI(g_uri, g_host, g_port))
	{
		ROS_FATAL("---");
		ROS_BREAK();
	}
}

其中涉及两个未知的函数ROS_BREAK()和network::splitURI(g_uri,g_host,g_port)

ROS_BREAK()函数的定义在: ./src/ros_comm/rosconsole/include/ros/assert.h
该函数用于中断ROS程序的执行，并显示在哪个文件哪行发生了中断。

network::splitURI()
该函数定义在: ./src/ros_comm/roscpp/src/libros/network.cpp

bool splitURI(const std::string& uri, std::string& host, uint32_t& port)
{
	// 提取uri中去掉协议的部分，赋值给host
	if (uri.substr(0,7) == std::string("http://"))
			host = uri.substr(7);
	else if (uri.substr(0,9) == std::string("rosrpc://"))
			host = uri.substr(9);
	// 将uri中的端口号(:后面部分)取出来赋值给port_str
	std::string::size_type colon_pos = host.find_first_of(":");
	if (colon_pos == std::string::npos) return false;// 如果uri中没有端口号，则该函数返回失败
	std::string port_str = host.substr(colon_pos+1);
	//删除端口号中第一个"/"
	std::string::size_type slash_pos = port_str.find_first_of("/");
	if (slash_pos != std::string::npos)
			port_str = port_str.erase(slash_pos);
	port = atoi(port_str.c_str()); // 将字符串转化为整形
	host = host.erase(colon_pos); // 从host变量中删除第一个:
	return true;
}
该函数的作用是对uri进行解析，将去掉协议部分赋值给host,将端口号赋值给port。

3.this_node::init()

源码在：./src/ros_comm/roscpp/src/libros/this_node.cpp

void init(const std::string& name, const M_string& remappings, uint32_t options)
{
	ThisNode::instance().init(name, remappings, options);
}

其中，ThisNode是文件 ./src/ros_comm/roscpp/src/libros/this_node.cpp 中定义的一个类,该类的具体定义如下：
class ThisNode
{
	std::string name_;
	std::string namespace_;

	ThisNode() : name_("empty") {}

	public:
		static ThisNode& instance()
		{
			static ThisNode singleton; // 整个ROS程序只有singleton一个拷贝，详见编程中的“单例模式”。
			return singleton;
		}

		const std::string& getName() const
		{
			return name_;
		}

		const std::string& getNamespace() const
		{
			return namespace_;
		}

		void init(const std::string& name, const M_string& remappings, uint32_t options);
};

this_node::init()函数实际上直接调用的是ThisNode类中的void init(const std::string& name, const M_string& remappings, uint32_t options);
该函数的定义如下:
./src/ros_comm/roscpp/src/libros/this_node.cpp

void ThisNode::init(const std::string& name, const M_string& remappings, uint32_t options)
{
	char *ns_env = NULL;
    #ifdef _MSC_VER
	_dupenv_s(&ns_env, NULL, "ROS_NAMESPACE");
    #else
	ns_env = getenv("ROS_NAMESPACE"); //获取ROS_NAMESPACE的环境变量名
    #endif

	if (ns_env) // 如果环境变量ns_env已被赋值
	{
		namespace_ = ns_env; // 将ROS_NAMESPACE的环境变量名赋值给namespace_
		//namespace_ 是类ThisNode的成员变量
        #ifdef _MSC_VER
			free(ns_env);
		#endif
	}

	// 检测通过参数传入的节点名不能为空
	if (name.empty()) {
		throw InvalidNameException("The node name must not be empty");
	}

	name_ = name; // 将传入的节点名赋值给变量name_,name_是类ThisNode的成员变量

	bool disable_anon = false;
	// 在输入参数remappings查找键为"__name"的项
	M_string::const_iterator it = remappings.find("__name");
	if (it != remappings.end())// 如果找到了
	{
		name_ = it->second; // 将对应的值赋给name_
		disable_anon = true;
	}
	// 再参数remappings查找键为"__ns"的项
	it = remappings.find("__ns");
	if (it != remappings.end()) // 如果找到了
	{
		namespace_ = it->second; // 将对应项的值赋给变量namespace_
	}
	
	if (namespace_.empty())
	{
		namespace_ = "/";
	}

	namespace_ = (namespace_ == "/") ? std::string("/") : ("/" + namespace_);

	std::string error;
	// 对照命名规则检查namespace_，看看是否合法。
    if (!names::validate(namespace_, error))
	{
		std::stringstream ss;
		ss << "Namespace [" << namespace_ << "] is invalid: " << error;
		throw InvalidNameException(ss.str());
	}

	names::init(remappings); // 将remappings映射为g_remappings和g_unresolved_remappings两个变量
	// 检查name_的合法性
	if (name_.find("/") != std::string::npos)
	{
		throw InvalidNodeNameException(name_, "node names cannot contain /");
	}
	if (name_.find("~") != std::string::npos)
	{
		throw InvalidNodeNameException(name_, "node names cannot contain ~");
	}

	name_ = names::resolve(namespace_, name_); // 进行格式化整理

	if (options & init_options::AnonymousName && !disable_anon)
	{
		char buf[200];
		snprintf(buf, sizeof(buf), "_%llu", (unsigned long long)WallTime::now().toNSec());
		name_ += buf;
	}

	ros::console::setFixedFilterToken("node", name_);

}
该函数完成：
1.获取ROS_NAMESPACE的环境变量名；
2.给变量name_赋值，并进行一些格式化处理。name_是类ThisNode的成员变量；
3.给变量namespace_赋值，并进行一些格式化处理。namespace_是类ThisNode的成员变量；
根据类ThisNode的定义，该类的成员变量就只有name_和namespace_两个变量。因此，该函数可以看做是根据输入参数，对ThisNode的对象进行初始化。
而根据ThisNode::instance()函数，该类在程序中只有唯一的一个对象。即调用this_node::init()的时候完成对该类唯一对象的初始化。
另外，上述函数调用了
	names::validate(namespace_, error);
	names::init(remappings);
	ros::console::setFixedFilterToken

补充1：
names::validate(namespace_, error)
定义在: ./src/ros_comm/roscpp/src/libros/names.cpp

bool validate(const std::string& name, std::string& error)
{
	if (name.empty())
	{
		return true;
	}

	// 检查首字符,首字符只能是~ / or alpha
	char c = name[0];
	if (!isalpha(c) && c != '/' && c != '~')
	{
		std::stringstream ss;
		ss << "Character [" << c << "] is not valid as the first character in Graph Resource Name [" << name << "]. Valid characters are a-z, A-Z, / and in some cases ~.";
		error = ss.str();
		return false;
	}

	// 逐个检查name中的每个字符是否为合法字符
	for (size_t i = 1; i < name.size(); ++i)
	{
		c = name[i];
		if (!isValidCharInName(c))
		{
			std::stringstream ss;
			ss << "---";
			error = ss.str();
			return false;
		}
	}
	return true;
}

补充2：
names::init(remappings)
位置: ./src/ros_comm/roscpp/src/libros/names.cpp
作用是将remappings映射为g_remappings和g_unresolved_remappings两个变量，其中g_remappings是按照一定规则整理过的remappings,而
g_unresolved_remappings是初始传入的remappings参数。

void init(const M_string& remappings)
{
	// 该函数的作用是将remappings映射为g_remappings和g_unresolved_remappings两个变量
	M_string::const_iterator it = remappings.begin();
	M_string::const_iterator end = remappings.end();
	for (; it != end; ++it) 
	{
		const std::string& left = it->first; // left 为键
		const std::string& right = it->second; // right 为值
		// 键不为空且键的第一个字符不为"_"且键不等于ThisNode对象的name_成员变量
		if (!left.empty() && left[0] != '_' && left != this_node::getName())
		{
			std::string resolved_left = resolve(left, false);
			std::string resolved_right = resolve(right, false);
			g_remappings[resolved_left] = resolved_right;
			g_unresolved_remappings[left] = right;
		}
	}
}

其中调用了resolve()函数，该函数定义在 ./src/ros_comm/roscpp/src/libros/names.cpp中，执行一些简单的格式化操作；


补充3.
ros::console::setFixedFilterToken
文件在 ./src/ros_comm/rosconsole/src/rosconsole/rosconsole.cpp

void setFixedFilterToken(const std::string& key, const std::string& val)
{
	g_extra_fixed_tokens[key] = val;
}
该函数主要是对变量g_extra_fixed_tokens进行赋值。

总结：
当初始化函数this_node::init()被ros::init()调用时，实际上调用了ROS程序中ThisNode类唯一的实例中的init(name, remappings, options)
函数，作用是对该唯一的实例进行初始化。
该函数的具体作用如下：
1.获取ROS_NAMESPACE的环境变量；
2.给变量name_赋值，并进行一些格式化处理。name_是类ThisNode的成员变量；
3.给namespace_赋值，并进行一些格式化处理。namespace_是类ThisNode的成员变量；
4.将remappings映射为g_remappings和g_unresolved_remappings两个变量；

ROS程序初始化-file_log::init()和param::init()

file_log::init()函数：
从file_log::init()名字我们可以猜测，该函数用于对日志文件的初始化。
file_log::init()函数定义在 ./src/ros_comm/roscpp/src/libros/file_log.cpp

void init(const M_string& remappings)
{
	std::string log_file_name;
	M_string::const_iterator it = remappings.find("__log");
	// 在remappings中找到键为"__log"的项
	if (it != remappings.end())
	{
		log_file_name = it->second; 
	}

	{
		if (log_file_name.empty())//如果log_file_name是个空串
		{
			pid_t pid = getpid(); // 获取当前进程号
			std::string ros_log_env;
			if (get_environment_variable(ros_log_env, "ROS_LOG_DIR")) // 获取ROS_LOG_DIR的环境变量的值
			{
				log_file_name = ros_log_env + std::string("/");
			}
			else // 如果不存在ROS_LOG_DIR这个环境变量
			{
				if (get_environment_variable(ros_log_env, "ROS_HOME")) //获取ROS_HOME的环境变量的值
				{
					log_file_name = ros_log_env + std::string("/log/");
				}
				else// 如果不存在环境变量ROS_HOME
				{
					if (get_environment_variable(ros_log_env, "HOME")// 获取HOME
					{
						std::string dotros = ros_log_env + std::string("/.ros/");
						fs::create_directory(dotros);
						log_file_name = dotros + "log/";
						fs::create_directory(log_file_name);// 创建相应的文件夹
					}
				}
			}

			// 处理节点的名字并接到log_file_name后面
			for (size_t i = 1; i < this_node::getName().length(); i++)
			{
				if (!isalnum(this_node::getName()[i]))
				{
					log_file_name += '_';
				}
				else
				{
					log_file_name += this_node::getName()[i];
				}
			}

			char pid_str[100];
			snprintf(pid_str, sizeof(pid_str), "%d", pid);
			log_file_name += std::string("_") + std::string(pid_str) + std::string(".log");
		}

		// 返回log_file_name对应文件的完整路径
		log_file_name = fs::system_complete(log_file_name).string();
		g_log_directory = fs::path(log_file_name).parent_path().string();
	}
}

该函数大部分代码用于生成一个变量log_file_name，该变量时ROS程序日志文件的路径和值。最终，将该变量的值赋给全局变量g_log_directory
该变量在ros::file_log命名空间下，在file_log.cpp文件的开头有声明。

补充1.
get_environment_variable()
位于 ./src/roscpp_core/cpp_common/include/ros/platform.h

inline bool get_environment_variable(std::string &str, const char* environment_variable)
{
	char* env_var_cstr = NULL;
    #ifdef _MSC_VER
		_dupenv_s(&env_var_cstr, NULL, environment_variable);
	#else
		env_var_cstr = getenv(environment_variable);
	#endif
	if (env_var_cstr)
	{
		str = std::string(env_var_cstr);
        #ifdef _MSC_VER
			free(env_var_cstr);
		#endif
		return true;
	}
	else
	{
		str = std::string("");
		return false;
	}
}

在file_log::init()中，主要调用get_environment_variable()函数获取ROS_HOME,ROS_LOG_DIR的环境变量的值。
























































































