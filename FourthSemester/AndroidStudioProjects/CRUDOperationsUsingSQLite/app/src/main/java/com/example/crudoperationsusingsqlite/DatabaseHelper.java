package com.example.crudoperationsusingsqlite;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelper extends SQLiteOpenHelper {

    public static final String databasename = "student_database";
    private static final String key = "id";
    private static final int databaseversion = 1;

    DatabaseHelper(@Nullable Context context) {
        super(context, databasename, null, databaseversion);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table student_database(id integer primary key,name text,year integer)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("Drop table IF EXISTS student_database");
        onCreate(db);
    }

    public Cursor readData(int idvalue) {
        SQLiteDatabase db = this.getReadableDatabase();
        // use execSQL for CREATE, INSERT, UPDATE, DELETE SQL Operations. Execute a sql SELECT query using rawQuery which returns Cursor as a result-set .
        Cursor res = db.rawQuery("Select * from student_database where id=" + idvalue + "", null);
        res.moveToFirst();
        //String data = res.getString(2);
        return res;
    }

    public Cursor getAllData()
    {
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor res = db.rawQuery("Select * from "+databasename,null);
        return res;
    }

    public boolean insertData(Integer id, String name, Integer year) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put("id", id);
        contentValues.put("name", name);
        contentValues.put("year", year);

        long res = db.insert(databasename, null, contentValues);

        if(res==-1)
            return false;
        else
            return true;

    }

    public Integer deleteData(Integer id) {
        SQLiteDatabase db = this.getWritableDatabase();
        return db.delete(databasename, "id = ? ", new String[]{Integer.toString(id)});
    }

    public boolean updateData(Integer id, String name) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put("name", name);

        db.update(databasename, contentValues,  "id = ?",
                new String[]{String.valueOf(id)});
        return true;

    }
}