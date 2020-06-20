#include <stdio.h>
#include <string.h>



int ocorrencias(char *s, char x){
    int count, y=0;
    
    for (int i = 0; s[i] != '\0'; ++i) {
        if (x == s[i])
            ++count;
    }
    return y;   
    y=0;
}

int main(){

    char word[100];
    char *s = word;
    char x;
    printf ("Digite uma palavra: ");
    fgets(s, sizeof(s), stdin);
    scanf("Digite uma letra: %c", &x);

    printf("%d",ocorrencias(s, x));
}

