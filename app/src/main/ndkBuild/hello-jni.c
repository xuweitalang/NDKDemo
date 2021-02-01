#include <jni.h>

int test() {
    return 123;
}

//com.example.ndkdemo
jint Java_com_example_ndkdemo_MainActivity_nativeTest(JNIEnv *env, jobject thiz) {
    return test();
}