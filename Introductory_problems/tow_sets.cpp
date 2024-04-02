#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
    ll n;cin>>n;
    
    ll sum1 = 0;
    ll sum2 = 0;

    vector<ll> set1,set2;

    for(int i=n;i>=1;i--) {
        if(sum1<=sum2) {
            set1.push_back(i);
            sum1+=i;
        } else {
            set2.push_back(i);
            sum2+=i;
        }
    }
    if(sum1 != sum2) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<set1.size()<<endl;
    for(int i=0;i<set1.size();i++) {
        cout<<set1[i]<<" ";
    }
    cout<<endl<<set2.size()<<endl;
    for(int i=0;i<set2.size();i++) {
        cout<<set2[i]<<" ";
    }

    return;

}

int main() {
    init_code();
    solve();
    return 0;
}