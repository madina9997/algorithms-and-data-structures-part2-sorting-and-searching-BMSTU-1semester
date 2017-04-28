/*Составьте программу prefixes.c, выполняющую поиск всех периодических префиксов заданной строки S*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char** args) 
{
    int t, Pi[strlen(args[1])];
    Pi[0]=t=0;
    int i=1;
    while (i<strlen(args[1])) {
      while ((t>0)&& (args[1][t]!=args[1][i]))
        t=Pi[t-1];
      if (args[1][t]==args[1][i])
        t++;
      Pi[i]=t;
      i++;
    }
    if (strlen(args[1])>1)  
      for (i=1;i<strlen(args[1]);i++) {
	if (Pi[i]&&!((i+1)%(i+1-Pi[i])))
	  printf("%d %d\n",i+1,((i+1)/(i+1-Pi[i])));
	}	
}
