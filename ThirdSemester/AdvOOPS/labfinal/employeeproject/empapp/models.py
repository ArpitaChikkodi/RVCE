from django.db import models

# Create your models here.
class Employee(models.Model):
    empid = models.CharField(max_length=10)
    name = models.CharField(max_length=30)
    address = models.CharField(max_length=50)

    def __str__(self):
        return self