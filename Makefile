# makefile rules to compile cpp file
name = password-generator

SRC = $(name).cpp

all : $(name)
	c++ -o $(name) $(SRC)

re : clean all

clean:
	rm $(name)