PROG= ipu_demo.exe
OBJS= ipu_demo.o ipu.o soklib.o
CC= gcc

all: $(OBJS)
	$(CC) -o $(PROG) $(OBJS) 
	cp $(PROG) progs
	rm *.o
ipu_demo.o:
	$(CC) -c ipu_demo.c
ipu.o:
	$(CC) -c ipu.c
soklib.o:
	$(CC) -c soklib.c
