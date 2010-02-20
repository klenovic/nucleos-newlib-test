#!/bin/sh

# Initialization
PATH=:/bin:/usr/bin
export PATH

rm -rf DIR*			# remove any old junk lying around
passed=`expr 0`			# count number of tests run correctly
failed=`expr 0`			# count number of tests that failed
total=`expr 0`			# total number of tests tried
badones=			# list of tests that failed

# Print test welcome message
clear
echo "Running POSIX compliance test suite. There are 44 tests in total."
echo " "

# Run all the tests, keeping track of who failed.
for i in  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 \
         21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38    40 \
         41    43 44
# sh1.sh sh2.sh
do total=`expr $total + 1`
   FAIL=0
   if [ $USER = root -a \( $i = 11 -o $i = 33 \) ]
   then su - ast -c "cd `pwd`; ./test$i" || FAIL=1
   else ./test$i || FAIL=1
   fi

   if [ $FAIL -eq 0 ]
      then passed=`expr $passed + 1`
      else failed=`expr $failed + 1`
           badones=`echo $badones " " $i`
   fi
done

# Print results of the tests.
echo " "
if test $total = $passed
   then echo All $passed tests completed without error.
   else echo Testing completed.  Score:   $passed passed,  $failed failed
        echo The following tests failed: $badones
fi

# echo " "
