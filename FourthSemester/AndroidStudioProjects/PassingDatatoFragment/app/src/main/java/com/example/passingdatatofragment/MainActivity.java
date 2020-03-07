package com.example.passingdatatofragment;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    FragmentOne fragment1;
    FragmentTwo fragment2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fragment1 = new FragmentOne();
        Bundle bundle = new Bundle();
        bundle.putInt("a", 1);
        fragment1.setArguments(bundle);



    }
}
