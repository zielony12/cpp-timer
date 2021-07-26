CXX := g++
TARGET := libtimer.so
SRC := src/Timer.cpp
INC := include
OBJ := Timer.o
BIN := bin
INSTALLDIR := /usr/lib
H_INSTALLDIR := /usr/include
CXXFLAGS := -c -I $(INC)
LDFLAGS := -shared -o
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g -gdwarf -fpic
else
	CXXFLAGS += -O2 -Wall -Werror -fpic
endif

$(BIN)/$(TARGET) : $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC)
	$(CXX) $(LDFLAGS) $(BIN)/$(TARGET) $(OBJ)
install:
	mkdir -p $(INSTALLDIR)
	mkdir -p $(H_INSTALLDIR)
	cp -p $(BIN)/$(TARGET) $(INSTALLDIR)
	cp -p include/timer/Timer.hpp $(H_INSTALLDIR)
uninstall:
	rm -r $(INSTALLDIR)/$(TARGET)
	rm -r $(H_INSTALLDIR)/Timer.hpp
clean :
	rm *.o
