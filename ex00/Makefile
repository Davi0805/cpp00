# Compiler settings
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# File names
SRCS = $(shell find . -name '*.cpp')
OBJS = $(SRCS:.cpp=.o)
TARGET = megaphone

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

# Clean and rebuild
re: clean all

.PHONY: all clean rebuild