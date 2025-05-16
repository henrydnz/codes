//https://codeforces.com/gym/104344/problem/G
//Presentes da Pascoa

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()

int main() {
    fastio;
    int eggCnt, cents; cin >> eggCnt >> cents;
    vector<int> prices (eggCnt);
    for(int& i:prices) cin >> i;
    sort(all(prices));
    int counter = 0;
    for(int i:prices) if(cents>=i) { cents-=i; counter++; }
    cout << counter << "\n";
    return 0;
}