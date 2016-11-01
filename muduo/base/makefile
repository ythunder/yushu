CC = clang++ -std=c++11
CGLAGS = -Wall -g
LDFLAGS = -lpthread
TIMESTAMP: test.o timestamp.o
	${CC} ${CGLAGS} -o TIMESTAMP test.o timestamp.o ${LDFLAGS} 
test.o: Timestamp.h 
	${CC} ${CGLAGS} -c test_timestamp.cc
timestamp.o: copyable.h Types.h
	${CC} ${CGLAGS} -c Timestamp.cc
clean:
	rm *.o
