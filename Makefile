CXX := g++
AR := ar
TARGET := libtimer.so
INCDIR := include
HPPDIR := timer
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
	@if ! test -d $(BINDIR); then mkdir $(BINDIR); fi
ifeq ($(STATIC), 0)
	$(CXX) $^ $(LDFLAGS) -o $@
else
	$(AR) $(ARFLAGS) $(BINDIR)/$(TARGET) $(OBJ)
endif
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if ! test -d $(OBJDIR); then mkdir $(OBJDIR); fi
	$(CXX) $< $(CXXFLAGS) -o $@
install:
	mkdir -p $(INSTALLDIR)
	mkdir -p $(H_INSTALLDIR)/$(HPPDIR)
	cp -p $(BINDIR)/$(TARGET) $(INSTALLDIR)
	cp -p include/$(HPPDIR)/*.hpp $(H_INSTALLDIR)/$(HPPDIR)
uninstall:
	rm -r $(INSTALLDIR)/$(TARGET)
	rm -r $(H_INSTALLDIR)/$(HPPDIR)
clean :
	rm $(OBJDIR)/*.o
