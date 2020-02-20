package com.example.canvasapp;


import android.graphics.Paint;
import android.graphics.Path;

public class PathWithPaint {
    private Path path;
    private Paint mpaint;

    public Path getPath()
    {
        return path;
    }
    public void setPath(Path path)
    {
        this.path = path;
    }

    public Paint getmPaint()
    {
        return mpaint;
    }

    public void setmPaint(Paint paint)
    {
        this.mpaint = mpaint;
    }

}
