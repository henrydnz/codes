//https://neps.academy/br/exercise/236
//Quadrado Magico

#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 100

int m[MAX][MAX];

int isPerfect(int m[][MAX], int sz, int* ans) {
    int d1=0,d2=0;
    for(int i = 0; i < sz; i++) {
        int row=0,col=0;
        for(int j = 0; j < sz; j++) {
            row+=m[i][j];
            col+=m[j][i];
            d1+=(i==j)?m[i][j]:0;
            d2+=(i==sz-j-1)?m[i][j]:0;
        }
        if(row!=col) return 0;
        *ans=row;
    }
    return !(((*ans!=d1)||(*ans!=d2))||d1!=d2);
}

int main() {
    fastio;
    int sz, ans; cin>>sz;
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++)
            cin>>m[i][j];
    if(!isPerfect(m,sz,&ans)) ans=-1;
    cout<<ans<<"\n";
}