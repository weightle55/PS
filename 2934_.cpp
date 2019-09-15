#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int L,R;
        cin >> L >> R;
        int pr=sum(rfenwick,MAXV)-sum(rfenwick,R);
        int pl=sum(lfenwick,L)-sum()
    }


    return 0;
}