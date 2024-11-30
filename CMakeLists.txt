cmake_minimum_required(VERSION 3.28)

project(StarSystem)

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)

set(SOURCES src/main.cpp src/SystemMap.cpp src/Stellar.cpp)

include_directories(include)

add_executable(StarSystem ${SOURCES})

target_link_libraries(StarSystem sfml-graphics sfml-window sfml-system)

