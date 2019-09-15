#include <iostream>
#include <queue>
#include <deque>
#include <climits>
using namespace std;

struct Nodes{
  int dist;
  deque<pair<int,int> > edge;
  bool operator<(struct Nodes a) const{
    if(dist<a.dist) return true;
    else return false;
  }
};

struct Nodes node[20001];

int main(){
  ios_base::sync_with_stdio(false);

  int V,E,start;
  int u,v,w;

  priority_queue<pair<struct Nodes,int> > que;
  cin >> V >> E >> start;

  for(int i=1;i<=E;i++){
    cin >> u >> v >>w ;
    node[u].edge.push_back(make_pair(v,w));
  }

  for(int i=1; i<=V; i++){
    node[i].dist=INT_MAX;
  }

  node[start].dist=0;
  que.push(make_pair(node[start],start));

  while(!que.empty()){
    int temp = que.top().second;
    que.pop();
    int minimum=INT_MAX;
    for(int i=0;i<node[temp].edge.size();i++){
      int cur=node[temp].edge[i].first;
      int value = node[temp].edge[i].second;
      if(node[cur].dist>node[temp].dist+value){
        node[cur].dist = node[temp].dist + value;
        if(minimum>cur){
          minimum=cur;
        }
      }
    }
    if(minimum <INT_MAX)
    que.push(make_pair(node[minimum],minimum));
  }

  for(int i=1;i<=V;i++){
    if(node[i].dist==INT_MAX) cout << "INF\n";
    else cout << node[i].dist << "\n";
  }


  return 0;
}
