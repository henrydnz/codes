//https://codeforces.com/problemset/problem/1930/A
//Maximise the Score

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define all(a) a.begin(), a.end()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void test() {
    int n, ans=0; cin>>n;
    vector<ll> board(2*n);

    for(auto& x:board) cin>>x;
    

    sort(all(board));

    do {
        int i=2*n-1;
        if (board[i]>=0) {
            ans+=min(board[i], board[i-1]);
            board[i] = -1;
        }
    } while (--n);
    cout<<ans<<"\n";
}

int main() {
    fastio;
    int t; cin>>t;
    while (t--) test();
    return 0;
}