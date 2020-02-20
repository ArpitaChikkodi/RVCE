from django import forms
from empapp.models import Employee
class CreateEmployee(forms.ModelForm):
    class Meta:
        model = Employee
        fields = '__all__'
