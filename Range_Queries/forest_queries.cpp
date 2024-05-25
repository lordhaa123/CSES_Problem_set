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
#define ull unsigned long long
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

    int n,q;cin>>n>>q;
    vector<vector<int> > grid(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            char x;cin>>x;
            grid[i][j] = grid[i][j-1]+grid[i-1][j]-grid[i-1][j-1];
            if(x == '*') {
                grid[i][j]++;
            }
        }
    }
    
    while(q--) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<grid[x2][y2]-grid[x1-1][y2]-grid[x2][y1-1]+grid[x1-1][y1-1]<<endl;
    }

}


int main() {
    init_code(); 
    solve();
    return 0;
}
