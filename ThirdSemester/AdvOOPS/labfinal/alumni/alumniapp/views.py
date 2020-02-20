from django.shortcuts import render
from django.views.generic import TemplateView

# Create your views here.
class IndexPage(TemplateView):
    def get(self,request,**kwargs):
        return render(request,'index.html',context = None)

class DisplayPage(TemplateView):
    def get(self,request,**kwargs):
        usn = request.GET['usn']
        name = request.GET['name']
        address = request.GET['address']
        d = {'name' : name,'usn' : usn,'address' : address,}
        return render(request,'display.html',d)