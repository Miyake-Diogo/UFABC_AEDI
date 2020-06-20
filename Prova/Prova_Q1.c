
#include <stdio.h>


int recursive_major_digit(int num) {
    int num_1 = num%10;
    int num_2 = num/10;

    if (num_2 == 0) { 
        return num_1;
    }
    int num_3 = recursive_major_digit(num_2);

    return num_1 > num_3 ? num_1 : num_3;
}


int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n", recursive_major_digit(n));
  return 0;
}
