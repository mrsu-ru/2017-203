CC=g++
CFLAGS=-c -Wall -g
LDFLAGS= -g
SOURCES= \
        main.cpp \
				geroevvn.cpp \
				golovenkomv.cpp \
				hramovaia.cpp \
				kuzminnal.cpp \
				sorokinai.cpp \
				lab.cpp


OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=vvm

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o vvm
