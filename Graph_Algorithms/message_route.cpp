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

void solve() {

    int n,m;cin>>n>>m;
    vector<vector<int> > grid(n,vector<int>());

    for(int i=0;i<m;i++) {
        int src,dest;cin>>src>>dest;

            grid[src-1].push_back(dest-1);
            grid[dest-1].push_back(src-1);

    }

    int start = 0;
    int end = n-1;
    vector<bool> vis(n,0);
    vector<int> dist(n,0);
    vector<int> parent(n,0);

    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int curr = q.front();q.pop();
        // cout<<curr<<endl;
        for(uint i=0;i<grid[curr].size();i++) {
            // cout<<i<<endl;
            int neigh = grid[curr][i];
            // cout<<neigh<<endl;
            if(!vis[neigh]){
                dist[neigh] = dist[curr] + 1;
                vis[neigh] = 1;
                parent[neigh] = curr;
                q.push(neigh);
            }
        }
    }

    // for(uint i=0;i<vis.size();i++) {
    //     cout<<vis[i]<<endl;
    // }

    if(!vis[end]) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    int val = dist[end]+1;

    vector<int> ans;

    for(int i=0;i<val;i++) {
        ans.push_back(end);
        end = parent[end];
    }

    reverse(ans.begin(),ans.end());

    cout<<val<<endl;
    for(uint i=0;i<ans.size();i++) {
        cout<<ans[i]+1<<" ";
    }



}


int main() {
    init_code(); 
    solve();
    return 0;
}
