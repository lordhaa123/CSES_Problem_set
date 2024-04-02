#include <vector>
#include <iostream>
using namespace std;

#define ll long long
#define endl "\n"

#define MOD 1000000007
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

int main(){
    init_code();
    string s;cin>>s;
    int maxi = 1;
    int temp = 1;
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            temp++;
        }
        else{
            maxi = max(maxi, temp);
            temp = 1;
        }
    }
    maxi = max(maxi, temp);
    cout<<maxi<<endl;
}