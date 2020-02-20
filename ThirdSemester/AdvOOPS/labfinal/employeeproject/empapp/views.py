from django.shortcuts import render, redirect
from empapp.models import Employee
from empapp.forms import CreateEmployee
from django.http import HttpResponse
from django.views.generic import TemplateView


# Create your views here.
class HomePage(TemplateView):
    template_name = 'index.html'


def upload(request):
    uploadform = CreateEmployee()
    if request.method == 'POST':
        uploadform = CreateEmployee(request.POST, request.FILES)
        if uploadform.is_valid():
            uploadform.save()
            return redirect('index')
        else:
            return HttpResponse('Invalid!')
    else:
        return render(request, 'insert.html', {'uploadform': uploadform})


def display(request):
    shelf = Employee.objects.all()
    return render(request, 'display.html', {'shelf': shelf})
