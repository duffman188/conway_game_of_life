CC = gcc
CFLAGS = -Wall -g
OBJS = main.o game_of_life.o arrays.o utils.o

all: game_of_life

game_of_life: $(OBJS)
	$(CC) $(OBJS) -o game_of_life

main.o: main.c game_of_life.h arrays.h utils.h
	$(CC) $(CFLAGS) -c main.c

game_of_life.o: game_of_life.c game_of_life.h arrays.h utils.h
	$(CC) $(CFLAGS) -c game_of_life.c

arrays.o: arrays.c arrays.h
	$(CC) $(CFLAGS) -c arrays.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

# Run the tests using test.sh
test: all
	chmod +x test.sh
	./test.sh

clean:
	rm -f *.o game_of_life
