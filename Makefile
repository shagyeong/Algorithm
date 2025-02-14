SRCS = test.c
CC = gcc
OPTS = -Wall -g

TARG = test

make: $(TARG)
$(TARG) :
	$(CC) -o $(TARG) $(SRCS) -lm
clean:
	rm -f $(TARG)
