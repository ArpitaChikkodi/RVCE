package com.example.fragmentsexample;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;

public class FragmentTwo extends Fragment {

    TextView tv;
    public View onCreateView(LayoutInflater layoutInflater, ViewGroup container, Bundle savedInstanceState)
    {

        return layoutInflater.inflate(R.layout.activity_fragment_two,container,false);
    }

}
