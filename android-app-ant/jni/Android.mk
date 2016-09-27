LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := jl2jni
LOCAL_CFLAGS += -std=c++11
LOCAL_SRC_FILES := gl_code.cpp
LOCAL_SHARED_LIBRARIES := liblog libGLESv2
LOCAL_LDLIBS := -llog -lGLESv2

include $(BUILD_SHARED_LIBRARY)
