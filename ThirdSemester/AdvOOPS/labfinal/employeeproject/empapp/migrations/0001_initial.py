# Generated by Django 2.2.7 on 2019-12-30 10:11

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Employee',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('empid', models.CharField(max_length=10)),
                ('name', models.CharField(max_length=30)),
                ('address', models.CharField(max_length=50)),
            ],
        ),
    ]
