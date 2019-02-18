# CMake generated Testfile for 
# Source directory: /Users/ETHIY/Workspace/Projects/houda/cra_pricer
# Build directory: /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test "/Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/tests/tests" "--reporter" "compact")
subdirs("lib")
subdirs("bin")
subdirs("tests")
