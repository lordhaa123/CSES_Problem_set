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

vector<int> dp;

int helper(vector<int> coins,int sum,int n) {

    if(sum == 0) return 1;
    if(sum<0) return 0;
    if(dp[sum]!=0) return dp[sum];

    for(int i=0;i<n;i++) {
        

        dp[sum] = (dp[sum] + helper(coins,sum-coins[i],n)) % MOD;

    }
    
    return dp[sum];

}


void solve() {

    int n,x;cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }

    dp = vector<int>(x+1,0);

    cout<<helper(coins,x,n)<<endl;


}


int main() {
    init_code(); 
    solve();
    return 0;
}
