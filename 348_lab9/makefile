CXX       = g++
CXXFLAGS  = -std=c++17 -Wall -Wextra -O2

SRC       = src/main.cpp src/Matrix.cpp
TARGET    = matrix_ops

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -Iinclude $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
