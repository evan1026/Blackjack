cmake_minimum_required(VERSION 3.3)

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

set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_MAN YES)
find_package(Doxygen)
if (DOXYGEN_FOUND)
    doxygen_add_docs(
        doxygen
        ${SOURCE_DIR}
        COMMENT "Generate documentation"
    )
endif(DOXYGEN_FOUND)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTKMM gtkmm-3.0)

#link_directories(${GTKMM_LIBRARY_DIRS})
#include_directories(${GTKMM_INCLUDE_DIRS})
#target_link_libraries(${EXECUTABLE_NAME} ${GTKMM_LIBRARIES})
