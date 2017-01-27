//
// Created by local on 24/01/17.
//
#include <jni.h>
#include "getrequest.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/curlbuild.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
using namespace std;

getrequest::getrequest()
{
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
}

getrequest::~getrequest()
{
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

string getrequest::requete(const std::string &url)
{

}
extern "C"
JNIEXPORT jstring JNICALL Java_com_example_local_app_1android_MainActivity_retourRequete(JNIEnv *env, jobject) {

}

