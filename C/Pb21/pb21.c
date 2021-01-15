#include <stdio.h>
#include <stdlib.h>


void get_divisors(int *divisors)
{
  for(int i = 1; i < 10000; i++)
  {
    divisors[i-1] = 0;
    for(int j = 1; j < i; j++)
    {
      if(i % j == 0)
        divisors[i-1] += j;
    }
  }
}


int get_amicable_numbers(int *divisors)
{

  int sum_amicable_numbers = 0;
  for(int i = 0; i < 9999; i++)
  {
    int b = 0;
    if(divisors[i] != 0)
    {
      for(int j = 9999; j > i; j--)
      {
        if(divisors[i] == (j+1) && (i+1) == divisors[j] && divisors[j] != 0)
        {
          b = 1;
          sum_amicable_numbers += (j+1);
          divisors[j] = 0;
        }
      }
      if(b)
      {
        sum_amicable_numbers += (i+1);
        divisors[i] = 0;
      }
    }
  }
  return sum_amicable_numbers;
}



int main(int argc, char **argv)
{
  int *divisors = malloc(9999 * sizeof(int));
  get_divisors(divisors);
  printf("Sum of all the amicable numbers before 10000 is %i\n", get_amicable_numbers(divisors));
  free(divisors);
  return 0;
}
