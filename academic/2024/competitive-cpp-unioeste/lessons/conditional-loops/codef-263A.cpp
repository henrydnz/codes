//https://codeforces.com/problemset/problem/263/A
//Beautiful Matrix

#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int main(){
    fastio;
    int mtrx[5][5];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> mtrx[i][j];
            if (mtrx[i][j] == 1) {
                int value = abs(i - 2) + abs(j - 2);
                cout << value << endl;
            }
        }
    }
    return 0;
}