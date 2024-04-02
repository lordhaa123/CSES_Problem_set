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

    string s;cin>>s;
    map<char,int> mp;
    
    for(int i=0;i<s.length();i++) {
        mp[s[i]]++;
    }

    string ans = "";

    string odd = "";

    for(map<char,int>::iterator it = mp.begin();it != mp.end();it++) {
        if(it->second%2 == 0) {
            for(int i=0;i<it->second/2;i++) {
                //cout<<it->first<<endl;
                ans += it->first;
            }
            it->second/=2;
        } else {
            for(int i=0;i<it->second/2;i++) {
                ans += it->first;
            }
            if(odd != "") {
                cout<<"NO SOLUTION"<<endl;
                return;
            }
            odd = it->first;
            it->second--;
        }
    }

    string rev = ans;
    reverse(rev.begin(),rev.end());
    ans += odd;
    ans += rev;

    cout<<ans<<endl;

}

int main() {
    init_code();
    solve();
    return 0;
}