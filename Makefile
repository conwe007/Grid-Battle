CC = gcc

OBJS = game.c grid.c character.c job.c action.c

COMPILER_FLAGS = -lm

OBJ_NAME = game

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)

clean :
	rm $(OBJ_NAME)