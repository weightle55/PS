#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  int r;
  double ucl, taxi;
  scanf("%d",&r);

  ucl = M_PI * pow((double)r,2);
  taxi = 2*pow((double)r,2);

  printf("%lf\n%lf\n",ucl,taxi);
  return 0;
}
