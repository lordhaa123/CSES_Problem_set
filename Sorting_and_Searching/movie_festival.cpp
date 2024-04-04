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

    vector<pair<int,int> > arr;

    for(int i=0;i<n;i++) {
        int a,b;cin>>a>>b;
        arr.push_back(make_pair(a,b));
    } 

    sort(arr.begin(),arr.end(),sortbysec);

    // for(int i=0;i<n;i++) {
    //     cout<<arr[i].first<<":::"<<arr[i].second<<endl;
    // }

    int ans=0;
    int curr = 0;
    for(int i=0;i<n;i++) {
        if(curr<=arr[i].first) {
            ans++;
            curr = arr[i].second;
        }
    }

    cout<<ans<<endl;

}

int main() {
    init_code();
    solve();
    return 0;
}