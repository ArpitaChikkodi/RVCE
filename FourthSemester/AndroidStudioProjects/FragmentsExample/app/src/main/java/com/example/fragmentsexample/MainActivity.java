package com.example.fragmentsexample;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

//Passing data over runtime or switching fragment at runtime
public class MainActivity extends AppCompatActivity {

    FragmentOne fragmentOne;
    FragmentTwo fragmentTwo;
    int showingFragment = 0;
    Bundle bundle;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fragmentOne = new FragmentOne();
         bundle = new Bundle();
        bundle.putString("abc","123");
        fragmentOne.setArguments(bundle);
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
            Bundle bundle2 = new Bundle();
            bundle2 = fragmentTwo.getArguments();

            if (bundle2 != null && bundle2.containsKey("abc")) {
                String str = (bundle2.getString("abc"));

                Toast.makeText(this, str, '7').show();
            }
        }
        else {
            fragmentTransaction.replace(R.id.clayout,fragmentOne);
            showingFragment = 1;
        }
        fragmentTransaction.commit();
    }
}
