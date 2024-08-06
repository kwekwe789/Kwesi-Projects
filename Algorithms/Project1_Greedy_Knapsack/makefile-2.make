P1.exe: driveralg.o item.o 
	g++ driveralg.o item.o -o P1.exe
driveralg.o: driveralg.cpp
	g++ -g -c driveralg.cpp -o driveralg.o
item.o: item.cpp item.h
	g++ -g -c item.cpp -o item.o
pq.o: pq.cpp pq.h
	g++ -g -c pq.cpp -o pq.o

clean:
	rm *.o P1.exe