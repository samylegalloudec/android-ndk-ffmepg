LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:= libavdevice
LOCAL_SRC_FILES:= distribution/ffmpeg/${APP_ABI}/include/libavdevice.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/ffmpeg/${APP_ABI}/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= libavcodec
LOCAL_SRC_FILES:= distribution/ffmpeg/${APP_ABI}/include/libavcodec.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/ffmpeg/${APP_ABI}/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= libavformat
LOCAL_SRC_FILES:= distribution/ffmpeg/${APP_ABI}/include/libavformat.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/ffmpeg/${APP_ABI}/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= libswscale
LOCAL_SRC_FILES:= distribution/ffmpeg/${APP_ABI}/include/libswscale.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/ffmpeg/${APP_ABI}/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= libavutil
LOCAL_SRC_FILES:= distribution/ffmpeg/${APP_ABI}/include/libavutil.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/ffmpeg/${APP_ABI}/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= libavfilter
LOCAL_SRC_FILES:= distribution/ffmpeg/${APP_ABI}/include/libavfilter.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/ffmpeg/${APP_ABI}/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= libswresample
LOCAL_SRC_FILES:= distribution/ffmpeg/${APP_ABI}/include/libswresample.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/ffmpeg/${APP_ABI}/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= lib-curl
LOCAL_SRC_FILES:= distribution/curl/lib/${APP_ABI}/libcurl.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/curl/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= gestionnaire
LOCAL_STATIC_LIBRARIES := libavcodec libavformat libavdevice libavfilter libavutil libpostproc libswresample libswscale
LOCAL_SRC_FILES:= gestionnaire.cpp lecteur.cpp downloader.cpp
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/distribution/curl/include
include $(PREBUILT_STATIC_LIBRARY)


APP_ABI := armeabi-v7a x86
APP_PLATFORM := android-11
