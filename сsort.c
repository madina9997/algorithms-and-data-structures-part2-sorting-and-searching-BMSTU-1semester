/*Составьте функцию сsort, выполняющую сортировку слов в предложении методом подсчёта сравнений. 
Слова в предложении разделяются произвольным количеством пробелов.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dlinaSlova(int i,char *str)
{
  int k, len=0;
  k=i;
  while(str[k] != ' ' && str[k] != '\0') {
    len++;
    k++;
  }
  if (str[k]=='\0') len--;
  return len;
}

int nextIndex(int i,char* str)
{
  int j,l=i;
  if (str[i]==' ') {
    while (str[l]==' ') l++;
  }
  j=dlinaSlova(l,str) + l;
  while (str[j]==' ')
    j++;
  return j;
}

int nel(char* str)
{
  int k=0,i=0,x=strlen(str)-1,flag;
  while (x>0) {
    x=x+i-nextIndex(i, str);
    k++;
    i= nextIndex(i, str);
   }
  return k;
}

char csort(char *src, char *dest) 
{ 
    int **s = calloc(2,sizeof(int*)); 
    int *ns = calloc(nel(src),sizeof(int));
    int i,j,l=0;
    while (src[l]==' ') l++;
    int k=l;
    s[1] = calloc(nel(src), sizeof(int));
    s[0] = calloc(nel(src), sizeof(int));
    int **count = calloc(2*nel(src),sizeof(int*)); 
    count[1] = calloc(nel(src), sizeof(int));
    count[0] = calloc(nel(src), sizeof(int));
    for (j=0;j<nel(src);j++) {
      s[0][j]=dlinaSlova(l,src);
      l=nextIndex(l,src);
    }
    l=k;
    for (j=0;j<nel(src);j++) {
      s[1][j]=l;
      l=nextIndex(l,src);
     }
    for (j=0;j<(nel(src)-1);j++) {
      i=j+1;
      while (i<nel(src)) {
	if (s[0][i]<s[0][j]) count[1][j]++;
	else count[1][i]++;
	i++;
      }
    }
    
    for (j=0;j<nel(src);j++)
	count[0][j]=s[1][j];
    for (i=0;i<nel(src);i++)
      ns[count[1][i]]=count[0][i];
    k=0;
    for (i=0;i<nel(src);i++) {
      for (j=0;j<dlinaSlova(ns[i],src);j++,k++) {dest[k]=src[ns[i]+j];printf("%c",dest[k]);}
      dest[k+1]=' '; 
      printf("%c",dest[k+1]);
      k+=2;
    }
    dest[k-1]='\0';
    
    free(s[0]);
    free(s[1]);
    free(count[0]);
    free(count[1]);
    free(ns);
    free(count);
    free(s);
} 

char main()
{
  int i;
  char* predloz= (char*)malloc(100 * sizeof(char));
  fgets(predloz,100,stdin);
  char *vuvod = calloc(100 , sizeof(char));
  csort(predloz,vuvod);
  i=0;
  free(predloz);
  free(vuvod);
}
  
  
