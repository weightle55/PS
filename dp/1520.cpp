#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int M,N;
int map[501][501];
int dp[501][501];

int row[4]={0,0,1,-1};
int col[4]={1,-1,0,0};

int dfs(int x,int y){
  //refer to prev memo
  if(dp[x][y] != -1) return dp[x][y];
  //out of range
  if(x<1 || y<1 || x>M || y>N) return 0;
  //start point
  if(x==1 && y==1) return 1;

  //visited
  dp[x][y]=0;

  for(int i=0;i<4;i++){
    int px=x+row[i];
    int py=y+col[i];
    if(map[px][py]>map[x][y]) dp[x][y]+= dfs(px,py);
  }

  return dp[x][y];

}

int main(){
  scanf("%d%d",&M,&N);

  for(int i=1;i<=M;i++){
    for (int j=1;j<=N;j++) scanf("%d",&map[i][j]);
  }

  memset(dp,-1,sizeof(dp));

  int result = dfs(M,N);
  printf("%d\n",result);
  return 0;
}
