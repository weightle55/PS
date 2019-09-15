#include <cstdio>
#include <cstring>

using namespace std;

char str[10001];

int main(){
    scanf("%s",str);
    int len=strlen(str);

    int joi=0,ioi=0;

    for(int i=0;i<len-2;i++){
        if(str[i]=='J' && str[i+1]=='O' && str[i+2]=='I') joi++;
        if(str[i]=='I' && str[i+1]=='O' && str[i+2]=='I') ioi++;
    }

    printf("%d\n%d\n",joi,ioi);

    return 0;
}