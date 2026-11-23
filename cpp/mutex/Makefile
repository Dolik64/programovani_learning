# Compiler settings
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -g -pthread
LDFLAGS  := -pthread

# Program names
TARGETS := mutex1 unique_lock

# Source files
SRCS    := mutex1.cpp unique_lock.cpp
OBJS    := $(SRCS:.cpp=.o)

.PHONY: all clean

# Výchozí cíl: sestaví oba programy
all: $(TARGETS)

# Pattern rule: pro každý program X použij X.o
# $@ = jméno cíle (např. mutex1), $< = závislost (mutex1.o)
$(TARGETS): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

# Převod .cpp → .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Smaže všechny vygenerované soubory
clean:
	rm -f $(OBJS) $(TARGETS)
