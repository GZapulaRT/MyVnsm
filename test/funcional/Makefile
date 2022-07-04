Funcional: Main.cpp Exponencial.o Logistico.o Complexo.o Perda.o Ganho.o System.o Flow.o Model.o Troca.o 
	g++ Main.cpp Exponencial.o Logistico.o Complexo.o Perda.o Ganho.o Troca.o ../../src/System.o ../../src/Flow.o ../../src/Model.o -o Funcional

Exponencial.o: Exponencial.cpp
	g++ -c Exponencial.cpp -o Exponencial.o

Logistico.o: Logistico.cpp
	g++ -c Logistico.cpp -o Logistico.o

Complexo.o: Complexo.cpp
	g++ -c Complexo.cpp -o Complexo.o

Perda.o: Perda.cpp
	g++ -c Perda.cpp -o Perda.o

Ganho.o: Ganho.cpp
	g++ -c Ganho.cpp -o Ganho.o

Troca.o: Troca.cpp
	g++ -c Troca.cpp -o Troca.o	

System.o: ../../src/System.cpp
	g++ -c ../../src/System.cpp -o ../../src/System.o

Flow.o: ../../src/Flow.cpp
	g++ -c ../../src/Flow.cpp -o ../../src/Flow.o

Model.o: ../../src/Model.cpp
	g++ -c ../../src/Model.cpp -o ../../src/Model.o	

clean:
	rm -rf *.o Funcional