#定义模块当前路径
LOCAL_PATH := $(call my-dir)

#清空当前环境变量
include $(CLEAR_VARS)

#当前模块名(这里命名为hello-jni,这样会生成hello-jni.so的文件)
local_module := hello-jni

#当前模块包含的源代码文件(如果这里有多个文件，用空格隔开)
local_src_files := hello-jni.c

#生成一个动态库
include $(BUILD_SHARED_LIBRARY)