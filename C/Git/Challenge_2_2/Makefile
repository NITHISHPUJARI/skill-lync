# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCS = calculator.c main.c
OBJS = $(SRCS:.c=.o)

# Executable
TARGET = calculator

# Test files
TEST_SRCS = test_calculator.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_TARGET = test_calculator

# Default target
all: $(TARGET)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the calculator program
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Build the test program
test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) $(filter-out main.o, $(OBJS))
	$(CC) $(TEST_OBJS) $(filter-out main.o, $(OBJS)) -o $(TEST_TARGET)

# Run the test program
runtest: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean object files and executables
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)
