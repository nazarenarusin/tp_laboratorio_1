#include <stdio.h>
#include "biblioteca.h"

/** \brief Funcion que pide al usuario ingresar datos y los toma.
 *
 * \param void No recibe parametros.
 * \return int retorna la opcion ingresada por el usuario.
 *
 */
int tomarDato(void)
{
    int opcion;
    printf("                Ingrese una opcion: ");
    scanf("%d", & opcion);

    return opcion;
}

/** \brief Funcion que pide al usuario ingresar el valor A.
 *
 * \param void No recibe parametros.
 * \return float Retorna el valor A ingresado por el usuario.
 *
 */
float operadorA(void)
{
    float valorA;
    printf("                Ingrese valor A: ");
    scanf("%f", & valorA);

    return valorA;
}

/** \brief Funcion que pide al usuario ingresar el valor B.
 *
 * \param void No recibe parametros.
 * \return float Retorna el valor A ingresado por el usuario.
 *
 */
float operadorB(void)
{
    float valorB;
    printf("                Ingrese valor B: ");
    scanf("%f", & valorB);

    return valorB;
}

/** \brief Funcion que suma el valor A y el valor B.
 *
 * \param x float Representa el valor A.
 * \param y float Representa el valor B.
 * \return float Retorna el resultado de la suma.
 *
 */
float suma(float x, float y)
{
    float resultadoSuma;

    resultadoSuma = x + y ;

    return resultadoSuma;
}

/** \brief Funcion que resta el valor A y el valor B.
 *
 * \param x float Representa el valor A.
 * \param y float Representa el valor B.
 * \return float Retorna el resultado de la resta.
 *
 */
float resta(float x, float y)
{
    float resultadoResta;

    resultadoResta = x - y ;

    return resultadoResta;
}

/** \brief Funcion que multiplica el valor A por el valor B.
 *
 * \param x float Representa el valor A.
 * \param y float Representa el valor B.
 * \return float Retorna el resultado de la multiplicacion.
 *
 */
float multiplicacion(float x, float y)
{
    float resultadoMulti;

    resultadoMulti = x * y ;

    return resultadoMulti;
}

/** \brief Funcion que divide el valor A por el valor B.
 *
 * \param x float Representa el valor A.
 * \param y float Representa el valor B.
 * \return float Retorna el resultado de la division.
 *
 */
float division(float x, float y)
{
    float resultadoDiv;

    if(y!=0)
    {
        resultadoDiv = x / y ;
    }

    else
        {
            printf("                No es posible dividir por 0\n");
        }


    return resultadoDiv;
}

/** \brief Funcion que da el factorial del valor A.
 *
 * \param x float Representa el valor A.
 * \return float Retorna el resultado factorial del valor A.
 *
 */
float factorialA(float x)
{
    float factA;
    factA = 1;
    float factorialUno;
    if (x>=0)
    {
        for (factorialUno=x; factorialUno>1; factorialUno--)
        {
            factA =factA*factorialUno;
        }
    }
    return factA;
}

/** \brief Funcion que da el factorial del valor B.
 *
 * \param y float Representa el valor B.
 * \return float  Retorna el resultado factorial del valor B.
 *
 */
float factorialB(float y)
{
    float factB;
    factB = 1;
    float factorialDos;
    if (y>=0)
    {
        for (factorialDos=y; factorialDos>1; factorialDos--)
        {
            factB =factB*factorialDos;
        }
    }
    return factB;
}




