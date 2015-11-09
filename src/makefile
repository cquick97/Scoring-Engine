OBJS = backdoor.o networking.o files.o serviceConfig.o sudoers.o users.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
BOOST = -lboost_system -lboost_filesystem

output: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(BOOST) -o output

backdoor.o: backdoor.cpp backdoor.hpp networking.hpp files.hpp globals.hpp
	$(CC) $(CFLAGS) backdoor.cpp

networking.o: networking.cpp networking.hpp
	$(CC) $(CFLAGS) networking.cpp

files.o: files.cpp files.hpp
	$(CC) $(CFLAGS) files.cpp

serviceConfig.o: serviceConfig.cpp serviceConfig.hpp files.hpp globals.hpp
	$(CC) $(CFLAGS) serviceConfig.cpp

sudoers.o: sudoers.cpp sudoers.hpp files.hpp globals.hpp
	$(CC) $(CFLAGS) sudoers.cpp

users.o: users.cpp users.hpp files.hpp globals.hpp
	$(CC) $(CFLAGS) users.cpp

main.o: main.cpp globals.hpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm -f *.o *~ output

