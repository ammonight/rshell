#!/bin/bash

echo "running..."
cat > test.txt
{
echo "echo testing semicolon"
echo "echo statement 1 ; echo statement 2"
echo "echo statement 1;echo statement 2"
echo "ls ; mkdir foo"
echo "foo ; echo first statement fail test"
echo "echo second statement fail test ; foo"
echo "echo ...done"

echo "echo testing AND"
echo "echo true && echo true2"
echo "foo && echo first statement fail"
echo "echo second statement fail && foo"
echo "echo ...done"

echo "echo testing NAND"
echo "echo true || echo true"
echo "foo || echo first statement fail"
echo "echo second statement fail || foo"
echo "foo || foo"
echo "echo ...done"

echo "echo testing multi done"
} | ./rshell
