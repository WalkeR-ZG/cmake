include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/src/lifegame/include/")
include_directories("${PROJECT_SOURCE_DIR}/src/hackson/include/")
include_directories("${PROJECT_SOURCE_DIR}/src/common/include/")
file(COPY ./hackson/resource/  DESTINATION  ./hackson/resource/)
file(COPY ./lifegame/resource/ DESTINATION  ./lifegame/resource/)
file(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)

add_executable(cmake-test ${all_files})
target_link_libraries(cmake-test hackson lifegame pthread)
