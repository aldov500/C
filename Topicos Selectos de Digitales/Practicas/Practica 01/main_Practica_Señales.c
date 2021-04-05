#include <stdio.h>
#include <stdlib.h>

typedef struct mensaje
{
    int num;
    int s1;
    int s2;
} Mensaje;

void printMsn();

Mensaje m[5];

int main()
{

    printf("Recepcion de mensajes.\n");

    for(int i = 0; i<5; i++)
    {

        m[i].num = i+1;
        printf("Mensaje numero [%d]\n", m[i].num);

        printf("Ingresa la señal 1.\n");
        scanf("%d",&m[i].s1);

        printf("Ingresa la señal 2.\n");
        scanf("%d",&m[i].s2);

        switch(m[i].num)
        {

        case 1:
            if(!(m[i].s1 == 1 || m[i].s1 == 0))
            {
                while(!(m[i].s1 == 1 || m[i].s1 == 0))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 1.\n");
                    scanf("%d",&m[i].s1);
                }
                printf("OK");

            }
            else if(!(m[i].s2 >= 0 || m[i].s2 <= 7))
            {
                while(!(m[i].s2 >= 0 || m[i].s2 <= 7))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 2.\n");
                    scanf("%d",&m[i].s2);
                }

                printf("OK");

            }
            system("pause");
            system("cls");

            break;

        case 2:
            if(!(m[i].s1 == 1 || m[i].s1 == 0))
            {
                while(!(m[i].s1 == 1 || m[i].s1 == 0))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 1.\n");
                    scanf("%d",&m[i].s1);
                }
                printf("OK");

            }
            else if(!(m[i].s2 >= 0 || m[i].s2 <= 4))
            {
                while(!(m[i].s2 >= 0 || m[i].s2 <= 4))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 2.\n");
                    scanf("%d",&m[i].s2);
                }
                printf("OK");
            }

            system("pause");
            system("cls");

            break;

        case 3:
            if(!(m[i].s1 == 1 || m[i].s1 == 0))
            {
                while(!(m[i].s1 == 1 || m[i].s1 == 0))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 1.\n");
                    scanf("%d",&m[i].s1);
                }
                printf("OK");

            }
            else if(!(m[i].s2 >= 0 || m[i].s2 <= 7))
            {
                while(!(m[i].s2 >= 0 || m[i].s2 <= 7))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 2.\n");
                    scanf("%d",&m[i].s2);
                }
                printf("OK");
            }

            system("pause");
            system("cls");

            break;

        case 4:
            if(!(m[i].s1 == 1 || m[i].s1 == 0))
            {
                while(!(m[i].s1 == 1 || m[i].s1 == 0))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 1.\n");
                    scanf("%d",&m[i].s1);
                }
                printf("OK");

            }
            else if(!(m[i].s2 >= 0 || m[i].s2 <= 65535))
            {
                while(!(m[i].s2 >= 0 || m[i].s2 <= 65535))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 2.\n");
                    scanf("%d",&m[i].s2);
                }
                printf("OK");
            }

            system("pause");
            system("cls");

            break;

        case 5:
            if(!(m[i].s1 == 1 || m[i].s1 == 0))
            {
                while(!(m[i].s1 == 1 || m[i].s1 == 0))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 1.\n");
                    scanf("%d",&m[i].s1);
                }
                printf("OK");

            }
            else if(!(m[i].s2 >= 0 || m[i].s2 <= 4095))
            {
                while(!(m[i].s2 >= 0 || m[i].s2 <= 4095))
                {
                    printf("Error de Ingreso\n");
                    printf("Ingresa la señal 2.\n");
                    scanf("%d",&m[i].s2);
                }
                printf("OK");
            }

            system("pause");
            system("cls");

            break;


        }
    }


    if(m[0].s1 == 1 && m[0].s2 == 0)
    {
        if(m[1].s1 == 1 && (m[0].s2>=0 && m[0].s2<=2) )
        {
            if(m[2].s1 == 1 && m[2].s2 == 0)
            {
                if(m[3].s1 == 1 && (m[3].s2>=0 && m[3].s2<=4) )
                {
                    if(m[4].s1 == 1 && (m[4].s2>=15 && m[4].s2<=255) )
                    {
                        printMsn();
                        printf("\nResultado = TRUE\n");
                        return 0;
                    }
                }
            }
        }
    }

    printMsn();
    printf("\nResultado = FALSE\n");
    return 0;
}

void printMsn()
{
    for(int i = 0; i<5; i++)
    {
        printf("Mensaje numero [%d]\n", m[i].num);
        printf("Signal 01: [%d]\n", m[i].s1);
        printf("Signal 02: [%d]\n", m[i].s2);
        printf("----------------------------------\n");
    }
    system("pause");

}
