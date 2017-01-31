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

//méthode qui écrit les données
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    string data((const char*) ptr, (size_t) size * nmemb);
    *((stringstream*) stream) << data << endl;
    return size * nmemb;
}

downloader::downloader() {
    //Ouvre la connexion
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
}

downloader::~downloader() {
    //Ferme la connexion
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

string downloader::download(const std::string& url) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //Je lui indique l'url
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Si redirection, suit la redirection
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1); //Evite le bug : "longjmp causes uninitialized stack frame"
    std::stringstream out;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); //indique la méthode de données
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out); //écrit les données ici

    CURLcode res = curl_easy_perform(curl); //se comporte comme indiqué ci dessus
//En cas d'erreur
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
    //On appelle la méthode en lui mettant un lien
    std::string content = downloaderz.download("http://iris.appert44.org");
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