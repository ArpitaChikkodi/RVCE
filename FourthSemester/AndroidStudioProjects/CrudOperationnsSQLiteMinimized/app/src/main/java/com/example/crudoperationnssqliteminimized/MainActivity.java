package com.example.crudoperationnssqliteminimized;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    DatabaseHelperClass databaseHelperClass;
    EditText id,name,year;
    Button createTbl,addData,updateData,deleteData,viewData;
    ImageButton emailData;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        databaseHelperClass = new DatabaseHelperClass(this);
        id = findViewById(R.id.editId);
        name = findViewById(R.id.editName);
        year = findViewById(R.id.editYear);

        //createTbl = findViewById(R.id.btnCreate);
        addData = findViewById(R.id.btnAdd);
        viewData = findViewById(R.id.btnView);
        updateData = findViewById(R.id.btnUpdate);
        deleteData = findViewById(R.id.btnDelete);
        emailData = findViewById(R.id.btnMail);


        AddData();
        UpdateData();
        ViewAll();
        DeleteData();
        SendToMail();
//        createTable();
    }

//    public void createTable(){
//        createTbl.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                boolean isCreated = databaseHelperClass.onCreate();
//            }
//        });
//    }


    public void AddData(){
        addData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                boolean isInserted = databaseHelperClass.insertData(id.getText().toString(), name.getText().toString(), year.getText().toString());
                if (isInserted == true) {
                    Toast.makeText(MainActivity.this,"Data Inserted !!!",Toast.LENGTH_LONG).show();
                }else {
                    Toast.makeText(MainActivity.this,"Data not Inserted !!!",Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    public void UpdateData(){
        updateData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                boolean isUpdated = databaseHelperClass.updateDataThroughId(id.getText().toString(),name.getText().toString(),year.getText().toString());

                if(isUpdated == true){
                    Toast.makeText(MainActivity.this,"Data Updated !!!",Toast.LENGTH_LONG).show();
                }else {
                    Toast.makeText(MainActivity.this,"Data not updated !!!",Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    public void DeleteData(){
        deleteData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Integer deletedRows = databaseHelperClass.deleteDataThroughId(id.getText().toString());
                if( deletedRows > 0){
                    Toast.makeText(MainActivity.this,"Data deleted !!!",Toast.LENGTH_LONG).show();
                }else {
                    Toast.makeText(MainActivity.this,"Data not deleted !!!",Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    public void ViewAll(){
        viewData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Cursor cursor = databaseHelperClass.getAllData();
                if(cursor.getCount() == 0){
                    showMessage("Error", "No record found ");
                    Toast.makeText(MainActivity.this,"Data not available !!!",Toast.LENGTH_LONG).show();
                    return;
                }else {
                    StringBuffer stringBuffer = new StringBuffer();
                    while (cursor.moveToNext()){
                        stringBuffer.append("ID : " + cursor.getString(0)+"\n");
                        stringBuffer.append("NAME : " + cursor.getString(1)+"\n");
                        stringBuffer.append("YEAR : " + cursor.getString(2)+"\n\n");

                    }
                    showMessage("DATA : ",stringBuffer.toString());
                }
            }
        });
    }

    public void showMessage(String title, String message){
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setMessage(message);
        builder.show();
    }

    public void SendToMail(){
        emailData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String sid = id.getText().toString();
                String nm = name.getText().toString();
                String syear = year.getText().toString();
                Intent intentMail = new Intent(Intent.ACTION_SEND);
                intentMail.putExtra(Intent.EXTRA_EMAIL, new String[]{"apschikkodi@gmail.com"});
                intentMail.putExtra(Intent.EXTRA_SUBJECT, "Sending mail from Android App");
                intentMail.putExtra(Intent.EXTRA_TEXT,"Id : " + sid +"\nNAME : " + nm + "\nYear : " + syear);
                intentMail.setType("message/rfc822");

                startActivity(Intent.createChooser(intentMail,"Choose Mail App"));
            }
        });
    }
}
