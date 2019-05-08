CMAKE+GTEST：

Environment
Compiler:

GCC 4.8 or above
CMAKE 2.8 or above

OS:

Linux

Build

$ cd build
$ cmake ..
$ make
$ cd test
$ ./demo-test

CODE layout

src  #源代码 
	|common    公共模块(模块耦合)
	    |include 头文件
	|hackson   模块1
	    |include 头文件
		    |……
			    |……	
	    |src     实现文件	
			|……
			    |……	
	|lifegame  模块2
	    |include 头文件
		    |……
			    |……	
	    |src     实现文件	
			|……
			    |……		
test #测试用例
	|gtest     gtest工程
	|hackson   模块1
	   |resource 测试源数据
	|lifegame  模块2
		   |resource 测试源数据