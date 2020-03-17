import os
import time
import unittest
from selenium import webdriver

# path of the webdriver
driverpath = "../drivers/x32/chromedriver.exe"


class LoginPageTest(unittest.TestCase):
    def setUp(self):
        self.driver = webdriver.Chrome(driverpath)
        self.driver.maximize_window()
        time.sleep(5)

    def login_test_fun1(self):
        # give path of the file/page to be tested
        #self.driver.get("../testingfiles/loginPage.html")
        self.driver.get("http://localhost:63342/AutomationTestingForLab/testingfiles/loginPage.html")

        # copy xpath of the webelement and paste it here in single quotes
        userid = self.driver.find_element_by_xpath('//*[@id="User"]')
        userpassword = self.driver.find_element_by_xpath('//*[@id="Pass"]')
        time.sleep(5)

        # send_keys() is used to pass value to the page
        userid.send_keys('admin')
        userpassword.send_keys('root123')

        loginbutton = self.driver.find_element_by_xpath('//*[@id="btn"]')
        loginbutton.click()
        time.sleep(2)
        print("You have entered valid Email and Password")
        alertbox = self.driver.switch_to.alert
        print(alertbox.text)
        alertbox.accept()
        time.sleep(5)

    def tearDown(self):
        self.driver.quit()


if __name__ == "__main__":
    unittest.main()
