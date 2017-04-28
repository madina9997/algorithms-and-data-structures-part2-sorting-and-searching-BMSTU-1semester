/*Составьте программу rangemax.c, выполняющую поиск
максимального элемента на различных интервалах последовательности целых чисел, которая время от времени изменяется.*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int * v;

int max(a,b)
{
  return (a>b)? a:b;
}
void build(int *v,int i,int a,int b,int * T)
{
  if (a==b) T[i]=v[a];
  else {
    int m = (a+b)/2;
    build(v,(2*i+1),a,m,T);
    build(v,(2*i+2),(m+1),b,T);
    T[i]=max(T[2*i+1],T[2*i+2]);
  }        	
}

int query(int * T, int l, int r, int i, int a, int b)
{
  int p;
  if ((l==a)&&(r==b)) return T[i];
  else {
    int m=(a+b)/2;
    if (r<=m)
      return query(T,l,r,(2*i+1),a,m);
    else if (l>m) return query(T,l,r,(2*i+2),(m+1),b);
    else
      return max(query(T,l,m,(2*i+1),a,m),query(T,(m+1),r,(2*i+2),(m+1),b));
    }	
}

void update(int j,int value,int i,int a,int b,int * T)
{
  if (a==b) T[i]=value;
  else {
    int m=(a+b)/2;
    if (j<=m) update(j,value,(2*i+1),a,m,T);
    else update(j,value,(2*i+2),m+1,b,T);
    T[i]=max(T[2*i+1],T[2*i+2]);
  }
}

int main()
{
  int n, i, k, l, r, value,j;
  scanf("%d", &n);
  v=calloc(n,sizeof(int));
  int * T=calloc(4*n,sizeof(int));
  char st[5];
  for (i=0;i<n;i++) scanf("%d",v+i);
  scanf("%d",&k);
  build(v,0,0,(n-1),T);
  for (j=0;j<k;j++) {
    scanf("%s",st);
    if (st[0]=='M') {
      scanf("%d %d", &l, &r);
      printf("%d\n", query(T,l,r,0,0,(n-1)));
    }
    else {
      scanf("%d %d", &i, &value);
      update(i,value,0,0,(n-1),T);
    }
  }
  free(v);
  free(T);
  return 0;
}
