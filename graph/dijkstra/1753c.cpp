#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int value[20001];

int main(){
  ios_base::sync_with_stdio(false);

  int V,E,start;
  int u,v,w;

  cin >> V >> E >> start;

  vector<pair<int,int> > node[V+1];

  for(int i=1;i<=E;i++){
    cin >> u >> v >>w ;
    node[u].push_back(make_pair(v,w));
  }

  for(int i=1 ; i<=V ; i++) value[i] = INT_MAX;
  value[start]=0;

  priority_queue<pair<int,int> > pq;
  pq.push(make_pair(value[start],start));

  while(!pq.empty()){
    int cost = -pq.top().first;
    int curr = pq.top().second;
    pq.pop();

    if(value[curr] < cost) continue;
    for(int i=0;i < node[curr].size();i++){
      int next = node[curr][i].first;
      int nextw = node[curr][i].second;
      if(value[next]>cost+nextw){
        value[next]=cost+nextw;
        pq.push(make_pair(-value[next],next));
      }
    }

  }

  for(int i=1;i<=V;i++){
    if(value[i]!=INT_MAX) cout << value[i] << "\n";
    else cout << "INF\n";
  }

  return 0;
}
