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

class DSU {
    public:
        vector<int> parent;
        
        DSU(int n) {
            parent = vector<int>(n);
            for(int i=0;i<n;i++) {
                parent[i] = i;
            }
        }

        void make_set(int v) {
            parent[v] = v;
        }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
            return true;
        }
        return false;
    }

};

vector<int> parent;
vector<int> vis;

void dfs(vector<vector<int> > &grid,int src)  {

    for(uint i=0;i<grid[src].size();i++) {
        int neigh = grid[src][i];
        // cout<<src<<":::"<<neigh<<endl;
        if(vis[neigh] == 0) {
            vis[neigh] = 1;
            parent[neigh] = src;
            dfs(grid,neigh);
        }
    }

}

void solve() {

    int n,m;cin >> n >> m;

    vector<vector<int> > grid(n,vector<int>());

    DSU dsu(n);
    vector<int> ans;
    parent = vector<int>(n,-1);
    vis=vector<int>(n,0);
    bool flag = false;
    for(int i=0;i<m;i++) {
        int src,dest;cin>>src>>dest;

        grid[src-1].push_back(dest-1);
        grid[dest-1].push_back(src-1);
        
        if(!dsu.union_sets(src-1,dest-1)){
            flag = true;
            vis[src-1] = 1;

            dfs(grid,src-1);
            int u = dest-1;
            while(u!=-1) {
                ans.push_back(u);
                u=parent[u];
            }
            break;
        }
    }

    if(flag){
        cout<<ans.size()+1<<endl;
        for(uint i=0;i<ans.size();i++) {
            cout<<ans[i]+1<<" ";
        }
        cout<<ans[0]+1<<" ";
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }


    return;
}


int main() {
    init_code(); 
    solve();
    return 0;
}
