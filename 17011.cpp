#include <cstdio>
#include <cstring>
using namespace std;

int main(){

    int T;
    scanf("%d",&T);
    for(;T>0;T--){
        char str[81];
        scanf("%s",str);
        int len = strlen(str);

        int cnt=1;
        char cur=str[0];
        for(int i=1;i<len;i++){
            if(cur==str[i]){
                cnt++;
            }
            else{
                printf("%d %c ",cnt,cur);
                cur=str[i];
                cnt=1;
            }
        }
        printf("%d %c\n",cnt,cur);
    }
    return 0;
}