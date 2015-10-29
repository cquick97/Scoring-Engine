OBJS = backdoor.o networking.o files.o serviceConfig.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
BOOST = -lboost_system -lboost_filesystem

output: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(BOOST) -o output

backdoor.o: backdoor.cpp backdoor.hpp networking.hpp files.hpp
	$(CC) $(CFLAGS) backdoor.cpp

networking.o: networking.cpp networking.hpp
	$(CC) $(CFLAGS) networking.cpp

files.o: files.cpp files.hpp
	$(CC) $(CFLAGS) files.cpp

serviceConfig.o: serviceConfig.cpp serviceConfig.hpp files.hpp
	$(CC) $(CFLAGS) serviceConfig.cpp

main.o: main.cpp backdoor.hpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm -f *.o *~ output

