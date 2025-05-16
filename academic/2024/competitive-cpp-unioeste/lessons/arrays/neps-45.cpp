//https://neps.academy/br/exercise/45
//Torre

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

vector< pair<int,int> > sum (1000);

int main() {
    fastio;

    int n; cin>>n;
    int board[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>board[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            sum[i].first+=board[i][j];
            sum[j].second+=board[i][j];
        }

    int ans=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            int s = sum[i].first + sum[j].second - 2*board[i][j];
            ans = max(ans, s);
        }

    cout<<ans<<"\n";
    
}