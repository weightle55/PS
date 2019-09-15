#include <cstdio>
#include <cstring>
using namespace std;

char str[10001];
char str2[10001];

int main(){
    scanf("%s",str);
    scanf("%s",str2);
    int len=strlen(str);
    int len2=strlen(str2);

    long long num1=0,num2=0;
    for(int i=0;i<len;i++){
        num1+=(long long)(str[i]-'0');
    }

    for(int i=0;i<len2;i++){
        num2+=(long long)(str2[i]-'0');
    }
    
    printf("%lld\n",num1*num2);

    return 0;
}