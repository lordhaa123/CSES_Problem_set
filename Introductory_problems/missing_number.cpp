#include <vector>
#include <iostream>
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
int main() {
    init_code();
    int n;cin >> n;
    int res = 0;
    for(int i=1; i<=n-1; i++){
        int x;cin>>x;
        res ^= x;
        res ^= i;
    }
    res ^= n;
    cout<<res<<endl;

}