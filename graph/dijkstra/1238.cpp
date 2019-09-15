#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[1001];
int value[1001];

int dijkstra(int s,int t,int N){
    memset(value,0x3f,sizeof(int)*(N+1));

    priority_queue<pair<int,int> > pq;
    value[s]=0;

    pq.push(make_pair(value[s],s));

    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].first;
            int weight=graph[cur][i].second;
            if(value[next]>cost+weight){
                value[next]=cost+weight;
                pq.push(make_pair(-value[next],next));
            }
        }
    }

    return value[t];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M,X;

    cin >> N >> M >> X;

    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
    }

    int ans=0;
    int max=0;
    for(int i=1;i<=N;i++){
        if(i==X) continue;
        int temp=dijkstra(i,X,N)+dijkstra(X,i,N);
        max = max < temp ? temp : max;
    }

    cout << max<<"\n";
    return 0;
}