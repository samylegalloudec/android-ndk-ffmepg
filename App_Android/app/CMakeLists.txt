cmake_minimum_required(VERSION 3.4.1)

set(distribution_DIR ${CMAKE_SOURCE_DIR}/../distribution)


add_library(lib-curl STATIC IMPORTED)



set_target_properties(lib-curl PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/curl/lib/${ANDROID_ABI}/libcurl.a)

add_library(ffmpeg-codec STATIC IMPORTED)
set_target_properties(ffmpeg-codec PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavcodec.a)

add_library(ffmpeg-device STATIC IMPORTED)
set_target_properties(ffmpeg-device PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavdevice.a)

add_library(ffmpeg-filter STATIC IMPORTED)
set_target_properties(ffmpeg-filter PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavfilter.a)

add_library(ffmpeg-format STATIC IMPORTED)
set_target_properties(ffmpeg-format PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavformat.a)

add_library(ffmpeg-util STATIC IMPORTED)
set_target_properties(ffmpeg-util PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libavutil.a)

add_library(ffmpeg-postproc STATIC IMPORTED)
set_target_properties(ffmpeg-postproc PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libpostproc.a)

add_library(ffmpeg-sample STATIC IMPORTED)
set_target_properties(ffmpeg-sample PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libswresample.a)

add_library(ffmpeg-scale STATIC IMPORTED)
set_target_properties(ffmpeg-scale PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/lib/libswscale.a)




set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")


add_library( # Sets the name of the library.
             downloader
             SHARED
             src/main/cpp/downloader.cpp
             src/main/cpp/downloader.h
              )


add_library( # Sets the name of the library.
             getrequest
             SHARED
             src/main/cpp/getrequest.cpp
             src/main/cpp/getrequest.h
              )

add_library( # Sets the name of the library.
             lecteur
             SHARED
             src/main/cpp/lecteur.cpp
             src/main/cpp/lecteur.h
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
                       ffmpeg-codec
                       ffmpeg-device
                       ffmpeg-filter
                       ffmpeg-format
                       ffmpeg-util
                       ffmpeg-postproc
                       ffmpeg-sample
                       ffmpeg-scale
                       z
                       ${log-lib}
                       )