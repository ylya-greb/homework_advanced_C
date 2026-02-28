CC = gcc
CFLAGS = -Wall  -std=c99 
LIBS = -lm

all: adv_C_kurs

adv_C_kurs: main.o functions.o
	$(CC) -o adv_C_kurs main.o functions.o $(LIBS)

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	del -f *.o func
	del adv_C_kurs.exe
	