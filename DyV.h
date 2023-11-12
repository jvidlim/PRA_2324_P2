#ifndef DyV_H
#define DyV_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T> class DyV{

private:

	void swap(int &i, int &j){
		int temp = i;
		i = j;
		j = temp;
	}

	int Partition(vector<T> &V, int ini, int fin){
		T x = V[fin];
		int i = ini;
		for(int j = ini; j<fin-1; ++j){
			if(V[j] <= x){
				swap(V[i], V[j]);
				i++;	
			}
		}
		swap(V[i], V[fin]);
		return i;
	}

public:
	void print(vector<T> arr){
		for(int i = 0; i<arr.size(); ++i){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	T BusquedaBinaria(T X, vector<T> V, int ini, int fin){
		if(ini > fin){
			return -1;
		}
		int medio = (ini+fin)/2;
		if(V[medio] == X) return medio;
		else if(V[medio] > X) return BusquedaBinaria(X, V, ini, medio-1);
		else return BusquedaBinaria(X, V, medio+1, fin);
	}

	T BusquedaBinaria_INV(T X, vector<T> V, int ini, int fin){
		if(ini > fin){
			return -1;
		}
		int medio = (ini+fin)/2;
		if(V[medio] == X) return medio;
		else if(V[medio] > X) return BusquedaBinaria_INV(X, V, medio+1, fin);
		else return BusquedaBinaria_INV(X, V, ini, medio-1);
	}

	void QuickSort(vector<T> &V, int ini, int fin){
		if(ini < fin){
			int pivot = Partition(V, ini, fin);
			QuickSort(V, ini, pivot-1);
			QuickSort(V, pivot+1, fin);
		}
	}

	

};


#endif
