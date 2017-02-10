//
// Created by local on 27/01/17.
//

#include "lecteur.h"
#include <jni.h>
#include <string>
#include <iostream>
using namespace std;


lecteur::lecteur()
{

}

lecteur::~lecteur()
{

}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_local_app_1android_MainActivity_getString(JNIEnv *env, jobject) {

    std::string info = "Hello !";
    return env->NewStringUTF(info.c_str());
}

extern "C"
{
#include <libavcodec/avcodec.h>

JNIEXPORT jstring JNICALL
Java_com_example_local_app_1android_MainActivity_getString2(JNIEnv *env, jobject instance) {

    char info[10000] = {0};

    sprintf(info, "%s\n", avcodec_configuration());
    return env->NewStringUTF(info);
}

}