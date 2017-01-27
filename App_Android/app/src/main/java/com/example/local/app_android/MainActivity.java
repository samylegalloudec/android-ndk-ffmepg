package com.example.local.app_android;

import android.net.Uri;
import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Button;
import android.widget.VideoView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("downloader");
        System.loadLibrary("getrequest");
        //System.loadLibrary("lecteur");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView) findViewById(R.id.sample_text);
        //System.out.println(stringFromJNI());
        tv.setText(stringFromJNI2());

        TextView tv_ip = (TextView) findViewById(R.id.ip_text);
        tv_ip.setText(getString());

        Button button = (Button) findViewById(R.id.bouton);
        button.setText(stringFromJNI3());

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    //public native String refresh();
    public native String Download();
    public native String stringFromJNI2();
    public native String stringFromJNI3();
    public native String getString();

    public void refresh(){

    }
    //public native String retourRequete();
}
