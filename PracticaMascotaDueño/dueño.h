#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harryio.h"

typedef struct
{
    int idDuenio;
    char nombre[51];
    char apellido[51];
    char localidad[51];
    char telefono[51];
    int edad;
    char sexo[51];
    int estado;
}sDuenio;

void hardcodearDuenio(sDuenio duenio[],int tamD);

void inicializarDuenio(sDuenio duenio[],int tamD ,int libre);

void mostrarDuenio(sDuenio duenio[],int tamD, int ocupado);

int buscarLibreDuenio(sDuenio duenio[],int tamD, int libre);

int buscarIdDuenio(sDuenio duenio[], int tamD, int ocupado);

int altaDuenio(sDuenio duenio[],int tamD, int libre, int ocupado);

int modificarDuenio(sDuenio duenio[], int tamD, int ocupado);

void promediodevaronesYMujeres(sDuenio duenio[], int tamD, int ocupado);

void porcentajeMujeres(sDuenio duenio[], int tamD, int ocupado);

