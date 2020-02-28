package com.example.crudoperationnssqliteminimized;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

import androidx.annotation.Nullable;

public class DatabaseHelperClass extends SQLiteOpenHelper {
    public static final String DATABASE_NAME = "automobile.db";
    public static final String TABLE_NAME = "automobile_table";
    public static final String AUTO_ID = "id";
    public static final String AUTO_NAME = "name";
    public static final String AUTO_YEAR = "year";

    public DatabaseHelperClass(@Nullable Context context) {
        super(context, DATABASE_NAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL("create table " + TABLE_NAME + " (id varchar(30) primary key, name text, year text) ");
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int oldVersion, int newVersion) {
        sqLiteDatabase.execSQL("DROP TABLE IF EXISTS " + TABLE_NAME);
        onCreate(sqLiteDatabase);
    }

    public boolean insertData(String id, String name, String year ){
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(AUTO_ID,id);
        contentValues.put(AUTO_NAME,name);
        contentValues.put(AUTO_YEAR,year);
        long result = sqLiteDatabase.insert(TABLE_NAME,null,contentValues);
        if(result == -1){
            return false;
        }else {
            return true;
        }
    }

    public Cursor getAllData(){
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        Cursor cursor = sqLiteDatabase.rawQuery("SELECT * FROM " + TABLE_NAME,null);
        return cursor;
    }

    public boolean updateDataThroughId(String id, String name, String year){
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(AUTO_ID,id);
        contentValues.put(AUTO_NAME,name);
        contentValues.put(AUTO_YEAR,year);
        sqLiteDatabase.update(TABLE_NAME,contentValues, " id = ? ", new String[] { id });
            return true;
    }

    public Integer deleteDataThroughId(String id){
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        return sqLiteDatabase.delete(TABLE_NAME,"id = ? ",new String[] { id });
    }
}