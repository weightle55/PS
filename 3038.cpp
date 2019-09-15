#include <cstdio>

using namespace std;

int arr[40000];



int main(){
    int N;
    int num;

    scanf("%d",&N);
    num=1;
    for(int i=0;i<N;i++) num*=2;
    num--;

    printf("%d %d\n",N,num);


    return 0;
}