CC = gcc
CFLAGS = -I. `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`
SOURCES = ltxApp.c ltxWindow.c ltxFileCommands.c ltxStatusbar.c ltxMenubar.c ltxHelpCommands.c
OBJECTS = ltxApp.o ltxWindow.o ltxFileCommands.o ltxStatusbar.o ltxMenubar.o ltxHelpCommands.o
EXECUTABLE = ltxApp

ltxApp: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o ltxApp

ltxApp.o: ltxApp.c
	$(CC) $(CFLAGS) $(LIBS) -c ltxApp.c

ltxWindow.o: ltxWindow.c
	$(CC) $(CFLAGS) $(LIBS) -c ltxWindow.c

ltxFileCommands.o: ltxFileCommands.c
	$(CC) $(CFLAGS) $(LIBS) -c ltxFileCommands.c

ltxStatusbar.o: ltxStatusbar.c
	$(CC) $(CFLAGS) $(LIBS) -c ltxStatusbar.c

ltxMenubar.o: ltxMenubar.c
	$(CC) $(CFLAGS) $(LIBS) -c ltxMenubar.c

ltxHelpCommands.o: ltxHelpCommands.c
	$(CC) $(CFLAGS) $(LIBS) -c ltxHelpCommands.c



clean:
	rm *.o
