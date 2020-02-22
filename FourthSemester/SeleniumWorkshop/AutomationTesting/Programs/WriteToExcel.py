import os,time,xlwt,xlrd
from selenium import webdriver
from xlutils.copy import copy
mypath = os.path.abspath(os.path.dirname(__file__))
timestr = time.strftime("%Y%m%d-%H%M%S")
path = os.path.join(mypath,"../Drivers/x32/chromedriver.exe")

excelpath = os.path.join(mypath,"../TestData/WriteData.xls")

screenShot = os.path.join(mypath,"../ScreenPrint/")
driver = webdriver.Chrome(path)
driver.maximize_window()
driver.get("https://www.google.com/")


searchBox = driver.find_element_by_xpath("//input[@role='combobox']")
searchBox.send_keys("Selenium easy demo website")
time.sleep(3)

driver.save_screenshot(screenShot+"GooglePage_"+timestr+".png")

driver.find_element_by_id("lga") #click somewhere else
magnifyingGlass = driver.find_element_by_css_selector("input[type='submit']")
magnifyingGlass.click()  #click

firstResult = driver.find_element_by_css_selector("#rso > div:nth-child(2) > div > div:nth-child(2) > div > div > div.r > a> h3")
value = firstResult.text #to fetch data from a webelement

'''
--------------------TO WRITE TO EXCEL-------------------------
workbook = xlwt.Workbook()
worksheet = workbook.add_sheet(("Sheet 1"))
worksheet.write(0,0,value) #if the file is open it will not work and if file consists of some data it will be overwritten
workbook.save(excelpath)'''

#-----------------TO UPDATE/APPEND TO EXISTING EXCEL---------------

wb = copy(xlrd.open_workbook(excelpath))
wb.get_sheet(0).write(3,3,value)
wb.save(excelpath)