PROJ_NAME = PA1
CC = gcc
CFLAGS = -Wall -O3 
LIBS = 
OBJFILES := $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.s,%.o,$(wildcard *.s))

$(PROJ_NAME): $(OBJFILES) 
	$(CC) -o $(PROJ_NAME) $(OBJFILES) $(ASM_OBJ) $(LIBS)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
%.o : %.s
	$(CC) $(CFLAGS) -c $< -o $@
%.lst: %.c
	$(CC) $(CFLAGS) -Wa,-adhln $(LIBS) $< > $@
clean:
	rm -f *.o *.lst $(PROJ_NAME)
