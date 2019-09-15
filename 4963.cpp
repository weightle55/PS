#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int map[50][50];
bool visited[50][50];
int w=1,h=1;

void dfs(int th,int tw){
    visited[th][tw]=true;
    //왼
    if(tw>0 && map[th][tw-1]==1 && !visited[th][tw-1]) dfs(th,tw-1);
    //오
    if(tw<w-1 && map[th][tw+1]==1 && !visited[th][tw+1]) dfs(th,tw+1);
    //위
    if(th>0 && map[th-1][tw]==1 && !visited[th-1][tw]) dfs(th-1,tw);
    //아래
    if(th<h-1 && map[th+1][tw]==1 && !visited[th+1][tw]) dfs(th+1,tw);

    //왼위
    if(tw>0 && th>0 && map[th-1][tw-1]==1 && !visited[th-1][tw-1]) dfs(th-1,tw-1);
    //왼아래
    if(tw>0 && th<h-1 && map[th+1][tw-1]==1 && !visited[th+1][tw-1]) dfs(th+1,tw-1);
    //오위
    if(tw<w-1 && th>0 && map[th-1][tw+1]==1 && !visited[th-1][tw+1]) dfs(th-1,tw+1);
    //오아래
    if(tw<w-1 && th<h-1 && map[th+1][tw+1]==1 && !visited[th+1][tw+1]) dfs(th+1,tw+1);
}

int main(){

    vector<pair<int,int> > vec; 

    scanf("%d%d",&w,&h);

    while(w*h != 0){
        vec.clear();
        memset(visited,false,sizeof(visited));
        memset(map,0,sizeof(map));

        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==1) vec.push_back(make_pair(i,j));
            }
        }

        int res=0;
        for(int i=0;i<vec.size();i++){
            int th,tw;
            th=vec[i].first;
            tw=vec[i].second;
            if(visited[th][tw]==true) continue;

            res++;
            dfs(th,tw);           
        }

        // for(int i=0;i<h;i++){
        //     for(int j=0;j<w;j++){
        //         printf("%d ",visited[i][j]);
        //     }
        //     printf("\n");
        // }

        printf("%d\n",res);

        scanf("%d%d",&w,&h);
    }

    return 0;
}