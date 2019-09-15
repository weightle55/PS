#include <iostream>
#include <deque>

using namespace std;

int graph[101][101];
bool visited[101];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N,M;

  cin >> N >> M;

  deque<int> dq;
  int ret=0;

  for(int i=0;i<M;i++){
    int input1,input2;
    cin >> input1 >> input2;
    graph[input1][input2]=1;
    graph[input2][input1]=1;
  }

  dq.push_back(1);
  visited[1] = true;

  while(!dq.empty()){
    int cur=dq.front();
    dq.pop_front();

    for(int i=1;i<=N;i++){
      if(graph[cur][i]==1 && visited[i]==false){
        dq.push_back(i);
        visited[i]=true;
        ret++;
      }
    }
  }

  cout << ret << "\n";

  return 0;
}
