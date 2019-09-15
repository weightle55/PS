#include <iostream>
#include <cmath>
using namespace std;

int arr[501];

double average(int start,int end){
    int sum=0;
    for(int i=start;i<=end;i++){
        sum+=arr[i];
    }

    return sum/(double)(end-start+1);
}

double Vsqrt(int start,int end){
    double avr=average(start,end);

    double tmp=0.0;
    for(int i=start;i<=end;i++){
        tmp+=pow((double)arr[i]-avr,2);
    }

    tmp/=(end-start+1);

    return sqrt(tmp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,K;
    cin >> N >> K;

    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    double min=100000000.0;

    for(int j=K;j<=N;j++){
        for(int i=1;i<=N-j+1;i++){
            double tmp=Vsqrt(i,i+j-1);
            min = min>tmp ? tmp:min;
        }
    }
    

    cout << fixed;
    cout.precision(11);
    cout << min <<"\n";
    return 0;
}