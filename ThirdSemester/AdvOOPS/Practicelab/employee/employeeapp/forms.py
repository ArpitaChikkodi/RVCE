from employeeapp.models import Employee
from django import forms

class EmployeeCreate(forms.ModelForm):
    class Meta:
        model = Employee
        fields = '__all__'