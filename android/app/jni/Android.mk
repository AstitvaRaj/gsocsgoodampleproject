LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := newtojni
LOCAL_SRC_FILES := myfunction.c
include $(BUILD_SHARED_LIBRARY)
