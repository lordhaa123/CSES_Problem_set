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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int left=0,right=0;

    map<int,int> mp;

    int maxi = 0;
    for(;right<n && left<n;) {
        //cout<<left<<":"<<right<<":"<<maxi<<endl;
        if(mp[arr[right]] == 0) {
            //cout<<mp[arr[right]]<<endl;
            mp[arr[right]]++;
            maxi = max(maxi,right-left + 1);
            right++;
        } else {
            mp[arr[left]]--;
            left++;
        }
    }

    cout<<max(maxi,right-left)<<endl;

}

int main() {
    init_code();
    solve();
    return 0;
}