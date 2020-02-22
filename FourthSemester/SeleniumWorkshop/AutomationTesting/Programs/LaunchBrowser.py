#to give relative path with ./ or through os.path
import os
from selenium import webdriver
#give absolute path with \\  of chromedriver.exe or
#driver = webdriver.Chrome("D:\\RVCELab\\SeleniumWorkshop\\AutomationTesting\\Drivers\\x32\\chromedriver.exe")

#Relative path
mypath = os.path.abspath(os.path.dirname(__file__))


#path = os.path.join(mypath,"../Drivers/x32/chromedriver.exe")
#driver = webdriver.Chrome(path)


#for firefox we need to register path everytime so it is executable_path
path = os.path.join(mypath,"../Drivers/x64/geckodriver.exe")
driver = webdriver.Firefox(executable_path=path)


#for IEDriver(here not downloaded)
#path = os.path.join(mypath,"../Drivers/x64/IEDriverServer.exe")
#driver = webdriver.Ie(path)

#same link for all
driver.get("https://www.seleniumeasy.com/")