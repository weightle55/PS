#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int arr[100010];
int segtree[400010];
//long long valuetree[200010];

int init(int node,int left,int right){
    if(left==right){
        segtree[node] = left;

        return segtree[node];
    }
    else{
        int lchild=init(node*2,left,(left+right)/2);
        int rchild=init(node*2+1,(left+right)/2+1,right);
        if( arr[lchild] < arr[rchild] ){
            segtree[node]=lchild;
        }
        else {
            segtree[node]=rchild;
        }

        return segtree[node];
    } 
}

int query(int node,int start,int end,int left,int right){
    if(right<start || left>end ) return -1;

    if(start<=left && right <=end) return segtree[node];

    int mid = (left+right)/2;
    int lchild = query(node*2,start,end,left,mid);
    int rchild = query(node*2+1,start,end,mid+1,right);

    if(lchild == -1) return rchild;
    if(rchild == -1) return lchild;
    
    if(arr[lchild] <= arr[rchild]) return lchild;
    else return rchild;   
}

ll volumn(int start,int end,int left,int right){
    ll max=0,temp=0;
    int mini= query(1,start,end,left,right);

    max = (ll)arr[mini] * (ll)(end-start+1);

    ll leftmax=0;
    if(start<=mini-1) leftmax=volumn(start,mini-1,left,right);
    ll rightmax=0;
    if(mini+1<=end) rightmax=volumn(mini+1,end,left,right);

    temp = leftmax < rightmax ? rightmax : leftmax;

    max = max < temp ? temp : max ;
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        int N;
        cin >> N;

        if(N==0) break;

        for(int i=1;i<=N;i++) cin >> arr[i];

        init(1,1,N);

        cout << volumn(1,N,1,N) << "\n";
        //for(int i=1;i<2*N;i++) cout <<segtree[i]<< " ";
        //cout << "\n"; 
    }
    
    return 0;
}