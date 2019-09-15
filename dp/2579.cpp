#include <cstdio>

using namespace std;

int arr[301];
int dp[301][2];

int main(){
  int N;

  scanf("%d",&N);

  for(int i=1;i<=N;i++){
    scanf("%d",arr+i);
  }

  for(int i=1;i<=N;i++){
    if(i==1){
      dp[i][0]=arr[i];
    }
    else if(i==2){
      dp[i][0]=dp[i-1][0]+arr[i];
      dp[i][1]=arr[i];
    }
    else{
      dp[i][0]=dp[i-1][1]+arr[i];
      dp[i][1]=dp[i-2][0]>dp[i-2][1] ? dp[i-2][0] : dp[i-2][1];
      dp[i][1]+=arr[i];
    }
  }

  int result = dp[N][0] > dp[N][1] ? dp[N][0] : dp[N][1];
  printf("%d\n",result);

  return 0;
}
