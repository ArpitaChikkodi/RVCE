package com.example.fragmentexample;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import java.util.zip.Inflater;

public class FragmentOne extends Fragment {


    public View onCreateView(LayoutInflater inflater, ViewGroup container,Bundle savedInstanceState)
   {
        return inflater.inflate(R.layout.fragment_one,container,false);
   }
}
