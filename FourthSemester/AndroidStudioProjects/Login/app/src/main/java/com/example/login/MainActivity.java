package com.example.login;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Intent;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Button signin,cancel;
    EditText username,password;
    int count=0;
    //ConstraintLayout constraintLayout = new ConstraintLayout(R.id.clayout);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        signin = (Button)findViewById(R.id.signin);
        cancel = (Button)findViewById(R.id.cancel);

        username = (EditText)findViewById(R.id.username);
        password = (EditText)findViewById(R.id.password);

        signin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(username.getText().toString().equals("abc") && password.getText().toString().equals("123")){
                    Toast.makeText(getApplicationContext(),"Login Valid",Toast.LENGTH_SHORT).show();

                    Intent intent = new Intent(MainActivity.this,MainActivity2.class);
                            startActivity(intent);
                }
                else
                {
                    count++;
                    Toast.makeText(getApplicationContext(),"Invalid credentials",'2').show(); //2seconds
                    if(count==3)
                    {
                        signin.setEnabled(false);
                        Toast.makeText(getApplicationContext(),"SignIn button has been blocked for 10 seconds",Toast.LENGTH_LONG).show();

                        new CountDownTimer(10000, 100) {
                            @Override
                            public void onTick(long millisUntilFinished) {

                            }

                            @Override
                            public void onFinish() {
                                    signin.setEnabled(true);
                                    count = 0;
                            }
                        }.start();


                    }
                }
            }
        });

        cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

    }
}
