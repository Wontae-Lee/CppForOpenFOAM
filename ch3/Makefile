CXX=g++
# CXXFLAGS= -03 -fno-math-errno
LDFLAGS=
INCLUDE = -Iinclude
LIB =-L,-Llib
SRC =main.cpp
OBJ=$(SRC:%.cpp = %.o)
OUT =main.exe

%.o:%.cpp
${CXX}${CXXFLAGS}${INCLUDE} -c $<

all:build

build:${OBJ}
${CXX} ${CXXFLAGS}${INCLUDE} -o ${OUT} $^{LDFLAGS}${LIB}

clean:
rm -rf ${OBJ} ${OUT}

.PHONY: all build clean