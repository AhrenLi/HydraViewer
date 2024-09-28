# CMakeList.txt : CMake project for HydraViewer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

project ("HydraViewer")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# thir_praty
add_subdirectory(third_party)

find_package(pxr REQUIRED)
find_package(OpenGL REQUIRED)
# spdlog
if (NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

file(GLOB_RECURSE SRC_CPP
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  "src/*.cpp"
)
file(GLOB_RECURSE SRC_H
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  "src/*.h"
)

include_directories(${PROJECT_NAME} ${PXR_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC_CPP} ${SRC_H})

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${PXR_INCLUDE_DIRS}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PXR_LIBRARIES}
        spdlog::spdlog
)

if(WIN32)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE
            NOMINMAX
            _USE_MATH_DEFINES
    )
endif()