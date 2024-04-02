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

vector<bool> col(8,false),diag1(8,false),diag2(8,false);

void nqueens(vector<string> &grid,int &ans,int r) {
    if(r==8) {
        ans++;
        return;
    }
    for(int i=0;i<8;i++) {
        if(grid[r][i] == '.') {
            if (!col[i] && !diag1[r - i + 8 - 1] && !diag2[r + i])
            {
                col[i] = diag1[r - i + 8 - 1] = diag2[r + i] = true;
                nqueens(grid, ans, r+1);
                col[i] = diag1[r - i + 8 - 1] = diag2[r + i] = false;
            }
        }
    }
}

void solve() {

    vector<string> grid;
    for(int i=0;i<8;i++) {
        string temp;cin>>temp;
        grid.push_back(temp);
    }

    int ans = 0;

    nqueens(grid,ans,0);

    cout<<ans<<endl;


}

int main() {
    init_code();
    solve();
    return 0;
}