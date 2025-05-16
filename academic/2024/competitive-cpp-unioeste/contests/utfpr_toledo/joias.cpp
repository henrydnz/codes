#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
int main() {
    fastio;
    int sz; cin>>sz;
    int s1, s2, t1, t2;
    cin>>s1>>s2>>t1>>t2;
    int ans = abs(s1-t1) + abs(s2-t2);
    cout<<ans<<"\n";
    return 0;
}