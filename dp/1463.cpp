#include <cstdio>

using namespace std;

int dp[1000001];

int dyp(int n){
  if(n==1){
    return 0;
  }
  if(dp[n]>0) return dp[n];

  dp[n]=dyp(n-1)+1;

  if(n%3==0){
    int temp=dyp(n/3) +1;
    dp[n]=temp < dp[n] ? temp : dp[n];
  }
  if(n%2==0){
    int temp=dyp(n/2) +1;
    dp[n]=temp < dp[n] ? temp : dp[n];
  }
  return dp[n];
}

int main(){
  int N;
  scanf("%d",&N);

  dyp(N);

  printf("%d\n",dp[N]);

  return 0;
}
