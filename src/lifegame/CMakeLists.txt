FILE(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)
add_library(lifegame STATIC ${all_files})
target_include_directories(lifegame PRIVATE include  "${PROJECT_SOURCE_DIR}/src/common/include")
install(TARGETS lifegame ARCHIVE DESTINATION lib)