#include <iostream>
#include <cstring>
#include <climits>
#include <deque>
using namespace std;

int edge[20001][20001];
int node[20001];
bool visited[20001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V,E,start;

  cin >> V >> E >> start;

  for(int i=1;i<=V;i++){
    node[i]=INT_MAX;
  }

  for(int i=0;i<E;i++){
    int u,v,w;
    cin >> u >> v >> w;
    edge[u][v] = w;
  }

  node[start] = 0;

  deque<int> dq;

  dq.push_back(start);

  while(!dq.empty()){
    int temp = dq.front();
    dq.pop_front();
    visited[temp] = true;

    for(int i=1;i<=V;i++){
      if(edge[temp][i] != 0 && visited[i]==false){
        node[i]=node[i] < node[temp]+edge[temp][i] ? node[i] : node[temp]+edge[temp][i];
        dq.push_back(i);
      }
    }
  }

  for(int i=1;i<=V;i++){

    if(node[i] != INT_MAX) cout << node[i] << "\n";
    else cout << "INF" << "\n";
  }

  return 0;
}
