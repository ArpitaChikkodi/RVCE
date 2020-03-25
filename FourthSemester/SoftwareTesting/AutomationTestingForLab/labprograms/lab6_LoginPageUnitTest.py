import os
import time
import unittest
from selenium import webdriver

class LoginClass(unittest.TestCase):

    def setUp(self):
        self.driver = webdriver.Chrome('../drivers/x32/chromedriver.exe')
        time.sleep(2)
        self.driver.maximize_window()

    # This method will test for valid username and valid password
    def test_chrome_fn(self):
        self.driver.get("https://gnsaddy.github.io/webAutomationSelenium/")
        email = self.driver.find_element_by_xpath('//*[@id="inputEmail"]')
        password = self.driver.find_element_by_xpath('//*[@id="inputPassword"]')

        email.send_keys("aditya@gmail.com")  # sending valid username
        password.send_keys("testing")  # sending valid password

        submitbtn = self.driver.find_element_by_xpath('//*[@id="btnLogin"]')
        submitbtn.click()
        time.sleep(5)
        print("Testing Valid Email and Password")
        alertJS = self.driver.switch_to.alert
        print(alertJS.text)
        alertJS.accept()

        timer1 = time.strftime("%Y%m%d = %H%M%S")
        picture = "Images"

        self.driver.save_screenshot("../screenShots/" + picture + timer1 + ".png")
        time.sleep(5)

    # This method will test for invalid username and valid password
    def test_chrome_fn1(self):
        self.driver.get("https://gnsaddy.github.io/webAutomationSelenium/")
        email = self.driver.find_element_by_xpath('//*[@id="inputEmail"]')
        password = self.driver.find_element_by_xpath('//*[@id="inputPassword"]')

        email.send_keys("abc@gmail.com")  # sending invalid username
        password.send_keys("testing")  # sending valid password

        submitbtn = self.driver.find_element_by_xpath('//*[@id="btnLogin"]')
        submitbtn.click()
        time.sleep(5)
        print("Testing Invalid Email with valid Password")
        alertJS = self.driver.switch_to.alert
        print(alertJS.text)
        alertJS.accept()

        timer1 = time.strftime("%Y%m%d = %H%M%S")
        picture = "Images"

        self.driver.save_screenshot("../screenShots/" + picture + timer1 + ".png")
        time.sleep(5)

    # This method will test for valid username and invalid password
    def test_chrome_fn2(self):
        self.driver.get("https://gnsaddy.github.io/webAutomationSelenium/")
        email = self.driver.find_element_by_xpath('//*[@id="inputEmail"]')
        password = self.driver.find_element_by_xpath('//*[@id="inputPassword"]')

        email.send_keys("aditya@gmail.com")  # sending valid username
        password.send_keys("123")  # sending invalid password

        submitbtn = self.driver.find_element_by_xpath('//*[@id="btnLogin"]')
        submitbtn.click()
        time.sleep(5)
        print("Valid Email with invalid Password")
        alertJS = self.driver.switch_to.alert
        print(alertJS.text)
        alertJS.accept()
        timer1 = time.strftime("%Y%m%d = %H%M%S")
        picture = "Images"
        self.driver.save_screenshot("../screenShots/" + picture + timer1 + ".png")
        time.sleep(5)

    # This method will test for invalid username and invalid password
    def test_chrome_fn3(self):
        self.driver.get("https://gnsaddy.github.io/webAutomationSelenium/")
        email = self.driver.find_element_by_xpath('//*[@id="inputEmail"]')
        password = self.driver.find_element_by_xpath('//*[@id="inputPassword"]')

        email.send_keys("abc@gmail.com")  # sending invalid username
        password.send_keys("123")  # sending invalid password

        submitbtn = self.driver.find_element_by_xpath('//*[@id="btnLogin"]')
        submitbtn.click()
        time.sleep(5)
        print("Testing Invalid Email and Password")
        alertJS = self.driver.switch_to.alert
        print(alertJS.text)
        alertJS.accept()
        timer1 = time.strftime("%Y%m%d = %H%M%S")
        picture = "Images"

        self.driver.save_screenshot("../screenShots/" + picture + timer1 + ".png")
        time.sleep(5)

    def tearDown(self):
        self.driver.quit()


if __name__ == "__main__":
    unittest.main()