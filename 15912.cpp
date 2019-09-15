#include <cstdio>

#define ll long long

using namespace std;

ll W[1001];
ll E[1001];

int main(){
    int N;
    ll W_max=0;
    ll E_max=0;
    scanf("%d",&N);

    for(int i=1;i<=N;i++){
        ll input;
        scanf("%lld",&input);
        W[i]=input;
        W_max=input > W_max ? input : W_max;
    }
    for(int i=1;i<=N;i++){
        ll input;
        scanf("%lld",&input);
        E[i]=input;
        E_max=input > E_max ? input : E_max;
    }

    


    return 0;
}