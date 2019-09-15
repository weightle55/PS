#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int woods[501][501];
int lis[501][501];

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int res=0;

// void bfs(int x,int y,int N){
//     deque<pair<int,int> > dq;

//     dq.push_back(make_pair(x,y));

//     while(!dq.empty()){
//         int tx=dq.front().first;
//         int ty=dq.front().second;
//         dq.pop_front();

//         for(int i=0;i<4;i++){
//             int ttx=tx+dx[i];
//             int tty=ty+dy[i];
//             if(ttx<=N && ttx>0 && tty>0 && tty<=N && woods[tty][ttx]>woods[ty][tx]){
//                 if(lis[tty][ttx]<lis[ty][tx]+1){
//                     lis[tty][ttx]=lis[ty][tx]+1;
//                     dq.push_back(make_pair(ttx,tty));
//                     res=lis[tty][ttx]>res?lis[tty][ttx]:res;
//                 }
//             }
//         }
//     }
// }

int dfs(int x,int y,int N){
    if(lis[y][x]!=0){
        return lis[y][x];
    }

    lis[y][x]=1;

    int dmax=lis[y][x];
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<=N && tx>0 && ty>0 && ty<=N && woods[ty][tx]>woods[y][x]){
            dmax=max(dmax,lis[y][x]+dfs(tx,ty,N));
        }
    }

    lis[y][x]=dmax;

    return dmax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> woods[i][j];
            //lis[i][j]=1;
        }    
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            lis[i][j]=dfs(j,i,N);
            res = res<lis[i][j]?lis[i][j]:res;
        }
    }

    cout << res<< "\n";

    return 0;
}