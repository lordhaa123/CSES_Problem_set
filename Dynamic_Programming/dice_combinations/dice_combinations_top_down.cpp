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

int helper(int n){ 
    if(n==0 || n==1) return 1;
    if(dp[n]!=0) return dp[n];

    for(int i=1;i<=6 && i<=n;i++) {
        dp[n] = (dp[n] + helper(n-i)) % MOD;
    } 
    return dp[n];
    
}

void solve() {

    int n;cin>>n;

    dp = vector<int>(n+1,0);
    // cout<<"hi"<<endl;
    cout<<helper(n);


}


int main() {
    init_code(); 
    solve();
    return 0;
}
