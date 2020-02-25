package com.example.crudoperationsusingsqlite;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class UpdateActivity extends AppCompatActivity {

    EditText id,name;
    Button update;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_update);

        final DatabaseHelper dhelper=new DatabaseHelper(this);

         id=(EditText)findViewById(R.id.idupdate);
         name=(EditText)findViewById(R.id.nameupdate);
        update=(Button)findViewById(R.id.updateup);

        update.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Boolean result=dhelper.updateData(Integer.parseInt(id.getText().toString()),name.getText().toString());
                if(result)
                {
                    Toast.makeText(getApplicationContext(),"Updated Successfully!",Toast.LENGTH_LONG).show();
                }
            }
        });


    }
}
