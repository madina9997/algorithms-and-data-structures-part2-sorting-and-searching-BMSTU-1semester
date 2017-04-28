/*В классической сортировке втавками для вставки элемента в отсортированную часть последовательности выполняется сравнение
элемента со всеми членами отсортированной части до тех пор, пока для него не будет найдено место, то есть
переменная loc (см. алгоритм в лекциях) на каждой итерции внутреннего цикла уменьшается на единицу.
Метод Шелла является модификацией сортировки вставками, в которой переменная loc на каждой итерции 
внутреннего цикла уменьшается на некоторое число d ≥ 1. При этом фактически сортировка выполняется 
несколько раз для всё меньших и меньших значений d до тех пор, пока d не станет равно 1. Тем самым, сначала
выполняется серия «грубых» сортировок, которые не дают точного ответа, но делают последовательность более упорядоченной, 
обеспечивая более быстрое выполнение финальной точной сортировки при d = 1.
Составьте функцию shellsort, выполняющую сортировку произвольной последовательности методом Шелла. */

#include <stdlib.h> 
#include <stdio.h> 
 
int *array; 
 
int compare(unsigned long i, unsigned long j) 
{ 
        if (i <= j) { 
                printf("COMPARE␣%d␣%d\n", i, j); 
        } else { 
                printf("COMPARE␣%d␣%d\n", j, i); 
        } 
 
        if (array[i] == array[j]) return 0; 
        return array[i] < array[j] ? -1 : 1; 
} 
 
void swap(unsigned long i, unsigned long j) 
{ 
        if (i <= j) { 
                printf("SWAP␣%d␣%d\n", i, j); 
        } else { 
                printf("SWAP␣%d␣%d\n", j, i); 
        } 
 
        int t = array[i]; 
        array[i] = array[j]; 
        array[j] = t; 
} 
 
void shellsort(unsigned long nel,int (*compare)(unsigned long i, unsigned long j), 
        void (*swap)(unsigned long i, unsigned long j))
{
  unsigned long i,k,loc,d,j;
  unsigned long fib[2*nel];
  fib[0]=fib[1]=1;
  i=2;
  if (nel!=1) {
  for (i=2;i<2*nel;i++) {
          fib[i]=fib[i-1]+fib[i-2];
          k=i;
	  if (fib[i]>=nel) break;
	}
  
  for (j=(k-1);j>0;j--) {
    d=fib[j];
    i=d;
    while (i<nel) {
      loc=i-d;
      while ((loc>=0) && (compare(loc,(loc+d))>0)) {
	swap(loc,(loc+d));
	  if (loc>=d) loc=loc-d; 
          else break;
      }
      i=i+1;
    }
  }
  }
} 
 
int main(int argc, char **argv) 
{ 
        int i, n; 
        scanf("%d", &n); 
 
        array = (int*)malloc(n * sizeof(int)); 
        for (i = 0; i < n; i++) scanf("%d", array+i); 
 
        shellsort(n, compare, swap); 
        for (i = 0; i < n; i++) printf("%d␣", array[i]); 
        printf("\n"); 
 
        free(array); 
        return 0; 
}
