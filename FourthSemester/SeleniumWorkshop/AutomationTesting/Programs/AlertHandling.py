#to select xpath manually for class and space use '.' as .btn.btn-default and escape characters ()[]
import os,time
from selenium import webdriver

mypath = os.path.abspath(os.path.dirname(__file__))
path = os.path.join(mypath,"../Drivers/x32/chromedriver.exe")

driver = webdriver.Chrome(path)
driver.maximize_window()
driver.get("https://www.seleniumeasy.com/test/javascript-alert-box-demo.html")
driver.implicitly_wait(5)
clickbtn = driver.find_element_by_css_selector("button[onclick='myAlertFunction\(\)']")
clickbtn.click()
time.sleep(3)

alerti = driver.switch_to.alert

print(alerti.text)
alerti.accept() #to click on ok

#to click on reject/cancel in alertbox
#alerti.dismiss()