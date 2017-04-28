/*Составьте программу dsort.c, осуществляющую сортировку латинских букв в строке в алфавитном порядке (размер строки – до миллиона букв).
В программе должен быть реализован алгоритм сортировки распределением.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
  char * key = (char *) malloc(27*sizeof(char));
  strcpy(key,"abcdefghijklmnopqrstuvwxyz");
  char * stroka = (char *) malloc(1000001*sizeof(char));
  fgets(stroka, 1000000, stdin);
  int * count = calloc(26,sizeof(int));
  char * d = (char *) malloc(1000001*sizeof(char));
  int j,i,n=(strlen(stroka)-1),k;
  for(j=0;j<n;j++)
    count[(int)stroka[j]-97]++;
  for (i=1;i<26;i++)
    count[i]+=count[i-1];
  for (j=n-1;j>=0;j--) {
    k=(int)stroka[j]-97;
    i=count[k]-1;
    count[k]=i;
    d[i]=stroka[j];
  }
  for (i=0;i<n;i++) printf("%c",d[i]);
  free(stroka);
  free(d);
  free(count);
  free(key);
}
