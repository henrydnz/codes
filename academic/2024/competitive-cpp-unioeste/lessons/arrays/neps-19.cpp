//https://neps.academy/br/exercise/19
//Botas Trocadas

#include <bits/stdc++.h>
using namespace std; 

int main() {
    
    int n, d_cnt = 0, e_cnt = 0; cin >> n;
    int e[n], d[n];
    
    for(int i = 0; i < n; i++) {
        int a; char b;
        cin >> a >> b;
        if (b - 68) e[e_cnt++] = a;     // D - 68 = 0, E - 68 = 1
        else d[d_cnt++] = a;
    }

    sort(d, d + d_cnt, greater<int>());
    sort(e, e + e_cnt, greater<int>());

    int sum = 0;
    for (int i = 0, j = 0; i < d_cnt && j < e_cnt; ) {
        if (d[i] == e[j]) { 
            sum++; 
            i++; 
            j++;
        }
        else if (d[i] > e[j]) i++;
        else j++;
    }
    cout << sum << endl;
    return 0;
}