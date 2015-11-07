all: rshell

rshell: hwcode.cc
	g++ -Wall -Werror -ansi -pedantic hwcode.cc -o rshell
	mkdir bin
	chmod 700 rshell
	mv rshell bin
