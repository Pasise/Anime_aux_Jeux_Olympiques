CC = g++
CCFLAGS = -Wall -Werror -std=c++11 -g
INCLUDES = -I../Code/headers
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Recherchez tous les fichiers source dans le répertoire ../Code/src/ avec l'extension .cpp
SRC = $(wildcard ../Code/src/*.cpp)

# Générez la liste des fichiers objets en remplaçant l'extension .cpp par .o
OBJ = $(SRC:.cpp=.o)

# Recherchez tous les fichiers source de test dans le répertoire actuel avec l'extension .cpp
TST = $(wildcard *.cpp)

# Générez la liste des fichiers objets de test en remplaçant l'extension .cpp par .o
OBJ_TEST = $(filter-out ../Code/main.o, $(OBJ)) $(TST:.cpp=.o)

testcase.out : $(OBJ_TEST) 
	$(CC) $(CCFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

# Règle générique pour créer des fichiers objets (.o) à partir de fichiers source (.cpp)
%.o: %.cpp
	$(CC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<

test: testcase.out
	./testcase.out

.depend:
	g++ $(CCFLAGS) $(INCLUDES) -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ_TEST) testcase.out ../Code/src/*.o