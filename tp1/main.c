#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    system("color 0c");
    float numA=0;
    float numB=0;
    int menu;
    float sumar;
    float restar;
    float multiplicar;
    float dividir;
    int confirmar=0;
    int confirmar2=0;
    int confirmar3=0;
    float factA;
    float factB;

    do
    {
        system("cls");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("                               ~~CALCULADORA~~\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("                Por favor ingrese una de las siguientes opciones:\n");
        printf("                    1) Ingresar el 1er operando (A=%.2f)\n", numA);
        printf("                    2) Ingresar el 2do operando (B=%.2f)\n", numB);
        printf("                    3) Calcular todas las operaciones\n");
        printf("                    4) Informar los resultados\n");
        printf("                    5) Salir\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        menu=tomarDato();

        switch(menu)
        {
        case 1:
            numA=operadorA();
            confirmar=1;
            system("pause");

        break;

        case 2:
            numB=operadorB();
            confirmar2=1;
            system("pause");

        break;

        case 3:
            if(confirmar!=1 && confirmar2!=1)
            {
                printf("Error, debe ingresar la opcion 1 y 2 para hacer las operaciones.\n");
                system("pause");
            }

            else
            {


            printf("                A) La suma entre A=%.2f + B=%.2f\n", numA , numB);
            sumar = suma(numA , numB);


            printf("                B) La resta entre A=%.2f - B=%.2f\n", numA , numB);
            restar = resta(numA , numB);


            printf("                C) La multiplicacion entre A=%.2f * B=%.2f\n", numA , numB);
            multiplicar = multiplicacion(numA , numB);


            printf("                D) La division entre A=%.2f / B=%.2f\n", numA , numB);
            dividir = division(numA , numB);


            printf("                E) El factorial de A=%.2f \n", numA);
            factA = factorialA(numA);

            printf("                E) El factorial de B=%.2f \n", numB);
            factB = factorialB(numB);
            system("pause");

            confirmar3=1;

            }
            break;


        case 4:

        if(confirmar!=0 && confirmar2!=0 && confirmar3!=0)
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("                                ~~RESULTADOS~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("                    A) El resutlado de la suma es: %.2f\n", sumar);
            printf("                    B) El resultado de la resta es: %.2f\n", restar);
            printf("                    C) El resultado de la multiplicacion es: %.2f\n", multiplicar);
            printf("                    D) El resultado de la division es: %.2f\n", dividir);
            printf("                    E) El factorial de A=%.2f es: %.2f \n", numA, factA );
            printf("                    E) El factorial de B=%.2f es: %.2f \n", numB, factB );
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

            system("pause");
        }

        else
        {
            printf("Error, debe ingresar la opcion 1, 2 y 3 para obtener los resultados de las operaciones.\n");
            system("pause");
        }

        break;

        case 5:
            printf("                Saliendo de la calculadora\n");
            system("pause");

        break;

        default:

            printf("                Error, Ingrese una opcion valida\n");
            system("pause");

        }

    }while(menu!=5);
    return 0;
}

