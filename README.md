Here to try to implement ffmpeg.

How to compilate : 

Follow steps from https://github.com/googlesamples/android-ndk
to get NDK

build libcurl for android using the post from :

https://github.com/googlesamples/android-ndk/issues/348#issue-200637507

then build FFMPEG for android :

git pull https://github.com/WritingMinds/ffmpeg-android.git

cd ffmpeg-android

Set environment variable :
export ANDROID_NDK={ndk_bundle}

install libs :
sudo apt-get --quiet --yes install build-essential git autoconf libtool pkg-config gperf gettext yasm python-lxml

vim init_update_libs.sh 

Modify this line 13 : libpng-1.6.X
Put : libpng-1.6.28

same in libpng_build.sh

vim libpng_build.sh

line 5 : pushd libpng-1.6.28

then ./init_update_libs.sh

and ./android_build.sh (takes almost 30-40 min)
