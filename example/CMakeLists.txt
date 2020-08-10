find_package(Qt5 COMPONENTS REQUIRED Core)

set(CMAKE_AUTOMOC ON)

add_executable(example-msshtunnel main.cpp)

target_link_libraries(example-msshtunnel msshtunnel
  Qt5::Core
)
