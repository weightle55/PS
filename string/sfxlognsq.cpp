#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char str[500001];
int sfx[500001];
int group[500001];
int tmpg[500001];
int lcp[500001];
int RANK[500001];

int t;

bool sfxcmp(int i,int j){
    if(group[i] == group[j]) return group[i+t]<group[j+t];
    return group[i] < group[j];
}

void sfxarray(int n){
    t=1;
    for(int i=0;i<n;i++){
        sfx[i]=i;
        group[i]=str[i]-'a';
    }

    while(t<=n){
        group[n]=-1;
        
        sort(sfx,sfx+n,sfxcmp);
        
        tmpg[sfx[0]]=0;

        for(int i=0;i<n-1;i++){
            if(sfxcmp(sfx[i],sfx[i+1])) tmpg[sfx[i+1]]=tmpg[sfx[i]]+1;
            else tmpg[sfx[i+1]]=tmpg[sfx[i]];
        }

        for(int i=0;i<n;i++) group[i]=tmpg[i];
        t *=2;
    }
}

void func_lcp(int n){
    for(int i=0;i<n;i++){
        RANK[sfx[i]]=i;
    }

    int len=0;

    for(int i=0;i<n;i++){
        
        int k=RANK[i];

        if(k>0){
            int tmp=sfx[k-1];

            while(str[tmp+len]==str[i+len]) len++;

            lcp[k]=len;

            if(len>0) len--;
        }
    }
}

int main(){

    int n=0;

    scanf("%s",str);
    n=strlen(str);

    sfxarray(n);
    func_lcp(n);

    for(int i=0;i<n;i++) printf("%d ",sfx[i]+1);
    printf("\nx ");
    for(int i=1;i<n;i++) printf("%d ",lcp[i]);
    printf("\n");

    return 0;
}