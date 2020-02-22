import os,time
from selenium import webdriver

#to avoid png from overriding on every run
timestr = time.strftime("%Y%m%d-%H%M%S")

mypath = os.path.abspath(os.path.dirname(__file__))
path = os.path.join(mypath,"../Drivers/x32/chromedriver.exe")

#to take screenshot, create a directory ScreenPrint
 #or give it directly in save_screenshot
screenShot = os.path.join(mypath,"../ScreenPrint/")
driver = webdriver.Chrome(path)
driver.maximize_window() #to maximize
driver.get("https://www.google.com/")

#tagname[attribute=], attributes may be role,title
#searchBox = driver.find_element_by_css_selector("input[title='Search']")

searchBox = driver.find_element_by_xpath("//input[@role='combobox']")
searchBox.send_keys("Selenium easy demo website") #type selenium easy in input box
time.sleep(3) #stop execution for 3 seconds

#driver.save_screenshot(screenShot+"GooglePage.png")

driver.save_screenshot(screenShot+"GooglePage_"+timestr+".png")

driver.find_element_by_id("lga") #click somewhere else
magnifyingGlass = driver.find_element_by_css_selector("input[type='submit']")
magnifyingGlass.click()  #click

#magnifyingGlass.submit()
#how to go inside link after search
firstResult = driver.find_element_by_css_selector("#rso > div:nth-child(2) > div > div:nth-child(2) > div > div > div.r > a> h3")
time.sleep(3)
firstResult.click()