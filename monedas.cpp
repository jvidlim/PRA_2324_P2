#include <iostream>
#include <vector>

using namespace std;


int min(int a, int b){
	if(a > b) return b;
	else return a;
}

vector<int> cambios(vector<int> monedas, int p, vector<vector<int>> &T){
	
	vector<int> sol (monedas.size(), 0);

	T[0][0] = 0;

	for(int j = 1; j<=p; j++){
		if(j >= monedas[0] && T[0][j-monedas[0]] != -1) T[0][j] = (1 + T[0][j - monedas[0]]);
	}

	for(int i = 1; i<monedas.size(); i++){
		T[i][0] = 0;
		for(int j = 1; j<=p; j++){
			if(j < monedas[i] || T[i][j-monedas[i]] == -1) T[i][j] = T[i-1][j];
			else if(T[i-1][j] != -1) T[i][j] = min(T[i-1][j], (1 + T[i][j-monedas[i]]));
			else T[i][j] = (1 + T[i][j-monedas[i]]);	
		}
	}

	int i = monedas.size()-1, j = p;

	while(i != 0 && j != 0){
		if(i == 0 || T[i][j] != T[i-1][j]){
			sol[i] = sol[i]+1;
			j -= monedas[i];
		}else i--;
	}

	return sol;	

}

int main(){	
	
	vector<int> monedas = {1, 4, 6};
	int p = 8;

	vector<vector<int>> T (monedas.size(), vector<int> (p+1, -1));
	
	vector<int> sol = cambios(monedas, p, T);

	for(auto i : T){
		for(auto j : i){
			cout << j << " ";
		}
		cout << "\n";
	}

	for(int i = 0; i<sol.size(); i++){
		cout << monedas[i] << ": " << sol[i] << endl;
	}




	return 0;
}
