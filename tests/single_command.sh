#!/bin/bash

echo "running..."
echo "testing single commands..."
cat > test.txt
{
echo "echo testing echo..."
echo "echo firstTest"
echo "echo second Test"
echo "echo third ; test && using || connecters"
echo "echo ...done"

echo "testing ls..."
echo "echo basic ls command"
echo "ls"
echo "echo ls -a"
echo "ls -a"
echo "echo ...done"


} | ./rshell
