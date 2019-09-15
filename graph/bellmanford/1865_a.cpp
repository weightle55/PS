#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[501];
int value[501];
bool inQ[501];
int renew[501];

bool spfa(int N){
    memset(value,0x3f,sizeof(value));
    memset(renew,0,sizeof(renew));
    memset(inQ,false,sizeof(inQ));
    
    deque<int> dq;
    dq.push_back(1);
    inQ[1]=true;
    value[1]=0;
    renew[1]++;

    while(!dq.empty()){
        int cur=dq.front();
        dq.pop_front();

        inQ[cur]=false;
        renew[cur]++;

        if(renew[cur] >=N){
            return false;
        }

        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].first;
            int cost=graph[cur][i].second;
            if(value[next]>value[cur]+cost && !inQ[next]){
                inQ[next]=true;
                value[next]=value[cur]+cost;
                dq.push_back(next);
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
            graph[S].push_back(make_pair(E,-T));
            graph[E].push_back(make_pair(S,-T));
        }

        if(spfa(N)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
        for(int i=1;i<=N;i++){
            graph[i].clear();
        }
    }
    return 0;
}