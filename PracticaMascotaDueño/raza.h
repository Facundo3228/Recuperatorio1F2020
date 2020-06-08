#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harryio.h"

typedef struct
{
  int idRaza;
  char nombreRaza[50];
  char pais[50];
  int estado;
}sRaza;


#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

void hardcodearRaza(sRaza raza[], int tamR);

void inicializarRaza(sRaza raza[], int tamR, int libre);

int generarIDRaza(sRaza raza[],int tamR, int libre);

void mostrarRaza(sRaza raza[],int tamR, int ocupado);



#endif // RAZA_H_INCLUDED
