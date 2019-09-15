#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

int graph[51][51];
bool visited[51][51];
vector<pair<int,int> > input;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool bfs(int x,int y,int m,int n){
    if(visited[y][x]==true) return false;

    deque<pair<int,int> > dq;
    dq.push_back(make_pair(x,y));
    visited[y][x]=true;

    while(!dq.empty()){
        int tx=dq.front().first;
        int ty=dq.front().second;

        dq.pop_front();

        for(int i=0;i<4;i++){
            if(m>tx+dx[i] && 0<=tx+dx[i] && n>ty+dy[i] && 0<=ty+dy[i]){
                if(graph[ty+dy[i]][tx+dx[i]]==1 && !visited[ty+dy[i]][tx+dx[i]]){
                    visited[ty+dy[i]][tx+dx[i]]=true;
                    dq.push_back(make_pair(tx+dx[i],ty+dy[i]));
                }
            }
        }
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    for(;T>0;T--){
        int M,N,K;  
        
        memset(graph,0,sizeof(graph));
        memset(visited,false,sizeof(visited));

        input.clear();

        cin >> M >> N >> K;

        for(int i=0;i<K;i++){
            int x,y;
            cin >> x >> y;
            graph[y][x]=1;
            input.push_back(make_pair(x,y));
        }

        int cnt=0;
        for(pair<int,int> a : input){
            int x=a.first;
            int y=a.second;
            if(bfs(x,y,M,N)) cnt++;
        }

        cout << cnt << "\n";

        // for(int i=0;i<N;i++){
        //     for(int j=0;j<M;j++) cout << visited[i][j] << " ";
        //     cout << endl;
        // }
    }

    return 0;
}