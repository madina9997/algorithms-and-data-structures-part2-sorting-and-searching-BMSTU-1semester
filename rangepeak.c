/*Напомним, что элемент последовательности чисел, значение которого – не меньше значений его непосредственных соседей, называется пиком.
Составьте программу rangepeak.c, выполняющую вычисление количества пиков на различных интервалах последовательности целых чисел, 
которая время от времени изменяется.*/

#include <stdio.h>
#include <stdlib.h>

int n;

int peak(int *v, int i)
{
  return (((!i)&&(v[i]>=v[i + 1])) ||
  ((i==(n-1))&&(v[i]>=v[i - 1]))|| 
  ((i>0)&&(i<n-1)&&(v[i]>=v[i+1])&&(v[i]>=v[i - 1])));
}

void build(int *v,int i,int a,int b,int * T)
{
  if (a==b) T[i]=peak(v,a);
  else {
    int m = (a+b)/2;
    build(v,(2*i+1),a,m,T);
    build(v,(2*i+2),(m+1),b,T);
    T[i]=T[2*i+1]+T[2*i+2];
  }        	
}

int query(int * T, int l, int r, int i, int a, int b)
{
  if ((l==a)&&(r==b)) v=T[i];
  else {
    int m=(a+b)/2;
    if (r<=m)
      v=query(T,l,r,(2*i+1),a,m);
    else {
      if (l>m) v=query(T,l,r,(2*i+2),(m+1),b);
    }
    else
      v=query(T,l,m,(2*i+1),a,m)+query(T,(m+1),r,(2*i+2),(m+1),b);
    }	
}

void update(int j,int * v,int i,int a,int b,int * T)
{
  if (a==b) T[i] = peak(v,a);
  else {
    int m=(a+b)/2;
    if (i<=m) update(j,v,(2*i+1),a,m,T);
    else update(j,v,(2*i+2),m+1,b,T);
    T[i]=T[2*i+1]+T[2*i+2];
  }
}

int main()
{
  int i, k, left, right, value;
  scanf("%d", &n);
  int * v=calloc(n+1,sizeof(int))
  int * T=calloc(4*n,sizeof(int));
  char * st=calloc(5,sizeof(char));
  for (i=0;i<n;i++) scanf("%d",v+i);
  scanf("%d",&k);
  build(v,0,0,(n-1),T);
  for (j=0;j<k;j++) {
    scanf("%s",st);
    if (st[0]=='P') {
      scanf("%d %d", &l, &r);
      printf("%d\n", query(T,l,r,0,0,(n-1)));
    }
    else {
      scanf("%d %d", &i, &value);
      v[i]=value;
      update(i,value,0,0,(n-1),T);
    }
  }
  free(v);
  free(st);
  free(T);
  return 0;
}
