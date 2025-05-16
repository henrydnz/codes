#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long

int main() {
    fastio;
    ll x, ans=0;
    cin>>x;
    for(ll i = 1; i<=x; i++) ans += i*3;
    ans -= x;
    cout<<ans<<"\n";
    return 0;
}