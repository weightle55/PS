#include <cstdio>

using namespace std;

int R[401][401];
int G[401][401];
int B[401][401];
int res[401][401];

int main(){
    int N,M;
    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d%d%d",&R[i][j],&G[i][j],&B[i][j]);
            res[i][j]=2126*R[i][j]+7152*G[i][j]+722*B[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(res[i][j]>=0 && res[i][j]<510000) printf("#");
            else if(res[i][j]<1020000) printf("o");
            else if(res[i][j]<1530000) printf("+");
            else if(res[i][j]<2040000) printf("-");
            else printf(".");
        }
        printf("\n");
    }


    return 0;
}