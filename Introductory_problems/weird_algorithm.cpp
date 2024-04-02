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
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(!(n==1))
    {
        if(n%2==0)
        {
            n=n/2;
            cout<<n<<" ";
        }
        else
        {
            n=n*3+1;
            cout<<n<<" ";
        }    
    }
}