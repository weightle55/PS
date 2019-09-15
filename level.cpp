#include <iostream>

using namespace std;

int dp[16];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dp[0]=2;

    int N;

    cin >> N;

    for(int i=1;i<16;i++){
        dp[i]= 2*dp[i-1]-1;
    }

    cout << dp[N]*dp[N]<<"\n";
    
   
    return 0;
}