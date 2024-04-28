CXX = g++
CXXFLAGS = -std=c++11 -I/include
LDFLAGS = -lcppunit



SRCDIRS = /src

##EXCLUDE_TEST_FILES = Article/test/TestMain.cpp Auberge/test/mainTestAuberge.cpp Batiment/test/MainTest.cpp EtablissementCommercial/test/MainTest.cpp

SOURCES = $(wildcard src/*.cpp)
TEST_SOURCES = $(filter-out $(EXCLUDE_TEST_FILES), $(wildcard $(addsuffix /*.cpp,$(TESTDIRS))))

OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

MAIN_TEST_SRC = .

MAIN_TEST = main.cpp

TARGET = testExecutable

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS) $(TEST_OBJECTS) $(MAIN_TEST:.cpp=.o)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(TARGET) $(MAIN_TEST:.cpp=.o)


.PHONY: all clean

