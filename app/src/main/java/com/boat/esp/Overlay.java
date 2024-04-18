package com.boat.esp;

import android.annotation.*;
import android.app.Service;
import android.content.*;
import android.graphics.*;
import android.os.*;
import android.view.*;
import java.io.*;

public class Overlay extends Service {

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    WindowManager windowManager;
    CheatViewer overlayView;
    @SuppressLint("StaticFieldLeak")
    private static Overlay Instance;

    @SuppressLint("StaticFieldLeak")
    static Context ctx;

    @SuppressLint("InflateParams")
    @Override
    public void onCreate() {
        super.onCreate();
        ctx = this;         
        if (MainActivity.gameType == 9154 && MainActivity.is32) {
            Start(ctx, 1, 1);
        } else if (MainActivity.gameType == 9154 && MainActivity.is64) {
            Start(ctx, 1, 2);
        } else if (MainActivity.gameType == 2484 && MainActivity.is32) {
            Start(ctx, 2, 1);
        } else if (MainActivity.gameType == 2484 && MainActivity.is64) {
            Start(ctx, 2, 2);
        } else if (MainActivity.gameType == 3326 && MainActivity.is32) {
            Start(ctx, 3, 1);
        } else if (MainActivity.gameType == 3326 && MainActivity.is64) {
            Start(ctx, 3, 2);
        } else if (MainActivity.gameType == 4782 && MainActivity.is32) {
            Start(ctx, 4, 1);
        } else if (MainActivity.gameType == 4782 && MainActivity.is64) {
            Start(ctx, 4, 2);
        } else if (MainActivity.gameType == 5394 && MainActivity.is32) {
            Start(ctx, 5, 1);
        } else if (MainActivity.gameType == 5394 && MainActivity.is64) {
            Start(ctx, 5, 2);
        }

        windowManager = (WindowManager) ctx.getSystemService(Context.WINDOW_SERVICE);
        overlayView = new CheatViewer(ctx);
        //  mFloatingView = LayoutInflater.from(ctx).inflate(R.layout.float_view, null);
        DrawCanvas();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Close();
        if (overlayView != null) {
            ((WindowManager) ctx.getSystemService(Context.WINDOW_SERVICE)).removeView(overlayView);
            overlayView = null;
        }
    }

    public void Start(final Context context, final int gametype, final int bit) {
        if (Instance == null) {
            Thread t = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        getReady(gametype);
                    }
                });
            t.start();
            Thread t2 = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        try {
                            Thread.sleep(100);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                        StartDaemon(context, bit);
                    }
                });
            t2.start();
        }
    }

    static native boolean getReady(int nameofgame);

    public void StartDaemon(final Context context, int bit) {
        Shell(MainActivity.socket);
    }

    private native void Close();

    static boolean getConfig(String key) {
        SharedPreferences sp = ctx.getSharedPreferences("espValue", Context.MODE_PRIVATE);
        return sp.getBoolean(key, false);
    }

    private void DrawCanvas() {
        int LAYOUT_FLAG;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            LAYOUT_FLAG = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
        } else {
            LAYOUT_FLAG = WindowManager.LayoutParams.TYPE_SYSTEM_OVERLAY;
        }
        final WindowManager.LayoutParams params = new WindowManager.LayoutParams(
            WindowManager.LayoutParams.MATCH_PARENT,
            WindowManager.LayoutParams.MATCH_PARENT, 0, getNavigationBarHeight(),
            LAYOUT_FLAG,
            WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE
            | WindowManager.LayoutParams.FLAG_NOT_TOUCHABLE | WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN | WindowManager.LayoutParams.FLAG_FULLSCREEN,
            PixelFormat.RGBA_8888);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P)
            params.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;

        params.gravity = Gravity.TOP | Gravity.START;        //Initially view will be added to top-left corner
        params.x = 0;
        params.y = 0;
        windowManager = (WindowManager) getSystemService(WINDOW_SERVICE);
        windowManager.addView(overlayView, params);
    }

    public static native void DrawOn(CheatViewer espView, Canvas canvas);

    private int getNavigationBarHeight() {
        boolean hasMenuKey = ViewConfiguration.get(this).hasPermanentMenuKey();
        int resourceId = getResources().getIdentifier("navigation_bar_height", "dimen", "android");
        if (resourceId > 0 && !hasMenuKey) {
            return getResources().getDimensionPixelSize(resourceId);
        }
        return 0;
    }

    public void Shell(String str) {
        try {
            Runtime.getRuntime().exec(str);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
