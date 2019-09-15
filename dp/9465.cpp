#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[100001][2];
int dp[100001][3];

int main(){
    int T;

    scanf("%d",&T);
    for(;T>0;T--){
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));

        int N;
        scanf("%d",&N);
        for(int i=0;i<2*N;i++){
            scanf("%d",&arr[i%N][i/N]);
        }

        dp[0][0]=arr[0][0];
        dp[0][1]=arr[0][1];
        dp[0][2]=0;

        for(int i=1;i<N;i++){
            dp[i][0]=max(dp[i-1][1],dp[i-1][2])+arr[i][0];
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+arr[i][1];
            dp[i][2]=max(dp[i-1][0],dp[i-1][1]);
        }

        printf("%d\n", max(dp[N-1][0],max(dp[N-1][1],dp[N-1][2])));
    }
    return 0;
}