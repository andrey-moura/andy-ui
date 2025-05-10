#Require a minimum version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(uva-ui)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_library(andy-ui OBJECT
    ${CMAKE_CURRENT_LIST_DIR}/src/app.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/dialog.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/frame.cpp
)

# Create an executable for each file in examples
file(GLOB EXAMPLES ${CMAKE_CURRENT_LIST_DIR}/examples/*.cpp)

foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)

    add_executable(${EXAMPLE_NAME} ${EXAMPLE})

    target_link_libraries(${EXAMPLE_NAME} andy-ui)

    # andy_ui_properties(${EXAMPLE_NAME})
endforeach()