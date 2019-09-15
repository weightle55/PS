#include <iostream>
#include <vector>
using namespace std;

int num;

vector<pair<int, int> > vec;

void hanoi(int start,int mid,int end,int height){
    if(height==0) return;
    if(height==1){
        vec.push_back(make_pair(start,end));
        num++;
        return;
    }
    hanoi(start,end,mid,height-1);
    hanoi(start,mid,end,1);
    hanoi(mid,start,end,height-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;

    cin >> N;
    
    num=0;

    hanoi(1,2,3,N);

    cout << num << "\n";

    for(int i=0;i<vec.size();i++){
        cout << vec[i].first << " " <<vec[i].second << "\n";
    }

    return 0;
}