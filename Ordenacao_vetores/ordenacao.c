#include <stdio.h>

int isArraySorted(int [], int);

int main()
{
  int n, s[1000], i, r;

  while (scanf("%d", &n) != EOF){  
    //scanf("%d", &n);

  for (i = 0; i < n; i++)
    scanf("%d", &s[i]);

  r = isArraySorted(s, n);

  if (r == 1)
    printf("C\n");
  else if (r == 2)
    printf("D\n");
  else
    printf("N\n");
}
  return 0;
}

int isArraySorted(int s[], int n) {
  int a = 1, d = 1, i = 0;

  while ((a == 1 || d == 1) && i < n - 1) {
    if (s[i] < s[i+1])
      d = 0;
    else if (s[i] > s[i+1])
      a = 0;
    i++;
  }

  if (a == 1)
    return 1;
  else if (d == 1)
    return 2;
  else
    return 0;
}