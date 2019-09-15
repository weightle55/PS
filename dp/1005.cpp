#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

int btime[1001];
vector<int> graph[1001];
int indegree[1001];
int node[1001];

void tsort(int N){
  deque<int> dq;
  while(dq.size()<N){
    for(int i=1;i<=N;i++){
      if(indegree[i]==0){
        indegree[i]=-1;
        dq.push_back(i);
        for(int j=0;j<graph[i].size();j++){
          int tmp=graph[i][j];
          node[tmp]=max(node[tmp],node[i]+btime[tmp]);
          indegree[tmp]--;
        }
      }
    }
  }
}

int main(){
  int T;
  scanf("%d",&T);
  for(;T>0;T--){
    int N,K,win;
    scanf("%d%d",&N,&K);
    memset(indegree,0,sizeof(indegree));
    memset(node,0,sizeof(node));
    memset(btime,0,sizeof(btime));
    
    for(int i=1;i<=N;i++) scanf("%d",btime+i);
    for(int i=0;i<K;i++){
      int u,v;
      scanf("%d%d",&u,&v);
      graph[u].push_back(v);
      indegree[v]++;
    }
    scanf("%d",&win);

    for(int i=1;i<=N;i++) node[i]=btime[i];

    tsort(N);

    printf("%d\n",node[win]);

    for(int i=1;i<=N;i++) graph[i].clear();
  }
  return 0;
}
