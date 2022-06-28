CC=gcc
CFLAGS="-Wall"

TICTACTOE="tictactoe.exe"

all: main board logger minimax

main:
	$(CC) $(CFLAGS) -o ./out/main.o -c ./src/main.c

board:
	$(CC) $(CFLAGS) -o ./out/board.o -c ./src/board.c

logger:
	$(CC) $(CFLAGS) -o ./out/logger.o -c ./src/logger.c

minimax:
	$(CC) $(CFLAGS) -o ./out/minimax.o -c ./src/minimax.c

# Build executable from object files
build:
	$(CC) $(CFLAGS) ./out/*.o -o ./bin/$(TICTACTOE)
	
# Run executable
run:	
	./bin/$(TICTACTOE)