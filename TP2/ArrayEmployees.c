#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int menu ()
{
  int opcion;

  system ("cls");

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("                                  AMB\n");
  printf("                      Nazarena Florencia Rusin 1F\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf ("                         1) Alta empleado\n");
  printf ("                         2) Modificar empleado\n");
  printf ("                         3) Baja empleado\n");
  printf ("                         4) Informar\n");
  printf ("                         5) Salir\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf ("                         *Ingrese una opcion: ");
  fflush (stdin);
  scanf ("%d", & opcion);



  system ("pause");
  return opcion;
}


void initEmployees(eEmployee vec[], int tam)
{
   for (int i = 0; i < tam; i++)
    {
      vec[i].isEmpty = 1;
    }
}

int searchFree(eEmployee list[], int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if(list[i].isEmpty ==1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int findEmployeeById(eEmployee list[], int tam, int idNew)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(list[i].id == idNew && list[i].isEmpty==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void addEmployees(eEmployee list[], int tam, eSector sectors[], int tamSector)
{
    int indice;
    int idSector;

    eEmployee newEmployee;

    indice = searchFree(list, tam);

    system("cls");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                            Alta empleados\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if(indice == -1)
    {
        printf("No hay lugar");
        system("pause");
    }

        else
        {
            printf("\nIngresar nombre: ");
            fflush(stdin);
            scanf("%s", &newEmployee.name);

            printf("\nIngresar apellido: ");
            fflush(stdin);
            scanf("%s", &newEmployee.lastName);

            printf("\nIngresar sueldo: ");
            fflush(stdin);
            scanf("%f", &newEmployee.salary);

            listSectors(sectors,tamSector);

            printf("\nIngrese Sector: ");
            scanf("%d", &idSector);

            newEmployee.idSector = idSector;
            newEmployee.id = 0 + indice;
            newEmployee.isEmpty = 0;
            list[indice] = newEmployee;

        }
}

void removeEmployee(eEmployee list[], int tam)
{
    int id;
    int indice;
    char seguir;

    system("cls");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                            Baja de empleados\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("\nIngrese numero de ID: ");
    scanf("%d", &id);

    indice = findEmployeeById(list, tam, id);

    if(indice == -1)
    {
        printf("\nNo se encuentra ningun empleado con ese numero de ID.\n");
        system("pause");
    }

        else
        {
            printf("\nDesea eliminar a este empleado?: ");
            fflush(stdin);
            scanf("%c", & seguir);

            if(seguir == 's')
            {
                list[indice].isEmpty = 1;
                printf("\nSe ha eliminado al empleado con exito.");
            }

                else
                    {
                        printf("\nSe ha cancelado la eliminacion del empleado.\n");
                    }

                system("pause");
        }
}

void modifyEmployee(eEmployee list [], int tam, eSector sectors[], int tamSector)
{
    int id;
    int indice;
    char seguir;

    eEmployee newDataEmployee;

    system("cls");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                        \nModificar Empleado\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("\nIngrese ID: ");
    scanf("%d", &id);

    indice = findEmployeeById(list, tam, id);

    if(indice == -1)
    {
        printf("\nNo se encuentra ningun empleado con ese numero de ID.\n", id);
        system("pause");
    }

        else
        {
            do
                {
                    printf("\nDesea modificar este empleado?: ");
                    fflush(stdin);
                    scanf("%c", & seguir);
                    seguir = tolower(seguir);
                }while(seguir !='s' && seguir!= 'n');

                    if(seguir == 's')
                    {
                        do
                        {
                            switch(menuModify())
                            {
                            case 1:
                                printf("\nIngrese ID: ");
                                scanf("%d", newDataEmployee.id);
                                list[indice].id = newDataEmployee.id;
                                break;

                            case 2:
                                printf("\nIngrese nombre: ");
                                fflush(stdin);
                                scanf("%s", &newDataEmployee.name);
                                strcpy(list[indice].name, newDataEmployee.name);
                                break;

                            case 3:
                                printf("\nIngrese apellido: ");
                                fflush(stdin);
                                scanf("%s", &newDataEmployee.lastName);
                                strcpy(list[indice].lastName, newDataEmployee.lastName);
                                break;

                            case 4:
                                printf("\nIngrese sueldo: ");
                                scanf("%f", &newDataEmployee.salary);
                                list[indice].salary = newDataEmployee.salary;
                                break;

                            case 5:
                                listSectors(sectors, tamSector);
                                printf("\nIngrese Sector: ");
                                scanf("%d", &newDataEmployee.idSector);
                                list[indice].idSector = newDataEmployee.idSector;
                                break;

                            case 6:
                                seguir = 'n';
                                break;

                            default:
                                printf("\nError, ingrese una opcion valida.\n");
                                system("pause");
                                break;
                            }

                        }while (seguir != 'n');

                        printf("\nSe ha modificado el empleado exitosamente.\n");
                        system("pause");
                    }
        }
}

int menuModify()
{
    int opcion;

    system("cls");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\nModificar empleado\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n1) ID");
    printf("\n2) Nombre");
    printf("\n3) Apellido");
    printf("\n4) Sueldo");
    printf("\n5) Sector");
    printf("\n6) Salir");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void listSectors(eSector sectors[], int tam)
{
    printf("\nSectores\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d\n", sectors[i].id, sectors[i].info);
    }
}

void getSector(eSector sectors[], int tam, int idSector, char string[])
{
    for(int i=0; i<tam; i++)
    {
        if(sectors[i].id == idSector)
        {
            strcpy(string, sectors[i].info);
        }
    }
}

void showEmployee(eEmployee oneEmployee, eSector sectors [], int tam)
{
    char showMeEmployee[51];

    getSector(sectors, tam, oneEmployee.idSector, showMeEmployee);

    printf("%d %10s %10s %6.2f %10s", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, showMeEmployee);
}

void showEmployees(eEmployee list[], int tam, eSector sectors[], int tamSector)
{
    system("cls");
    orderEmployees(list, tam);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\nID  NOMBRE  APELLIDO  SUELDO  SECTOR\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


    for(int i=0; i<tam; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showEmployee(list[i], sectors, tamSector);
        }
    }

    system("pause");
}

void orderEmployees(eEmployee list[], int tam)
{
    eEmployee axuEmployee;

    for(int i=0; i<tam-1; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if(strcmp(list[i].name, list[j].lastName) >0)
            {
                axuEmployee = list[i];
                list[i] = list [j];
                list[i] = axuEmployee;
            }
        }
    }
}

float averageSalary(eEmployee list[], int tam)
{
    float sum = 0;
    float average;
    int i;
    int flag=0;
    int contEmployees=0;
    int contExceedsAverage=0;

        if(list!=0)
        {
            for(i=0; i<tam; i++)
            {
                if(list[i].isEmpty ==0)
                {
                    sum = sum + list[i].salary;
                    contEmployees++;
                    average=sum/contEmployees;
                }
            }

                for(i=0; i<tam; i++)
                {
                    if(list[i].isEmpty == 0)
                    {
                        if(list[i].salary > average)
                        {
                            contExceedsAverage++;
                        }
                    }
                }
                    printf("\nLa suma total de los salarios es de: %.2f", sum);
                    printf("\nEl promedio total de los salarios es de: %.2f", average);
                    printf("\nLos empleados que superan el salario promedio son: %d", contExceedsAverage);
                    flag=1;
        }

    return flag;
}
