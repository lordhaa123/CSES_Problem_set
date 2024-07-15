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
vector<int> vis(MAXN,0);
int ans;

void dfs(int s, int p){
    for (auto i: adj[s]){
        if (i!=p){
            dfs(i,s);
            if (!vis[i] && !vis[s]) ans++, vis[i]=1,vis[s]=1;
        }
    }
}
void solve(){
    int n; 
    cin>>n;
    ans = 0;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    cout<<ans<<endl;
}    


int main() {
    init_code(); 
    solve();
    return 0;
}
