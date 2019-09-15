#include <cstdio>
//#include <iostream>
#include <vector>
using namespace std;

typedef long long lll;

bool map[1300001];
bool ans[1000001];

int main(){
    lll min, max,cnt=0;
    scanf("%lld%lld",&min,&max);

    vector<lll> prime;

    for (int i = 2; i <= max && i<1300001; i++) { 
        if (map[i]) 
            continue;
        for (int j = i + i; j <= max && j<1300001; j += i) { 
            map[j] = true;
        }
        prime.push_back((long long)i);
    }


    lll newres=0;


    for(lll j=0;j<prime.size();j++){
        lll sq=prime[j]*prime[j];
        lll n; 
        if(min%sq==0) n=min;
        else n=((min/sq)+1LL) * sq;
        //printf("%lld\n",n);
        for(lll k = n-min;k<=max-min;k+=sq){
            if(!ans[k]){
                ans[k]=true;
               // newres++;
            }
        }
    }

    for(int i=0;i<=max-min;i++){
        if(!ans[i]) newres++;
    }

    printf("%lld\n",newres);
    //cout << prime.size() << endl;

    return 0;
}