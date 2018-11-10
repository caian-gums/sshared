CXX=g++
DEBUG=-g
CFLAGS= -Wall $(DEBUG) -std=c++11

INCLUDES=-I./include -I$(HOME)/sw/include
LIBS=-L$(HOME)/sw/lib -lntl -lgmp -lgf2x -lm


# this is to avoid files, directories and targets with the same name
# let 'make' assume that is all up to date
.PHONY: all test clean

# source files
SRC= src/controller.cpp \
	src/shamir_dealer.cpp \
	util/file.cpp \
	util/file_handler.cpp \
	src/main.cpp

# test source files
TST_SRC= src/controller.cpp \
	src/shamir_dealer.cpp \
	util/file.cpp \
	util/file_handler.cpp \
	test/test_controller.cpp \
	test/test_shamir_dealer.cpp \
	test/test_file.cpp \
	test/test_list.cpp \
	test/main.cpp

# output
OUT=sshared

# test output
TST_OUT=stest

# test shares output
TST_SHARES=*.share*

# compile all
all:
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(OUT) $(SRC) $(LIBS)

# compile test
test:
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(TST_OUT) $(TST_SRC) $(LIBS)

clean:
	rm $(OUT) $(TST_OUT)

veryclean:
	rm $(OUT) $(TST_OUT) $(TST_SHARES)
