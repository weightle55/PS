#include <cstdio>

using namespace std;

int dock[100000];
bool isdock[100000];

int main(){
    int G,P,cnt=0;
    scanf("%d%d",&G,&P);
    for(int i=0;i<P;i++){
        scanf("%d",dock+i);
        if(!isdock[dock[i]]){
            isdock[dock[i]]=true;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}