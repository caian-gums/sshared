CXX=g++
DEBUG=-g
CFLAGS= -Wall $(DEBUG) -std=c++11

INCLUDES=-I./include

# this is to avoid files, directories and targets with the same name
# let 'make' assume that is all up to date
.PHONY: all test clean

# source files
SRC= src/controller.cpp \
	src/shamir_dealer.cpp \
	util/file.cpp \
	src/main.cpp

# test source files
TST_SRC= src/controller.cpp \
	src/shamir_dealer.cpp \
	util/file.cpp \
	test/main.cpp

# output
OUT=sshared

# test output
TST_OUT=stest

# compile all
all:
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(OUT) $(SRC)

# compile test
test:
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(TST_OUT) $(TST_SRC)

clean:
	rm $(OUT) $(TST_OUT)
