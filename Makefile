CC=g++
CFLAGS=-c -Wall -g
LDFLAGS= -g
SOURCES= \
        main.cpp \
				fedotov.cpp \
				geroevvn.cpp \
				golovenkomv.cpp \
				gorbylevako.cpp \
				hramovaia.cpp \
				kidyaevvs.cpp \
				klyushenkovaaa.cpp \
				KulyaginTI.cpp \
				kurbatovdi.cpp \
				kuzminnal.cpp \
				mulichevaes.cpp \
				polischukoa.cpp \
				sorokinai.cpp \
				zhuravlevama.cpp \
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
