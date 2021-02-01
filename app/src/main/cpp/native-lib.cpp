#include <jni.h>
#include <string>

/**
 * 静态注册：通过 JNIEXPORT 和 JNICALL 两个宏定义声明，在虚拟机加载 so 时发现上面两个宏定义的函数时就会链接到对应的 native 方法。
 * 对应规则： Java + 包名 + 类名 + 方法名
 * 其中使用下划线将每部分隔开，包名也使用下划线隔开，如果名称中本来就包含下划线，将使用下划线加数字替换。
 */
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


/**
 * 动态注册：
 * 动态注册不再使用 JNIEXPORT 和 JNICALL 两个宏定义声明指定的方法，
 * 也不用依照固定的命名规则命名方法（不过通常 jni 里的方法名还是保持和 native 方法的方法名一致，见名思义），而是通过了一个 RegisterNatives 方法完成了动态注册。
 */
//extern "C" {
//    jstring stringFromJNI(JNIEnv *env, jobject instance) {
//        std::string hello = "Hello from C++";
//        return env->NewStringUTF(hello.c_str());
//    }
//
//    jint add(JNIEnv *env, jobject clazz, jint a, jint b) {
//        return a + b;
//    }
//
//    jint RegisterNatives(JNIEnv *env) {
//        jclass clazz = env->FindClass("com/example/ndkdemo/MainActivity");
//        if(clazz == NULL) {
//            return JNI_ERR;
//        }
//        JNINativeMethod method_MainActivity[] = {
//                {"stringFromJNI","()Ljava/lang/String;",(void *) stringFromJNI},
//                {"add","(II)I",(void *) add}
//        };
//        // RegisterNatives()方法解析：
//        //定义： jint RegisterNatives(jclass clazz, const JNINativeMethod* methods, jint nMethods)
//        //参数：clazz: 指定的类，即native所属的类，
//        // methods: 方法数组，
//        //nMethods: 方法数组的长度
//        return env->RegisterNatives(clazz,method_MainActivity,sizeof(method_MainActivity)/sizeof(method_MainActivity[0]));
//    }
//
//    jint JNI_OnLoad(JavaVM *vm, void *reserved) {
//        JNIEnv *env = NULL;
//        if(vm->GetEnv((void **) &env,JNI_VERSION_1_6) != JNI_OK) {
//            return JNI_ERR;
//        }
//        jint result = RegisterNatives(env);
//        return JNI_VERSION_1_6;
//    }
//}