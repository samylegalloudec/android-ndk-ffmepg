//
// Created by local on 27/01/17.
//

#include "lecteur.h"
#include <jni.h>
#include <string>
#ifdef __cplusplus
extern "C" {
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#ifdef __cplusplus
}
#endif
using namespace std;


lecteur::lecteur()
{

}

lecteur::~lecteur()
{

}

void lecteur::test()
{
    av_register_all();
}

extern "C"


JNIEXPORT jstring JNICALL
Java_com_example_local_app_1android_MainActivity_getString(JNIEnv *env, jobject) {

    std::string info = "Hello !";
    return env->NewStringUTF(info.c_str());
}
