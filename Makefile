
CC	= gcc
CFLAGS	= -W -Wall
LINK	= gcc
LFLAGS	=
LIBS	=
DEL_FILE      = rm -f


TARGET	= ex15-4
SOURCES	= main.c field.c position.c
OBJECTS	= main.o field.o position.o


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

.SUFFIXES: .o .c

.c.o:
	$(CC) -c $(CFLAGS) -o "$@" "$<"

main.o: main.c field.h position.h
field.o: field.c field.h position.h
position.o: position.c position.h

clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) $(TARGET)