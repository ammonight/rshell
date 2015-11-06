#!/bin/bash

echo "testing exit function"

echo "single statement..."
exit | ./rshell

echo "...done"

echo "with ;"
echo test ; exit | ./rshell
echo done 1
exit ; echo "should not execute" | ./rshell
echo done 2
foo ; exit | ./rshell
echo done 3
echo done

echo "with &&"
echo test && exit | ./rshell
echo done 1
exit && echo "should not execute" | ./rshell
echo done 2
foo && exit | ./rshell
echo done 3
echo done


echo "with ||"
echo test || exit | ./rshell
echo done 1
exit || echo "should not execute" | ./rshell
echo done 2
foo || exit | ./rshell
echo done 3
echo done

echo complete
