#include <stdlib.h>
#include <stdio.h>

void print(double *dptr, int size)
{
  int i;
  for (i=0; i<size; i++)
  printf("%lf ",*(dptr+i));
  printf("\n");
  return;
}

int main()
{
  double *ptr, *ptr2;
  ptr = (double *)calloc(5,sizeof(double));
  ptr2 = ptr;
  *ptr2=1;
  *(ptr2+1)=*ptr + *ptr;
  *(ptr2+2)=*(ptr+1)+*(ptr+1);
  ptr2++;
  *(ptr2+2)=*(ptr2-1)+*(ptr+1);
  ptr2++;
  *(ptr2+2)=*ptr2-1+*ptr-1;
  print(ptr,5);
}
