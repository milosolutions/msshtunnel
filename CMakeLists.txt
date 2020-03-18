if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif ()

cmake_minimum_required(VERSION 3.5)

project(msshtunnel
  VERSION 0.0.1
  DESCRIPTION "Milo SSH Tunnel"
  LANGUAGES CXX
)

find_package(Qt5 COMPONENTS REQUIRED Core)

set(SOURCES sshtunnel.h sshtunnel.cpp)

set(OTHER_FILES README.md msshtunnel.doxyfile)

add_library(msshtunnel OBJECT ${SOURCES} ${OTHER_FILES})

# Defines
target_compile_definitions(msshtunnel PUBLIC MSSHTUNNEL_LIB)

target_include_directories(msshtunnel
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

qt5_use_modules(msshtunnel Core)

enable_testing()
add_subdirectory(test_msshtunnel)
add_test(NAME MSSHTunnelTest COMMAND msshtunnel_test)
