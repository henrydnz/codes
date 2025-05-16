//https://neps.academy/br/exercise/159
//Soma dos Elementos

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, num, soma = 0; cin >> a;
    while (a != 0) {        
        cin >> num;
        soma = soma + num;
        a--;
    }
    cout << soma << endl;
}


