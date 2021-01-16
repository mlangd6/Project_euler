/** Champerwone's constant
    Here I use a very brut method. We can see that the execution is
    quite long, near 3 seconds.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int construct_champerwone_s_constant(char *champerwone)
{
  int i = 1;
  while(strlen(champerwone) < 1000005)
  {
    char buf[20];
    sprintf(buf, "%d", i);
    strcat(champerwone, buf);
    i++;
  }
  return 0;
}

int find_result(char *champerwone)
{
  int res = 1;
  for(int i = 1; i < 1000003; i *= 10)
  {
    int res_int = champerwone[i-1] - 48;
    res *= res_int;
  }
  return res;
}

int main(int argc, char **argv)
{
  float temps;
  clock_t t1, t2;

  t1 = clock();

  char *champerwone = malloc(1000001);
  champerwone[0] = '\0';
  construct_champerwone_s_constant(champerwone);
  int res = find_result(champerwone);
  free(champerwone);

  t2 = clock();
  temps = (float)(t2-t1)/CLOCKS_PER_SEC;

  printf("Le produit trouvé est %i. Ceci a étét trouvé en %f secondes\n", res, temps);
  return 0;
}
