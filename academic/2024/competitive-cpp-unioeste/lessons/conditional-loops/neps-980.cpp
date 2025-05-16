//https://neps.academy/br/exercise/980
//Camisetas da Olimpiada

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, peq = 0, med = 0, peqDid, medDid;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cami; cin >> cami; cami--;
        cami? med++: peq++;
    }
    
    cin >> peqDid; cin >> medDid;
    cout << ( (peqDid == peq && medDid == med)? "S": "N" ) << endl;
}