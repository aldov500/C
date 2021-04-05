#include <stdio.h>
#include <stdlib.h>

void pasa_a_mayusculas(char *s);
void pasa_a_minusculas(char *s);


int main()
{
    char *min, *may;

    printf("\n Char Minusculas: ");
    scanf("%s", &min);

    printf("\n Char Mayusculas: ");
    scanf("%s", &may);

    pasa_a_mayusculas(min);
    pasa_a_minusculas(may);

    return 0;
}


void pasa_a_mayusculas(char *s){
    s = toupper(s);
    printf("%c\n", s);
}

void pasa_a_minusculas(char *s){
    s = tolower(s);
    printf("%c\n", s);
}
