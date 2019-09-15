#include <cstdio>
#include <deque>
#include <vector>
#include <iostream>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int fx,fy;
int jx,jy;

char mmap[1002][1002];
int visited[1002][1002];
int bfs(int R,int C){

    deque <pair<int,int> > jdq;
    jdq.push_back(make_pair(jx,jy));
    visited[jy][jx]=1;

    while(!jdq.empty()){
        int tjx=jdq.front().first;
        int tjy=jdq.front().second;
        jdq.pop_front();

        if(tjx==1 || tjx==C || tjy==1 || tjy==R){
            return visited[tjy][tjx];
        }
        
        for(int i=0;i<4;i++){
            int ttjx=tjx+dx[i];
            int ttjy=tjy+dy[i];
            if(ttjx>0 && ttjy>0 && ttjx<=C && ttjy<=R && mmap[ttjy][ttjx]!='#' && (visited[ttjy][ttjx] > visited[tjy][tjx]+1 || visited[ttjy][ttjx]==0)){
                visited[ttjy][ttjx]=visited[tjy][tjx]+1;
                jdq.push_back(make_pair(ttjx,ttjy));
            }
        }

       
    }

    return -1;
}

void fbfs(int R,int C){
    deque<pair<int,int> > fdq;

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(mmap[i][j]=='F'){
                visited[i][j]=1;
                fdq.push_back(make_pair(j,i));
            }
        }
    }

    while(!fdq.empty()){
        int tx=fdq.front().first;
        int ty=fdq.front().second;
        fdq.pop_front();

        for(int i=0;i<4;i++){
            int ttx=tx+dx[i];
            int tty=ty+dy[i];
            if(ttx>0 && tty>0 && ttx<=C && tty<=R && mmap[tty][ttx]!='#' && visited[tty][ttx]==0){
                visited[tty][ttx]=visited[ty][tx]+1;
                fdq.push_back(make_pair(ttx,tty));
            }
        }
    }
}

int main(){
    int R,C;
    scanf("%d%d",&R,&C);

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            scanf(" %c",&mmap[i][j]);
            if(mmap[i][j]=='J'){
                jy=i;
                jx=j;
            }
            else if(mmap[i][j]=='F'){
                fy=i;
                fx=j;
            }
        }
    }

    fbfs(R,C);

    int res=bfs(R,C);

    // printf("\n");
  

    // for(int i=1;i<=R;i++){
    //     for(int j=1;j<=C;j++){
    //         printf("%d",fvisited[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    // for(int i=1;i<=R;i++){
    //     for(int j=1;j<=C;j++){
    //         printf("%d ",visited[i][j]);
    //     }
    //     printf("\n");
    // }

    if(res<0){
        printf("IMPOSSIBLE\n");
    }
    else{
        printf("%d\n",res);
    }
    return 0;
}