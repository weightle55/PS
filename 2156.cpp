#include <cstdio>
#include <algorithm>
using namespace std;

int dp[10001][2];
int wine[10001];

int main(){
    int N;

    scanf("%d",&N);

    for(int i=1;i<=N;i++){
        scanf("%d",wine+i);
    }

    dp[1][0]=wine[1];
    dp[1][1]=wine[1];

    for(int i=2;i<=N;i++){
        dp[i][0]=wine[i]+dp[i-1][1];
        dp[i][1]=wine[i]+max(dp[i-2][0],dp[i-2][1]);
    }

    printf("%d\n",max(max(dp[N][0],dp[N][1]),max(dp[N-1][0],dp[N-1][1])));

    for(int i=0;i<2;i++){
        for(int j=1;j<=N;j++){
            printf("%5d ",dp[j][i]);
        }
        printf("\n");
    }
    return 0;
}