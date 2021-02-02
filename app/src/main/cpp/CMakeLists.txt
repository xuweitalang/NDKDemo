# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.
cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("ndkdemo")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
#找到一个ndk的库，并且将这个库的路径存储在一个变量中。
find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
#关联库。将指定的库关联起来
target_link_libraries( # Specifies the target library.
        native-lib

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})


#=============================以下内容为CMakeLists常用语法api=======================================

#[[搜索所有的cpp文件
aux_source_directory(dir VAR) 发现一个目录下所有的源代码文件并将列表存储在一个变量中。]]
#aux_source_directory(. SRC_LIST) #搜索当前目录下的所有cpp文件
#add_library(ndkdemo ${SRC_LIST})

#自定义搜索规则
#file(GLOB SRC_LIST "*.cpp" "protocal/*.cpp")
#add_library(ndkdemo ${SRC_LIST})
##或者
#file(GLOB SRC_LIST "*.cpp")
#file(GLOB SRC_PROTOCOL_LIST "protocal/*.cpp")
#add_library(ndkdemo ${SRC_LIST} ${SRC_PROTOCOL_LIST})
##或者
#aux_source_directory(. SRC_LIST)
#aux_source_directory(. SRC_PROTOCOL_LIST)
#add_library(ndkdemo ${SRC_LIST} ${SRC_PROTOCOL_LIST})

#设置包含的目录
#include_directories(
#        ${CMAKE_CURRENT_SOURCE_DIR}
#        ${CMAKE_CURRENT_BINARY_DIR}
#        ${CMAKE_CURRENT_SOURCE_DIR}/include
#)

#设置链接库搜索目录
#link_directories(
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib
#)

#指定链接动态库或静态库
#target_link_directories(ndkdemo libface.a) #链接静态库
#target_link_directories(ndkdemo libface.so) #链接动态库
#指定全路径
#target_link_directories(ndkdemo ${CMAKE_CURRENT_SOURCE_DIR}/libs/libface.a)

#设置变量
#1.set直接设置变量的值
#set(SRC_LIST native-lib.cpp)
#add_executable(ndkdemo ${SRC_LIST})

#2.set追加变量的值
#set(SRC_LIST native-lib.cpp)
#set(SRC_LIST ${SRC_LIST} test.cpp)
#add_executable(ndkdemo ${SRC_LIST})

#3.list追加或删除变量的值
#set(SRC_LIST native-lib.cpp)
#list(APPEND SRC_LIST test.cpp) #追加
#list(REMOVE_ITEM SRC_LIST test.cpp) #删除
#add_executable(ndkdemo ${SRC_LIST})

#打印信息: message()
#message(${PROJECT_SOURCE_DIR})

#包含其他cmake文件
#include(./common.cmake) #指定包含文件的全路径
#include(def) #在搜素路径中搜索def.cmake文件
#set(CMAKE_MODULE_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/cmake) #设置include的搜索路径