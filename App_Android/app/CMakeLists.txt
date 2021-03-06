cmake_minimum_required(VERSION 3.4.1)

#set(CMAKE_C_COMPILER "/usr/bin/gcc") #change le compilateur clang en gcc
#set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set (APP_PLATFORM -DAPP_PLATFORM=android-11)

set(distribution_DIR ${CMAKE_SOURCE_DIR}/../distribution) #indique ou se trouve les librairies

add_library(lib-curl STATIC IMPORTED) #importe la librairie lib-curl en statique (sans paramètres)
set_target_properties(lib-curl PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/curl/lib/${ANDROID_ABI}/libcurl.a) #Je mets les paramètres de l'importation

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
set(CMAKE_SHARED_LINKER_FLAGS "-Wall -v -Wl,--no-warn-shared-textrel") #Evite les problèmes de linker dus à la déprécation



add_library( # Sets the name of the library. #Je crée la librairie gestionnaire qui contient mes classes
             gestionnaire
             SHARED
             src/main/cpp/downloader.cpp
             src/main/cpp/lecteur.cpp
             src/main/cpp/gestionnaire.cpp
              )


#Je définis ou se trouve le dossier des include pour que ma lib gestionnaire les trouve
target_include_directories(gestionnaire PRIVATE
                           ${distribution_DIR}/curl/include
                           ${distribution_DIR}/ffmpeg/${ANDROID_ABI}/include)

find_library( # Sets the name of the path variable.
              log-lib

              log )

#link toutes mes librairies à ma lib gestionnaire
target_link_libraries( # Specifies the target library.
                       gestionnaire
                       ffmpeg-codec
                       ffmpeg-device
                       ffmpeg-filter
                       ffmpeg-format
                       ffmpeg-util
                       ffmpeg-postproc
                       ffmpeg-sample
                       ffmpeg-scale
                       lib-curl
                       z
                       ${log-lib}
                       )