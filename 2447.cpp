#include <cstdio>
#include <cstring>
using namespace std;

char map[2200][2200];

void rec(int x,int y,int size){
    if(size==1){
        map[y][x]='*';
        return;
    }

    int msize=size/3;

    rec(x,y,msize);
    rec(x+msize,y,msize);
    rec(x+2*msize,y,msize);
    rec(x,y+msize,msize);
    rec(x+2*msize,y+msize,msize);
    rec(x,y+2*msize,msize);
    rec(x+msize,y+2*msize,msize);
    rec(x+2*msize,y+2*msize,msize);

}

int main(){
    memset(map,' ',sizeof(map));

    int N;
    scanf("%d",&N);

    rec(1,1,N);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }

    return 0;
}