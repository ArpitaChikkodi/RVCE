package com.example.runtimeimage;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ImageView;
import android.widget.LinearLayout;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        LinearLayout flayout = findViewById(R.id.flayout);
        ImageView im = new ImageView(this);
        im.setImageResource(R.drawable.index1);
        flayout.addView(im);
    }
}