CXX := g++
LIBS := -ltimer
TARGET := timer-test
INCDIR := include
SRCDIR := src
OBJDIR := obj
BINDIR := bin
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o) 
INSTALLDIR := /usr/bin
H_INSTALLDIR := /usr/include
CXXFLAGS := -c -I $(INCDIR) -std=c++20
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g -gdwarf
else
	CXXFLAGS += -O2 -Wall -Werror
endif

$(BINDIR)/$(TARGET): $(OBJ)	
	@if ! test -d $(BINDIR); then mkdir $(BINDIR); fi
	$(CXX) $^ $(LIBS) $(LDFLAGS) -o $@
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if ! test -d $(OBJDIR); then mkdir $(OBJDIR); fi
	$(CXX) $< $(CXXFLAGS) -o $@
install:
	mkdir -p $(INSTALLDIR)
	cp -p $(BINDIR)/$(TARGET) $(INSTALLDIR)
uninstall:
	rm -r $(INSTALLDIR)/$(TARGET)
clean :
	rm $(OBJDIR)/*.o
