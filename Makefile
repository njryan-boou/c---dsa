CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -pedantic -O2
TARGET := main.exe
SRC := main.cpp

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
