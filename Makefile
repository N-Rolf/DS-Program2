# target            - output - highest priority
# prerequisites     - monitor changes to main.o Stack.o
# command           - link object files (.o files)
#                   - generate executable named output
output: main.o Stack.o
	g++ -o output main.o Stack.o

# target            - main.o
# prerequisites     - monitor changes to main.cpp
# command           - generate main.o
main.o: main.cpp
	g++ -c main.cpp

# target            - Stack.o
# prerequisites     - monitor changes to Stack.cpp, Stack.h
# command           - generate Stack.o
Stack.o: Stack.h Stack.cpp
	g++ -c Stack.cpp

# target            - clean
# prerequisites     - none
# command           - remove .o files and executable
# command line      - make clean
clean:
	rm output main.o Stack.o