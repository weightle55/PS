#include <iostream>
#define MAX 100001

using namespace std;

typedef long long ll;


ll BIT[MAX];

void update(int i,int val,int n){
    while(i<=n){
        BIT[i]+=val;
        i+= i&(-i);
    }
}

ll sum(int i){
    ll ret=0;
    while(i>0){
        ret+=BIT[i];
        i-= i& (-i);
    }
    return ret;
}

ll query(int left,int right){
    ll ret=sum(right)-sum(left-1);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        int input;
        cin >> input;
        update(i,input,N);
    }

    int l,r;
    
    for(int i=1;i<=M;i++){
        cin >> l >> r;
        cout << query(l,r) << "\n";
    }

    return 0;
}