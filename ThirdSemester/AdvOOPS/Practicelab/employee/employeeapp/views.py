from django.shortcuts import render,redirect
from employeeapp.models import Employee
from employeeapp.forms import EmployeeCreate
from django.views.generic import TemplateView
from django.http import HttpResponse
# Create your views here.

class HomePage(TemplateView):
    template_name = 'index.html'

def upload(request):
    upload = EmployeeCreate()
    if request.method == 'POST':
        upload = EmployeeCreate(request.POST,request.FILES)
        if upload.is_valid():
            upload.save()
            return redirect('index')
        else:
            return HttpResponse("Invalid!")
    else:
        return render(request,'insert.html',{'upload':upload})

def display(request):
    shelf = Employee.objects.all()
    return render(request,'display.html',{'shelf':shelf})