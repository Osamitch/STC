add_executable(Tests tests.c)
target_include_directories(Tests PUBLIC ..)
target_link_libraries(Tests floatfinder)

