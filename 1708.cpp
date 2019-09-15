#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lbx=0x3f3f3f3f,lby=0x3f3f3f3f;

struct Point{
    long long x,y;
};

long long sqrdist(Point a,Point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int ccw(Point a,Point b,Point c){
    long long tmp = a.x*b.y+b.x*c.y+c.x*a.y;
    tmp -= b.x*a.y+c.x*b.y+a.x*c.y;
    if(tmp>0)return 1;
    else if(tmp==0) return 0;
    return -1;
}

bool compare(Point a,Point b){
    Point lb;
    lb.x=lbx;
    lb.y=lby;
    if(ccw(lb,a,b)>0){
        return true;
    }
    else if(ccw(lb,a,b)==0){
        return sqrdist(lb,a)<sqrdist(lb,b);
    }
    else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Point> points;
    for(int i=0;i<N;i++){
        Point input;
        cin >> input.x >> input.y;
        points.push_back(input);
        if(lby>input.y){
            lby=input.y;
            lbx=input.x;
        }
        else if(lby==input.y){
            if(lbx>input.x){
                lbx=input.x;
            }
        }
    }

    sort(points.begin(),points.end(),compare);

    vector<Point> hull;

    hull.push_back(points[0]);
    hull.push_back(points[1]);

    int cur=2;

    while(cur<N){
        while(hull.size()>=2){
            Point pre,ppre;
            pre=hull.back();
            hull.pop_back();
            ppre=hull.back();

            if(ccw(ppre,pre,points[cur])>0){
                hull.push_back(pre);
                break;
            }
        }
        hull.push_back(points[cur]);
        cur++;
    }

    cout << hull.size()<<"\n";

    return 0;
}