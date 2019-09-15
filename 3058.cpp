#include <cstdio>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);

    for(;T>0;T--){
        int N=7;
        int sum=0;
        int min=101;
        for(int i=0;i<N;i++){
            int input;
            scanf("%d",&input);
            if(input%2==0){
                sum+=input;
                min= min > input ? input : min;
            }
        }
        printf("%d %d\n",sum,min);
    }
    return 0;
}