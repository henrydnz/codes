#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define rall(a) a.rbegin(),a.rend()
#define ll double

int main() {
    fastio;
    ll n, w, ans = 0, w_atual = 0; 
    cin>>n>>w;
    vector< pair<ll,ll> > items (n);

    for(int i=0; i<n; i++) {
        ll peso, valor;
        cin >> peso >> valor;
        items[i].first = valor/peso;
        items[i].second = peso;
    }
    
    sort(rall(items));
    
    for(int i=0; i<n; i++) {
        if ( w_atual + items[i].second <= w ) {
            w_atual += items[i].second;
            ans += items[i].first * items[i].second;
        }
        else {
            ll fraction = w - w_atual;
            ans += items[i].first * fraction;
            break;
        }
    }

    printf("%.2lf\n", ans);
    return 0;
}