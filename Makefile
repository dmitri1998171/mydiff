BIN := mydiff

SRC := main.c
CC := gcc
CFLAGS := -Wall
LDFLAGS := -lpanel -lncurses

.PHONY: all clean

all: $(BIN)

$(BIN):
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BIN)

clean:
	rm -rf main 
