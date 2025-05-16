//https://www.spoj.com/problems/BSEARCH1/
//BSEARCH1 - Binary Search

#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main() {
    fastio;
    ll n, q; cin >> n >> q;
    vector<ll> arr(n);
    for (ll& num: arr) cin >> num;

    while (q--) {
        ll l=0, r=n-1, ans= -1, s; cin >> s;
        while (l<=r) {
            ll m = (l+r)/2;
            if (arr[m]==s) ans=m;
            arr[m]>=s? r=m-1: l=m+1;
        }
        cout << ans << "\n";
    }
    return 0;
}   