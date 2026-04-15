.PHONY: clean
main: main.cpp
	g++ --std=c++20 -o main main.cpp -lraylib -lgdi32 -lwinmm
clean:
	rm -rf *.exe