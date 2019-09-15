#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[501];
int value[501];

bool bellman(int s,int N){
    memset(value,INF,sizeof(value));
    value[s]=0;

    for(int i=0;i<N;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<graph[j].size();k++){
                int next=graph[j][k].first;
                int cost=graph[j][k].second;
                if(value[next]>value[j]+cost){
                    value[next]=value[j]+cost;
                    if(i==N-1) return false;
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
        int N,M,W;
        int S,E,T;

        cin >> N >> M >> W;
        for(int i=0;i<M;i++){
            cin >>S>>E>>T;
            graph[S].push_back(make_pair(E,T));
            graph[E].push_back(make_pair(S,T));
        }
        for(int i=0;i<W;i++){
            cin >> S >> E >> T;
            graph[S].push_back(make_pair(E,(-1)*T));

        }

        // for(int i=1;i<=N;i++){
        //     if(!bellman(i,N)){
        //         iscycle=true;
        //         break;
        //     }
        // }

        if(!bellman(1,N)) cout << "YES\n";
        else cout << "NO\n";
    
        
        for(int i=1;i<=N;i++){
            graph[i].clear();
        }
    }
    return 0;
}