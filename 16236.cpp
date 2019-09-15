#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

int mmap[21][21];
int visited[21][21];

int sx,sy;
int retT = 0;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int main(){
    int N;
    int sharkw=2;
    int cnt=0;

    scanf("%d",&N);

     vector<pair<int,int> > dist;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&mmap[i][j]);
            if(mmap[i][j]==9){
                sy=i;
                sx=j;
                mmap[i][j]=0;
            }
            else if(mmap[i][j]>0 && sharkw>mmap[i][j]){
                dist.push_back(make_pair(i,j));  
            }
        }
    }

    sort(dist.begin(),dist.end());

    int predistsize=dist.size();
    while(!dist.empty()){
        int firY=dist[0].first;
        int firX=dist[0].second;

        if(mmap[firY][firX]>=sharkw) break;

        //printf("FIRST\n");
        memset(visited,0,sizeof(visited));

        deque<pair<int,int> > dq;
        dq.push_back(make_pair(sy,sx));
        visited[sy][sx]=1;

        while(!dq.empty()){
           // printf("BFS\n");
            int ty=dq.front().first;
            int tx=dq.front().second;
            dq.pop_front();

            for(int i=0;i<4;i++){
                int tmpy=ty+dy[i];
                int tmpx=tx+dx[i];
                if(tmpy<N+1 && tmpx<N+1 && tmpy>0 && tmpx>0 && visited[tmpy][tmpx]==0 && mmap[tmpy][tmpx]<=sharkw){
                    visited[tmpy][tmpx]=visited[ty][tx]+1;
                    dq.push_back(make_pair(tmpy,tmpx));
                }
            }
        }

        int mindist=0x3f3f3f3f;
        for(int i=0;i<dist.size();i++){
            if(mindist > visited[dist[i].first][dist[i].second]){
                mindist = visited[dist[i].first][dist[i].second];
                sy=dist[i].first;
                sx=dist[i].second;
            }
        }

        if(mindist < 0x3f3f3f3f && mindist>0){
            retT+=mindist-1;
            mmap[sy][sx]=0;
            cnt++;
            if(cnt==sharkw){
                sharkw++;
                cnt=0;
            }
        }

        predistsize==dist.size();
        dist.clear();

         //printf("\n");
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(mmap[i][j]<sharkw && mmap[i][j]>0 && mmap[i][j]<9 && visited[i][j]>0){
                    dist.push_back(make_pair(i,j));
                }
                //printf("%d ",mmap[i][j]);
            }
            //printf("\n");
        }
       

        sort(dist.begin(),dist.end());
    
    }

    printf("%d\n",retT);
    

    return 0;
}