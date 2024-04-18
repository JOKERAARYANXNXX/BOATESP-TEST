package com.boat.esp;

import android.app.*;
import android.content.*;
import android.graphics.*;
import android.net.*;
import android.os.*;
import android.provider.*;
import android.view.*;
import android.view.View.*;
import android.widget.*;
import java.io.*;
import java.lang.Process;
import java.util.Objects;
import android.util.Log;
import java.util.TimerTask;
import java.util.Timer;
import android.content.pm.PackageManager;
import androidx.core.content.ContextCompat;
import android.Manifest;

public class MainActivity extends Activity implements OnClickListener {
	
	String gameName="com.tencent.ig";
	static int gameType=1;
	static int bit=1;
	
	
	static {
        System.loadLibrary("JOKERAARYAN");
    }
           
   private boolean isDisplay = false, isMenuDis = false;
    Context ctx;
    public static String socket;
    public String daemonPath,daemonPath64;
    static boolean isRoot = false, isNoRoot = false, rootMod = false, verMod = true, isDaemon = false, is64 = false, is32 = false, bitMod = false;
	AlertDialog.Builder builder;
	public Button mbutton2,mbutton1;
	private RadioGroup radioBit;
	public TextView textmode;
    native String Name1();
	native String Name2();
	native String Name3();
	native String Name4();
	native String Name5();
    native String Name6();
    native String toastCrack();
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {		
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
		CheckFloatViewPermission();
		initialization();
		loadAssets();		
		loadAssets64();
		Toast.makeText(getApplication(), toastCrack(), Toast.LENGTH_LONG).show();
		ctx = this;		
		textmode=(TextView)findViewById(R.id.textmode);
		mbutton1=(Button)findViewById(R.id.button1);
		mbutton2=(Button)findViewById(R.id.button2);
		radioBit = (RadioGroup) findViewById(R.id.radioBit);
		mbutton1.setOnClickListener(this);
		mbutton2.setOnClickListener(this);
		
		builder = new AlertDialog.Builder(this);  
		builder.setTitle("Execution Mode")
			.setMessage("Please select execution method")
			.setPositiveButton("Root", new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					isRoot = true;
					ExecuteElf();
					isNoRoot = false;
					rootMod = true;
					textmode.setText("Root");
				}
			})
			.setNegativeButton("Virtual", new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					isNoRoot = true;
					isRoot = false;
					rootMod = true;
					textmode.setText("Virtual");
				}
			});
		AlertDialog dialog = builder.create();
		dialog.show();
		
		final String[] vers = {"Global", "Korea", "Vietnam", "Taiwan", "Bgmi"};
		final Spinner spin = findViewById(R.id.spinner);
		ArrayAdapter<String> dataAdapter = new ArrayAdapter<>(this, R.layout.spinner_items, vers);
		dataAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
		spin.setAdapter(dataAdapter);
		spin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
				@Override
				public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
					if (spin.getSelectedItem().toString().equals("Global")){
						gameName = "com.tencent.ig";
						gameType=9154;
                      //  Toast.makeText(MainActivity.this, "BGMI",Toast.LENGTH_SHORT).show();
					}
					if (spin.getSelectedItem().toString().equals("Taiwan")){
						gameName = "com.rekoo.pubgm";
						gameType=4782;
					}
					else if (spin.getSelectedItem().toString().equals("Korea")){
						gameName = "com.pubg.krmobile";
						gameType=2484;
					}
					else if (spin.getSelectedItem().toString().equals("Vietnam")){
						gameName = "com.vng.pubgmobile";
						gameType=3326;
					}
					else if (spin.getSelectedItem().toString().equals("Bgmi")){
						gameName = "com.pubg.imobile";
                        gameType=5394;
					}
				}
				@Override
				public void onNothingSelected(AdapterView<?> parent) {

				}
			});
			
			radioBit.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() 
			{
				@Override
				public void onCheckedChanged(RadioGroup group, int checkedId) {
					// checkedId is the RadioButton selected
					switch (checkedId) {
						case R.id.radiobutton5:
                            is32 = true;
							is64 = false;

							bitMod = true;

							break;

						case R.id.radiobutton6:
                            is64 = true;
							is32 = false;

							bitMod = true;

							break;
					}
				}
			});
	
		}
		
	public void onClick(View v) {
        switch (v.getId()) {
            case R.id.button1:
                if (!isDisplay && !isMenuDis) {
                    if (!rootMod || !verMod || !bitMod) {
                        Toast.makeText(MainActivity.this, "Please Select Settings First !!", Toast.LENGTH_LONG).show();
                    } else {
                        if (isNoRoot) {           
                        if(is32) {								
					       socket = daemonPath;									//			MemHack = daemonPathMEM;						
						}
						else if(is64)
						{																	//			MemHack = daemonPathMEM;
						socket = daemonPath64;								
						}}                                
                        if (isRoot) {         
                        if(is32) {		             
                        socket = "su -c " + daemonPath;      
                        } 
                        else if(is64)
                        { 
                        socket = "su -c " + daemonPath64;      
                        }                 
                        }
                       // ExecZLX("/Bypass.sh");
                        startPatcher();          
						startService(new Intent(this, Overlay.class));	
						/*	Intent launchIntent = getPackageManager().getLaunchIntentForPackage(gameName);
			            if (launchIntent != null) { 
			            startActivity(launchIntent);     
			            } */
                        isDisplay = true;
                        isDaemon = true;
                    }   
                } else {
                    Toast.makeText(MainActivity.this, "Already Started !!", Toast.LENGTH_LONG).show();
                }
                break;
            case R.id.button2:
                if (isDisplay) {
                    isDisplay = false;
                    isMenuDis = false;
                    isDaemon = false;
                    stopService(new Intent(this, MainService.class));
                    stopService(new Intent(this, Overlay.class));
                }
                break;
        }
    }

	
	
    public void CheckFloatViewPermission() {
        if (!Settings.canDrawOverlays(this)) {
            Toast.makeText(this, "Enable Floating Permission ", Toast.LENGTH_LONG).show();
            startActivityForResult(new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, Uri.parse("package:" + getPackageName())), 0);
        }
    }

    private boolean isServiceRunning() {
        ActivityManager manager = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
        if (manager != null) {
            for (ActivityManager.RunningServiceInfo service : manager.getRunningServices(Integer.MAX_VALUE)) {
                if (MainService.class.getName().equals(service.service.getClassName())) {
                    return true;
                }
            }
        }
        return false;
    }

    void startPatcher() {
        if (!Settings.canDrawOverlays(this)) {
            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, Uri.parse("package:" + getPackageName()));
            startActivityForResult(intent, 123);
        } else {
            startFloater();
        }
    }

    private void startFloater() {
        if (!isServiceRunning()) {
            startService(new Intent(this, MainService.class));
        } else {
            Toast.makeText(this, "Service Already Running!", Toast.LENGTH_SHORT).show();
        }
    }

    private void ExecuteElf() {
        try {
            Runtime.getRuntime().exec("su -c", null, null);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void loadAssets() {
		String filepath =Environment.getExternalStorageDirectory() + "/Android/data/.tyb";
		FileOutputStream fos = null;
		try {
			fos = new FileOutputStream(filepath);
			byte[] buffer = "DO NOT DELETE".getBytes();
			fos.write(buffer, 0, buffer.length);
			fos.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (fos != null) {
				try {
					fos.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}

		String pathf = getFilesDir().toString() + "/sock";
		try {	
			OutputStream myOutput = new FileOutputStream(pathf);
			byte[] buffer = new byte[1024];
			int length;
			InputStream myInput = getAssets().open("sock");
			while ((length = myInput.read(buffer)) > 0) {
				myOutput.write(buffer, 0, length);
			}
			myInput.close();
			myOutput.flush();
			myOutput.close();
		} catch (IOException e) { 
		}
		daemonPath = getFilesDir().toString() + "/sock";
		try {
			Runtime.getRuntime().exec("chmod 777 " + daemonPath);
		} catch (IOException e) { 
		}
	}
    
    	public void loadAssets64()
	{

		String pathf = getFilesDir().toString()+"/sock64";
		 try
		 {	
		 OutputStream myOutput = new FileOutputStream(pathf);
		 byte[] buffer = new byte[1024];
		 int length;
		 InputStream myInput = getAssets().open("sock64");
		 while ((length = myInput.read(buffer)) > 0) {
		 myOutput.write(buffer, 0, length);
		 }
		 myInput.close();
		 myOutput.flush();
		 myOutput.close();

		 }

		 catch (IOException e)
		 { 
		 }


		daemonPath64 = getFilesDir().toString()+"/sock64";


		try{
			Runtime.getRuntime().exec("chmod 777 "+daemonPath64);
		}
		catch (IOException e)
		{ 
		}

	}
	
	public void ExecZLX(String path) {
        try {
        	// ROOT
            ExecuteElf0("su -c chmod 777 " + getFilesDir() + path);
            ExecuteElf0("su -c " + getFilesDir() + path);
            // VIRTUAL
            ExecuteElf0("chmod 777 " + getFilesDir() + path);
            ExecuteElf0("" + getFilesDir() + path);
		} catch (Exception e) {
        }
    }
    private void ExecuteElf0(String shell) {
		String s=shell;
		try {
			Runtime.getRuntime().exec(s, null, null);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

     private boolean MvAssets(String outPath, String fileName) {
        File file = new File(outPath);
        if (!file.exists()) {
            if (!file.mkdirs()) {
                Log.e("--Method--", "copyAssetsSingleFile: cannot create directory.");
                return false;
            }
        }
        try {
            InputStream inputStream = getAssets().open(fileName);
            File outFile = new File(file, fileName);
            FileOutputStream fileOutputStream = new FileOutputStream(outFile);
            byte[] buffer = new byte[1024];
            int byteRead;
            while (-1 != (byteRead = inputStream.read(buffer))) {
                fileOutputStream.write(buffer, 0, byteRead);
            }
            inputStream.close();
            fileOutputStream.flush();
            fileOutputStream.close();
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }
    
    private void initialization() {
		if (!LoginActivity.loginLoaded) { //Jump Login Protection
        	finishAffinity();
        } else {
			MvAssets(getFilesDir() + "/", Name1());//7hopx
			MvAssets(getFilesDir() + "/", Name2());//7hop
			MvAssets(getFilesDir() + "/", Name3());//bypass7h
			MvAssets(getFilesDir() + "/", Name4());//7hbase
	     	MvAssets(getFilesDir() + "/", Name5());//fix.sh
	     	MvAssets(getFilesDir() + "/", Name6());//off.sh
			Handler Handler = new Handler();
			Handler.postDelayed(new Runnable() {
					@Override
					public void run() {}}, 6000);
		}
    }

        public void Telegram(View view) {
        Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://t.me/INJECTOR_7H"));
        startActivity(browserIntent);
    }
        public void TelegramChat(View view) {
        Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://t.me/JOKERAARYANXNXX"));
        startActivity(browserIntent);
    }
	
}// made by @VinayakYT1
