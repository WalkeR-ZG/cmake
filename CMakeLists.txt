project(cmake)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_path(XXX ContextRole.h /home/zange/cmake//src/hackson/include/domain/)
if(XXX)
message("find!!!")
else(XXX)
message("not find")
endif(XXX)
if()
message("not null")
else()
message("null")
endif()
message("${XXX}")


foreach(x 1 2 35 6 7)
message("${x}")
endforeach(x)


add_subdirectory(src)
add_subdirectory(test)
