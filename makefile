all: rshell commands.o connecters.o

commands.o: commands.cc commands.h
	g++ -c -Wall -Werrer -ansi -pedantic commands.cc

connecters.o: connecters.cc connecters.h
	g++ -c -Wall -Werror -ansi -pedantic connecters.cc

rshell: main.cc
	g++ -c -Wall -Werror -ansi -pedantic main.cc -o rshell

