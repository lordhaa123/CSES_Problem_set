#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <cstring>
#include <bitset>
#include <limits.h>
#include <string.h>
#include <stdio.h>

using namespace std;

#define MAXN 9999999
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

void init_code() {
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}

vector<vector<int> > adj(MAXN);

vector<int> subTreeSize(MAXN);

int helper(int node) {

    if(adj[node].size() == 0) {
        return 1;
    } else {
        for(int i = 0; i < adj[node].size();i++) {
            subTreeSize[node] += helper(adj[node][i]);
        }
    }
    return subTreeSize[node]+1;

}

void solve() {

    int n;cin>>n;

    for(int i=2;i<=n;i++) {
        int x;cin>>x;
        adj[x].push_back(i);
    }

    helper(1);

    for(int i=1;i<=n;i++) {
        cout<<subTreeSize[i]<<" ";
    }

}


int main() {
    init_code(); 
    solve();
    return 0;
}
