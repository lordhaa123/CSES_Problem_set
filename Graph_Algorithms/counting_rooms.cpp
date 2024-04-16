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

vector<pair<int,int> > dir(4);

void dfs(vector<string>& grid,int n, int m, int x, int y) {
    grid[x][y] = '9';
    
    for(int i=0;i<4;i++) {
        int dx = dir[i].first;
        int dy = dir[i].second;

        int newX = x+dx;
        int newY = y+dy;
        // cout<<newX<<" "<<newY<<endl;
        if(newX>=0 && newX<n && newY>=0 && newY<m) {
            if(grid[newX][newY] == '.') {
                // cout<<"qwerty"<<endl;
                // cout<<newX<<" "<<newY<<endl;
                dfs(grid,n,m,newX,newY);
            }
        }

    }

}

void solve() {

    int n,m;cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) {
        cin>>grid[i];
    }

    int count = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '.') {
                dfs(grid,n,m,i,j);
                // cout<<i<<"   "<<j<<endl;
                count++;
                // break;
            }
        }
        // if(i==1) break;
    }

    // for(int i=0;i<n;i++) {
    //     cout<<grid[i]<<endl;
    // }
 
    cout<<count<<endl;
}


int main() {
    init_code();
    dir[0] = make_pair(0,1);
    dir[1] = make_pair(1,0);
    dir[2] = make_pair(0,-1);
    dir[3] = make_pair(-1,0);
    solve();
    return 0;
}