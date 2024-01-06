package com.example.jnitest;


import androidx.appcompat.app.AppCompatActivity;


import android.os.Bundle;


//import java.util.logging.Level;
//import java.util.logging.Logger;
import android.util.Log;


//===========================


import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("jnitest");
    }
//    JNI declare
    public native String stringFromJNI();
    public native boolean sendStringToJNI(String text);


    public String testFunc(){
        Log.i("testFunc", "who calling ME!!!!");
        return "I am a lonely function";
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = findViewById(R.id.button1);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // 处理按钮点击事件的代码
                String TAG = "MainActivity";
                Log.i(TAG, "Button Clicked");
                final TextView editText = findViewById(R.id.editText);
                String flag = editText.getText().toString();
                Log.d(TAG, flag);


                TextView TV = findViewById(R.id.MySample_text) ;
                TV.setText(stringFromJNI());
                boolean tmp = sendStringToJNI(flag);


                TextView TV2 = findViewById(R.id.res_text) ;
                if(tmp){
                    TV2.setText("success");
                }else {
                    TV2.setText("wrong");
                }
            };
        });

    }

}