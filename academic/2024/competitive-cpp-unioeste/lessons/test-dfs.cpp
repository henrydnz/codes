#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
vector<int> graph[MAXN];
vector<int> visited(MAXN);
vector<int> vec(MAXN);

void dfs(int v) {

    visited[v] = 1;
    vec.push_back(v);

    if(graph[v].empty()) 
        cout << "no connections. returning.\n";
    else
        for(auto u: graph[v]) {
            cout << "graph of " << v << ". will try " << u << ".\n";
            if(!visited[u]) {
                dfs(u);
            }
            else
                cout << "already visited. returning.\n";
        }
}

int main() {

    int n; cin >> n;

    for(int i = 0; i < n; i++){ 
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1);

    cout << "visited all. Numbers are:  ";

    for(int i = n-1; i >= 0; i--)
        cout << vec[MAXN-i] << "  ";
    return 0;
}