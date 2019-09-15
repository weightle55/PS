#include <cstdio>

using namespace std;

int inorder[100001];
int postorder[100001];

void makepreorder(int is,int ie, int ps, int pe){
    int rt=postorder[pe];
    int inr=0;

    printf("%d",rt);
    
    for(int i=is;i<=ie;i++){
        if(inorder[i]==rt){
            inr=i; break;
        }
    }
    
    
    if(is<=inr-1){
        printf(" ");
        makepreorder(is,inr-1,ps,inr-1);
    } 
    
    if(inr<=pe-1){
        printf(" ");
        makepreorder(inr+1,pe,inr,pe-1);
    } 
}

int main(){
    int N;

    scanf("%d",&N);

    for(int i=1;i<=N;i++) scanf("%d",&inorder[i]);
    for(int i=1;i<=N;i++) scanf("%d",&postorder[i]);

    makepreorder(1,N,1,N);

    return 0;
}