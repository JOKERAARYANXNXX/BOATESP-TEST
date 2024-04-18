package com.boat.esp;

import android.app.*;
import android.os.*;
import android.widget.*;
import android.view.*;
import android.content.*;
import android.provider.*;
import android.net.*;
import android.graphics.*;
import java.util.Timer;
import java.util.TimerTask;
import android.content.Intent;
import android.graphics.Color;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageView;

public class SplashActivity extends Activity
{
    private ProgressBar progressBar;
	
    @Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_splash);
		progressBar = findViewById(R.id.progressBar);
		progressBar.setProgress(40);		
		new Handler().postDelayed(new Runnable(){
				@Override
				public void run(){
				progressBar.setProgress(80);	
				}
			},1000);
	new Handler().postDelayed(new Runnable(){
				@Override
				public void run(){
					progressBar.setProgress(100);	
					startActivity(new Intent(SplashActivity.this,LoginActivity.class));
				}
			},2000);
	}

}
