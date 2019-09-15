#include <cstdio>

using namespace std;

int Gcd(int a,int b){
  if(b==0) return a;
  else return Gcd(b,a%b);
}

int lcm(int a, int b){
  return a*b/Gcd(a,b);
}

int main(){

  int a,b;
	scanf("%d%d",&a,&b);

	printf("%d\n%d\n",Gcd(a,b),lcm(a,b));

  return 0;
}
