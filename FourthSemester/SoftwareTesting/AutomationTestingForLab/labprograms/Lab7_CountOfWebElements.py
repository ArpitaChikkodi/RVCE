import time
import unittest
from selenium.webdriver.support.ui import Select
from selenium import webdriver

chromeDriver = "../drivers/x32/chromedriver.exe"


class CountWidget(unittest.TestCase):

    def setUp(self):
        self.driver = webdriver.Chrome(chromeDriver)
        driver = self.driver
        time.sleep(3)
        driver.maximize_window()

    def test_chrome_fn1(self):
        self.driver.get("https://gnsaddy.github.io/webAutomationSelenium/countWidgets.html")
        radio1 = self.driver.find_elements_by_css_selector('input[name="gender"]')
        radio2 = self.driver.find_elements_by_css_selector('input[name="age"]')
        radio3 = self.driver.find_elements_by_css_selector('input[name="subject"]')
        count = 0

        for i in radio1:
            count += 1
        print("\nRadio button count for gender = ", count)

        for i in radio2:
            count += 1
        print("\nRadio button count for age = ", count)

        for i in radio3:
            count += 1
        print("\nRadio button count for subject = ", count)
        print("----------------------------------------------------------")
        time.sleep(5)

    def test_chrome_fn2(self):
        self.driver.get("https://gnsaddy.github.io/webAutomationSelenium/countWidgets.html")
        textBox = self.driver.find_elements_by_css_selector('input[type="text"]')
        count = 0
        count1 = 0

        for i in textBox:
            count += 1
        print("\nText box count = ", count)
        print("----------------------------------------------------------")
        time.sleep(5)

    def test_chrome_fn3(self):
        self.driver.get("https://gnsaddy.github.io/webAutomationSelenium/countWidgets.html")
        con = 0
        dropdown = Select(self.driver.find_element_by_xpath("//*[@id='cars']"))
        con += 1
        dropdown2 = Select(self.driver.find_element_by_xpath('//*[@id="bikes"]'))
        con += 1

        print("\nCombobox count : ", con)

        count = 0

        for i in dropdown.options:
            count += 1
        print("\ncombobox1 value count = ", count)
        val = []
        for element in dropdown.options:
            val.append([element.get_attribute("value")])
            print(element.get_attribute("value"))
        count = 0
        for i in dropdown2.options:
            count += 1
        print("\ncombobox2 value count = ", count)
        val = []
        for element in dropdown2.options:
            val.append([element.get_attribute("value")])
            print(element.get_attribute("value"))
        time.sleep(5)

    def tearDown(self):
        self.driver.quit()


if __name__ == "__main__":
    unittest.main()
