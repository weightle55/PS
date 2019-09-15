#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[10001];
bool visited[10001];
int value[10001];

void dfs(int node,int snode){
    if(visited[node]) return;

    visited[node]=true;

    value[snode]++;

    for(int i=0;i<graph[node].size();i++){
        int next=graph[node][i];
        dfs(next, snode);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;

    cin >> N >> M;

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for(int i=1;i<=N;i++){
        memset(visited,false,sizeof(visited));
        dfs(i,i);
    }

    vector<int> result;

    // for(int i=1;i<=N;i++) cout << value[i]<<" ";
    // cout << endl;

    for(int i=1;i<=N;i++){
        if(result.empty()) result.push_back(i);
        else if(value[result.back()]==value[i]) result.push_back(i);
        else if(value[result.back()]<value[i]){
            result.clear();
            result.push_back(i);
        }
    }

    sort(result.begin(),result.end());

    for(int a : result){
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}