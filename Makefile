.PHONY: clean
main: main.cpp utils.cpp
	g++ --std=c++20 -o main main.cpp utils.cpp -lraylib -lgdi32 -lwinmm
clean:
	rm -rf *.exe