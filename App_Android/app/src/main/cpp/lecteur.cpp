//
// Created by local on 27/01/17.
//

#include "lecteur.h"
#include <jni.h>
#include <string>
using namespace std;



extern "C"
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

JNIEXPORT jstring JNICALL
Java_com_example_local_app_1android_MainActivity_getString(JNIEnv *env, jobject) {

    std::string info = "Hello !";
    return env->NewStringUTF(info.c_str());
}
