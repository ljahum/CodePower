// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("jnitest");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("jnitest")
//      }
//    }


#include <jni.h>
#include <string>
#include <android/log.h>
#include <unistd.h>
#include "string.h"
#include <vector>

void rc4_crypt(unsigned char* Data, unsigned long Len_D, unsigned char* key, unsigned long Len_k);


extern "C" JNIEXPORT jstring JNICALL

Java_com_example_jnitest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject thisObj) {

    jclass thisClass = env->GetObjectClass(thisObj);
    jmethodID getNameMethod = env->GetMethodID(thisClass, "testFunc", "()Ljava/lang/String;");
    jstring className = (jstring)env->CallObjectMethod(thisObj, getNameMethod);
    const char* classNameStr = env->GetStringUTFChars(className, nullptr);

    __android_log_print(ANDROID_LOG_INFO, "MyApp", "Calling class: %s", classNameStr);
    env->ReleaseStringUTFChars(className, classNameStr);


    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


const unsigned char enc[] = {0xd, 0x3, 0x1c, 0xd8, 0x37, 0x2e, 0xeb, 0xcd, 0xf4, 0x5, 0x54, 0x1a, 0x1c};



extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_jnitest_MainActivity_sendStringToJNI(
        JNIEnv* env,
        jobject /*this*/,
        jstring inputString) {


    const char *cString = env->GetStringUTFChars(inputString, nullptr);
    int len = std::strlen(cString);
    unsigned char* flag = new unsigned char[len + 1];
    std::strcpy(reinterpret_cast<char*>(flag), cString);
    size_t flag_length = strlen(reinterpret_cast<const char*>(flag));
    unsigned char key[] = "ljahum";
    unsigned long key_len = sizeof(key) - 1;

    __android_log_print(ANDROID_LOG_INFO, "MyApp", "flag %s %d", flag,flag_length);
    if(flag_length != 13){
        return false;
    }
    rc4_crypt(flag, flag_length, key, key_len);

// flag{xsj-kwy}
    for (int i = 0; i < flag_length; ++i) {
        if(flag[i]!=enc[i])
            return false;
//        __android_log_print(ANDROID_LOG_INFO, "MyApp", "enc%d %x %x",i, flag[i],enc[i]);
    }
//    __android_log_print(ANDROID_LOG_INFO, "MyApp", "====");
//    rc4_crypt(flag, flag_length, key, key_len);
//// flag{xsj-kwy}
//
//    for (int i = 0; i < flag_length; ++i) {
//        __android_log_print(ANDROID_LOG_INFO, "MyApp", "%d %c",i, flag[i]);
//    }

    return true;

}





/*
RC4初始化函数
*/
void rc4_init(unsigned char* s, unsigned char* key, unsigned long Len_k)
{
    int i = 0, j = 0;
    char k[256] = { 0 };
    unsigned char tmp = 0;
    for (i = 0; i < 256; i++) {
        s[i] = i;
        k[i] = key[i % Len_k];
    }
    for (i = 0; i < 256; i++) {
        j = (j + s[i] + k[i]) % 256;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/*
RC4加解密函数
unsigned char* Data     加解密的数据
unsigned long Len_D     加解密数据的长度
unsigned char* key      密钥
unsigned long Len_k     密钥长度
*/



void rc4_crypt(unsigned char* Data, unsigned long Len_D, unsigned char* key, unsigned long Len_k) //加解密
{
    unsigned char s[256];
    rc4_init(s, key, Len_k);
    int i = 0, j = 0, t = 0;
    unsigned long k = 0;
    unsigned char tmp;
    for (k = 0; k < Len_D; k++) {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        t = (s[i] + s[j]) % 256;
        Data[k] = Data[k] ^ s[t];
    }
}

