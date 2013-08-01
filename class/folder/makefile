OBJS = Message.o Folder.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

p1: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o p1
		
Folder.o: Folder.h Folder.cc Message.h Message.cc
		$(CC) $(CFLAGS) Folder.cc

Message.o: Message.h Message.cc Folder.h Folder.cc
		$(CC) $(CFLAGS) Message.cc
		
main.o: main.cc Message.h Message.cc Folder.h Folder.cc
		$(CC) $(CFLAGS) main.cc

		
clean:
	\rm *.o *~ p1
