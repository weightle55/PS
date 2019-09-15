#include <cstdio>
using namespace std;

long long divine(long long x, long long y,long long start,long long end){
    if(end-start==2){
        if(x==0 && y==0) return 0;
        else if(x==1 && y==0) return 1;
        else if(x==0 && y==1) return 2;
        else return 3;
    }

    long long N = end-start;
    long long mid=N/2;

    if(x<mid && y<mid){
        return divine(x,y,start,mid);
    }

    if(x>=mid && y<mid){
        return mid*mid + divine(x-mid,y,mid,end);
    }

    if(x<mid && y>=mid){
        return mid*mid*2 + divine(x,y-mid,mid,end);
    }

    if(x>=mid && y>=mid){
        return mid*mid*3 + divine(x-mid,y-mid,mid,end);
    }

}

int main(){
    long long N,r,c;

    long long sq=2;

    scanf("%lld%lld%lld",&N,&r,&c);

    for(long long i=1;i<N;i++){
        sq*=2;
    }

    printf("%lld\n",divine(r,c,0,sq));
    return 0;
}