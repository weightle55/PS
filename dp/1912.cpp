#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[100000][2];

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",arr+i);
    
    dp[0][1]=arr[0];
    dp[0][0]=-0x3f3f3f3f;

    for(int i=1;i<N;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = max(arr[i],dp[i-1][1]+arr[i]);
    }

    // for(int i=0;i<N;i++) printf("%d ",dp[i][0]);
    // printf("\n");
    // for(int i=0;i<N;i++) printf("%d ",dp[i][1]);
    // printf("\n");

    printf("%d\n",max(dp[N-1][0],dp[N-1][1]));
    return 0;
}