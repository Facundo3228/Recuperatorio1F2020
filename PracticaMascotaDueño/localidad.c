#include "localidad.h"

void hardcodearLocalidad(sLocalidad localidad[], int tamL)
{
    int i;

    int idLocalidad[10] = {1,2,3};
    char provincia[10][100] = {"Arrugado", "Callegero", "Policial", "Dogo", "Lagarto obero", "Camaleon" };
    int codigoPostal[10] = {};
    char descripcion[10][100] = {"Persa", "Egipcio", "Aleman", "Argentina", "Colombia", "India"};
    int estado[10] = {1,1,1,1,1,1};

    for(i = 0; i < tamL; i++)
    {
        raza[i].idRaza = idRaza[i];
        strcpy(raza[i].nombreRaza, nombreRaza[i]);
        strcpy(raza[i].pais, pais[i]);
        raza[i].estado = estado[i];
    }
}
