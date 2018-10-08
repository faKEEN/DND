CC =g++
INCLUDES = ../Header
EXEC_NAME = main
LIBS=
CFLAGS= -std=c++0x -Wall -g
SOURCES = $(wildcard *.cpp)
OBJ_FILES =  $(SOURCES:.cpp=.o)
all : $(EXEC_NAME)


$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(CFLAGS)

%.o: %.cpp $(INCLUDES)/%.hpp
	$(CC) -o $@ -c $< $(CFLAGS)
main.o:main.cpp
	$(CC) -o $@ -c $< -std=c++0x -Wall -g
clean :
	rm -f $(OBJ_FILES) $(EXEC_NAME)
