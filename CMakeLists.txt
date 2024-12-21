#Require a minimum version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(uva-ui)

include_directories(${CMAKE_CURRENT_LIST_DIR})

set(UVA_UI_BACKEND "NONE")

if(WIN32)
    set(UVA_UI_BACKEND "WIN32")
elseif(LINUX)
    find_package(PkgConfig)

    if(PKG_CONFIG_FOUND)
        pkg_check_modules(GTK3 gtk+-3.0)

        if(GTK3_FOUND)
            set(UVA_UI_BACKEND "GTK3")
        endif()

        include_directories(${GTK3_INCLUDE_DIRS})
    endif()
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

if (NOT UVA_UI_BACKEND STREQUAL "NONE")
    # Add uvaui as shared library

    add_library(uvaui
        ${CMAKE_CURRENT_LIST_DIR}/src/${UVA_UI_BACKEND}/app.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/${UVA_UI_BACKEND}/frame.cpp
    )

    include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

    if(WIN32)
        set_target_properties(uvaui PROPERTIES WIN32_EXECUTABLE true)
    elseif(LINUX)
        target_link_libraries(uvaui ${GTK3_LIBRARIES})
    else()
        message(FATAL_ERROR "Unsupported platform")
    endif()

    add_definitions(-D"__UVA_UI_BACKEND_${UVA_UI_BACKEND}__")
endif()

message(STATUS "UVA_UI_BACKEND: ${UVA_UI_BACKEND}")

# Create an executable for each file in examples
file(GLOB EXAMPLES ${CMAKE_CURRENT_LIST_DIR}/examples/*.cpp)

foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)

    add_executable(${EXAMPLE_NAME} ${EXAMPLE})

    target_link_libraries(${EXAMPLE_NAME} uvaui)
endforeach()