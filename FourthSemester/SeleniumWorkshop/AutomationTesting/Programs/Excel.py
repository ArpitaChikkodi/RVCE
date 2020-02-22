import os,time
from selenium import webdriver
import xlrd
timestr = time.strftime("%Y%m%d-%H%M%S")

mypath = os.path.abspath(os.path.dirname(__file__))
screenShot = os.path.join(mypath,"../ScreenPrint/")

driverpath = os.path.join(mypath,"../Drivers/x32/chromedriver.exe")
path = os.path.join(mypath,"../TestData/TestData.xls")

driver = webdriver.Chrome(driverpath)
driver.maximize_window()
time.sleep(3)
driver.get("https://www.facebook.com")
time.sleep(3)

email = driver.find_element_by_id("email")
password = driver.find_element_by_id("pass")
loginbtn = driver.find_element_by_css_selector("input[type='submit']")

book = xlrd.open_workbook(path) #opening xls file
worksheet = book.sheet_by_index(0) #for xls sheets start from 0 for xlsx it starts from 1

username = worksheet.cell_value(1,0) #1st row 0th column
pwd = worksheet.cell_value(1,1) #1st row 1st column

#set the values fetched to our variables on website through sendkeys
email.send_keys(username)
password.send_keys(str(pwd))
time.sleep(3)
driver.save_screenshot(screenShot+"FacebookPage_"+timestr+".png")
time.sleep(3)
loginbtn.click()