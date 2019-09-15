#include <iostream>
#include <vector>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

vector<int> graph[101];
int dist[101][101];
int pre[101][101];

void floydWarshall(int N){
    memset(dist,INF,sizeof(dist));
    memset(pre,-1,sizeof(pre));

    for(int i=1;i<=N;i++){
        dist[i][i] = 0;
    }
    //initialize
    for(int i=1;i<=N;i++){
        for(int j=0;j<graph[i].size();j++){
            int tmp = graph[i][j];
            dist[i][tmp]=1;
            pre[i][tmp] = i;
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(dist[k][j]>dist[k][i]+dist[i][j]){
                    dist[k][j] = dist[k][i]+dist[i][j];
                    pre[k][j] = pre[i][j];
                }
            }
            cout << dist[i][j] << "," << pre[i][j] <<" ";
        }
        cout <<z
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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    floydWarshall(N);

    int min=INF;
    int id=1;
    for(int i=1;i<=N;i++){
        int temp=0;
        for(int j=1;j<=N;j++){
            if(dist[i][j] != INF){
                temp += dist[i][j];
            }
        }
        if(temp < min){
            min = temp;
            id = i;
        }
    }

    cout << id << "\n";

    return 0;
}