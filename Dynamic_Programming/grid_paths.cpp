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

    int n;cin>>n;
    vector<vector<char> > grid(n,vector<char>(n));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    vector<vector<int> > dp(n,vector<int>(n,0));

    int flag_row = 1;
    for(int i=0;i<n;i++) {

        if(flag_row == 0) {
            dp[0][i] = 0;
        } else {
            if(grid[0][i] != '*') {
                dp[0][i] = 1;
            } else {
                dp[0][i] = 0;
                flag_row = 0;
            }
        }

    }

    int flag_col = 1;
    for(int i=0;i<n;i++) {

        if(flag_col == 0) {
            dp[i][0] = 0;
        } else {
            if(grid[i][0] != '*') {
                dp[i][0] = 1;
            } else {
                dp[i][0] = 0;
                flag_col = 0;
            }
        }

    }



    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            if(grid[i][j] == '.')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }

    cout<<dp[n-1][n-1]<<endl;

}


int main() {
    init_code(); 
    solve();
    return 0;
}
