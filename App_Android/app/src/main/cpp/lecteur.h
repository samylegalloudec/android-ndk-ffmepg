//
// Created by local on 27/01/17.
//

#ifndef APP_ANDROID_LECTEUR_H
#define APP_ANDROID_LECTEUR_H


#include <libavcodec/avcodec.h>

class lecteur {
public:
    lecteur();
    ~lecteur();

    static void audio_encode_example(const char *filename);
    static uint64_t select_channel_layout(AVCodec *codec);
    static int check_sample_fmt(AVCodec *codec, enum AVSampleFormat sample_fmt);
    static int select_sample_rate(AVCodec *codec);
    static void audio_decode_example(const char *outfilename, const char *filename);
    static void video_encode_example(const char *filename, int codec_id);
    static void pgm_save(unsigned char *buf, int wrap, int xsize, int ysize, char *filename);
    static int decode_write_frame(const char *outfilename, AVCodecContext *avctx, AVFrame *frame, int *frame_count, AVPacket *pkt, int last);
    static void video_decode_example(const char *outfilename, const char *filename);

private:
    AVCodec *codec;
};


#endif //APP_ANDROID_LECTEUR_H
