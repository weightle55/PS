#include <iostream>
#include <algorithm>
using namespace std;

int L[51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> L[i];
    }
    int num;
    cin >> num;

    sort(L,L+N);

    int low=0,high=0;

    for(int i=0;i<N;i++){
        if(L[i]>=num){
            if(i!=0){
                high=L[i];
                low=L[i-1];
            }
            else{
                high=L[i];
                low=0;
            }
            break;
        }
    }

    if(num==high || num==low || high-low==2){
        cout << "0\n";
        return 0;
    }
    cout <<high-low-2+(high-num-1)*(num-low-1)<<"\n";

    return 0;
}