package com.example.fragmentsexample;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.View;

//Passing data over runtime or switching fragment at runtime
public class MainActivity extends AppCompatActivity {

    FragmentOne fragmentOne;
    FragmentTwo fragmentTwo;
    int showingFragment = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fragmentOne = new FragmentOne();
        fragmentTwo = new FragmentTwo();

        //Remember steps-> 1.FragmentManager,2.Fragment Transaction, 3.Commit
        FragmentManager fragmentManager = getSupportFragmentManager();
        //same fragment manager should be called for transaction
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        fragmentTransaction.add(R.id.clayout,fragmentOne);
        fragmentTransaction.commit();
        showingFragment = 1;
    }

    public void switchFragment(View view) {
        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();

        if(showingFragment == 1)
        {
            fragmentTransaction.replace(R.id.clayout,fragmentTwo);
            showingFragment = 2;
        }
        else {
            fragmentTransaction.replace(R.id.clayout,fragmentOne);
            showingFragment = 1;
        }
        fragmentTransaction.commit();
    }
}
