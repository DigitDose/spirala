# Ustawienia pkg-config
PKG_CONFIG_PATH := /usr/lib/x86_64-linux-gnu/pkgconfig
CFLAGS := $(shell pkg-config --cflags glfw3 glew)
LDFLAGS := $(shell pkg-config --libs glfw3 glew)

# Nazwa wynikowego programu
PROGRAM = spirala

# Pliki źródłowe i obiektowe
SOURCES = main.cpp spirala.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Reguły kompilacji
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	g++ $(CFLAGS) -o $(PROGRAM) $(OBJECTS) $(LDFLAGS)

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@

# Reguły dodatkowe
clean:
	rm -f *.o *~ $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)
