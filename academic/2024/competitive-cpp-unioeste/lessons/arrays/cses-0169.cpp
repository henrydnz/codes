//https://cses.fi/problemset/task/1069
//Repetitions

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    vector<int> x;
    int c = 1;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i+1] == s[i])
            c++;
        else {
            x.push_back(c);
            c = 1;
        }
    }
    cout << *max_element(x.begin(), x.end()) << endl;
}