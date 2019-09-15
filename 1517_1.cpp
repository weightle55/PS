#include <iostream>
#include <cmath>
using namespace std;

int mergearr[5000000];
int arr[5000000];

void merge(int left,int right,int &cnt){
  int mid= (left+right)/2;
  int left_i=left;
  int right_i=mid+1;

  int merge_i=left;
  while(left_i<=mid && right_i<=right){
    if(arr[left_i]<=arr[right_i]){
      mergearr[merge_i]=arr[left_i];
      left_i++;
    }
    else{
      mergearr[merge_i]=arr[right_i];
      right++; cnt++;
    }
    merge_i++;
  }

  int t;
  if(left_i>mid) t=right_i;
  else t=left_i;

  for(;merge_i<=right;merge_i++,t++){
    mergearr[merge_i] = arr[t];
  }
  for(int i=0;i<=right;i++){
    arr[i]=mergearr[i];
  }
}

void mergesort(int left,int right,int &cnt){
  int mid;
  if(left<right){
    mid=(left+right)/2;
    mergesort(left,mid,cnt);
    mergesort(mid,right,cnt);
    merge(left,right,cnt);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int result=0;
  cin >> N;
  for(int i=0;i<N;i++) cin >> arr[i];

  mergesort(0,N-1,result);

  cout << result << "\n";

  return 0;
}
