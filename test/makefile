# Makefile for running CppUnit tests

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Iinclude -Itests/include -I/opt/homebrew/include -std=c++11
LDFLAGS = -L/opt/homebrew/Cellar/cppunit/1.15.1/lib -lcppunit

# Add all source files here
SOURCES = $(wildcard src/*.cpp)
# Add all test files here
TEST_SOURCES = $(wildcard tests/src/*.cpp)
# Objects for source files
OBJECTS = $(SOURCES:.cpp=.o)
# Test objects
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Name of the test executable
TEST_EXEC = run_tests

.PHONY: all clean test

all: test

test: $(TEST_EXEC)
#	./$(TEST_EXEC)

$(TEST_EXEC): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(TEST_EXEC)
