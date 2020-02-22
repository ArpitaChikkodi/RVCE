#Count number of radio buttons
import os
from selenium import webdriver
mypath = os.path.abspath(os.path.dirname(__file__))
path = os.path.join(mypath,"../Drivers/x64/geckodriver.exe")
driver = webdriver.Firefox(executable_path=path)
driver.get("https://www.facebook.com")

#findelementsbycssselector ===>> for a group of elements here radio buttons
radio = driver.find_elements_by_css_selector("input[name = 'sex']")
count=0
for i in radio:
    count += 1
print("The count of Radio Buttons = ",count)
driver.quit()