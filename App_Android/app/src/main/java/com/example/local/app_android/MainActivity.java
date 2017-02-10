package com.example.local.app_android;


import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        //Appelle les librairies SHARED
        System.loadLibrary("gestionnaire");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Crée un text view, prend les paramètres du textview qui a pour id sample_text dans activity_main.xml
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI2());

        TextView tv_ip = (TextView) findViewById(R.id.ip_text);
        tv_ip.setText(getString2());

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
    //public native String getInt();
    public native String getString2();

    public void refresh(){


    }
}
