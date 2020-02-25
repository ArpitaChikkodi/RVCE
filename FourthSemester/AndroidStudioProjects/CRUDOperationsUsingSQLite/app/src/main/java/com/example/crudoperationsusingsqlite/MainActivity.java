package com.example.crudoperationsusingsqlite;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    EditText Eid,Ename,Eyear;
    Button add,read,delete,update,email;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Eid = (EditText)findViewById(R.id.editId);
        Ename = (EditText)findViewById(R.id.editName);
        Eyear = (EditText)findViewById(R.id.editYear);

        add = (Button)findViewById(R.id.add);
        read = (Button)findViewById(R.id.read);
        update = (Button)findViewById(R.id.update);
        delete = (Button)findViewById(R.id.delete);
        email = (Button)findViewById(R.id.email);


        final DatabaseHelper dhelper = new DatabaseHelper(this);
        add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Integer id = Integer.parseInt(Eid.getText().toString());
                    String name = Ename.getText().toString();
                    Integer year = Integer.parseInt(Eyear.getText().toString());

                    if (dhelper.insertData(id, name, year)) {
                        String msg = "Inserted data successfully!";
                        createToast(msg);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        read.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, ReadActivity.class);
                startActivity(i);
            }
        });

        delete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, DeleteActivity.class);
                startActivity(i);
            }
        });


        update.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, UpdateActivity.class);
                startActivity(i);
            }
        });

    }


    private void createToast(String msg) {
        Toast.makeText(MainActivity.this,msg,'7').show();
    }
}
