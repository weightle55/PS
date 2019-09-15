#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

bool bmap[10];

int main(){
    char input[6];
    int intinput;
    
    scanf("%s",input);
    intinput=atoi(input);
    int length=strlen(input);

    int M;
    scanf("%d",&M);
    memset(bmap,true,sizeof(bmap));

    int in;
    for(int i=0;i<M;i++){
        scanf("%d",&in);
        bmap[in]=false;
    }

    int up=0,down=1;

    int abdown=0,abup=9;

    for(int i=0;i<9;i++){
        if(bmap[abdown]){
            abdown=i; break;
        }
    }

    for(int i=0;i<9;i++){
        if(bmap[abup-i]){
            abup=abup-i; break;
        }
    }

    //up
    for(int i=0;i<length;i++){
        int num=input[i]-'0';
        if(bmap[num]){
            up*=10;
            up+=num;
        }else{
            int mintmp=0;
            for(int j=num+1;j<10;j++){
                if(bmap[j]){
                    mintmp=j;
                    break;
                }
                if(j==9)
            }

        }
    }

    return 0;
}