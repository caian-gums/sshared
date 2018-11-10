CXX=g++
CFLAGS= -std=c++11
DYNAMIC_FLAGS=-fPIC
DEBUG=-g
CFLAGS_DEBUG= -Wall $(DEBUG) $(CFLAGS)

AR=ar
ARFLAGS=-rcs

INCLUDES=-I./include -I$(HOME)/sw/include
LIBS=-L$(HOME)/sw/lib -lntl -lgmp -lgf2x -lm


# this is to avoid files, directories and targets with the same name
# let 'make' assume that is all up to date
.PHONY: all test clean

# source files
SRC= src/controller.cpp \
	src/shamir_dealer.cpp \
	util/file.cpp \
	util/file_handler.cpp

# source files
STATIC_OBJ_PATH= bin/static/

# standalone main
STANDALONE_MAIN= src/main.cpp

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
OUT=bin/sshared

# static lib name
OUT_STATIC=bin/sshared.a

# test output
TST_OUT=stest

# test shares output
TST_SHARES=*.share*

# compile all
all:
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(OUT) $(SRC) $(STANDALONE_MAIN) $(LIBS)

# compile all
static: 
	$(CXX) $(CFLAGS) $(INCLUDES) -c src/controller.cpp -o $(STATIC_OBJ_PATH)controller.o
	$(CXX) $(CFLAGS) $(INCLUDES) -c src/shamir_dealer.cpp -o $(STATIC_OBJ_PATH)shamir_dealer.o
	$(CXX) $(CFLAGS) $(INCLUDES) -c util/file.cpp -o $(STATIC_OBJ_PATH)file.o
	$(CXX) $(CFLAGS) $(INCLUDES) -c util/file_handler.cpp -o $(STATIC_OBJ_PATH)file_handler.o
	$(AR) $(ARFLAGS) $(OUT_STATIC) $(STATIC_OBJ_PATH)* 

# compile test
test:
	$(CXX) $(CFLAGS_DEBUG) $(INCLUDES) -o $(TST_OUT) $(TST_SRC) $(LIBS)

clean:
	rm $(OUT) $(TST_OUT)

veryclean:
	rm $(OUT) $(STATIC_OBJ_PATH)* $(OUT_STATIC) $(TST_OUT) $(TST_SHARES)
