CC = gcc
CFLAGS = -I. `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`
SOURCES = ltxApp.c ltxWindow.c
OBJECTS = ltxApp.o ltxWindow.o 
EXECUTABLE = ltxApp

ltxApp: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o ltxApp

ltxApp.o: ltxApp.c
	$(CC) $(CFLAGS) $(LIBS) -c ltxApp.c

ltxWindow.o: ltxWindow.c
	$(CC) $(CFLAGS) $(LIBS) -c ltxWindow.c

clean:
	rm *.o
