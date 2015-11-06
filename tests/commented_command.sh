#!/bin/bash

echo "testing commented commands"
cat > test.txt
{
echo "echo this is an uncommented statement"
echo "echo this statement has a comm#ent in the middle"
echo "echo comment separated # by space"
echo "echo comment at end#"
echo "mkdir test ;# ls"
echo "mkdir te#st ; ls"
echo "#mkdir test ; ls"

echo "echo done"
echo exit

} | ./rshell
