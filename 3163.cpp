#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

struct ant{
    int dist;
    int place;
    int idx;
    int id;
    int L;
    bool dir;

    bool operator<(struct ant b)const {
        return dist<b.dist;
    }
};

int main(){
    int T;
    cin >> T;

    for(;T>0;T--){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int N,L,k;
        cin >> N >> L >> k;
        deque<int> dq;
        vector<struct ant> ants(N);

        for(int i=0;i<N;i++){
            int index,id;
            bool dirir;
            cin >> index >> id;

            if(id>0) dirir=true;
            else dirir=false;

            if(dirir) ants[i].dist=L-index;
            else ants[i].dist=index;
            ants[i].place=index;
            ants[i].idx=i;
            ants[i].id=id;
            ants[i].L=L;
            ants[i].dir=dirir;

            dq.push_back(id);
        }

        sort(ants.begin(),ants.end());

        vector<int> res;


        // for(int i=0;i<dq.size();i++){
        //     cout << dq[i] <<" ";
        // }
        // cout << endl;

        for(int i=0;i<k;i++){
            if(i<k && ants[i].dist==ants[i+1].dist){
                if(dq.size()>1 && dq.front()<dq.back()){
                    res.push_back(dq.front());
                    dq.pop_front();
                    res.push_back(dq.back());
                    dq.pop_back();
                }
                else{
                    res.push_back(dq.back());
                    dq.pop_back();
                    res.push_back(dq.front());
                    dq.pop_front();
                }
                i++;
            }
            else{
                if(ants[i].dir){
                    res.push_back(dq.back());
                    dq.pop_back();
                }
                else{
                    res.push_back(dq.front());
                    dq.pop_front();
                }
            }
        }

        // for(int i=0;i<ants.size();i++){
        //     cout << ants[i].id << " ";
        // }
        // cout << endl;


        // for(int i=0;i<res.size();i++){
        //     cout << res[i] <<" ";
        // }
        // cout << endl;

        cout << res[k-1] << "\n";
    }

    return 0;
}