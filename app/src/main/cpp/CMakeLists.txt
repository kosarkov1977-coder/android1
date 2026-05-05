cmake_minimum_required(VERSION 3.22.1)
project(vulkangeometry)

add_library(vulkangeometry SHARED native-lib.cpp)

find_library(log-lib log)
find_library(android-lib android)

# Vulkan loader is provided by Android NDK on supported devices.
find_library(vulkan-lib vulkan)

target_link_libraries(
    vulkangeometry
    ${log-lib}
    ${android-lib}
    ${vulkan-lib}
)
