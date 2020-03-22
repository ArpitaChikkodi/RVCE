import unittest
import lab6_LoginPageUnitTest
import Lab7_CountOfWebElements


# two test cases are run together
class Test_Suite(unittest.TestCase):
    def test_main(self):
        self.suite = unittest.TestSuite()
        self.suite.addTests([unittest.TestLoader().loadTestsFromModule(lab6_LoginPageUnitTest),
                             unittest.TestLoader().loadTestsFromModule(Lab7_CountOfWebElements)])

        runner = unittest.TextTestRunner()
        runner.run(self.suite)


if __name__ == "__main__":
    unittest.main()