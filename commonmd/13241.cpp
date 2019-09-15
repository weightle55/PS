#include <cstdio>
#define ll long long
using namespace std;

ll mcm(int a, int b){
  ll atemp=a;
  ll btemp=b;
  ll ret;

  while(true){
	if(atemp==btemp){
	  ret = atemp;
	  break;
	}
	else if(atemp<btemp){
	  atemp+=a;
	}
	else{
	  btemp+=b;
	}
  }

  return ret;
}

int main(){
	int a,b;
	scanf("%d%d",&a,&b);

	printf("%lld\n",mcm(a,b));
  return 0;
}
