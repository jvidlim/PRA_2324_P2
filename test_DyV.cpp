#include "DyV.h"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

int main(){

	vector<int> test = {1,2,3,4,5,6,7,8};
	sort(test.begin(), test.end());

	DyV<int> ctest;

	int k = 4;

	int pos = ctest.BusquedaBinaria(4, test, 0, test.size()-1);
	
	ctest.print(test);
	pos == -1 ? cout << "El elemento no se encuentra en el array\n" : cout << "El elemento se encuentra en la posición: " << pos << "\n";	
	
	reverse(test.begin(), test.end());
	pos = ctest.BusquedaBinaria_INV(4, test, 0, test.size()-1);
	ctest.print(test);
	pos == -1 ? cout << "El elemento no se encuentra en el array\n" : cout << "El elemento se encuentra en la posición: " << pos << "\n";	

	auto rng = default_random_engine {};
	

	cout << "\n\nQuicksort...\n";
	shuffle(test.begin(), test.end(), rng);
	ctest.print(test);
	ctest.QuickSort(test, 0, test.size()-1);
	cout << "Ordenando...\n";
	ctest.print(test);

	return 0;
}
