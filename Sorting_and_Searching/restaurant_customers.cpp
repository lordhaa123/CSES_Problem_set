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

bool cust_compare(pair<int,int> a,pair<int,int> b) {
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    else return a.second > b.second;
}

void solve() {

    int n;cin>>n;
    vector<pair<int,int> > arr;

    for(int i=0;i<n;i++) {
        int start,end;cin>>start>>end;
        arr.push_back(make_pair(start,1));
        arr.push_back(make_pair(end,-1));
    }

    sort(arr.begin(),arr.end(),cust_compare);

    int curr = 0;
    int maxi = 0;

    for(uint i=0;i<arr.size();i++) {
        //cout<<arr[i].first<<"::::"<<arr[i].second<<endl;
        curr += arr[i].second;
        maxi = max(maxi,curr);
    }

    cout<<maxi<<endl;

}

int main() {
    init_code();
    solve();
    return 0;
}