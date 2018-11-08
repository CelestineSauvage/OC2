CXXFLAGS = -Wall -std=c++14 -Wextra
LDFLAGS=
CPP=g++
LD=g++

EXECS = tsp

SRCS_tsp = parse.cpp
OBJS_tsp = ${SRCS_tsp:.cpp=.o}

.SUFFIXES:
.SUFFIXES: .o .cpp

all: clean $(EXECS)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

tsp: $(OBJS_tsp)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf $(EXECS)

cleanedit:
	rm -rf *~
