#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[500000];
vector<pair<int,int> > vec;

int main(){
  int N;
  scanf("%d",&N);
  vector<pair<int,int> >::iterator it;

  for(int i=0;i<N;i++){
    scanf("%d",arr+i);
    int temp = *(arr+i);
    vec.push_back(make_pair(temp,0));
  }

  for(int i=N-2;i>=0;i--){
    int temp=vec.back().first;
    if(vec[i].first > temp){
      vec[i].second=vec.back().second+1;
    }
    it=vec.begin()+i;
    sort(it,vec.end());
  }

  int result=0;
  for(int i=0;i<N;i++){
    result += vec[i].second;
  }

  printf("%d\n",result);

  return 0;
}
