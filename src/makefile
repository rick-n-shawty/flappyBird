# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -I/opt/homebrew/Cellar/sfml/2.6.1/include

# Linker flags
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

# Target executable
TARGET = game

# Source files
SRCS = main.cpp Game.cpp Globals.cpp Pipe.cpp

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to build the target executable from object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean
