#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include <stdio.h>

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
    int isEmpty;
}eEmployee;

typedef struct
{
    int id;
    char info[51];
}eSector;

/** \brief Print the main menu
 *
 * \return Opción elegida por el usuario
 *
 */
int menu();

/** \brief Calculates total average wages and employees that exceed the average wage
 *
 * \param list[] eEmployee The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */
int menuModify();

/** \brief Run through the array to see if it's empty
 *
 * \param list[] eEmployee The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */
void initEmployees(eEmployee list[], int tam);

/** \brief Gets the first free index of the array
 *
 * \param list[] eEmployee The array is passed as a parameter
 * \param tam int Array size
 * \return int The first available index
 *
 */
int searchFree(eEmployee list[], int tam);

void listSectors(eSector sectors[], int tam);

/** \brief Search for an employee receiving their ID as a search parameter
 *
 * \param list[] eEmployee
 * \param tam int
 * \return int
 *
 */

int findEmployeeById(eEmployee list[], int tam, int idNew);

/** \brief Request the data to load
 *
 * \param list[] eEmployee The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */

void addEmployees(eEmployee list[], int tam, eSector sectors[], int tamSector);

/** \brief Find the employee id and delete it
 *
 * \param list [] eEmploye The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */

void removeEmployee(eEmployee list[], int tam);

/** \brief Modify saved employee data
 *
 * \param list [] eEmploye The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */

void modifyEmployee(eEmployee list [], int tam, eSector sectors[], int tamSector);

/** \brief Displays saved employee data
 *
 * \param eEmploye The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */

void showEmployee(eEmployee oneEmployee, eSector sectors [], int tam);

/** \brief Displays saved employees data
 *
 * \param eEmploye The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */

void showEmployees(eEmployee list[], int tam, eSector sectors[], int tamSector);

void getSector(eSector sectors[], int tam, int idSector, char string[]);

/** \brief Compare names and order them alphabetically
 *
 * \param list [] eEmploye The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */

void orderEmployees(eEmployee list[], int tam);

/** \brief Calculate average wages, sum, and employees that exceed the average wage
 *
 * \param list [] eEmploye The array is passed as a parameter
 * \param tam int Array size
 * \return
 *
 */

float averageSalary(eEmployee list[], int tam);

#endif // ARRAYEMPLOYEES_H_INCLUDED
