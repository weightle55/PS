#include <cstdio>

using namespace std;

int dp[1500001][51];
int T[1500001];
int P[1500001];
int max[1500001];

int main(){
  int N;
  scanf("%d",&N);

  for(int i=1;i<=N;i++) scanf("%d%d",T+i,P+i);

  for(int i=1;i<=N;i++){
    if( (T[i]+i-1) <= N ){
      dp[T[i]+i-1][T[i]]=P[i];
    }
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N && j<=50;j++){
      if((i-j)>0){
        dp[i][j]+=max[i-j];
      }

      max[i]=dp[i][j] > max[i] ? dp[i][j] : max[i];
    }
  }

  printf("%d\n", max[N]);
  return 0;
}
