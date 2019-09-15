#include <cstdio>

using namespace std;

char mmap[51][51];

int recolor(int x,int y){
    int black,white;

    int recolored=0;

    //Black
    for(int i=y;i<y+8;i++){
        for(int j=x;j<x+8;j++){
            if((i-y)%2==0){
                if((j-x)%2==0){
                    if(mmap[i][j]!='B') recolored++;
                }
                else{
                    if(mmap[i][j]!='W') recolored++;
                }
            }
            else{
                if((j-x)%2==0){
                    if(mmap[i][j]!='W') recolored++;
                }
                else{
                    if(mmap[i][j]!='B') recolored++;
                }
            }
        }
    }

    black=recolored;
    recolored=0;

    //White
    for(int i=y;i<y+8;i++){
        for(int j=x;j<x+8;j++){
            if((i-y)%2==0){
                if((j-x)%2==1){
                    if(mmap[i][j]!='B') recolored++;
                }
                else{
                    if(mmap[i][j]!='W') recolored++;
                }
            }
            else{
                if((j-x)%2==1){
                    if(mmap[i][j]!='W') recolored++;
                }
                else{
                    if(mmap[i][j]!='B') recolored++;
                }
            }
        }
    }

    white=recolored;
    int mini = black<white ? black : white;
    return mini;
}

int main(){
    int N,M;
    
    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf(" %c",&mmap[i][j]);
        }
    }

    int ans=0x3f3f3f3f;
    for(int i=1;i<=N-7;i++){
        for(int j=1;j<=M-7;j++){
            int temp=recolor(j,i);
            ans= temp < ans ? temp : ans;
        }
    }

    printf("%d\n",ans);

    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=M;j++){
    //         printf("%c",mmap[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}