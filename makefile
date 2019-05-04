XX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#LDFLAGS = -lboost_date_time

OBJS = main.o Board.o Ant.o getInput.o printAntBoard.o

SRCS = main.cpp Board.cpp Ant.cpp printAntBoard.cpp getInput.cpp

HEADERS = Board.hpp Ant.hpp getInput.hpp printAntBoard.hpp

TARGET = project1 

${TARGET}: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o ${TARGET}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	$(RM) ${TARGET} ${OBJS}
