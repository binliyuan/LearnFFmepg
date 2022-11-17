//
// Created by LiyuanBin on 2022/11/17.
//
#include "LearnFFmepg.h"
#include "android/log.h"

#define  LOG_TAG "ByteFlow"

#define  LOGCATE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGCATV(...)  __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)
#define  LOGCATD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGCATI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)



void LearnFFmepg::Init(char *url) {
    LOGCATE("DecoderBase::Init url=%s ", url);
    strcpy(m_Url, url);
    m_MediaType = LEARN_AVMEDIA_TYPE_VIDEO;
    m_Thread = new thread(DoAVDecoding, this);
}

//
int LearnFFmepg::InitFFDecoder() {
    int result = -1;
    do {
        //1.创建封装格式上下文
        m_AVFormatContext = avformat_alloc_context();

        int openResult = avformat_open_input(&m_AVFormatContext, m_Url, NULL, NULL);
        LOGCATE("DecoderBase::InitFFDecoder %s openResult: %d", m_Url, openResult);
        //2.打开文件
        if (avformat_open_input(&m_AVFormatContext, m_Url, NULL, NULL) != 0) {
            LOGCATE("DecoderBase::InitFFDecoder avformat_open_input fail.");
            break;
        }

        //3.获取音视频流信息
        if(avformat_find_stream_info(m_AVFormatContext, NULL) < 0) {
            LOGCATE("DecoderBase::InitFFDecoder avformat_find_stream_info fail.");
            break;
        }

        //4.获取音视频流索引
        for(int i=0; i < m_AVFormatContext->nb_streams; i++) {
            if(m_AVFormatContext->streams[i]->codecpar->codec_type == m_MediaType) {
                m_StreamIndex = i;
                break;
            }
        }
//        m_AVFormatContext->bit_rate;
//
        if(m_StreamIndex == -1) {
            LOGCATE("DecoderBase::InitFFDecoder Fail to find stream index.");
            break;
        }
        LOGCATE("DecoderBase::InitFFDecoder m_StreamIndex %d", m_StreamIndex);
//        //5.获取解码器参数
//        AVCodecParameters *codecParameters = m_AVFormatContext->streams[m_StreamIndex]->codecpar;
//
//        //6.获取解码器
//        m_AVCodec = avcodec_find_decoder(codecParameters->codec_id);
//        if(m_AVCodec == nullptr) {
//            LOGCATE("DecoderBase::InitFFDecoder avcodec_find_decoder fail.");
//            break;
//        }
//
//        //7.创建解码器上下文
//        m_AVCodecContext = avcodec_alloc_context3(m_AVCodec);
//        if(avcodec_parameters_to_context(m_AVCodecContext, codecParameters) != 0) {
//            LOGCATE("DecoderBase::InitFFDecoder avcodec_parameters_to_context fail.");
//            break;
//        }
//
//        AVDictionary *pAVDictionary = nullptr;
//        av_dict_set(&pAVDictionary, "buffer_size", "1024000", 0);
//        av_dict_set(&pAVDictionary, "stimeout", "20000000", 0);
//        av_dict_set(&pAVDictionary, "max_delay", "30000000", 0);
//        av_dict_set(&pAVDictionary, "rtsp_transport", "tcp", 0);
//
//        //8.打开解码器
//        result = avcodec_open2(m_AVCodecContext, m_AVCodec, &pAVDictionary);
//        if(result < 0) {
//            LOGCATE("DecoderBase::InitFFDecoder avcodec_open2 fail. result=%d", result);
//            break;
//        }
//        result = 0;
//
//        m_Duration = m_AVFormatContext->duration / AV_TIME_BASE * 1000;//us to ms
//        //创建 AVPacket 存放编码数据
//        m_Packet = av_packet_alloc();
//        //创建 AVFrame 存放解码后的数据
//        m_Frame = av_frame_alloc();
    } while (false);
//
//    if(result != 0 && m_MsgContext && m_MsgCallback)
//        m_MsgCallback(m_MsgContext, MSG_DECODER_INIT_ERROR, 0);

    return result;
}

void LearnFFmepg::DoAVDecoding(LearnFFmepg *decoder) {
    LOGCATE("DecoderBase::DoAVDecoding");
    do {
        if(decoder->InitFFDecoder() != 0) {
            break;
        }
//        decoder->OnDecoderReady();
//        decoder->DecodingLoop();
    } while (false);

//    decoder->UnInitDecoder();
//    decoder->OnDecoderDone();

}
