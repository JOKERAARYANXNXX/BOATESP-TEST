package com.boat.esp;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Build;
import android.os.Handler;
import android.os.Message;
import android.provider.Settings;
import android.text.InputType;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.Button;
import android.view.View;
import android.os.Bundle;
import android.widget.Toast;
import android.widget.TextView;

public class LoginActivity extends Activity {
	
	private static SharedPreferences m_Prefs;
    private EditText editTextEmail;
    private TextView Buy;
    private Button buttonLogin;   
    static boolean loginLoaded=false;
    Context m_Context = (Context) LoginActivity.this;
	Activity m_Activity = (Activity) LoginActivity.this;


	static {
        System.loadLibrary("JOKERAARYAN");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);        
        loginLoaded = false;

       Buy = findViewById(R.id.Buy);
       Buy.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View view) {
					Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://t.me/INJECTOR_7H"));
                    startActivity(browserIntent);
				}
			});		
			
		m_Prefs = m_Context.getSharedPreferences("XSkill_Data", Context.MODE_PRIVATE);
        if (!m_Prefs.contains("USER_KEY")) {		
			editTextEmail = findViewById(R.id.mail);
			buttonLogin = findViewById(R.id.init);
        buttonLogin.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View view) {
					String userKey = editTextEmail.getText().toString();
					Login(m_Context, userKey);     
				}
			});		
	} else {
		Login(m_Context, m_Prefs.getString("USER_KEY", null));
	}
}
	private static void Login(final Context m_Context, final String userKey) {
        final ProgressDialog progressDialog = new ProgressDialog(m_Context, 5);
        progressDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
        progressDialog.setMessage("Please wait...");
        progressDialog.setCancelable(false);
        progressDialog.show();
		
		final  Handler loginHandler = new Handler() {
		
            @Override
            public void handleMessage(Message msg) {
				progressDialog.dismiss();
                if (msg.what == 0) {
					loginLoaded = true;
					m_Context.startActivity(new Intent(m_Context, MainActivity.class));
					
				} else if (msg.what == 1) {			    
                    AlertDialog.Builder builder = new AlertDialog.Builder(m_Context, 5);
                    builder.setTitle("Key Status");
                    builder.setMessage(msg.obj.toString());
                    builder.setCancelable(false);

                    builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
							@Override
							public void onClick(DialogInterface dialog, int which) {
						    								      
							}
						});
                    builder.show();
                }

            }
        };

        new Thread(new Runnable() {
				@Override
				public void run() {
					String result = Check(m_Context, userKey);
					if (result.equals("OK")) {
						m_Prefs.edit().putString("USER_KEY", userKey).apply();

						loginHandler.sendEmptyMessage(0);
					} else {
						m_Prefs.edit().clear().apply();

						Message msg = new Message();
						msg.what = 1;
						msg.obj = result;
						loginHandler.sendMessage(msg);
					}
				}
			}).start();
			   	   
    }

	//  private static native void Init(Context mContext);
    private static native String Check(Context mContext, String userKey);
}
