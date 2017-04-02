#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int day;
  int month;
  int year;
} Date;

int before(Date *d1, Date *d2);
int within30days(Date *d1, Date *d2);

int main(void)
{
  Date *d1ptr = (Date *)malloc(sizeof(Date));
  Date *d2ptr = (Date *)malloc(sizeof(Date));
  printf("Enter date1 (mm dd yyyy): ");
  scanf("%d %d %d", &d1ptr->month, &d1ptr->day, &d1ptr->year);
  printf("Enter date2 (mm dd yyyy): ");
  scanf("%d %d %d", &d2ptr->month, &d2ptr->day, &d2ptr->year);
  printf("\n");

  if(before(d1ptr, d2ptr))
    printf("%02d/%02d/%d is before %02d/%02d/%d\n", d1ptr->month, d1ptr->day, d1ptr->year, d2ptr->month, d2ptr->day, d2ptr->year);
  else
    printf("%02d/%02d/%d is before %02d/%02d/%d\n", d2ptr->month, d2ptr->day, d2ptr->year, d1ptr->month, d1ptr->day, d1ptr->year);

  if(within30days(d1ptr, d2ptr))
    printf("%02d/%02d/%d is within 30 days of %02d/%02d/%d\n", d1ptr->month, d1ptr->day, d1ptr->year, d2ptr->month, d2ptr->day, d2ptr->year);
  else
    printf("%02d/%02d/%d is not within 30 days of %02d/%02d/%d\n", d1ptr->month, d1ptr->day, d1ptr->year, d2ptr->month, d2ptr->day, d2ptr->year);

  free(d1ptr);
  free(d2ptr);

  return 0;
}

int before(Date *d1, Date *d2)
{
  if(d1->year > d2->year)
    return 0;
  else if(d2->year > d1->year)
    return 1;
  else if(d1->month > d2->month)
    return 0;
  else if(d2->month > d1->month)
    return 1;
  else if(d1->day > d2->day)
    return 0;
  else if(d2->day > d1->day)
    return 1;
  else
    return 0;
}

int within30days(Date *d1, Date *d2)
{
  int numdays1 = d1->year * 360 + (d1->month - 1) * 30 + d1->day;
  int numdays2 = d2->year * 360 + (d2->month - 1) * 30 + d2->day;
  int diff = numdays1 - numdays2;
  if(diff <= 30 && diff >= -30)
    return 1;

  return 0;
}

