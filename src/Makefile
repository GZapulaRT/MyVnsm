Main: System.o Flow.o Model.o Main.cpp
	g++ System.o Flow.o Model.o Main.cpp -o Main

System.o: System.cpp
	g++ -c System.cpp -o System.o 

Flow.o: Flow.cpp
	g++ -c Flow.cpp -o Flow.o 

Model.o: Model.cpp
	g++ -c Model.cpp -o Model.o 

clean:
	rm -rf *.o Main