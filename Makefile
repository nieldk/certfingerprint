# Makefile for cert_fingerprint

CC = gcc
CFLAGS = -Wall -Wextra -O2
LIBS = -lssl -lcrypto
SRC = cert_fingerprint.c
BIN = cert_fingerprint

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC) $(LIBS)

clean:
	rm -f $(BIN)

.PHONY: all clean
