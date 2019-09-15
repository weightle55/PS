#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > vec[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,X;
    cin >> N >> M >> X;
    for(int i=1;i<=M;i++){
        int n,m,x;
        cin >> n >> m >> x;
        vec[n].push_back(make_pair(m,x));
    }

    return 0;
}