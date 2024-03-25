# CMake generated Testfile for 
# Source directory: /home/codio/workspace/hw4/hw4_tests/equalpaths_tests
# Build directory: /home/codio/workspace/hw4/hw4_tests/equalpaths_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(EqualPaths.Empty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.Empty")
add_test(EqualPaths.RootOnly "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.RootOnly")
add_test(EqualPaths.RootLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.RootLeft")
add_test(EqualPaths.RootRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.RootRight")
add_test(EqualPaths.Full1 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.Full1")
add_test(EqualPaths.TrueTest1 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.TrueTest1")
add_test(EqualPaths.TrueTest2 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.TrueTest2")
add_test(EqualPaths.TrueTest3 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.TrueTest3")
add_test(EqualPaths.TrueTest4 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.TrueTest4")
add_test(EqualPaths.FalseTest1 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.FalseTest1")
add_test(EqualPaths.FalseTest2 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.FalseTest2")
add_test(EqualPaths.FalseTest3 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/equalpaths_tests/equalpaths_tests" "--gtest_filter=EqualPaths.FalseTest3")
