#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);

    if(N==1){
        printf("*\n");
        return 0;
    }

    for(int i=0;i<N;i++){
        if(N%2==0){
            for(int k=0;k<N/2-1;k++){
                printf("* ");
            }
            printf("*\n ");
            for(int k=0;k<N/2-1;k++){
                printf("* ");
            }                
            printf("*\n");
        }else{
            for(int k=0;k<N/2;k++){
                printf("* ");
            }
            printf("*\n ");
            for(int k=0;k<N/2-1;k++){
                printf("* ");
            }                
            printf("*\n");
        }
    }
    return 0;
}