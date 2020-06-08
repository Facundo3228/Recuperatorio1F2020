#include "mascota_raza.h"

//MOSTRAR MASCOTA POR TIPO (13)
void mostraMascotasRazaPorTipo(sMascota mascota[], int tamMascota, sRaza raza[], int tamRaza, int ocupado)
{
    int i,j;
    char respuesta[10];
    int opcion;

    do
    {
        printf("\n\n\t\t>>>>>>>>>>> MOSTRAR POR TIPO DE MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
        printf("\t\t_____________________________________________________________\t\t\n");
        printf("\t\t| (1) TIPO GATO         \t\t|\n");
        printf("\t\t| (2) TIPO PERRO        \t\t|\n");
        printf("\t\t| (3) TIPO RARO         \t\t|\n");
        printf("\t\t________________________________________________________\t\t\n\t\t|");
        fflush(stdin);
        //__fpurger(stdin);

        opcion = getInt(" ELIJA UNA OPCION DEL MENU: ",
                        "\t\t|\n\t\t| ELIJA UNA OPCION DEL MENU: ", 1, 4, 1);
        system("clear");

        switch(opcion)
        {
        case 1:
        {
            system("clear");
            strcpy(respuesta, "Gato");
            break;
        }
        case 2:
        {
            system("clear");
            strcpy(respuesta, "Perro");

            break;
        }
        case 3:
        {
            system("clear");
            strcpy(respuesta, "Raro");
            break;
        }
        default:
            printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
            system("pause");
            break;
        }
    }
    while(opcion != 1 && opcion != 2 && opcion != 3);

    printf("\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("\t\t_____________________________________________________________________________________\t\t\n");
    printf("\n\t\t| N          NOMBRE\t  TIPO             RAZA \tPAIS \tEDAD \tPESO \tSEXO|\n");
    printf("\t\t_____________________________________________________________________________________\t\t\n");

    for(i = 0; i < tamMascota; i++)
    {
        if(mascota[i].estado == ocupado && strcmpi(mascota[i].tipo, respuesta) == 0)
        {
            for(j = 0; j < tamRaza; j++)
            {
                if(raza[j].estado == ocupado && raza[j].idRaza == mascota[i].idRaza)
                {

                    printf("%19d %15s %10s %16s %12s %7d %7.2f %7s\n",
                           i+1,
                           mascota[i].nombre,
                           mascota[i].tipo,
                           raza[j].nombreRaza,
                           raza[j].pais,
                           mascota[i].edad,
                           mascota[i].peso,
                           mascota[i].sexo);
                }
            }


        }
    }
}
