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

    int n,x;cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }

    vector<int> dp(x+1,0);

    dp[0] = 1;

    for(int i=1;i<=x;i++) {
        for(int j=0;j<n;j++) {
            if(coins[j]<=i) {
                dp[i] = (dp[i] + dp[i-coins[j]])%MOD;
            }
        }
    }

    cout<<dp[x]<<endl;

}


int main() {
    init_code(); 
    solve();
    return 0;
}
