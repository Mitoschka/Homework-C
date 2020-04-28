#include <stdio.h>
#include "Sort.h"
#include <string.h>

void algorithm(int n, int m, char names[][30], char nameSort[][30], int loyalty[], int helpLoyalty[], int helpNames[], int amountOfPersons)
{
    for (int i = 0; i < n; i++)
    {
        bool array[1000]{};
        qsortForInt(0, amountOfPersons - 1, loyalty, helpLoyalty);
        qsortForStrings(0, amountOfPersons - 1, names, helpNames);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", names[helpLoyalty[i]]);
            array[helpLoyalty[i]] = true;
        }

        int j = 0;
        while (m > 0)
        {
            if (!array[helpNames[j]])
            {
                printf("%s\n", nameSort[j]);
                m--;
                array[helpNames[j]] = true;
            }
            j++;
        }

        for (int i = 0; i < amountOfPersons; i++)
        {
            if (!array[i])
            {
                printf("%s", names[i]);
            }
        }
    }
}

int main()
{
    char names[1000][30]{};
    char nameSort[1000][30]{};
    int loyalty[1000]{};
    int helpLoyalty[1000]{};
    int helpNames[1000]{};
    int amountOfPersons;
    int n;
    int m;
    printf("Input n : ");
    scanf("%d", &n);
    printf("Input m : ");
    scanf("%d", &m);
    printf("Input amount of persons : ");
    scanf("%d", &amountOfPersons);
    for (int i = 0; i < amountOfPersons; i++)
    {
        char name;
        printf("Input person :");
        scanf("%s", names[i]);
        printf("Input loyalty : ");
        scanf("%d", &loyalty[i]);
        strcpy(nameSort[i], names[i]);
        helpLoyalty[i] = i;
        helpNames[i] = i;
    }
    algorithm(n, m, names, nameSort, loyalty, helpLoyalty, helpNames, amountOfPersons);
}

