TARGET = Test
COMPILER = g++


SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))


$(TARGET): $(OBJ)
	$(COMPILER) $(OBJ) -o $(TARGET)


%.o: %.cpp
	$(COMPILER) -c $< -o $@


clean:
	rm $(TARGET) *.o

