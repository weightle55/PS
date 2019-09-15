#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int tarr[500001];

int binaryS(int start,int end,int value){
    int ret=-1;

    int mid=(start+end)/2;

    if(tarr[mid]<value){
        ret=binaryS(mid,end,value);
    }
    else if(tarr[mid]==value){
        ret=mid;
    }
    else{
        ret=binaryS(start,mid,value);
    }
    return ret;
}

int main(){
    int N;

    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> arr[i];
        tarr[i]=arr[i];
    }

    sort(tarr+1,tarr+N+1);

    // for(int i=1;i<=N;i++) cout << tarr[i] << " ";
    // cout << endl;

    int cnt=0;
    for(int i=1;i<=N;i++){
        int ind=binaryS(1,N+1,arr[i]);
        //cout << i << " "<< ind <<endl;
        if(i<ind){
            cnt++;
        }
    }

    cout<< cnt+1 << "\n";

    return 0;
}