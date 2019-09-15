#include <iostream>

using namespace std;

int sub1[100];
int sub2[100];
bool solve[100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,L,K;

    cin >> N >> L >> K;

    for(int i=0;i<N;i++){
        cin >> sub1[i] >> sub2[i];
    }

    int score=0;

    for(int i=0;i<N;i++){
        if(K<1) break;
        if(sub2[i]<=L){
            score+=140;
            K--;
            solve[i]=true;
        }
    }

    for(int i=0;i<N;i++){
        if(K<1) break;
        if(sub1[i]<=L && !solve[i]){
            score+=100;
            K--;
            solve[i]=true;
        }
    }

    cout << score<<"\n";

    return 0;
}