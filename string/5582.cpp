#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str1[4001];
int sfx[4001];
int g[4001];
int tg[4001];

int t;

bool cmp(int a,int b){
    if(g[a]==g[b]) return g[a+t]<g[b+t];
    return g[a] < g[b]; 
}

void suffixarray(int N){
    t=1;

    for(int i=0;i<N;i++){
        sfx[i]=i;
        g[i]=str1[i]-'A';
    }

    while(t<=n){
        g[N]=-1;
        sort(sfx,sfx+N,cmp);

        tg[sfx[0]]=0;

        for(int i=0;i<N;i++){
            if(cmp(sfx[i],sfx[i+1])) tg[sfx[i+1]]=tg[sfx[i]]+1;
            else tg[sfx[i+1]]=tg[sfx[i]];
        }

        for(int i=0;i<N;i++) g[i]=tg[i];

        t <<1;
    }
}

int main(){
    scanf("%s",str1);

    int n=strlen(str1);


    return 0;
}