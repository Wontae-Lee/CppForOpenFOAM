CXX=g++
CXXFLAGS=-W -Wall -O3 -std=c++11 -g
LDFLAGS=
INCLUDE=-I.
LIB=-L. -lm
SRC=main.cc read.cc write.cc
OBJ=$(SRC:%.C=%.o)
OUT=main.exe

%.o:%.cc
		$(CXX) $(CXXFLAGS) $(INCLUDE) -c $<
$(OUT): $(OBJ)
		$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^ $(LDFLAGS) $(LIB)
clean:
		#echo $(OBJ)
			rm -f *.o