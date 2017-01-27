cmake_minimum_required(VERSION 3.4.1)

set(distribution_DIR ${CMAKE_SOURCE_DIR}/../distribution)


add_library(lib-curl STATIC IMPORTED)

add_library(ffmpeg SHARED IMPORTED)

set_target_properties(lib-curl PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/curl/lib/${ANDROID_ABI}/libcurl.a)

set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavcodec.a)

set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavdevice.a)

set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavfilter.a)

set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavformat.a)

set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavutil.a)

set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libpostproc.a)

set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libswresample.a)

set_target_properties(ffmpeg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libswscale.a)




set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")


add_library( # Sets the name of the library.
             downloader
             SHARED
             src/main/cpp/downloader.cpp
              #src/main/cpp/downloader.h
              )


add_library( # Sets the name of the library.
             getrequest
             SHARED
             src/main/cpp/getrequest.cpp
              #src/main/cpp/getrequest.h
              )

add_library( # Sets the name of the library.
             lecteur
             SHARED
             src/main/cpp/lecteur.cpp
              #src/main/cpp/lecteur.h
              )

target_include_directories(downloader PRIVATE
                           ${distribution_DIR}/curl/include)

target_include_directories(getrequest PRIVATE
                           ${distribution_DIR}/curl/include)

target_include_directories(lecteur PRIVATE
                           ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/include)


find_library( # Sets the name of the path variable.
              log-lib

              log )

target_link_libraries( # Specifies the target library.
                       downloader
                       lib-curl
                       z
                       ${log-lib}
                       )

target_link_libraries( # Specifies the target library.
                       getrequest
                       lib-curl
                       z
                       ${log-lib}
                       )

target_link_libraries( # Specifies the target library.
                       lecteur
                       ffmpeg
                       z
                       ${log-lib}
                       )