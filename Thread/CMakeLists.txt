
include_directories()
link_libraries(pthread)


add_executable(1 Thread1.cpp)
add_executable(Foo1 1114.Foo.cpp)
add_executable(FooBar 1115.FooBar.cpp)
add_executable(ZeroEvenOdd 1116.ZeroEvenOdd.cpp)

