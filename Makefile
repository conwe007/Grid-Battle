CC = gcc

OBJS = ./src/main.c ./src/game.c ./src/grid.c ./src/character.c ./src/job.c ./src/action.c
INCS = -Iinclude
COMPILER_FLAGS = -lm

OBJ_NAME = main

all : $(OBJS)
	$(CC) $(OBJS) $(INCS) $(COMPILER_FLAGS) -o $(OBJ_NAME)

clean :
	rm $(OBJ_NAME)