/*Составьте программу maxprod.c, выполняющую поиск отрезка последовательности простых дробей
  i 0, на котором произведение дробей максимально.*/
  
  #include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
  int n,i;
  scanf("%d",&n);
  double b;
  double c;
  double * a = (double*)malloc(n*sizeof(double));
  for (i=0;i<n;i++) {
    scanf("%lf/%lf",&b,&c);
    a[i]=log2(b/c);
  }
  int l=0,r=0,start=0;
  double maxsum=a[0],sum=0;
  i=0;
  while (i<n) {
    sum+=a[i];
    if (sum>maxsum) {
      maxsum=sum;
      l=start;
      r=i;
    }
    i++;
    if (sum<0) {
      sum=0;
      start=i;
    }
  }
  printf("%d %d", l,r);
  free(a);
}
