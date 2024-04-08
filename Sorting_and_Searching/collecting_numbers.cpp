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

bool sortbysec(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
}

void solve() {

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    
    ll ans = 0;


    vector<int> idx(n+1);

    for(int i=0; i<n; i++) {
        idx[a[i]] = i;
    }


    for(int i=1;i<n;i++) {
        if(idx[i+1]<idx[i]) {
            ans++;
        }

    }

    cout<<ans+1<<endl;

}


int main() {
    init_code();
    solve();
    return 0;
}