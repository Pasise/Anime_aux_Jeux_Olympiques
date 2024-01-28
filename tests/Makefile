CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
CC_SFML= -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system 
SRC= $(wildcard ../*.cc)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cc)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o)

testcase.out : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^

%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) testcase.out

depends:
	g++ -MM $(SRC) >.depends
-include .depends
