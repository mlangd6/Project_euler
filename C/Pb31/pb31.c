#include <stdio.h>
#include <time.h>

//We search 1*a + 2*b + 5*c + 10*d + 20*e + 50*f + 100*g + 200*h = 200

int nb_possibility_brute()
{
  int res = 0;
  int obj = 200;//2 pounds vaut 200 pence

  for(int a = obj; a >= 0; a -= 200)
    for(int b = a; b >= 0; b -= 100)
      for(int c = b; c >= 0; c -= 50)
        for(int d = c; d >= 0; d -= 20)
          for(int e = d; e >= 0; e -= 10)
            for(int f = e; f >= 0; f -= 5)
              for(int g = f; g >= 0; g -= 2)
                res++;
  return res;
}

int main(int argc, char **argv)
{
  float temps;
  clock_t t1, t2;

  t1 = clock();
  int res = nb_possibility_brute();
  t2 = clock();
  temps = (float)(t2-t1)/CLOCKS_PER_SEC;
  printf("Il y a %i manières de payer 2 pounds. Ceci a étét trouvé en %f secondes\n", res, temps);
  return 0;
}
