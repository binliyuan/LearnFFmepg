/**
 *
 * Created by 公众号：字节流动 on 2021/3/16.
 * https://github.com/githubhaohao/LearnFFmpeg
 * 最新文章首发于公众号：字节流动，有疑问或者技术交流可以添加微信 Byte-Flow ,领取视频教程, 拉你进技术交流群
 *
 * */

//#include <cstdio>
//#include <cstring>
//#include <PlayerWrapper.h>
//#include <render/video/VideoGLRender.h>
//#include <render/video/VRGLRender.h>
//#include <render/audio/OpenSLRender.h>
//#include <MediaRecorderContext.h>
//#include "util/LogUtil.h"
#include "jni.h"
#include "player/LearnFFmepg.h"
#include "player/FFMediaPlayer.h"
#include "util/LogUtil.h"

extern "C" {
//#include <libavcodec/version.h>
//#include <libavcodec/avcodec.h>
//#include <libavformat/version.h>
//#include <libavutil/version.h>
//#include <libavfilter/version.h>
//#include <libswresample/version.h>
//#include <libswscale/version.h>
};

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_byteflow_learnffmpeg_media_FFMediaPlayer
 * Method:    native_GetFFmpegVersion
 * Signature: ()Ljava/lang/String;
 */
//JNIEXPORT jstring
//extern "C" JNICALL Java_com_byteflow_learnffmpeg_media_FFMediaPlayer_native_1GetFFmpegVersion
//        (JNIEnv *env, jclass cls)
//{
//    char strBuffer[1024 * 4] = {0};
//    strcat(strBuffer, "libavcodec : ");
//    strcat(strBuffer, AV_STRINGIFY(LIBAVCODEC_VERSION));
//    strcat(strBuffer, "\nlibavformat : ");
//    strcat(strBuffer, AV_STRINGIFY(LIBAVFORMAT_VERSION));
//    strcat(strBuffer, "\nlibavutil : ");
//    strcat(strBuffer, AV_STRINGIFY(LIBAVUTIL_VERSION));
//    strcat(strBuffer, "\nlibavfilter : ");
//    strcat(strBuffer, AV_STRINGIFY(LIBAVFILTER_VERSION));
//    strcat(strBuffer, "\nlibswresample : ");
//    strcat(strBuffer, AV_STRINGIFY(LIBSWRESAMPLE_VERSION));
//    strcat(strBuffer, "\nlibswscale : ");
//    strcat(strBuffer, AV_STRINGIFY(LIBSWSCALE_VERSION));
//    strcat(strBuffer, "\navcodec_configure : \n");
//    strcat(strBuffer, avcodec_configuration());
//    strcat(strBuffer, "\navcodec_license : ");
//    strcat(strBuffer, avcodec_license());
//    LOGCATE("GetFFmpegVersion\n%s", strBuffer);
//
//    //ASanTestCase::MainTest();
//
//    return env->NewStringUTF(strBuffer);
//}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_kuaiyou_learnffmepg_media_FFMediaPlayer_native_1Init(JNIEnv *env, jobject thiz,
                                                              jstring jurl, jint player_type,
                                                              jint render_type, jobject surface) {
    const char* url = env->GetStringUTFChars(jurl, nullptr);
//    FFMediaPlayer *player = new FFMediaPlayer();
////    LOGCATE("Init");
//    player->Init(env, thiz, const_cast<char *>(url), render_type, surface);
//    env->ReleaseStringUTFChars(jurl, url);
    LearnFFmepg *learnFFmepg  = new LearnFFmepg();
    LOGCATE("jurl ------- %s", url);
    learnFFmepg->Init(const_cast<char *>(url));
    return reinterpret_cast<jlong>(learnFFmepg);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_kuaiyou_learnffmepg_media_FFMediaPlayer_native_1Play(JNIEnv *env, jobject thiz,
                                                              jlong player_handle) {
    // TODO: implement native_Play()
}

extern "C"
JNIEXPORT void JNICALL
Java_com_kuaiyou_learnffmepg_media_FFMediaPlayer_native_1SeekToPosition(JNIEnv *env, jobject thiz,
                                                                        jlong player_handle,
                                                                        jfloat position) {
    // TODO: implement native_SeekToPosition()
}

extern "C"
JNIEXPORT void JNICALL
Java_com_kuaiyou_learnffmepg_media_FFMediaPlayer_native_1Pause(JNIEnv *env, jobject thiz,
                                                               jlong player_handle) {
    // TODO: implement native_Pause()
}
extern "C"
JNIEXPORT void JNICALL
Java_com_kuaiyou_learnffmepg_media_FFMediaPlayer_native_1Stop(JNIEnv *env, jobject thiz,
                                                              jlong player_handle) {
    // TODO: implement native_Stop()
}
extern "C"
JNIEXPORT void JNICALL
Java_com_kuaiyou_learnffmepg_media_FFMediaPlayer_native_1UnInit(JNIEnv *env, jobject thiz,
                                                                jlong player_handle) {
    // TODO: implement native_UnInit()
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_kuaiyou_learnffmepg_media_FFMediaPlayer_native_1GetMediaParams(JNIEnv *env, jobject thiz,
                                                                        jlong player_handle,
                                                                        jint param_type) {
    // TODO: implement native_GetMediaParams()
    long value = 0;
    return value;
}


#ifdef __cplusplus
}
#endif







