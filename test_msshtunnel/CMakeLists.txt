find_package(Qt5 COMPONENTS Core Test REQUIRED)

set(CMAKE_AUTOMOC ON)

add_executable(msshtunnel_test tst_msshtunneltest.cpp)

target_link_libraries(msshtunnel_test msshtunnel
  Qt5::Core Qt5::Test
)

add_test(msshtunnel_test msshtunnel_test)
