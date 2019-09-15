#include <cstdio>

using namespace std;

int mcm(int a, int b){
  int atemp=a;
  int btemp=b;
  int ret;

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
  int T;
  scanf("%d",&T);

  for(;T>0;T--){
	int a,b;
	scanf("%d%d",&a,&b);

	printf("%d\n",mcm(a,b));

  }
  return 0;
}
