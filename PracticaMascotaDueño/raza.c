#include "raza.h"

void hardcodearRaza(sRaza raza[], int tamR)
{
    int i;

    int idRaza[20] = {100,101,102,103,104,105};
    char nombreRaza[20][51] = {"Arrugado", "Callegero", "Policial", "Dogo", "Lagarto obero", "Camaleon" };
    char pais[20][51] = {"Persa", "Egipcio", "Aleman", "Argentina", "Colombia", "India"};
    int estado[20] = {1,1,1,1,1,1};

    for(i = 0; i < tamR; i++)
    {
        raza[i].idRaza = idRaza[i];
        strcpy(raza[i].nombreRaza, nombreRaza[i]);
        strcpy(raza[i].pais, pais[i]);
        raza[i].estado = estado[i];
    }
}

void inicializarRaza(sRaza raza[], int tamR, int libre)
{
    int i;
    for(i = 0; i < tamR; i++)
    {
        raza[i].estado = libre;
        raza[i].idRaza = 0;
    }
}

int generarIDRaza(sRaza raza[], int tamR, int libre)
{
    int i;
    int may = raza[0].idRaza;

    for(i = 0; i < tamR; i++)
    {
        if(i == 0 || raza[i].idRaza > may )
        {
            may = raza[i].idRaza;
        }
    }
    return may+1;
}

void mostrarRaza(sRaza raza[], int tamR, int ocupado)
{
    int i;

    printf("\n\t\t>>>>>>>>>>>>> RAZA DE MASCOTAS <<<<<<<<<<<<<<\n");
    printf("\t\t_____________________________________________\t\t\n");
    printf("\n\t\t| N\t ID\t     \tRAZA\t     \tPAIS|\n");
    printf("\t\t_____________________________________________\t\t\n");

    for(i = 0; i < tamR; i++)
    {
        if(raza[i].estado == ocupado)
        {
            printf("%19d %7d %16s %15s\n",
                   i+1,
                   raza[i].idRaza,
                   raza[i].nombreRaza,
                   raza[i].pais
                  );
        }
    }
}

