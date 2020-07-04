#main: main.o stack.o maze.o
#	gcc main.o stack.o maze.o -o main
#main.o: main.c main.h stack.h maze.h
#	gcc -c main.c
#stack.o: stack.c stack.h main.h
#	gcc -c stack.c
#maze.o:maze.c maze.h main.h
#	gcc -c maze.c
#clean:
#	@echo "cleanning project"
#	rm main *.o
#	@echo "clean completed"
#.PHONY: clean
#foo= $(bar)
#bar= Huh?
#all:
#	@echo $(foo)
#y := $(x)  bar
#x := foo
objects := main.o
objects += $(foo)
foo = foo.o bar.o
all:
	@echo $(objects)
	@echo $(foo)
