//https://codeforces.com/problemset/problem/1909/A
//Distinct Buttons

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()

void ans(){
    int points; cin>>points;
    vector<int> x(points), y(points);
    for(int i=0;i<points;i++) cin>>x[i]>>y[i];
    sort(all(x)); sort(all(y));
    if(x[0]>=0) cout<<"yes\n";
    else if(x[points-1]<=0) cout<<"yes\n";
    else if(y[0]>=0) cout<<"yes\n";
    else if(y[points-1]<=0) cout<<"yes\n";
    else cout<<"no\n";
}
int main(){
    fastio;
    int t; cin>>t;
    while(t--) ans();
    return 0;
}