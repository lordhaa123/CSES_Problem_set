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

//tower of hanoi code 
void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << from << " " << to << endl;
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    tower_of_hanoi(n - 1, aux, to, from);
}

void solve(){
    int n;cin>>n;
    cout<<(1<<n)-1<<endl;

    tower_of_hanoi(n, '1', '3', '2');

}

int main() {
    init_code();
    solve();
    return 0;
}