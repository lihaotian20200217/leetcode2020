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


















































