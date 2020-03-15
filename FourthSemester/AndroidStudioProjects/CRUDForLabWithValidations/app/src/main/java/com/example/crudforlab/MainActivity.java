package com.example.crudforlab;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.media.Image;
import android.os.Bundle;
import android.text.InputType;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    DatabaseHelperClass dhelper;
    EditText id,name,year,price;
    Button addbtn,readbtn,deletebtn,updatebtn,clearbtn;
    ImageButton emailbtn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        dhelper = new DatabaseHelperClass(this);
        id = findViewById(R.id.editId);
        id.setInputType(InputType.TYPE_CLASS_NUMBER);
        id.requestFocus();

        name = findViewById(R.id.editName);
        year = findViewById(R.id.editYear);
        year.setInputType(InputType.TYPE_CLASS_NUMBER);
        //year.setMaxLines(1);

        price = (EditText) findViewById(R.id.editPrice);
        price.setInputType(InputType.TYPE_CLASS_NUMBER);

        addbtn = (Button)findViewById(R.id.btnadd);
        deletebtn = (Button)findViewById(R.id.btndelete);
        readbtn = (Button)findViewById(R.id.btnread);
        updatebtn = (Button)findViewById(R.id.btnupdate);
        clearbtn = (Button)findViewById(R.id.btnclear);

        emailbtn = (ImageButton)findViewById(R.id.btnemail);

        addData();
        viewData();
        updateData();
        deleteData();
        sendEmail();
        clearData();
    }

    public void addData()
    {
        addbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String sid = id.getText().toString();
                String sname = name.getText().toString();
                String syear = year.getText().toString();
                String sprice = price.getText().toString();
                if (sid != "" && sname != "" && syear != "" && sprice != "") {
//                    if(syear.length()!=4)
//                        Toast.makeText, Toast.LENGTH_SHORT).show();
                    boolean isInserted = dhelper.insertToDb(sid,sname,syear,sprice);
                    if (isInserted == true)
                        Toast.makeText(MainActivity.this, "Data inserted!!", Toast.LENGTH_SHORT).show();
                    else
                        Toast.makeText(MainActivity.this, "Data not inserted!!", Toast.LENGTH_SHORT).show();
                }
            }

        });
    }

    public void viewData()
    {
        readbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Cursor cursor = dhelper.getAllData();
                if(cursor.getCount() == 0)
                {
                    showMessage("Error","There are no entries!");
                    Toast.makeText(MainActivity.this, "Data not available!!", Toast.LENGTH_SHORT).show();
                    return;
                }
                else
                {
                    StringBuffer sb = new StringBuffer();
                    while (cursor.moveToNext())
                    {
                        sb.append(cursor.getString(0)+"\n");
                        sb.append(cursor.getString(1)+"\n");
                        sb.append(cursor.getString(2)+"\n");
                        sb.append(cursor.getString(3)+"\n\n");
                    }
                    showMessage("Details",sb.toString());
                }
            }
        });
    }

    public void showMessage(String title,String message)
    {
        AlertDialog.Builder ad = new AlertDialog.Builder(this);
        ad.setCancelable(true);
        ad.setTitle(title);
        ad.setMessage(message);
        ad.show();
    }

    public void updateData()
    {
        updatebtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                boolean isupdated = dhelper.updateThroughId(id.getText().toString(),name.getText().toString(),year.getText().toString(),price.getText().toString());
                if(isupdated==true)
                    Toast.makeText(MainActivity.this, "Data updated!!", Toast.LENGTH_SHORT).show();
                else
                    Toast.makeText(MainActivity.this, "Data not updated! Please enter proper data!", Toast.LENGTH_SHORT).show();
            }
        });
    }

    public void deleteData()
    {
        deletebtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int deletedrows = dhelper.deleteThroughId(id.getText().toString());
                if(deletedrows > 0)
                    Toast.makeText(MainActivity.this, "Data deleted!!", Toast.LENGTH_SHORT).show();
                else
                    Toast.makeText(MainActivity.this, "Data not deleted!!", Toast.LENGTH_SHORT).show();
            }
        });
    }

    public void sendEmail()
    {
        emailbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String sid = id.getText().toString();
                String sname = name.getText().toString();
                String syear = year.getText().toString();
                String sprice = price.getText().toString();

                Intent intentmail = new Intent(Intent.ACTION_SEND);
                intentmail.putExtra(Intent.EXTRA_EMAIL,new String[] {"apschikkodi14@gmail.com"});
                intentmail.putExtra(Intent.EXTRA_SUBJECT,"Sending from Android App");
                intentmail.putExtra(Intent.EXTRA_TEXT,"\nID : "+sid+"\nName : "+sname+"\nYear : "+syear+"\nPrice : "+sprice);

                intentmail.setType("message/rfc822");

                startActivity(Intent.createChooser(intentmail,"Choose the app"));
            }
        });
    }

    public void clearData()
    {
        clearbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                id.setText("");
                name.setText("");
                year.setText("");
                price.setText("");

            }
        });

    }
}
