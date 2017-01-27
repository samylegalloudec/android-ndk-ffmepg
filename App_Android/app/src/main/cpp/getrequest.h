//
// Created by local on 24/01/17.
//

#ifndef APP_ANDROID_GETREQUEST_H
#define APP_ANDROID_GETREQUEST_H
#include <string>

class getrequest {
public:
    getrequest();
    ~getrequest();
    std::string requete(const std::string& url);

private:
    void* curl;
};


#endif //APP_ANDROID_GETREQUEST_H
