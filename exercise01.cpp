/*
	ov_msckf CMakeLists.txt
*/

cmake_minimum_required(VERSION 2.8.8)

project(ov_msckf)

/*
	说明：
	1.
	project(ov_msckf) 
	用于指定工程名！
*/

find_package(catkin REQUIRED COMPONENTS rosbag tf std_msgs geometry_msgs sensor_msgs nav_msgs visualization_msgs cv_bridge ov_core)

/*
	说明：
	2.
	依赖功能包
	寻找需要用到的其它CMake packages, 用函数 find_package.
	补充：
	例：比如在Linux下面工程依赖OpenCV,只需要下面几行就可以完全配置好：
	add_executable(my_bin src/my_bin.cpp)
	find_package(OpenCV REQUIRED)
	include_directories(${OpenCV_INCLUDE_DIRS})
	target_link_libraries(my_bin, ${OpenCV_LIBS})

	工作流程如下:
	1. find_package 在一些目录中查找OpenCV的配置文件。
	2. 找到后，find_package 会将头文件目录设置到 ${OpenCV_INCLUDE_DIRS} 中,将链接库设置到 ${OpenCV_LIBS}中。
	3. 设置可执行文件的链接库和头文件目录，编译文件。

	那么find_package会在哪些目录下面寻找OpenCV的配置文件？

	find_package目录
	为什么要知道这个问题？因为很多库，我们都是自己编译安装的。比如说，电脑中同时编译了OpenCV2和OpenCV3,我们该如何让cmake知道到底
	找哪个？


	--首先是查找路径的根目录。几个重要的默认查找目录总结如下：
	<package>_DIR
	CMAKE_PREFIX_PATH
	CMAKE_FRAMEWORK_PATH
	CMAKE_APPBUNDLE_PATH
	PATH

*/

/*
	--通过Cmake内置模块引入依赖包
		为了方便我们在项目中引入外部依赖包，cmake官方为我们预定义了许多寻找依赖包的Module,他们存储在path_to_your_cmake/share/cmake-
		<version>/Modules目录下。每个以Find<LibaryName>.cmake命名的文件都可以帮我们找到一个包。我们也可以在官方文档查看。
		我们以curl库为例，假设我们项目需要引入这个库，而官方已经定义好了FindCURL.cmake。所以我们在CMakeLists.txt中可以直接用
		find_pakcage进行引用。
		find_package(CURL)
		add_executable(curltest curltest.cc)
		if (CURL_FOUND)
			target_include_directories(clib PRIVATE ${CURL_INCLUDE_DIR})
			target_link_libraries(curltest ${CURL_LIBRARY})
		else (CURL_FOUND)
			message("----")
		endif(CURL_FOUND)

	--Module模式与Config模式
		在Module模式中,cmake需要找到一个叫做Find<LibraryName>.cmake的文件。这个文件负责找到库所在的路径，为我们的项目引入头文件路径
		和库文件路径。cmake搜索这个文件的路径有两个，一个是上文提到的cmake安装目录下的share/cmake-<version>/Modules 目录,另一个是我
		们指定的CMAKE_MODULE_PATH的所在目录。

		如果Module模式搜索失败，没有找到对应的Find<LibraryName>.cmake文件，则转入Config模式进行搜索。它主要通过<LibraryName>Config.
		cmake或者<lower-case-package-name>-config.cmake这两个文件来引入我们需要的库。以glog库为例，在我们安装之后，它在/usr/local/lib
		/cmake/glog/目录下生成了glog-config.cmake文件，而/usr/local/lib/cmake/<LibraryName>/正是find_package函数的搜索路径之一。

		所以，对于原生支持Cmake编译和安装的库通常会安装Config模式的配置文件到对应目录，这个配置文件直接配置了头文件库文件的路径以及
		各种cmake变量供find_package使用。而对于非由cmake编译的项目，我们通常会编写一个Find<LibraryName>.cmake，通过脚本来获取头文件，
		库文件等信息。通常，原生支持cmake的项目库安装时会拷贝一份XXXConfig.cmake到系统目录中，因此在没有显式指定搜索路径时也可以顺利
		找到。
*/
find_package(Eigen3 REQUIRED)
find_package(OpenCV 3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem thread data_time)


