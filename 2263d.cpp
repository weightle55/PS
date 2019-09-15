#include <iostream>

using namespace std;

int inorder[100001];
int postorder[100001];

void makepreorder(int is,int ie, int ps, int pe){
    int rt=postorder[pe];
    int inr=0;

    if(ie<is || ps>pe) return;

    cout << rt <<" ";
    
    for(int i=is;i<=ie;i++){
        if(inorder[i]==rt){
            inr=i; break;
        }
    }

    cout << is<< " "<< ie << " "<< ps <<" "<<pe<<" " << inr << endl;

    makepreorder(is,inr-1,ps,inr-1); 
    makepreorder(inr+1,ie,inr,pe-1);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;

    cin>>N;

    for(int i=1;i<=N;i++) cin >> inorder[i];
    for(int i=1;i<=N;i++) cin >> postorder[i];

    makepreorder(1,N,1,N);

    return 0;
}