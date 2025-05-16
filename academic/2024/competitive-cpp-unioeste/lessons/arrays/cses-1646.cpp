//https://cses.fi/problemset/task/1646
//Static Sum Range Queries

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

const ll n = 2*(1e5);
vector<ll> arr (n);

int main() {
 
    ll v, q; cin >> v >> q;
 
    for (ll i = 0; i < v; i++) {
        int a; cin >> a;
        arr[i+1]+=arr[i] + a;
    }

    while(q--) {
        int l, r; cin >> l >> r; l--;
        cout << arr[r] - arr[l] << endl;
    }
    
    return 0;
}