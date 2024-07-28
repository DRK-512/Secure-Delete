CC = gcc
CFLAGS = -Wall -Werror -Iinclude

all: sec-rm

sec-rm: 
	${CC} ${CFLAGS} ./src/functions.c ./src/main.c -o sec-rm 

clean: 
	rm sec-rm