#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    for(int i=1;i<=M;i++){
        arr[i]=1;
    }

    do{
        for(int i=1;i<=N;i++){
            if(arr[i]==1){
                cout << i <<" ";
            }
        }
        cout << "\n";
    }while(prev_permutation(arr+1,arr+N+1));
    return 0;
}