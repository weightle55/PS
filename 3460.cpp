#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    for(;T>0;T--){
        int N;
        scanf("%d",&N);

        vector<int> res;

        while(N>0){
            int tmp=N&(-N);
            N-=tmp;
            int cnt=0;
            while(tmp!=1){
                cnt++;
                tmp=tmp>>1;
            }
            res.push_back(cnt);    
        }

        for(int i=0;i<res.size();i++){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
    return 0;
}