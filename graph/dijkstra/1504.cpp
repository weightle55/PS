#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 0x3f3f3f3f3f3f3f3f
#define LL long long

using namespace std;

vector<pair<LL,LL> > graph[801];
LL value[801];

LL dijkstra(LL s,LL t, LL N){
    memset(value,0x3f,sizeof(value));

    priority_queue<pair<LL,LL> > pq;
    value[s]=0;
    pq.push(make_pair(-value[s],s));

    while(!pq.empty()){
        LL cost=-pq.top().first;
        LL cur =pq.top().second;
        pq.pop();

        for(pair<LL,LL> tmp : graph[cur]){
            LL next=tmp.first;
            LL wei=tmp.second;
            
            if(value[next]>cost+wei){
                value[next]=cost+wei;
                pq.push(make_pair(-value[next],next));
            }
        }
    }

    return value[t];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL N,E,a,b;

    cin >> N >> E;

    for(LL i=0;i<E;i++){
        LL u,v,w;
        cin >> u >> v >>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    cin >> a >> b;

    LL oneA,oneB,AB,Bend,Aend;

    oneA=dijkstra(1,a,N);
    oneB=dijkstra(1,b,N);
    AB=dijkstra(a,b,N);
    Bend=dijkstra(b,N,N);
    Aend=dijkstra(a,N,N);

    LL ans,ans2;

    if(oneA< INF && AB< INF && Bend< INF){
        ans = oneA+AB+Bend;
    }
    else ans =INF;
    
    if(oneB < INF && AB < INF && Aend < INF){
        ans2=oneB+AB+Aend;
    }
    else ans2= INF;

    ans = ans > ans2 ? ans2 : ans;

    //cout << oneA <<"\n" << oneB <<"\n" << AB <<"\n" << Bend <<"\n" << Aend <<"\n"; 

    if(ans>=INF) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}
