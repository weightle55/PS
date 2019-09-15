#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

int value[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    vector<pair<int,int> > vec[N+1];

    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v,w));
    }

    int s,t;

    cin >> s >> t;

    memset(value,INF,sizeof(value));

    priority_queue<pair<int,int> > pq;

    value[s]=0;
    pq.push(make_pair(value[s],s));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(value[curr]<cost) continue;

        for(int i=0;i<vec[curr].size();i++){
            int next = vec[curr][i].first;
            int nw = vec[curr][i].second;
            if(value[next]>cost+nw){
                value[next]=cost+nw;
                pq.push(make_pair(-value[next],next));
            }
        }
    }

    cout << value[t] <<"\n";
    return 0;
}