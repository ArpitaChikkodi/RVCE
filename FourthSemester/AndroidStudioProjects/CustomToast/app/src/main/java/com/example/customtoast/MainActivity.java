package com.example.customtoast;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;


//call a part of different activity in this activity
//giving layout id for second layout in the xml it is different from xml file
//calling an element from different layour with layout object.findViewById
public class MainActivity extends AppCompatActivity {

    Button customToast;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        customToast = (Button)findViewById(R.id.customToast);
        customToast.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                LayoutInflater inflater = getLayoutInflater();
                View layout = inflater.inflate(R.layout.custom_toast_layout,(ViewGroup)findViewById(R.id.toastlayout));
                ImageView customimageview = layout.findViewById(R.id.customimageView);
                customimageview.setImageResource(R.drawable.ic_launcher_foreground);
                Toast toast = new Toast(getApplicationContext());
                toast.setDuration('5');
                toast.setView(layout); //setView before calling show()**
                toast.show();
            }
        });

    }
}
