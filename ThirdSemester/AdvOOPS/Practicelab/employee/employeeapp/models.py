from django.db import models

# Create your models here.
class Employee(models.Model):
    ename = models.CharField(max_length = 30)
    empid = models.CharField(max_length=20)
    address = models.CharField(max_length=30)
