CXX=g++
RM=rm
INCLUDE=-I.
SOURCE=main.cpp laplacian.cpp cds.cpp upwind.cpp fields.cpp linalg.cpp
OBJ=$(SOURCE:%.cpp=%.o)

%.o:%.cpp
		$(CXX) $(INCLUDE) -C $<

all:build

build:$(OBJ)
		$(CXX) $(INCLUDE) $^ -o 1dconvectiondiffusion.exe

clean:
		$(RM) $(OBJ)


.PHONY.: all build clean