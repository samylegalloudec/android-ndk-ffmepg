//
// Created by local on 24/01/17.
//

#ifndef APP_ANDROID_DOWNLOADER_H
#define APP_ANDROID_DOWNLOADER_H
#include <string>

class downloader {
public:
    downloader();
    ~downloader();
    /**
     * Download a file using HTTP GET and store in in a std::string
     * @param url The URL to download
     * @return The download result
     */
    std::string download(const std::string& url);
    std::string requete(const std::string& url);
private:
    void* curl;

};

#endif //APP_ANDROID_DOWNLOADER_H
