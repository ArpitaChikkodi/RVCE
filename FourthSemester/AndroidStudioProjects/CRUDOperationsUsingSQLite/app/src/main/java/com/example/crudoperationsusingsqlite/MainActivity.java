package com.example.crudoperationsusingsqlite;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
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

       /* read.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, ReadActivity.class);
                startActivity(i);
            }
        });

        */

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

        read.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Cursor cursor = dhelper.getAllData();
                if(cursor.getCount() == 0){
                    showMessage("Error", "No record found!");
                    Toast.makeText(MainActivity.this,"No data available!",Toast.LENGTH_LONG).show();
                    return;
                }else {
                    StringBuffer stringBuffer = new StringBuffer();
                    while (cursor.moveToNext()){
                        stringBuffer.append("ID : " + cursor.getString(0)+"\n");
                        stringBuffer.append("Name : " + cursor.getString(1)+"\n");
                        stringBuffer.append("Year : " + cursor.getString(2)+"\n\n");

                    }
                    showMessage("Details : ",stringBuffer.toString());
                }
            }
        });

        email.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View arg0) {
                String to="apschikkodi14@gmail.com";
                String subject="Sending email from Android App";
                Integer id = Integer.parseInt(Eid.getText().toString());
                String name = Ename.getText().toString();
                Integer year = Integer.parseInt(Eyear.getText().toString());
                String message="\nID : "+id+"\nName : "+name+"\nYear : "+year;


                Intent email = new Intent(Intent.ACTION_SEND);
                email.putExtra(Intent.EXTRA_EMAIL, new String[]{ to});
                email.putExtra(Intent.EXTRA_SUBJECT, subject);
                email.putExtra(Intent.EXTRA_TEXT, message);

                //need this to prompts email client only
                email.setType("message/rfc822");

                startActivity(Intent.createChooser(email, "Choose an Email client :"));

            }

        });

    }


    private void createToast(String msg) {
        Toast.makeText(MainActivity.this,msg,'7').show();
    }

    public void showMessage(String title, String message){
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setMessage(message);
        builder.show();
    }


}
