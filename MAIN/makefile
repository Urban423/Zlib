Target = zlib
CC = g++


SRC = ${wildcard *.cpp}
OBJ = ${patsubst %.cpp, bin/%.o, ${SRC}}

${Target}: fileManager compiler
	./build/${Target}

fileManager:
	if not exist "bin" mkdir "bin"
	if not exist "build" mkdir "build"

compiler: ${OBJ}
	${CC} -o build/${Target} ${OBJ}

bin/%.o: %.cpp
	${CC} -c -o $@ $<