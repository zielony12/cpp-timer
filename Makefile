CXX := g++
AR := ar
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
ARFLAGS := rcs
STATIC := 0
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g -gdwarf
else
	CXXFLAGS += -O2 -Wall -Werror
endif

ifeq ($(STATIC), 0)
	CXXFLAGS += -fpic
	LDFLAGS += -shared
else
	TARGET := libtimer.a
endif

$(BINDIR)/$(TARGET): $(OBJ)	
ifeq ($(STATIC), 0)
	$(CXX) $^ $(LDFLAGS) -o $@
else
	$(AR) $(ARFLAGS) $(BINDIR)/$(TARGET) $(OBJ)
endif
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $< $(CXXFLAGS) -o $@
install:
	mkdir -p $(INSTALLDIR)
	mkdir -p $(H_INSTALLDIR)/timer
	cp -p $(BINDIR)/$(TARGET) $(INSTALLDIR)
	cp -p include/timer/*.hpp $(H_INSTALLDIR)/timer
uninstall:
	rm -r $(INSTALLDIR)/$(TARGET)
	rm -r $(H_INSTALLDIR)/timer
clean :
	rm $(OBJDIR)/*.o
