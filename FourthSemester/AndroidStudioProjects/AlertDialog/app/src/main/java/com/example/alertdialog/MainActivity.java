package com.example.alertdialog;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
//import androidx.appcompat.app.AlertDialog; //-->not compatible for this api
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Button btnAlert;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnAlert = findViewById(R.id.btnAlert);

        btnAlert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //select android for api less than Marshmellow otherwise select androidx for AlertDialog
                AlertDialog alertDialog = new AlertDialog.Builder(MainActivity.this).create();
             //   AlertDialog.Builder alertDialog = new AlertDialog.Builder(MainActivity.this);
                alertDialog.setTitle("Alert Dialog");
                alertDialog.setMessage("Custom alert dialog window");
                alertDialog.setIcon(R.drawable.image);
               alertDialog.setButton("Ok", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Toast.makeText(MainActivity.this,"Clicked on ok",'7').show();
                    }
                });

                //setButton2 for two buttons
               alertDialog.setButton2("Cancel", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Toast.makeText(MainActivity.this, "Clicked on cancel", Toast.LENGTH_SHORT).show();
                    }
                });

              /*  alertDialog.setPositiveButton("ok", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Toast.makeText(MainActivity.this,"Clicked on ok",'7').show();
                    }
                });

                alertDialog.setNegativeButton("cancel", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Toast.makeText(MainActivity.this,"Clicked on cancel",'7').show();
                    }
                });
*/
                alertDialog.show();
            }
        });
    }
}
