CC = clang++ -std=c++11
CGLAGS = -Wall -g
LDFLAGS = -pthread
LOG:asynLog_test.o asynLog.o logFile.o
	${CC} ${CGLAGS} -o LOG asynLog_test.o asynLog.o logFile.o ${LDFLAGS} && rm *.o
asynLog_test.o: asynLog.h
	${CC} ${CGLAGS} -c asynLog_test.cpp
asynLog.o:asynLog.h logFile.h fixBuffer.h timestamp.h
	${CC} ${CGLAGS} -c asynLog.cpp
logFile.o:logFile.h
	${CC} ${CGLAGS} -c logFile.cpp
.PHONY:clean
clean:
	rm *.o
