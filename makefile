CXX=g++
DEBUG=-g
CFLAGS= -Wall $(DEBUG) -std=c++11

INCLUDES=-I./include

# source files
SRC= src/controller.cpp \
	src/shamir_dealer.cpp \
	util/file.cpp \
	src/main.cpp

# output
OUT=sshared

# compile all
all:
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(OUT) $(SRC)

clean:
	rm $(OUT)
