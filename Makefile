bin/all: test_DyV.cpp DyV.h monedas.cpp mochila.cpp
	mkdir -p bin
	g++ -o bin/monedas monedas.cpp
	g++ -o bin/mochila mochila.cpp
	g++ -o bin/test_DyV test_DyV.cpp DyV.h

clean:
	rm -r bin
