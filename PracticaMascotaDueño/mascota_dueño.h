#include "mascota.h"
#include "dueño.h"
#include "raza.h"
#include "harryio.h"

typedef struct mascota_duenio
{
  int idDuenioMascota;
  int contadorMascotasDuenio;

}sMascota_sDuenio;


void mostrarMascotaDuenio(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza rasa[], int tamRaza, int ocupado);

int eliminarDuenioCascada(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, int ocupado, int libre);

void ordenarMascotaTipoListadaDuenio(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, sRaza raza[], int tamRaza, int ocupado, int libre);

void inisializarMascotaDuenio(sMascota_sDuenio aux_Duenio_Mascota[], sDuenio duenio[], int tamDuenio);

void contadoMascotaDuenio(sMascota_sDuenio aux_Duenio_Mascota[], int tamDuenio, sMascota mascota[], int tamMascota, int ocupado);

void mostrarClientesConMasDeUnaMascota(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, int ocupado);

void mostrarMascotaMasTresDuenio(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza, int ocupado);

void ordenarDueniosCantidadMascota(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, sRaza raza[], int tamRaza, int ocupado);

void ordenarDueniosCantidadMascotaYOrdenAlfabeticoNombre(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, sRaza raza[], int tamRaza, int ocupado);

int altaMascotaDuenioRaza(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza, int libre, int ocupado);

int modificarMascotaRazaDuenio(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza,  int ocupado);

void mostrarMascotaDuenioMismoSexo(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza, int ocupado);


