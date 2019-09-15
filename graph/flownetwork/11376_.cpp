#include <iostream>
#include <cstring>
#include <map>
#include <deque>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

map<int,int> graph[2002];
int rgraph[2002][2002];
bool visited[2002];


bool dfs(int n,int t,int parent[]){
    if(n==t){
        return true;
    }
    if(n==0){
        memset(visited,0,sizeof(visited));
        parent[n]=-1;
    }

    visited[n]=true;

    for(auto& v : graph[n]){
        if(v.second > 0 && !visited[v.first]){
            parent[v.first]=n;
            return dfs(v.first, t, parent);
        }
    }

    return false;
}


int fordfulkerson(int s,int t){
    int u,v;
    int *parent=new int[t+1];
    int max_flow=0;

    // for(int i=0;i<=t;i++){
    //     for(auto& v : graph[i]){
    //         rgraph[i][v.first]=v.second;
    //     }
    // }

    while(dfs(s,t,parent)){
        int path_flow = INF;
        for(v=t; v!=s; v=parent[v]){
            u=parent[v];
            path_flow=min(path_flow,graph[u][v]);
        }
        for(v=t; v!=s; v=parent[v]){
            u=parent[v];
            graph[u][v]-=path_flow; graph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }

    return max_flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M,s,t;

    cin >> N >> M;

    s=0;
    t=N+M+1;

    for(int i=1;i<=N;i++){
        int cnt;
        cin >> cnt;
        graph[0].insert(make_pair(i,2));

        for(int j=1;j<=cnt;j++){
            int num;
            cin >> num;
            graph[i].insert(make_pair(N+num,1));
        }
    }

    for(int i=1;i<=M;i++){
        graph[N+i].insert(make_pair(t,1));
    }

    cout << fordfulkerson(s,t) <<"\n";

    return 0;
}