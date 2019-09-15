#include <iostream>
#define DIV 10007
using namespace std;

int dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    dp[1]=1;
    dp[2]=3;

    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]*2;
        dp[i]%=DIV;
    }

    cout << dp[n]<<"\n";

    return 0;
}