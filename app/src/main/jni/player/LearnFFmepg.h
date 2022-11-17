//
// Created by LiyuanBin on 2022/11/17.
//

#ifndef LEARNFFMEPG_LEARNFFMEPG_H
#define LEARNFFMEPG_LEARNFFMEPG_H
extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
};
#include <thread>
using namespace std;

#define MAX_PATH   2048


enum LearnAVMediaType {
    LEARN_AVMEDIA_TYPE_UNKNOWN = -1,  ///< Usually treated as AVMEDIA_TYPE_DATA
    LEARN_AVMEDIA_TYPE_VIDEO,
    LEARN_AVMEDIA_TYPE_AUDIO,
    LEARN_AVMEDIA_TYPE_DATA,          ///< Opaque data information usually continuous
    LEARN_AVMEDIA_TYPE_SUBTITLE,
    LEARN_AVMEDIA_TYPE_ATTACHMENT,    ///< Opaque data information usually sparse
    LEARN_AVMEDIA_TYPE_NB
};
class LearnFFmepg {
public:
    LearnFFmepg(){};
    virtual ~LearnFFmepg(){};
    virtual void Init(char *url);
    virtual int InitFFDecoder();
    static void DoAVDecoding(LearnFFmepg *decoder);
private:
    //封装格式上下文
    AVFormatContext *m_AVFormatContext = nullptr;
    //解码器上下文
    AVCodecContext  *m_AVCodecContext = nullptr;
    thread             *m_Thread = nullptr;
    char       m_Url[MAX_PATH] = {0};
    //    //数据流的类型
    LearnAVMediaType      m_MediaType = LEARN_AVMEDIA_TYPE_UNKNOWN;
    int              m_StreamIndex = -1;

};

#endif //LEARNFFMEPG_LEARNFFMEPG_H
