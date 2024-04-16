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

void dfs(vector<vector<int> > &grid, vector<bool> &vis, vector<int> &color,int curr,int cc,bool &flag) {
    color[curr] = cc;
    for(uint i = 0; i < grid[curr].size();i++) {
        int neigh = grid[curr][i];
        // cout<<neigh<<endl;
        if(color[neigh] == cc) {
            flag = false;
        }
        if(vis[neigh] == 0) {
            vis[neigh] = 1;
            dfs(grid,vis,color,neigh,cc^1,flag);
        }
    }
}

void solve() {

    int n,m;cin >> n >> m;

    vector<vector<int> > grid(n,vector<int>());

    vector<int> color(n,-1);

    bool flag = true;

    for(int i=0;i<m;i++) {
        int src,dest;cin>>src>>dest;
        grid[src-1].push_back(dest-1);
        grid[dest-1].push_back(src-1);
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<grid[i].size();j++ ) {
    //         cout << grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl;

    vector<bool> vis(n);

    int cc = 0;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(grid,vis,color,i,cc,flag);
        }
    }

    if(!flag) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i=0;i<n;i++) {
        cout<<color[i]+1<<" ";
    }

    return;
}


int main() {
    init_code(); 
    solve();
    return 0;
}
