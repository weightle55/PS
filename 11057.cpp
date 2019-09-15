#include <cstdio>

using namespace std;

int dp[10][1000];

int main(){
  int N;
  scanf("%d",&N);

  for(int i=0;i<10;i++) dp[i][0]=1;

  for(int i=1;i<N;i++){
    int sum=0;
    for(int j=0;j<10;j++){
      sum += dp[j][i-1];
      dp[j][i] = sum % 10007;
    }
  }

  int result=0;
  for(int i=0;i<10;i++){
    result += dp[i][N-1];
    result %= 10007;
  }

  printf("%d\n",result);
  
  return 0;
}
