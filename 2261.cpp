#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>

using namespace std;

pair<long long,long long> points[100000];

bool ysort(pair<long long,long long> a,pair<long long,long long> b){
    if(a.second!=b.second) return a.second < b.second;
    else return a.first < b.second;
}

long long sqdist(long long x1,long long y1,long long x2,long long y2){
    long long ret=0;
    ret = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    //cout << "sqdist" << endl;
    return ret;
}

long long mindist(long long start,long long end){
    long long ret=INT_MAX;
    for(long long i=start;i<=end;i++){
        for(long long j=i+1;j<=end;j++){
            long long tmp=sqdist(points[i].first,points[i].second,points[j].first,points[j].second);
            if(tmp<ret) ret=tmp;
        }
    }
    //cout << "mindist" << endl;
    return ret;
}

long long lrdiff(vector<pair<long long,long long> > vec,long long diff){
    //cout << "lrdiff func" << endl;
    long long tmpmin=diff;

    sort(vec.begin(),vec.end(),ysort);

    for(long long i=0;i<vec.size();i++){
        for(long long j=i+1;j<vec.size() && abs(vec[j].second-vec[i].second)*abs(vec[j].second-vec[i].second)<diff;j++){
            long long ttmin=sqdist(vec[i].first,vec[i].second,vec[j].first,vec[j].second);
            if(tmpmin>ttmin) tmpmin=ttmin;
        }
    }

    return tmpmin;
}

long long divide(long long start,long long end){
    //cout << "divide func" << endl;
    if(end-start<=3) return mindist(start,end);
    
    long long mid=(start+end)/2;

    long long ldiff=divide(start,mid);
    long long rdiff=divide(mid+1,end);

    long long diff=ldiff<rdiff ? ldiff : rdiff;

    vector<pair<long long,long long> > inbox;

    for(long long i=start;i<=end;i++) {
        if(abs(points[mid].first-points[i].first)*abs(points[mid].first-points[i].first)<diff) inbox.push_back(points[i]);
    }
    long long lrd=lrdiff(inbox,diff);

    return min(lrd,diff);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    long long x,y;
    long long size;
    
    set<pair<long long,long long> > seeet;

    for(int i=0;i<N;i++){
        cin >> x >> y;
        //seeet.insert(make_pair(x,y));
        points[i] = make_pair(x,y);
    }

    //seeet.size();

    long long mm=0;
    // for(pair<long long,long long> point : seeet){
    //     points[mm]=point;
    //     mm++;
    // }

    cout << divide(0,N-1)<< endl;
    
    return 0;
}