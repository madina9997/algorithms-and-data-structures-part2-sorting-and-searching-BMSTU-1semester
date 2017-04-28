/*Составьте программу pword.c, определяющую, составлена ли строка T исключительно из префиксов строки S.
Программа получает строки S и T через аргументы командной строки и выводит ’yes’, если T составлена
из префиксов S, и ’no’ – в противном случае.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char** args) 
{
    int t, Pi[strlen(args[1])],l=0,m=5,flag=1;
    Pi[0]=t=0;
    int i=1,q=0,k=0;
    while (i<strlen(args[1])) {
      while ((t>0)&& (args[1][t]!=args[1][i]))
        t=Pi[t-1];
      if (args[1][t]==args[1][i])
	t++;
      Pi[i]=t;
      i++;
    }
    while (k<strlen(args[2])) {
      while ((q>0) && (args[1][q]!=args[2][k]))
	q=Pi[q-1];
      if (args[1][q]==args[2][k])
	q++;
      if (q==0) {
	flag=0;
	break;
      }
      if (q==strlen(args[1])) q=Pi[q-1];
      k++;
    }  
    if (flag==1) printf("yes"); else printf("no");
      
}
