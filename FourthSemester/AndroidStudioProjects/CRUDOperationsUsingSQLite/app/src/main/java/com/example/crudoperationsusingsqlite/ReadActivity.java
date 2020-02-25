package com.example.crudoperationsusingsqlite;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.database.SQLException;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class ReadActivity extends AppCompatActivity {

    EditText idval;
    Button fetch,clear;
    TextView result;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_read);

        idval = (EditText)findViewById(R.id.getid1);

        fetch = (Button)findViewById(R.id.fetch);

        clear = (Button)findViewById(R.id.clear);

        result=(TextView) findViewById(R.id.result);

        final DatabaseHelper dhelper = new DatabaseHelper(this);

        fetch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try
                {
                Integer id = Integer.parseInt(idval.getText().toString());
                Cursor res = dhelper.readData(id);
                //result.setText(res);
                res.moveToFirst();
                result.setText("\t      Details\nId : "+res.getString(res.getColumnIndex("id"))+"\nName : "+res.getString(res.getColumnIndex("name"))+"\nYear : "+res.getString(res.getColumnIndex("year")));


                //result.setText(result);
            }
                catch(SQLException e) {
                    e.printStackTrace();
                }

                }
        });

        clear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                idval.setText("");
                result.setText("");
            }
        });
    }
}
