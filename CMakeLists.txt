cmake_minimum_required(VERSION 3.8)
project(miruy)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(SRC 
        ./src/mutex.cc
        ./src/thread.cc
        ./src/config.cc
        ./src/log.cc
        ./src/util.cc
        ./src/fiber.cc
        ./src/scheduler.cc
        ./src/iomanager.cc
        ./src/timer.cc
        ./src/hook.cc
        ./src/fd_manager.cc
        ./src/address.cc
        ./src/socket.cc
        ./src/bytearray.cc
    )

set(LIBS 
        dl
        pthread
        yaml-cpp
    )

include_directories("./include")

add_executable(test ${SRC} ./test/test.cpp)
target_link_libraries(test ${LIBS})

add_executable(test_io ${SRC} ./test/test_io.cpp)
target_link_libraries(test_io ${LIBS})

add_executable(test_socket ${SRC} ./test/test_socket.cpp)
target_link_libraries(test_socket ${LIBS})

add_executable(test_bytearray ./src/bytearray.cc  ./test/test_bytearray.cpp)
