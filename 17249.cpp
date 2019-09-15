#include <cstdio>
#include <cstring>
using namespace std;

char str[1001];

int main(){
    scanf("%s",str);
    int len = strlen(str);
    int left = 0;
    int right = 0;
    int i=0;
    for(;str[i]!='(';i++){
        if(str[i]=='@') left++;
    }
    for(;i<len;i++){
        if(str[i]=='@') right++;
    }

    printf("%d %d\n",left,right);

    return 0;
}