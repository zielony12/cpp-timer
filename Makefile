CXX := g++
TARGET := libtimer.so
INCDIR := include
SRCDIR := src
OBJDIR := obj
BINDIR := bin
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o) 
INSTALLDIR := /usr/lib
H_INSTALLDIR := /usr/include
CXXFLAGS := -c -I $(INCDIR)
LDFLAGS := -shared -o
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g -gdwarf -fpic
else
	CXXFLAGS += -O2 -Wall -Werror -fpic
endif

CXXFLAGS += -o

$(BINDIR)/$(TARGET): $(OBJ)	
	$(CXX) $^ $(LDFLAGS) $@
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $< $(CXXFLAGS) $@
install:
	mkdir -p $(INSTALLDIR)
	mkdir -p $(H_INSTALLDIR)
	cp -p $(BIN)/$(TARGET) $(INSTALLDIR)
	cp -p include/timer/Timer.hpp $(H_INSTALLDIR)
uninstall:
	rm -r $(INSTALLDIR)/$(TARGET)
	rm -r $(H_INSTALLDIR)/Timer.hpp
clean :
	rm $(OBJDIR)/*.o
