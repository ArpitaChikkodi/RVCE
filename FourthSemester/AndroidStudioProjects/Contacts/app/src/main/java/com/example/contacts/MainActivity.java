package com.example.contacts;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentResolver;
import android.database.Cursor;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;

//API 11 contacrs was introduced
//Permissions is given in manifest before/after application tag
//After installing first go to settings and give permission to access contacts then only it will work

public class MainActivity extends AppCompatActivity {

    ArrayList<String> alist = new ArrayList<>();
    ListView lv;
    /** Called when the activity is first created*/

    //try to sort in alphabetical order,add email
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ContentResolver cr = getContentResolver();
        Cursor cur = cr.query(ContactsContract.Contacts.CONTENT_URI,
                null,null,null,null);
        if(cur.getCount()>0)
        {
            while (cur.moveToNext())
            {
                String id = cur.getString(cur.getColumnIndex(ContactsContract.Contacts._ID));
                String name = cur.getString(cur.getColumnIndex(ContactsContract.Contacts.DISPLAY_NAME));

                if(Integer.parseInt(cur.getString(cur.getColumnIndex(ContactsContract.Contacts.HAS_PHONE_NUMBER)))>0)
                {
                    Cursor pcur = cr.query(ContactsContract.CommonDataKinds.Phone.CONTENT_URI,null,
                            ContactsContract.CommonDataKinds.Phone.CONTACT_ID +" =?",
                            new String[]{id},null);

                    while (pcur.moveToNext())
                    {
                        String phoneNo = pcur.getString(pcur.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER));

                        alist.add("Name: "+name+"\nPhone No : "+phoneNo);
                    }
                    pcur.close();
                }
            }
        }

        lv = (ListView)findViewById(R.id.listview1);
        ArrayAdapter<String> adt = new ArrayAdapter<>(this,android.R.layout.simple_list_item_1,alist);
        lv.setAdapter(adt);
    }
}