CC = gcc
CFLAGS = -O2 -Wall
LDLIBS = -lpthread

all: good bad

good: goodcnt.c csapp.c
	$(CC) $(CFLAGS) -o good goodcnt.c csapp.c $(LDLIBS)

bad: badcnt.c csapp.c  
	$(CC) $(CFLAGS) -o bad badcnt.c csapp.c $(LDLIBS)

clean:
	rm -f good bad *.o
