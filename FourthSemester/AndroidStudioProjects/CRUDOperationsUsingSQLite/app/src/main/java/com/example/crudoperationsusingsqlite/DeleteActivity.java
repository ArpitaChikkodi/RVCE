package com.example.crudoperationsusingsqlite;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class DeleteActivity extends AppCompatActivity {

    EditText iddel;
    Button delete;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_delete);

        iddel = (EditText)findViewById(R.id.iddel);
        delete = (Button)findViewById(R.id.deletedel);

        final DatabaseHelper dhelper = new DatabaseHelper(this);

        delete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dhelper.deleteData(Integer.parseInt(iddel.getText().toString()));
            }
        });
    }
}

