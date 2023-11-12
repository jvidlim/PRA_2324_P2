/*   ____.                     ____   ____.__    .___      .__   
    |    | ____  ______ ____   \   \ /   /|__| __| _/____  |  |  
    |    |/  _ \/  ___// __ \   \   Y   / |  |/ __ |\__  \ |  |  
/\__|    (  <_> )___ \\  ___/    \     /  |  / /_/ | / __ \|  |__
\________|\____/____  >\___  >    \___/   |__\____ |(____  /____/
                    \/     \/                     \/     \/      */

#include <bits/stdc++.h>
using namespace std;

int P = 5;
vector<int> valores = {20, 15, 12, 10};
vector<int> pesos = {3, 2, 2, 1};
int elementos = valores.size();
vector<vector<int>> tabla (elementos, vector<int>(P, -1));

int solve(int i, int j){

	//cout << i << " : " << j << endl;
	if(i >= elementos) return 0;
	if(j < pesos[i]) return 0;
	if(j == 0) return valores[i];

	return tabla[i][j] = max(solve(i+1, j), valores[i] + solve(i+1, j-pesos[i]));
}


int main(){
	
	cout << solve(0, P) << endl;

	

	for(auto i : tabla){
		for(auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}

	

	return 0;
}
