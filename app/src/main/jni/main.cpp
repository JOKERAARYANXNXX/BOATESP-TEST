#include <jni.h>
#include <string>
#include "CanvasEngine.h"
#include "CanvasDrawing.h"
#include "Login.h"
#include "obfuscate.h"

ESP espOverlay;
int type=1,utype=2;

int d(int power){
    int t, ui, a,b,c,d;
a = power / 1000;
b = power % 1000 / 100;
c = power % 1000 % 100 / 10;
d = power % 1000 % 100 % 10;
t = ( a + 3 ) % 10;
a = ( c + 3 ) % 10;
c = t;
t = ( b + 3 ) % 10;
b = ( d + 3 ) % 10;
d = t;
ui = a * 1000 + b * 100 + c * 10 + d;
return ui;
}

extern "C" JNIEXPORT void JNICALL
Java_com_boat_esp_Overlay_DrawOn(JNIEnv *env, jclass , jobject espView, jobject canvas) {
    //You may need to comment this out if you are testing the app
    espOverlay = ESP(env, espView, canvas);
	
	if (g_Auth.empty())
        return;

    if (g_Token.empty())
        return;

    if (g_Auth != g_Token)
        return;
		
    if (espOverlay.isValid()){
        DrawESP(espOverlay, espOverlay.getWidth(), espOverlay.getHeight());
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainActivity_toastCrack(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("Welcome"));
	} else {
	return env->NewStringUTF(
            OBFUSCATE("Crack Detected Cheats Will Not Work"));	
	}
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainActivity_Name1(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("7hopx"));
	} else {
	return env->NewStringUTF(
            OBFUSCATE("Gay5b5"));	
	}
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainActivity_Name2(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("7hop"));
    } else {
	return env->NewStringUTF(
            OBFUSCATE("ffff"));	
	}
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainActivity_Name3(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("bypass7h"));
   } else {
   return env->NewStringUTF(
            OBFUSCATE("ffffdkd"));	
   }
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainActivity_Name4(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("7hbase"));
    } else {
	return env->NewStringUTF(
            OBFUSCATE("ffdkd"));	
	}
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainActivity_Name5(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("fix.sh"));
    } else {
	return env->NewStringUTF(
            OBFUSCATE("fxdkd"));	
	}
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainActivity_Name6(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("off.sh"));
    } else {
	return env->NewStringUTF(
            OBFUSCATE("fxxxx"));	
	}
}




extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainService_Name1(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("7hopx"));
	} else {
	return env->NewStringUTF(
            OBFUSCATE("Gay5b5"));	
	}
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainService_Name2(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("7hop"));
    } else {
	return env->NewStringUTF(
            OBFUSCATE("ffff"));	
	}
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainService_Name3(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("bypass7h"));
   } else {
   return env->NewStringUTF(
            OBFUSCATE("ffffdkd"));	
   }
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainService_Name4(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("7hbase"));
    } else {
	return env->NewStringUTF(
            OBFUSCATE("ffdkd"));	
	}
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainService_Name5(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("fix.sh"));
    } else {
	return env->NewStringUTF(
            OBFUSCATE("fxdkd"));	
	}
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_boat_esp_MainService_Name6(JNIEnv *env, jobject thiz) {
    if (bValid) {
    return env->NewStringUTF(
            OBFUSCATE("off.sh"));
    } else {
	return env->NewStringUTF(
            OBFUSCATE("fxxxx"));	
	}
}
extern "C" JNIEXPORT void JNICALL
Java_com_boat_esp_Overlay_Close(JNIEnv *,  jobject ) {
   Close();
}
jclass (*orig_FindClass)(JNIEnv *env, const char *name);
int Register2(JNIEnv *env) {
    JNINativeMethod methods[] = {{"Check", "(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;", (void *) native_Check}};

    jclass clazz = env->FindClass("com/boat/esp/LoginActivity");
    if (!clazz)
        return -1;

    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return -1;

    return 0;
}
extern "C" JNIEXPORT void JNICALL
Java_com_boat_esp_MainService_SettingValue(JNIEnv *,  jobject ,jint code,jboolean jboolean1) {
    switch((int)code){
		case 0:
		     showFPSOnScreen = jboolean1; break;
        case 1:
            isPlayerBox = jboolean1;   break;
        case 2:
            isPlayerLine = jboolean1;  break;
        case 3:
            isPlayerDist = jboolean1;  break;
        case 4:
            isPlayerHealth = jboolean1;  break;
        case 5:
            isPlayerName = jboolean1;  break;
        case 6:
            isPlayerHead = jboolean1;  break;
        case 7:
            isr360Alert = jboolean1;  break;
        case 8:
            isSkelton = jboolean1;  break;
        case 9:
            isGrenadeWarning = jboolean1;  break;
        case 10:
            isEnemyWeapon=jboolean1;  break;
        case 11:
            if(jboolean1 != 0)
                options.openState=0;
            else
                options.openState=-1;
            break;
        case 12:
            options.tracingStatus=jboolean1;
            break;
        case 13:
            options.pour=jboolean1;
            break;
    }
}


extern "C" JNIEXPORT void JNICALL
Java_com_boat_esp_MainService_Range(JNIEnv *,  jobject ,jint range) {
    options.aimingRange=1+range;
}
extern "C" JNIEXPORT void JNICALL
Java_com_boat_esp_MainService_Target(JNIEnv *,  jobject ,jint target) {
    options.aimbotmode=target;
}
extern "C" JNIEXPORT void JNICALL
Java_com_boat_esp_MainService_AimWhen(JNIEnv *,  jobject ,jint state) {
    options.aimingState=state;
}
extern "C" JNIEXPORT void JNICALL
Java_com_boat_esp_MainService_AimBy(JNIEnv *,  jobject ,jint aimby) {
    options.priority=aimby;
}
extern "C" JNIEXPORT jboolean JNICALL
Java_com_boat_esp_Overlay_getReady(JNIEnv *, jclass ,int typeofgame) {
    int sockCheck=1;
    if (!Create()) {
        perror("Creation failed");
        return false;
    }
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&sockCheck, sizeof(int));
    if (!Bind()) {
        perror("Bind failed");
        return false;
    }

    if (!Listen()) {
        perror("Listen failed");
        return false;
    }
    if (Accept()) {
        int ret;
        if (typeofgame == 1){
            ret = d(7257);
        } else if (typeofgame == 2) {
            ret = d(7357);
        } else if (typeofgame == 3) {
            ret = d(7457);
        } else if (typeofgame == 4) {
            ret = d(7557);
        } else if (typeofgame == 5) {
            ret = d(7657);
        }
        SetValue sv{};
        sv.mode=ret;
        sv.type=utype;
        sv.uname = "jokerchod";// Don't change name else sock not work
        send((void*)&sv,sizeof(sv));
       // Close();
        return true;
    }

}
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    
    if (Register2(env) != 0)
        return -1;
    
    return JNI_VERSION_1_6;
}//Made By @VinayakYT1  
