import os, time
import unittest
from selenium import webdriver

mypath = os.path.abspath(os.path.dirname(__file__))
path = os.path.join(mypath, "../Drivers/x32/chromedriver.exe")


# Unit Test contains
# 1.Test case 2.Test loader 3.Test runner 4.Test report 5.Test suite

# setup is entry point
# for userdefined functions start with test keyword always
class ChromeLaunch(unittest.TestCase):
    def setUp(self):
        self.driver = webdriver.Chrome(path)
        driver = self.driver
        time.sleep(2)
        driver.maximize_window()

    def test_chrome_func(self):
        self.driver.get("https://www.google.com")
        textBox = self.driver.find_element_by_name('q')
        textBox.send_keys("Hello Google")
        time.sleep(2)

    def tearDown(self):
        self.driver.quit()


# run from here
if __name__ == "__main__":
    unittest.main()
