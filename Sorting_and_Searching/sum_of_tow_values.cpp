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
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    map<int,int> mp;
    bool flag = false;

    for(int i=0;i<n;i++) {
        if(!flag) {
            if(mp.find(x-arr[i]) != mp.end()) {
                cout<<i+1<<" "<<mp.find(x-arr[i])->second<<endl;
                return;
            } else {
                mp.insert(make_pair(arr[i],i+1));
            }
        }
    }



    cout<<"IMPOSSIBLE"<<endl;


}

int main() {
    init_code();
    solve();
    return 0;
}