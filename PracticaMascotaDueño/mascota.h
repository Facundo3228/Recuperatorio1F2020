#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harryio.h"


typedef struct
{
    int idMascota;
    int idDuenio; //FK
    int idRaza; //FK
    char nombre[20];
    char tipo[20];
    char raza[20];
    int edad;
    float peso;
    char sexo[20];
    int estado;
}sMascota;

void hardcodearMascota(sMascota mascota[], int tamM);

void inicializarMascota(sMascota mascota[], int tamM ,int libre);

void mostrarMascota(sMascota mascota[], int tamM, int ocupado);

int buscarIdMascota(sMascota mascota[], int tamM, int ocupado);

int generarIDMascota(sMascota mascota[],int tamM, int libre);

int altaMascota(sMascota mascota[], int tamM, int libre, int ocupado);

int buscarLibreMascota(sMascota mascota[], int tamM, int libre);

int bajaMascota(sMascota mascota[], int tamM, int Ocupado, int libre);

int modificarMascota(sMascota mascota[], int tamM, int ocupado);

void mostraMascotasPorTipo(sMascota mascota[], int tamM, int ocupado);

float promedioEdadMascota(sMascota mascota[], int tamM, int ocupado);

float promedioEdadMascotaPorTipo(sMascota mascota[], int tamM, int ocupado);

