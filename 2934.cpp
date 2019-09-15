#include <iostream>

using namespace std;

#define MAXV 100000

int fenwick[100001];
int preflower[100001];

void update(int i,int value){
    while(i<=MAXV && i>0){
        fenwick[i]+=value;
        i+= i&(-i);
    }
}

int sum(int i){
    int ret=0;
    while(i>0){
        ret+=fenwick[i];
        i-= i&(-i);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        for(int i=1;i<10;i++){
        cout << fenwick[i] << " ";
        }
        cout << "\n";
        
        int L,R;
        cin >> L >> R;

        int pl=sum(L);
        int pr=sum(R);
        
        cout << pr+pl << "\n";

        update(L,-pl);
        update(L+1,pl);
        
        update(R,-pr);
        update(R+1,pr);

        update(L+1,1);
        update(R,-1);

    }    

    return 0;
}