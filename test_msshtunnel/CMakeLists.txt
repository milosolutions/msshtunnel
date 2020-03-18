set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Test REQUIRED)

set(TEST_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/tst_msshtunneltest.cpp
)

set(APP_SRC
    ${PROJECT_SOURCE_DIR}/sshtunnel.h
    ${PROJECT_SOURCE_DIR}/sshtunnel.cpp
)

add_executable(msshtunnel_test ${TEST_SRC} ${APP_SRC})

target_include_directories(msshtunnel_test PRIVATE ${PROJECT_SOURCE_DIR})

qt5_use_modules(msshtunnel_test Core Test)
