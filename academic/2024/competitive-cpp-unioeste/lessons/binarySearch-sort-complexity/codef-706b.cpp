//https://codeforces.com/problemset/problem/706/B
//Interesting Drink

//unfinished

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 10e5;
vector<int> prices (MAXN);
int n;

int ans(int coins) {
    for(int i=0; i<n; i++) 
        if(coins<prices[i])
            return i;
    return n;
}

signed main() {
    fastio;
    cin>>n;
    for(int i=0; i<n; i++) cin>>prices[i];
    sort(prices.begin(), prices.begin()+n);
    int q; cin>>q;
    for(int i=0; i<q; i++) {
        int coins;
        cin>>coins;
        cout<<ans(coins)<<"\n";
    }
    return 0;
}