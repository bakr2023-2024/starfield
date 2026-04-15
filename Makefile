.PHONY: clean
main: main.cpp
	g++ --std=c++20 -o starfield main.cpp -lraylib -lgdi32 -lwinmm -mwindows
clean:
	rm -rf *.exe