CFLAGS = -g -Wno-deprecated -fpermissive -std=c++11
OBJECTS = family.o

secret:	main.cpp family.h family.cpp
	g++ main.cpp $(CFLAGS) family.cpp -o secret_santa 
	
family.o: family.cpp family.h $(CFLAGS)
	g++ family.cpp $(CFLAGS) -c 

