#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> graph[1001];
int back[1001];
bool visited[1001];

bool dfs(int node){
    if(visited[node]) return false;
    visited[node]=true;

    for(int i=0;i<graph[node].size();i++){
        int tmp=graph[node][i];
        if(back[tmp]==0 || dfs(back[tmp])){
            back[tmp]=node;
            return true;
        }
    }

    return false;
}

int biqmatch(int n){
    int ret=0;

    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        if(dfs(i)){
            ret++;
        }
    }

    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        if(dfs(i)){
            ret++;
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M;

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        int cnt;
        cin >> cnt;

        for(int j=1;j<=cnt;j++){
            int num;
            cin >> num;
            graph[i].push_back(num);
        }
    }

    cout << biqmatch(N) << "\n";

    return 0;
}