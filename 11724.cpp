#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

vector<int> vec[1001];
bool visited[1001];

bool bfs(int start){
    if(visited[start]) return false;

    deque<int> dq;
    visited[start]=true;
    dq.push_back(start);

    while(!dq.empty()){
        int temp = dq.front();
        dq.pop_front();

        for(int i=0;i<vec[temp].size();i++){
            if(!visited[vec[temp][i]]){
                visited[vec[temp][i]]=true;
                dq.push_back(vec[temp][i]);
            }     
        }
    }
    
    return true;
}

int main(){
    int N,M;
    scanf("%d%d",&N,&M);

    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    int res=0;
    for(int i=1;i<=N;i++){
        if(bfs(i)) res++; 
    }

    printf("%d\n",res);

    return 0;
}