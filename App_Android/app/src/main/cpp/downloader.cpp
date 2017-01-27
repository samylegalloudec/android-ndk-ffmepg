//
// Created by local on 24/01/17.
//

#include <jni.h>
#include "downloader.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/curlbuild.h>
#include <sstream>
#include <iostream>

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    string data((const char*) ptr, (size_t) size * nmemb);
    *((stringstream*) stream) << data << endl;
    return size * nmemb;
}

downloader::downloader() {
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
}

downloader::~downloader() {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

string downloader::download(const std::string& url) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1); //Evite le bug : "longjmp causes uninitialized stack frame"
    std::stringstream out;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }
    return out.str();
}

extern "C"
JNIEXPORT jstring JNICALL Java_com_example_local_app_1android_MainActivity_Download(JNIEnv *env, jobject) {
    cout << "test" << endl;
    downloader downloaderz;
    std::string content = downloaderz.download("http://172.31.5.105:8001/get");
    std:: string test = "Début ---->" + content + "<---- Fin";
    return env->NewStringUTF(test.c_str());
}
extern "C"
jstring
Java_com_example_local_app_1android_MainActivity_stringFromJNI2(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Adresse IP Publique : ";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
jstring
Java_com_example_local_app_1android_MainActivity_stringFromJNI3(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "REFRESH";
    return env->NewStringUTF(hello.c_str());
}