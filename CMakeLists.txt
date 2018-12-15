cmake_minimum_required(VERSION 2.8)

project(BLACKJACK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror -DDEBUG")

set(SOURCE_DIR "src")

set(EXECUTABLE_NAME "blackjack")

add_executable(${EXECUTABLE_NAME}
               ${SOURCE_DIR}/main.cpp
               ${SOURCE_DIR}/Card.cpp
               ${SOURCE_DIR}/Hand.cpp
               ${SOURCE_DIR}/Deck.cpp
               ${SOURCE_DIR}/Game.cpp)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTKMM gtkmm-3.0)

#link_directories(${GTKMM_LIBRARY_DIRS})
#include_directories(${GTKMM_INCLUDE_DIRS})
#target_link_libraries(${EXECUTABLE_NAME} ${GTKMM_LIBRARIES})
