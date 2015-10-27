OBJS = backdoor.o check.o score.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
BOOST = -lboost_system -lboost_filesystem

output: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(BOOST) -o output

backdoor.o: backdoor.cpp backdoor.hpp check.hpp
	$(CC) $(CFLAGS) backdoor.cpp

check.o: check.cpp check.hpp
	$(CC) $(CFLAGS) check.cpp

score.o: score.cpp backdoor.hpp check.hpp
	$(CC) $(CFLAGS) score.cpp

clean:
	\rm -f *.o *~ output

