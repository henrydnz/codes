//https://www.spoj.com/problems/UPDATEIT/
//UPDATEIT - Update the array!

//unfinished

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void update(vector<int>& v) {
    int l,r,val;
    cin>>l>>r>>val;
    for(int i=l;i<=r;i++)
        v[i]+=val;
}

void test() {
    int sz, upd, qrr;
    cin>>sz>>upd;
    vector<int> v (sz);

    while(upd--)
        update(v);
    
    cin>>qrr;
    while(qrr--) {
        int i; cin>>i;
        cout<<v[i]<<"\n";
    }
}

int main() {
    fastio;
    int t; cin>>t;
    while(t--)
        test();
    return 0;
}