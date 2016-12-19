CPP=g++

# source files
SRC= src/main.cpp

# output
OUT=sshared

# compile all
all:
	$(CPP) -o $(OUT) $(SRC)

clean:
	rm $(OUT)
