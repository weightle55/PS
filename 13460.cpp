#include <cstdio>
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

char pan[11][11];
int visited[11][11];

int main(){
    int N,M;
    pair<int,int> blue,red,hole;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1c",&pan[i][j]);
            if(pan[i][j]=='R') red=make_pair(i,j);
            else if(pan[i][j]=='B') blue=make_pair(i,j);
            else if(pan[i][j]=='O') hole=make_pair(i,j);
        }
    }

    memset(visited,0,sizeof(visited));

    deque<pair<int,int> > dq;
    dq.push_back(red);

    while(!dq.empty()){
        
    }

    return 0;
}