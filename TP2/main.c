#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000
#include "ArrayEmployees.h"

int main()
{
    char seguir = 's';

    eSector sectors[]= {{1,"Sistemas\n"}, {2,"Ventas\n"}, {3,"Compras\n"}, {4,"Administracion\n"}, {5,"Tesoreria\n"}};

    eEmployee employees[TAM];
    initEmployees(employees, TAM);

    do
    {
      switch (menu ())

        {
            system("cls");
        case 1:
          addEmployees(employees, TAM, sectors, 5);
          break;

        case 2:
          modifyEmployee(employees, TAM, sectors, 5);
          break;

        case 3:
          removeEmployee(employees, TAM);
          break;

        case 4:
          showEmployees(employees, TAM, sectors, 5);
          break;

        case 5:
          seguir = 'n';
          break;

        default:
          printf ("Error, reingrese una opcion valida\n");
          break;
          system ("pause");

        }
    }while (seguir == 's');

return 0;
}
