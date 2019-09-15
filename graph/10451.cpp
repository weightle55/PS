#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

int graph[101][101];
int visited[101][101];

int main(){
  int N,M,cnt=0;
  scanf("%d%d",&N,&M);

  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      scanf("%1d",&graph[i][j]);
    }
  }

  deque<pair<int,int> > dq;
  dq.push_back(make_pair(1,1));
  visited[1][1]=1;

  while(!dq.empty()){
    int x=dq.front().second;
    int y=dq.front().first;
    int temp=visited[y][x];
    dq.pop_front();

    //down
    if(y<N && visited[y+1][x]==0 && graph[y+1][x]==1){
      dq.push_back(make_pair(y+1,x));
      visited[y+1][x]=temp+1;
      if(y==N-1 && x==M) break;
    }

    //right
    if(x<M && visited[y][x+1]==0 && graph[y][x+1]==1){
      dq.push_back(make_pair(y,x+1));
      visited[y][x+1]=temp+1;
      if(y==N && x==M-1) break;
    }

    //left
    if(x>1 && visited[y][x-1]==0 && graph[y][x-1]==1){
      dq.push_back(make_pair(y,x-1));
      visited[y][x-1]=temp+1;
    }

    //up
    if(y>1 && visited[y-1][x]==0 && graph[y-1][x]==1){
      dq.push_back(make_pair(y-1,x));
      visited[y-1][x]=temp+1;
    }

  }

  printf("%d\n",visited[N][M]);

  // for(int i=1;i<=N;i++){
  //   for(int j=1;j<=M;j++){
  //     printf("%d ",visited[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("\n");

  return 0;
}
