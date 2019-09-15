#include <cstdio>
#include <deque>

using namespace std;

int mmap[21][21];

int order[1001];

void dicemove(int N,int M,int x,int y,int K){
    deque<int> wid(3,0);
    deque<int> hei(4,0);
    for(int k=1;k<=K;k++){
        //동쪽
        if(order[k]==1){
            if(x+1>M-1) continue;
            int temp=wid.back();
            
            wid.pop_back();
            wid.push_front(hei[3]);
            hei[3]=temp;
            hei[1]=wid[1];

            if(mmap[y][x+1]==0){
                mmap[y][x+1]=hei[3];
            }else{
                hei[3]=mmap[y][x+1];
                mmap[y][x+1]=0;
            }

            // for(int i=0;i<wid.size();i++){
            //     printf("%d ",wid[i]);
            // }
            // printf("\n");
            // for(int i=0;i<hei.size();i++){
            //     printf("%d ",hei[i]);
            // }
            // printf("\n");

            printf("%d\n",hei[1]);

            x++;
        }
        //서쪽
        else if(order[k]==2){
            if(x-1<0) continue;
            int temp=wid.front();

            wid.pop_front();
            wid.push_back(hei[3]);
            hei[3]=temp;
            hei[1]=wid[1];

            if(mmap[y][x-1]==0){
                mmap[y][x-1]=hei[3];
            }else{
                hei[3]=mmap[y][x-1];
                mmap[y][x-1]=0;
            }

            // for(int i=0;i<wid.size();i++){
            //     printf("%d ",wid[i]);
            // }
            // printf("\n");
            // for(int i=0;i<hei.size();i++){
            //     printf("%d ",hei[i]);
            // }
            // printf("\n");

            printf("%d\n",hei[1]);
            x--;
        }
        //북쪽
        else if(order[k]==3){
            if(y-1<0) continue;
            int temp=hei.front();

            hei.pop_front();
            hei.push_back(temp);
            wid[1]=hei[1];

            if(mmap[y-1][x]==0){
                mmap[y-1][x]=hei[3];
            }
            else{
                hei[3]=mmap[y-1][x];
                mmap[y-1][x]=0;
            }

            // for(int i=0;i<wid.size();i++){
            //     printf("%d ",wid[i]);
            // }
            // printf("\n");
            // for(int i=0;i<hei.size();i++){
            //     printf("%d ",hei[i]);
            // }
            // printf("\n");

            printf("%d\n",hei[1]);
            
            y--;
        }
        //남쪽
        else{
            if(y+1>N-1) continue;
            int temp=hei.back();

            hei.pop_back();
            hei.push_front(temp);
            wid[1]=hei[1];

            if(mmap[y+1][x]==0){
                mmap[y+1][x]=hei[3];
            }
            else{
                hei[3]=mmap[y+1][x];
                mmap[y+1][x]=0;
            }

            // for(int i=0;i<wid.size();i++){
            //     printf("%d ",wid[i]);
            // }
            // printf("\n");
            // for(int i=0;i<hei.size();i++){
            //     printf("%d ",hei[i]);
            // }
            // printf("\n");

            printf("%d\n",hei[1]);

            y++;
        }
    }
}

int main(){
    int N,M,x,y,K;
    scanf("%d%d%d%d%d",&N,&M,&x,&y,&K);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&mmap[i][j]);
        }
    }

    for(int i=1;i<=K;i++){
        scanf("%d",&order[i]);
    }

    // for(int i=0;i<N;i++){
    //     for(int j=1;j<=M;j++){
    //         printf("%d ",mmap[i][j]);
    //     }
    //     printf("\n");
    // }

    dicemove(N,M,y,x,K);

    return 0;
}