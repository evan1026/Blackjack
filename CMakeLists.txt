cmake_minimum_required(VERSION 2.8)

project(BLACKJACK)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

set(SOURCE_DIR "src")

set(EXECUTABLE_NAME "blackjack")

add_executable(${EXECUTABLE_NAME}
               ${SOURCE_DIR}/main.cpp
               ${SOURCE_DIR}/Card.cpp
               ${SOURCE_DIR}/Hand.cpp
               ${SOURCE_DIR}/Deck.cpp)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTKMM gtkmm-3.0)

#link_directories(${GTKMM_LIBRARY_DIRS})
#include_directories(${GTKMM_INCLUDE_DIRS})
#target_link_libraries(${EXECUTABLE_NAME} ${GTKMM_LIBRARIES})
