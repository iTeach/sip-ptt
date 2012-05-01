// PJSIP header files
#include <pjsua-lib/pjsua.h>

// Android-specific header files
#include <android/log.h>
#include <jni.h>

#define  LOG_TAG    "Push To Talk"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

JNIEXPORT void JNICALL Java_com_csipsimple_ui_InCallActivity2_pttButtonTouchEvent(JNIEnv *env, jobject thiz, jboolean is_button_down, jint call_id)
{
    LOGI("pttButtonTouchEvent(%s, call_id=%d)", is_button_down ? "DOWN" : "UP", call_id);

    if (call_id != -1) {
        pj_str_t digit = pj_str(is_button_down ? "5" : "0");
        pjsua_call_dial_dtmf(call_id, &digit); 
    }
}

JNIEXPORT void JNICALL Java_com_csipsimple_ui_InCallActivity2_onCallConfirmed(JNIEnv *env, jobject thiz, jint call_id)
{
    LOGI("onCallConfirmed(call_id=%d)", call_id);
}

