FILE(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)
add_library(hackson STATIC ${all_files})
target_include_directories(hackson PRIVATE include  "${PROJECT_SOURCE_DIR}/src/common/include")
install(TARGETS hackson ARCHIVE DESTINATION lib)