#include <iostream>
#include <climits>
#include <vector>
#include <deque>

using namespace std;

struct edge{
  int weight;
  int dest;
};

struct Nodes{
  int value;
  bool visited;
  vector<edge> e;
};

struct Nodes node[20001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V,E,start;
  int u,v,w;

  cin >> V >> E >> start;

  for(int i=1;i<=V;i++){
    node[i].value = INT_MAX;
    node[i].visited = false;
  }

  node[start].value = 0;


  for(int i=0;i<E;i++){
    cin >> u >> v >> w;
    struct edge ed;
    ed.weight=w;
    ed.dest = v;
    node[u].e.push_back(ed);
  }

  deque<int> dq;

  dq.push_back(start);

  while(!dq.empty()){
    int temp = dq.front();
    dq.pop_front();

    node[temp].visited = true;

    for(int i=0;i<node[temp].e.size();i++){
      int next = node[temp].e[i].dest;
      int weig = node[temp].e[i].weight;
      if(node[next].value > node[temp].value + weig){
        node[next].value = node[temp].value + weig;
      }
      dq.push_back(next);
    }

  }

  for(int i=1;i<=V;i++){
    int result = node[i].value;
    if(result == INT_MAX) cout << "INF" << "\n";
    else cout << result << "\n";
  }

  return 0;
}
