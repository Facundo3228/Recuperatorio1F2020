#include <stdio.h>
#include <stdlib.h>
#include "mascota_dueño.h"
//#include "mascota_raza.h"
#include "harryio.h"

#define TAMD 10
#define TAMM 20
#define TAMR 20
#define TAML 10
#define LIBRE 0
#define OCUPADO 1

int main()
{
    sDuenio duenio[10];
    sMascota mascota[20];
    sRaza raza[20];
    sLocalidad[10];

    int eleccion;
    float promedio;

    inicializarDuenio(duenio,TAMD,LIBRE);
    inicializarMascota(mascota,TAMM,LIBRE);
    inicializarRaza(raza, TAMR, LIBRE);


    hardcodearDuenio(duenio,TAMD);
    hardcodearMascota(mascota,TAMM);
    hardcodearRaza(raza, TAMR);


    printf("\n\t\t------BIENVENIDO AL ABM DE LA VETERINARIA------\n");
    system("pause");
    do
    {
        system("clear");
        printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MENU DE LA VETERINARIA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
        printf("\t\t_________________________________________________________________________________________________\t\t\n");
        printf("\t\t| (1) MOSTRAR CLIENTES                                                           \t\t|\n");
        printf("\t\t| (2) MOSTRAR MASCOTAS                                                           \t\t|\n");
        printf("\t\t| (3) MOSTRAR CLIENTES CON SUS MASCOTAS                                          \t\t|\n");

        printf("\t\t| (4) AGREGAR UNA MASCOTA                                                        \t\t|\n");
        printf("\t\t| (5) ELIMINAR UNA MASCOTA                                                       \t\t|\n");
        printf("\t\t| (6) MODIFICAR MASCOTA                                                          \t\t|\n");

        printf("\t\t| (7) AGREGAR UN CLIENTE                                                         \t\t|\n");
        printf("\t\t| (8) ELIMINAR CLIENTE Y SUS MASCOTAS (CASCADA)                                  \t\t|\n");
        printf("\t\t| (9) ORDENAR LAS MASCOTAS POR TIPO Y MOSTRARLAS CON SU CLIENTE                  \t\t|\n");

        printf("\t\t| (10) MODIFICAR CLIENTE                                                         \t\t|\n");
        printf("\t\t| (11) MOSTRAR CLIENTES CON MAS DE UNA MASCOTA                                   \t\t|\n");
        printf("\t\t| (12) MOSTRAR MASCOTAS CON MAS DE 3 AÑOS DE EDAD CON SUS CLIENTE                \t\t|\n");

        printf("\t\t| (13) MOSTRAR MASCOTAS POR TIPO                                                 \t\t|\n");
        printf("\t\t| (14) ORDENAR LOS CLIENTES POR CANTIDAD DE MASCOTAS                             \t\t|\n");
        printf("\t\t| (15) ORDENAR LOS CLIENTES POR CANTIDAD DE MASCOTAS Y POR ORDEN ALFABETICO SEGUN SU NOMBRES\t|\n");
        printf("\t\t| (16) PROMEDIO DE EDADES DE LAS MASCOTAS                                        \t\t|\n");
        printf("\t\t| (17) PROMEDIO DE EDADES DE LAS MASCOTAS POR TIPO                               \t\t|\n");
        printf("\t\t| (18) PROMEDIO DE LOS CLIENTES HOMBRES Y MUJERES                                \t\t|\n");

        printf("\t\t| (1818) PORCENTAJE DE MUJERES SOBRE EL TOTAL DE CLIENTES                        \t\t|\n");
        printf("\t\t| (19) MOSTRAR LOS CLIENTES QUE TIENEN MASCOTAS DEL MISMO SEXO                   \t\t|\n");

        printf("\t\t| (20) SALIR                                                                     \t\t|\n");
        printf("\t\t_________________________________________________________________________________________________\t\t\n\t\t|");
        fflush(stdin);
        //__fpurger(stdin);

        eleccion = getInt(" ELIJA UNA OPCION DEL MENU: ",
                          "\t\t|\n\t\t| ELIJA UNA OPCION DEL MENU: ", 1, 2000, 1);
        system("clear");
        switch(eleccion)
        {
        case 1:
        {
            system("clear");
            mostrarDuenio(duenio,TAMD,OCUPADO);
            system("pause");
            break;
        }
        case 2:
        {
            system("clear");
            mostrarMascota(mascota,TAMM,OCUPADO);
            //mostrarRaza(raza, TAMR, OCUPADO);
            system("pause");
            break;
        }
        case 3:
        {
            system("clear");
            mostrarMascotaDuenio(mascota,TAMM,duenio,TAMD, raza, TAMR, OCUPADO);
            system("pause");
            break;
        }
        case 4:
        {
            //mostrarDuenio(duenio,TAMD,OCUPADO);
            //altaMascota(mascota,TAMM,LIBRE,OCUPADO);
            altaMascotaDuenioRaza(mascota, TAMM, duenio, TAMD, raza, TAMR, LIBRE, OCUPADO);
            system("pause");
            break;
        }
        case 5:
        {

            bajaMascota(mascota,TAMM,OCUPADO,LIBRE);
            system("pause");
            break;
        }
        case 6:
        {
            //mostrarMascota(mascota,TAMM,OCUPADO);
            //modificarMascota(mascota,TAMM,OCUPADO);
            modificarMascotaRazaDuenio(mascota, TAMM, duenio, TAMD, raza, TAMR, OCUPADO),
                                       system("pause");
            break;
        }

        case 7:
        {
            altaDuenio( duenio, TAMD,  LIBRE,  OCUPADO);
            system("pause");
            break;
        }
        case 8:
        {
            eliminarDuenioCascada(duenio, TAMD, mascota, TAMM, OCUPADO, LIBRE);
            system("pause");
            break;
        }

        case 9:
        {
            ordenarMascotaTipoListadaDuenio(duenio, TAMD, mascota, TAMM, raza, TAMR, OCUPADO, LIBRE);
            system("pause");
            break;
        }

        case 10:
        {
            //mostrarDuenio(duenio,TAMD,OCUPADO);
            modificarDuenio(duenio, TAMD, OCUPADO);
            system("pause");
            break;
        }
        case 11:
        {
            mostrarClientesConMasDeUnaMascota(duenio, TAMD, mascota, TAMM, OCUPADO);
            system("pause");
            break;
        }

        case 12:
        {
            mostrarMascotaMasTresDuenio(mascota, TAMM, duenio, TAMD, raza, TAMR, OCUPADO);
            system("pause");
            break;
        }

        case 13:
        {
            mostraMascotasRazaPorTipo(mascota, TAMM, raza, TAMR, OCUPADO);
            system("pause");
            break;
        }
        case 14:
        {
            ordenarDueniosCantidadMascota(duenio, TAMD, mascota, TAMM, raza, TAMR, OCUPADO);
            system("pause");
            break;
        }

        case 15:
        {
            ordenarDueniosCantidadMascotaYOrdenAlfabeticoNombre(duenio, TAMD, mascota, TAMM, raza, TAMR, OCUPADO);
            system("pause");
            break;
        }

        case 16:
        {
            promedio = promedioEdadMascota(mascota, TAMM, OCUPADO);
            printf("\nEL PROMEDIO ES: %.2f\n", promedio),
            system("pause");
            break;
        }
        case 17:
        {
            promedio = promedioEdadMascotaPorTipo(mascota, TAMM, OCUPADO);
            printf("\nEL PROMEDIO POR TIPO DE MASCOTA ES: %.2f\n", promedio),
            system("pause");
            break;
        }

        case 18:
        {
            promediodevaronesYMujeres(duenio, TAMD, OCUPADO);
            system("pause");
            break;
        }

        case 1818:
        {
            porcentajeMujeres(duenio, TAMD, OCUPADO);
            system("pause");
            break;
        }
        case 19:
        {
            mostrarMascotaDuenioMismoSexo(mascota, TAMM, duenio, TAMD, raza, TAMR, OCUPADO);
            system("pause");
            break;
        }
        case 20:
        {
            printf("Hasta la proxima!");
            break;
        }
        default:
            printf("\nOPCION NO IMPLEMENTADA...\n");
            break;
        }
    }
    while(eleccion != 20);

    return 0;
}
