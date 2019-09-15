#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[1001];
int value[1001];
int parent[1001];
bool visited[1001];

int dijkfunction(int N){
    memset(value,0x3f,sizeof(int)*(N+1));
    memset(parent,0,sizeof(int)*(N+1));
    memset(visited,false,sizeof(bool)*(N+1));

    priority_queue<pair<int, int> > pq;
    value[1]=0;
    pq.push(make_pair(value[1],1));

    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].first;
            int wei=graph[cur][i].second;
            if(visited[next]==true) continue;
            if(value[next]>value[cur]+wei){
                value[next]=value[cur]+wei;
                parent[next]=cur; 
                pq.push(make_pair(-value[next],next));                     
            }
        }
    }

    int ret=value[N];
    cout << value[N]<<"\n";

    for(int a=N; a!=1; a=parent[a]){
        visited[a]=true;
    }

    visited[N]=false;

    memset(value,0x3f,sizeof(int)*(N+1));
    memset(parent,0,sizeof(int)*(N+1));

    value[1]=0;
    pq.push(make_pair(value[1],1));

     while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].first;
            int wei=graph[cur][i].second;
            if(visited[next]==true) continue;
            if(value[next]>value[cur]+wei){
                value[next]=value[cur]+wei;
                parent[next]=cur; 
                pq.push(make_pair(-value[next],next));                     
            }
        }
    }

    return ret+value[N];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V,E;
    cin >> V >> E;

    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
    }

    cout << dijkfunction(V)<<"\n";


    return 0;
}