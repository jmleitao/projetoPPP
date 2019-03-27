CC = gcc
CFLAGS = -D_REENTRANT -pthread -Wall -g
LDFLAGS = -lm
OBJS = main.o ficheiros.o estruturas.o
PROG = projeto

# ------------------------------------------------

all:							${PROG}

clean_all:
									rm -f ${OBJS} ${PROG}

clean:
									rm -f ${OBJS}

# ------------------------------------------------

${PROG}:					${OBJS}
									${CC} ${CFLAGS} -o ${PROG} ${OBJS} ${LDFLAGS}
