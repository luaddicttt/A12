HOME=.
BIN=${HOME}/bin
INCL=${HOME}/incl
SRC=${HOME}/src
CC=g++-9
ALL=main.o

VPATH=${SRC}

.cpp.o:
	${CC} -c $< -I ${INCL} -std=c++17 -Wall
.o:
	${CC} $^ -o ${BIN}/$@
	-rm -f *.o

main: ${ALL}

test: test.o
	${CC} $^ -o ${BIN}/$@
	-rm -f *.o
	@echo ------------
	@${BIN}/$@
	@echo ------------
	-rm -f ${BIN}/$@

.PHONY: clean
clean:
	-rm -f *.o
