#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libswscale/swscale.h>
    #include <libavutil/avutil.h>
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativelib_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    AVCodec *codec = avcodec_find_encoder_by_name("libx264");
    AVCodecContext *context = avcodec_alloc_context3(codec);
    int ret = avcodec_open2(context, codec, NULL);
    __android_log_print(ANDROID_LOG_INFO, "TAG", "%s, %d", __FUNCTION__, ret);
    return env->NewStringUTF(hello.c_str());
}