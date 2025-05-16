//https://codeforces.com/gym/104545/problem/C
//Coffe Break

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long

ll arr[500][500],n, m, maior=0;

bool check(ll x1, ll y1, ll x2, ll y2) {
    for(ll i=x1;i<=x2;i++)
        for(ll j=y1;j<=y2;j++)
            if(!arr[i][j]) return false;
    return true;
}

int main() {
    fastio;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];

    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            for(ll k=i;k<n;k++)
                for(ll l=j;l<m;l++)
                    if(check(i,j,k,l)) {
                        ll size=(k-i+1)*(l-j+1);
                        maior=max(maior,size);
                    }

    cout<<maior<<"\n";
    return 0;
}   