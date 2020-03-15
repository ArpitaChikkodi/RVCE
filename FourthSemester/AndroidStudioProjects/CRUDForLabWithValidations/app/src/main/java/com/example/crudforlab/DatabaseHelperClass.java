package com.example.crudforlab;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelperClass extends SQLiteOpenHelper
{
    public static final String DATABASE_NAME = "automobile.db";
    public static final String TABLE_NAME = "automobile_table";
    public static final String AUTO_ID = "id";
    public static final String AUTO_NAME = "name";
    public static final String AUTO_YEAR = "year";
    public static final String AUTO_PRICE = "price";

    public DatabaseHelperClass(@Nullable Context context) {
      super(context, TABLE_NAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {

        db.execSQL("create table "+TABLE_NAME+" (id varchar(30) primary key,name text,year text,price text)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS "+TABLE_NAME);
        onCreate(db);
    }

    public boolean insertToDb(String id,String name,String year,String price)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues cv = new ContentValues();
        cv.put(AUTO_ID,id);
        cv.put(AUTO_NAME,name);
        cv.put(AUTO_YEAR,year);
        cv.put(AUTO_PRICE,price);
        long result = db.insert(TABLE_NAME,null,cv);
        if(result == -1)
            return false;
        else
            return true;
    }

    public Cursor getAllData()
    {
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor cursor = db.rawQuery("select * from "+TABLE_NAME,null);
        return cursor;
    }

    public boolean updateThroughId(String id,String name,String year,String price)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor cursor = db.rawQuery("select * from "+TABLE_NAME+" where id = ? ",new String[] {id});
        //System.out.println(cursor.getCount());

        if(cursor.getCount() == 1)
        {
            //System.out.println("fetched!!"); //It prints in LogCat
            cursor.moveToNext();
            //System.out.println("Name "+cursor.getString(1));
            if(cursor.getString(1).equals(name) && cursor.getString(2).equals(year) && cursor.getString(3).equals(price))
                return false;
        }

            ContentValues cv = new ContentValues();
            cv.put(AUTO_ID,id);
            cv.put(AUTO_NAME,name);
            cv.put(AUTO_YEAR,year);
            cv.put(AUTO_PRICE,price);
            int result =  db.update(TABLE_NAME,cv,"id = ? ",new String[] {id});
            if(result<1)
                return false;


        return true;
    }

    public Integer deleteThroughId(String id)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        return db.delete(TABLE_NAME,"id = ?",new String[] {id});
    }


}
