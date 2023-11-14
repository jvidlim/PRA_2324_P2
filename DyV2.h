#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename T> class bb{
	public: 

	T BusquedaBinaria(T x, vector<T>& v, int ini, int fin) {
		if(ini > fin){ cout << "No se encuentra en el array\n"; return -1;}
		
		int medio = (ini+fin)/2;
		if(v[medio] == x)return medio;
		else if(v[medio] > x)return BusquedaBinaria(x,v,ini,medio-1);
		else return BusquedaBinaria(x,v,medio+1,fin);
	}

	T BusquedaBinaria_INV(T x, vector<T>& v, int ini, int fin){
		if(ini > fin){ cout << "No se encuentra en el array\n"; return -1;}
		
		int medio = (ini+fin)/2;
		if(v[medio] == x)return medio;
		else if(v[medio] > x)return BusquedaBinaria_INV(x,v,medio+1,fin);
		else return BusquedaBinaria_INV(x,v,ini,medio-1);
	}

	void print(vector<T> &v, int size){
		for(int i = 0; i < size; i++)cout << v[i] << " ";
	       cout << endl;	
	}

	void swap(vector<T> &a, int x, int y){
		int aux = a[x];
		a[x] = a[y];
		a[y] = aux;
	}

	//Partition aprendida en clase de teorÃ­a
	/*
	int partition_ini(vector<T> &a, int ini, int fin){
		T p = a[ini];
		int i = ini;
		int j = fin;
	
		do{
			for(int k = 0; a[i] <= p && i < fin;k++)i++;
			for(int k = 0; a[j] >= p && j > ini; k++)j--;
			swap(a,i,j);
		}while(i<j);
		swap(a,i,j);
		swap(a,ini,j);
		return j;
	}*/

	int partition_ini(vector<T> &a, int ini, int fin){
		T p = a[ini];
		int i = ini;
		int j;
		for(j = ini; j <= fin; j++){
			if(a[j] < p){
				swap(a,i,j);
				if(i == ini)ini = j;
				i++;
			} 
		}
		swap(a,i,ini);
		return i;
	}

	//Partition aprendida en clase de prÃ¡ctica
	int partition_fin(vector<T> &a, int ini, int fin){
		T p = a[fin];
		int i = ini;
		int j;
		for(j = ini; j < fin; j++){
			if(a[j] <= p){
				swap(a,i,j);
				i++;
			} 
		}
		swap(a,i,fin);
		return i;
	} 

	int partition_mid(vector<T> &a, int ini, int fin){
		int mid = (ini + (fin-ini))/2;
		T p = a[mid];
		int i = ini;
		int j;
		for(j = ini; j <= fin; j++){
			if(a[j] < p){
				swap(a,i,j);
				if(i == mid) mid = j;
				i++;
			} 
		}
		swap(a,i,mid);
		return i;
	}

	int partition_rand(vector<T> &a, int ini, int fin){
		int rnd = ini + rand() % (fin+1-ini);
		T p = a[rnd];
		int i = ini;
		int j;
		for(j = ini; j <= fin; j++){
			if(a[j] < p){
				swap(a,i,j);
				if(i == rnd)rnd = j;
				i++;
			} 
		}
		swap(a,i,rnd);
		return i;
	}

	void quickSort_ini(vector<T> &a, int ini, int fin){
		int tam = fin - ini + 1;
		if(tam > 1){
			int s = partition_ini(a,ini,fin);
			
			quickSort_ini(a,ini,s);
			quickSort_ini(a,s+1,fin);
		}else return;
	}

	void quickSort_fin(vector<T> &a, int ini, int fin){
		int tam = fin - ini + 1;
		if(tam > 1){
			int s = partition_fin(a,ini,fin);
			//print(a,tam);
			quickSort_fin(a,ini,s-1);
			quickSort_fin(a,s+1,fin);
		}else return;
	}

	void quickSort_mid(vector<T> &a, int ini, int fin){
		int tam = fin - ini + 1;
		if(tam > 1){
			int s = partition_mid(a,ini,fin);
			//print(a,tam);
			quickSort_mid(a,ini,s-1);
			quickSort_mid(a,s+1,fin);
		}else return;
	}

	void quickSort_rand(vector<T> &a, int ini, int fin){
		int tam = fin - ini + 1;
		if(tam > 1){
			int s = partition_rand(a,ini,fin);
			//print(a,tam);
			quickSort_rand(a,ini,s-1);
			quickSort_rand(a,s+1,fin);
		}else return;
	}
};

#endif