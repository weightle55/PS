#include <cstdio>
#define Mod 1000000000

using namespace std;

int dp[10][101];

int main(){
  int N;
  scanf("%d",&N);

  for(int i=1;i<10;i++) dp[i][0]=1;

  for(int j=1;j<N;j++){
    for(int i=0;i<10;i++){
      if(i>0) dp[i][j] += dp[i-1][j-1];
      if(i<9) dp[i][j] += dp[i+1][j-1];
      dp[i][j] %= Mod;
    }
  }

  int result=0;
  for(int i=0;i<10;i++){
    result += dp[i][N-1];
    result %= Mod;
  }

  printf("%d\n",result);

  return 0;
}
