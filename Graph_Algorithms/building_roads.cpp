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

void dfs(vector<vector<int> > &grid, vector<int> &vis,int start,int val) {
    vis[start] = val;
    for(uint i=0;i<grid[start].size();i++) {
        int neigh = grid[start][i];
        //cout<<neigh<<endl;
        if(vis[neigh] == -1) {
            dfs(grid,vis,neigh,val);
        }
    }
}

void solve() {
    int n,m;cin>>n>>m;

    vector<vector<int> > grid(n,vector<int>());
    //cout<<"qwr"<<endl;

    for(int i=0;i<m;i++) {

        int src,dest;cin>>src>>dest;

        grid[src-1].push_back(dest-1);
        grid[dest-1].push_back(src-1);

    }

    vector<int> vis(n,-1);

    for(int i=0;i<n;i++) {
        if(vis[i] == -1) {
            dfs(grid,vis,i,i);
        }
    }
    vector<int> res;
    set<int> st;
    for(int i=0;i<n;i++) {
        if(st.find(vis[i]) == st.end()) {
            res.push_back(vis[i]);
            st.insert(vis[i]);
        }
    }

    cout<<res.size()-1<<endl;
    for(uint i=0;i<res.size()-1;i++) {
        cout<<res[i]+1<<" "<<res[i+1]+1<<endl;
    }
    //cout<<"qwe"<<endl;
    return;
}


int main() {
    init_code(); 
    solve();
    return 0;
}
