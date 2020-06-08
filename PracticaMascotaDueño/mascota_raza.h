#include "mascota.h"
#include "raza.h"
#include "harryio.h"

typedef struct
{
  int idRazaMascota;

}sMascota_sRaza;


#ifndef MASCOTA_RAZA_H_INCLUDED
#define MASCOTA_RAZA_H_INCLUDED

void mostraMascotasRazaPorTipo(sMascota mascota[], int tamMascota, sRaza raza[], int tamRaza, int ocupado);

#endif // MASCOTA_RAZA_H_INCLUDED
