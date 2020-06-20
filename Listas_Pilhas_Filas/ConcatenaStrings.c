#include <stdio.h>
#include <string.h>

char *concatena(char *s1, char *s2); 

int main()
{
  	char s1[1000], s2[1000];
  	scanf("%s",s1);
  	scanf("%s",s2);
  	
  	concatena(s1, s2);
  	printf("\n%s", s1);
  	return 0;
}

char *concatena(char *s1, char *s2)
{
	while(*s1)
	{
		s1++;
	}
	
	while(*s2)
	{
		*s1 = *s2;
		*s1++;
		*s2++;
  	}
  	*s1 = '\0';
}