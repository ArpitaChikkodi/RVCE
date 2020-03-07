package com.example.progressdialog;

import androidx.appcompat.app.AppCompatActivity;

import android.app.ProgressDialog;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    ProgressDialog pg;
    final int seconds = 30*1000;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void startProgress(View v)
    {
     pg   = new ProgressDialog(this);
     pg.setCancelable(false);
     pg.setMessage("Wait....");
     pg.show();
     new Handler().postDelayed(new Runnable() {
         @Override
         public void run() {
             pg.dismiss();
         }
     },seconds);
    }
}
