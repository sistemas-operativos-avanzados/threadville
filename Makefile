# Makefile para el programa threadville. Cuando se ejecuta el commando 'make' se compila y se crea el ejecutable.
# La carpeta 'target/' va a servir como punto en donde se van a dejar los archivos resultantes del proceso
# de compilacion

# make OPTFLAGS=-pthread

ODIR=target
SDIR=src
SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
EXECUTABLE=threadville
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG -fPIC $(OPTFLAGS)

all: clean $(EXECUTABLE)

build: $(ODIR) $(OBJECTS)
	$(CC) -shared -o $(ODIR)/tv.a $(OBJECTS)

$(EXECUTABLE): build
	$(CC) $(OBJECTS) -o $(ODIR)/$@

$(ODIR):
	mkdir $(ODIR)

clean:
	rm -f $(OBJECTS)
	rm -rf $(ODIR)