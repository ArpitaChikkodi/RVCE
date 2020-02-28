package com.example.runtimeimage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.os.Bundle;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ConstraintLayout clayout = findViewById(R.id.clayout);
        ImageView im = new ImageView(this);
        im.setImageResource(R.drawable.index1);
        clayout.addView(im);
    }
}
