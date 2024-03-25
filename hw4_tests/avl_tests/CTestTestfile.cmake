# CMake generated Testfile for 
# Source directory: /home/codio/workspace/hw4/hw4_tests/avl_tests
# Build directory: /home/codio/workspace/hw4/hw4_tests/avl_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AVLBST.ConstructionDestruction "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLBST.ConstructionDestruction")
add_test(AVLInsert.OneNode "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.OneNode")
add_test(AVLInsert.DoubleInsertLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.DoubleInsertLeft")
add_test(AVLInsert.DoubleInsertRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.DoubleInsertRight")
add_test(AVLInsert.InsertZigZigLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.InsertZigZigLeft")
add_test(AVLInsert.InsertZigZigRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.InsertZigZigRight")
add_test(AVLInsert.InsertZigZagLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.InsertZigZagLeft")
add_test(AVLInsert.InsertZigZagRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.InsertZigZagRight")
add_test(AVLInsert.7Elements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.7Elements")
add_test(AVLClear.Clear "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLClear.Clear")
add_test(AVLInsert.Duplicates "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.Duplicates")
add_test(AVLInsert.Random50x30ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.Random50x30ele")
add_test(AVLInsert.Random3x5000ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.Random3x5000ele")
add_test(AVLRemove.EmptyTree "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.EmptyTree")
add_test(AVLRemove.NodeMismatch "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.NodeMismatch")
add_test(AVLRemove.SingleRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.SingleRemove")
add_test(AVLRemove.RightChildRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.RightChildRemove")
add_test(AVLRemove.LeftChildRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.LeftChildRemove")
add_test(AVLRemove.TwoChildrenRemove_3Node "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.TwoChildrenRemove_3Node")
add_test(AVLRemove.TwoChildrenRemove_4Node "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.TwoChildrenRemove_4Node")
add_test(AVLRemove.Random50x30ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.Random50x30ele")
add_test(AVLStress.InsertRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLStress.InsertRemove")
add_test(AVLStress.Remove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/codio/workspace/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLStress.Remove")
