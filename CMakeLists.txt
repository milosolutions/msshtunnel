
project(msshtunnel
  VERSION 0.0.1
  DESCRIPTION "Milo SSH Tunnel"
  LANGUAGES CXX
)

find_package(Qt5 COMPONENTS REQUIRED Core)

set(SOURCES msshtunnel.h msshtunnel.cpp)

set(OTHER_FILES README.md msshtunnel.doxyfile)

add_library(msshtunnel OBJECT ${SOURCES} ${OTHER_FILES})

# Defines
target_compile_definitions(memailsystem PUBLIC MSSHTUNNEL_LIB)

target_include_directories(msshtunnel
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(msshtunnel
  Qt5::Core
)

message("MSshTunnel: missing unit test!")
#add_subdirectory(tst_msshtunnel)
