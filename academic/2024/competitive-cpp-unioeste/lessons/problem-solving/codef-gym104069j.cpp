//https://codeforces.com/gym/104069/problem/J
//Journey Through Time

//unfinished

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define all(a) a.begin(), a.end()

const ll sz=10e5;
vector<ll> arr;
ll ans[3][sz];

void answer() {
    ll t; cin>>t;

    for(ll i=0;i<t;i++) {
        int op; cin>>op;
        
        if(op==1){
            ll n; cin>>n;
            arr.push_back(n);
            ans[2][i]=ans[2][i-1]+n;
        }
        else if(op==2) {
            ll time;cin>>time;
            cout<<ans[0][time-1]<<"\n";
            ans[2][i]=ans[2][i-1];
        }
        else if(op==3) {
            ll time;cin>>time;
            cout<<ans[1][time-1]<<"\n";
            ans[2][i]=ans[2][i-1];
        }
        else {
            ll time;cin>>time;
            cout<<ans[2][time-1]<<"\n";
            ans[2][i]=ans[2][i-1];
        }

        ans[0][i]=*max_element(all(arr));
        ans[1][i]=*min_element(all(arr));
    }
}


int main() {
    fastio;
    answer();
    return 0;
}