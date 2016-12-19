CXX=g++
DEBUG=-g
CFLAGS= -Wall $(DEBUG) -std=c++11

# source files
SRC= src/main.cpp

# output
OUT=sshared

# compile all
all:
	$(CXX) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm $(OUT)
