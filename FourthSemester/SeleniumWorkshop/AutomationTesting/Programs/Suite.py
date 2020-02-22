import unittest
import UnitTestingExample
import FireFoxUnitTest
#two test cases are run together

class Test_Suite(unittest.TestCase):
    def test_main(self):
        self.suite = unittest.TestSuite()
        self.suite.addTests([
            unittest.defaultTestLoader.loadTestsFromTestCase(UnitTestingExample.ChromeLaunch),
            unittest.defaultTestLoader.loadTestsFromTestCase(FireFoxUnitTest.FirefoxLaunch),
        ])

        runner = unittest.TextTestRunner()
        runner.run(self.suite)

if __name__ == "__main__":
    unittest.main()