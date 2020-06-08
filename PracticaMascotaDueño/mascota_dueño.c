#include "mascota_dueño.h"

//LAS MASCOTAS CON EL DUENIO CORESPONDIENTE. (3)
void mostrarMascotaDuenio(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza, int ocupado)
{
    int i,j,k;

    for(i=0; i<tamDuenio; i++)
    {

        if(duenio[i].estado == ocupado)
        {
            printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DUENIOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("\n\t\t| N \tID \tNOMBRE\t APELLIDO\t LOCALIDAD\t TELEFONO\t SEXO |\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("%19d %6d %11s %10s %16s %14s %11s\n",
                   i+1,
                   duenio[i].idDuenio,
                   duenio[i].nombre,
                   duenio[i].apellido,
                   duenio[i].localidad,
                   duenio[i].telefono,
                   duenio[i].sexo
                  );

            printf("\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("\n\t\t| N          NOMBRE\t  TIPO             RAZA \tPAIS \tEDAD \tPESO \tSEXO|\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");

            for(j=0; j<tamMascota; j++)
            {

                if(mascota[j].estado == ocupado && mascota[j].idDuenio == duenio[i].idDuenio)
                {
                    for(k = 0; k < tamRaza; k++)
                    {
                        if(raza[k].estado == ocupado && mascota[j].idRaza == raza[k].idRaza)
                        {
                            printf("%19d %15s %10s %16s %12s %7d %7.2f %7s\n",
                                   j+1,
                                   mascota[j].nombre,
                                   mascota[j].tipo,
                                   raza[k].nombreRaza,
                                   raza[k].pais,
                                   mascota[j].edad,
                                   mascota[j].peso,
                                   mascota[j].sexo);
                        }
                    }
                }

            }
            printf("\t\t_____________________________________________________________________________________\t\t\n");
        }
    }
}

//ELIMINACION DE MASCOTAS Y DUENIO EN CASCADA. (8)
int eliminarDuenioCascada(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, int ocupado, int libre)
{
    int aux;
    int i; //mascota
    int retorno = -1; //SI ES INCORRECTO

    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ELIMINAR DUENIOS Y MASCOTAS EN CASCADA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    aux = buscarIdDuenio(duenio, tamDuenio, ocupado);

    if(aux != -1)
    {
        for(i = 0; i < tamMascota; i++)
        {
            if(mascota[i].idDuenio == duenio[aux].idDuenio)
            {
                mascota[i].estado = libre;
                duenio[aux].estado = libre;
                retorno = 1; //CORRECTO
            }

        }
    }

    return retorno; //RETORNO DE CONTROL
}

//ORDENAMIENTO DE MASCOTAS POR TIPO CON SUS DUENIOS. (9)
void ordenarMascotaTipoListadaDuenio(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, sRaza raza[], int tamRaza, int ocupado, int libre)
{
    int i;//mascotas-1
    int j;//mascotas i+1
    sMascota auxMascotaTipo;

    for(i = 0; i < tamMascota-1; i++)
    {
        for(j = i+1; j < tamMascota; j++)
        {
            if(mascota[i].estado == ocupado && mascota[j].estado == ocupado)
            {
                if(strcmp(mascota[i].tipo, mascota[j].tipo )> 0)
                {
                    auxMascotaTipo = mascota[i];
                    mascota[i] = mascota[j];
                    mascota[j] = auxMascotaTipo;
                }
            }
        }
    }
    mostrarMascotaDuenio(mascota, tamMascota, duenio, tamDuenio, raza, tamRaza, ocupado);
}

//INICIALIZAR ARRAY AUX DE LA ESTRUCTURA MASCOTA DUENIO. (11)
void inisializarMascotaDuenio(sMascota_sDuenio aux_Duenio_Mascota[], sDuenio duenio[], int tamDuenio)
{
    int i;
    //for que inicializa
    for(i = 0; i < tamDuenio; i++)
    {
        aux_Duenio_Mascota[i].idDuenioMascota = duenio[i].idDuenio;
        aux_Duenio_Mascota[i].contadorMascotasDuenio = 0;
    }
}

//CONTADOR DE MASCOTAS DE CADA DUENIO. (11)
void contadoMascotaDuenio(sMascota_sDuenio aux_Duenio_Mascota[], int tamDuenio, sMascota mascota[], int tamMascota, int ocupado)
{
    int i,j;
    //for que recorre los arrays
    for(i = 0; i < tamDuenio; i++)
    {
        for(j = 0; j < tamMascota; j++)
        {
            if(mascota[j].estado == ocupado && mascota[j].idDuenio == aux_Duenio_Mascota[i].idDuenioMascota)
            {
                aux_Duenio_Mascota[i].contadorMascotasDuenio++;
            }
        }
    }
}

//FUNCION QUE MUESTRA A LOS DUENIOS CON MAS DE UNA MASCOTA. (11)
void mostrarClientesConMasDeUnaMascota(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, int ocupado)
{
    sMascota_sDuenio aux_Duenio_Mascota[tamDuenio];//ARRAY AUX DE TIPO MASCOTA_DUENIO.

    int i;//Duenio
    int j;//Mascota

    inisializarMascotaDuenio( aux_Duenio_Mascota, duenio, tamDuenio); //LLAMADO A LA FUNCION INICIALIZAR

    contadoMascotaDuenio( aux_Duenio_Mascota, tamDuenio, mascota, tamMascota, ocupado); //LLAMADO A LA FUNCION QUE CUENTA LA CANTIDAD DE MASCOTAS DE CADA DUENIO

    //for que muestra la relacion
    for(i = 0; i < tamDuenio; i++) //RECORRO EL AUX_DUENIO_MASCOTA
    {
        for(j = 0; j < tamDuenio; j++) //duenio
        {
            if(duenio[j].estado == ocupado && duenio[j].idDuenio == aux_Duenio_Mascota[i].idDuenioMascota && aux_Duenio_Mascota[i].contadorMascotasDuenio > 1)
            {
                printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>> DUENIOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
                printf("\t\t______________________________________________________________________\t\t\n");
                printf("\n\t\t| N \tID \tNOMBRE\t \tAPELLIDO\t CANTIDAD DE MASCOTAS|\n");
                printf("\t\t______________________________________________________________________\t\t\n");
                printf("%19d %6d %11s %17s %16d \n",
                       j+1,
                       duenio[j].idDuenio,
                       duenio[j].nombre,
                       duenio[j].apellido,
                       aux_Duenio_Mascota[j].contadorMascotasDuenio);
            }
        }
    }

}

//MUESTRA A LOS DUENIOS CON MAS DE TRES MASCOTA. (12)
void mostrarMascotaMasTresDuenio(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza, int ocupado)
{
    int i, j, k;

    for(i = 0; i < tamDuenio; i++)
    {

        if(duenio[i].estado == ocupado)
        {
            printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DUENIOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("\n\t\t| N \tID \tNOMBRE\t APELLIDO\t LOCALIDAD\t TELEFONO\t SEXO |\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("%19d %6d %11s %10s %16s %14s %11s\n",
                   i+1,
                   duenio[i].idDuenio,
                   duenio[i].nombre,
                   duenio[i].apellido,
                   duenio[i].localidad,
                   duenio[i].telefono,
                   duenio[i].sexo
                  );

            printf("\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("\n\t\t| N          NOMBRE\t  TIPO             RAZA \tPAIS \tEDAD \tPESO \tSEXO|\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");

            for(j=0; j<tamMascota; j++)
            {

                if(mascota[j].estado == ocupado && mascota[j].idDuenio == duenio[i].idDuenio && mascota[j].edad > 3)
                {
                    for(k = 0; k < tamRaza; k++)
                    {
                        if(raza[k].estado == ocupado && mascota[j].idRaza == raza[k].idRaza)
                        {
                            printf("%19d %15s %10s %16s %12s %7d %7.2f %7s\n",
                                   j+1,
                                   mascota[j].nombre,
                                   mascota[j].tipo,
                                   raza[k].nombreRaza,
                                   raza[k].pais,
                                   mascota[j].edad,
                                   mascota[j].peso,
                                   mascota[j].sexo);

                        }
                    }

                    printf("\t\t_____________________________________________________________________________________\t\t\n");
                }
            }
        }
    }
}

//ORDENAR LOS DUENIOS POR CANTIDAD DE MASCOTAS (14) NOTA: (MENOR A MAYOR)
void ordenarDueniosCantidadMascota(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, sRaza raza[], int tamRaza, int ocupado)
{
    sMascota_sDuenio aux_Duenio_Mascota[tamDuenio];
    int i, j, k, l;
    sMascota_sDuenio auxcontaMascota;


    inisializarMascotaDuenio( aux_Duenio_Mascota, duenio, tamDuenio);

    contadoMascotaDuenio( aux_Duenio_Mascota, tamDuenio, mascota, tamMascota, ocupado);

    for(i = 0; i < tamDuenio-1; i++)
    {
        for(j = i+1; j < tamDuenio; j++)
        {
            if(aux_Duenio_Mascota[i].contadorMascotasDuenio > aux_Duenio_Mascota[j].contadorMascotasDuenio)
            {

                auxcontaMascota = aux_Duenio_Mascota[i];
                aux_Duenio_Mascota[i] = aux_Duenio_Mascota[j];
                aux_Duenio_Mascota[j] = auxcontaMascota;
            }
        }
    }

    for(i = 0; i < tamDuenio; i++)//estructura aux
    {

        for(j = 0; j < tamDuenio; j++)//duenio
        {
            if(aux_Duenio_Mascota[i].idDuenioMascota == duenio[j].idDuenio && duenio[j].estado == ocupado)
            {
                printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DUENIOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
                printf("\t\t_____________________________________________________________________________________\t\t\n");
                printf("\n\t\t| N \tID \tNOMBRE\t APELLIDO\t LOCALIDAD\t TELEFONO\t SEXO |\n");
                printf("\t\t_____________________________________________________________________________________\t\t\n");
                printf("%19d %6d %11s %10s %16s %14s %11s\n",
                       j+1,
                       duenio[j].idDuenio,
                       duenio[j].nombre,
                       duenio[j].apellido,
                       duenio[j].localidad,
                       duenio[j].telefono,
                       duenio[j].sexo
                      );

                printf("\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
                printf("\t\t_____________________________________________________________________________________\t\t\n");
                printf("\n\t\t| N          NOMBRE\t  TIPO             RAZA \tPAIS \tEDAD \tPESO \tSEXO|\n");
                printf("\t\t_____________________________________________________________________________________\t\t\n");
                for(k = 0; k < tamMascota; k++)//mascota
                {
                    if(mascota[k].estado == ocupado && mascota[k].idDuenio == duenio[j].idDuenio)
                    {
                        for(l = 0; l < tamRaza; l++)
                        {
                            if(raza[l].estado == ocupado && mascota[k].idRaza == raza[l].idRaza)
                            {

                                printf("%19d %15s %10s %16s %12s %7d %7.2f %7s\n",
                                       j+1,
                                       mascota[k].nombre,
                                       mascota[k].tipo,
                                       raza[l].nombreRaza,
                                       raza[l].pais,
                                       mascota[k].edad,
                                       mascota[k].peso,
                                       mascota[k].sexo);
                            }

                        }
                    }
                }
                printf("\t\t_____________________________________________________________________________________\t\t\n");

            }
        }
    }
}

//ORDENAR LOS DUENIOS POR CANTIDAD DE MASCOTAS Y SI TIENEN LA MISMA CANTIDAD POR EL NOMBRE DEL DUENIO (15) NOTA: (MENOR A MAYOR)
void ordenarDueniosCantidadMascotaYOrdenAlfabeticoNombre(sDuenio duenio[], int tamDuenio, sMascota mascota[], int tamMascota, sRaza raza[], int tamRaza, int ocupado)
{

    sDuenio auxDuenio;

    sMascota_sDuenio aux_Duenio_Mascota[tamDuenio];
    int i, j, k, l;
    sMascota_sDuenio auxcontaMascota;


    inisializarMascotaDuenio( aux_Duenio_Mascota, duenio, tamDuenio);

    contadoMascotaDuenio( aux_Duenio_Mascota, tamDuenio, mascota, tamMascota, ocupado);

    for(i=0; i<tamDuenio-1; i++)
    {
        for(j=i+1; j<tamDuenio; j++)
        {
            if(aux_Duenio_Mascota[i].contadorMascotasDuenio > aux_Duenio_Mascota[j].contadorMascotasDuenio)
            {

                auxcontaMascota = aux_Duenio_Mascota[i];
                aux_Duenio_Mascota[i] = aux_Duenio_Mascota[j];
                aux_Duenio_Mascota[j] = auxcontaMascota;
            }
        }
    }

    for(i=0; i<tamDuenio-1; i++)
    {
        for(j=i+1; j<tamDuenio; j++)
        {
            if(duenio[i].estado == ocupado && duenio[j].estado == ocupado)
            {
                if(strcmpi(duenio[i].nombre, duenio[j].nombre) > 0)
                {
                    auxDuenio = duenio[i];
                    duenio[i] = duenio[j];
                    duenio[j] = auxDuenio;
                }
            }
        }
    }

    for(i=0; i<tamDuenio; i++)//estructura aux
    {

        for(j=0; j<tamDuenio; j++)//duenio
        {
            if(aux_Duenio_Mascota[i].idDuenioMascota == duenio[j].idDuenio && duenio[j].estado == ocupado)
            {

                printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DUENIOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
                printf("\t\t_____________________________________________________________________________________\t\t\n");
                printf("\n\t\t| N \tID \tNOMBRE\t APELLIDO\t LOCALIDAD\t TELEFONO\t SEXO |\n");
                printf("\t\t_____________________________________________________________________________________\t\t\n");
                printf("%19d %6d %11s %10s %16s %14s %11s\n",
                       j+1,
                       duenio[j].idDuenio,
                       duenio[j].nombre,
                       duenio[j].apellido,
                       duenio[j].localidad,
                       duenio[j].telefono,
                       duenio[j].sexo
                      );

                printf("\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
                printf("\t\t_____________________________________________________________________________________\t\t\n");
                printf("\n\t\t| N          NOMBRE\t  TIPO             RAZA \tPAIS \tEDAD \tPESO \tSEXO|\n");
                printf("\t\t_____________________________________________________________________________________\t\t\n");
                for(k = 0; k < tamMascota; k++)//mascota
                {
                    if(mascota[k].estado == ocupado && mascota[k].idDuenio == duenio[j].idDuenio)
                    {
                        for(l = 0; l < tamRaza; l++)
                        {
                            if(raza[l].estado == ocupado && mascota[k].idRaza == raza[l].idRaza)
                            {

                                printf("%19d %15s %10s %16s %12s %7d %7.2f %7s\n",
                                       j+1,
                                       mascota[k].nombre,
                                       mascota[k].tipo,
                                       raza[l].nombreRaza,
                                       raza[l].pais,
                                       mascota[k].edad,
                                       mascota[k].peso,
                                       mascota[k].sexo);
                            }

                        }
                    }
                }
                printf("\t\t_____________________________________________________________________________________\t\t\n");

            }
        }


    }
}

//ALTA DE MASCOTA (4)
int altaMascotaDuenioRaza(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza, int libre, int ocupado)//NOTA: PENDIENTE sDuenio Y sRaza
{
    int aux;
    int opcion;

    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> INGRESO DE MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");

    aux = buscarLibreMascota(mascota, tamMascota, libre); //LLAMO A LA FUNCION BUSCAR LIBRE

    int retorno = -1; //VARIABLE DE RETORNO SI ES -1 NO ENCONTRO ESPACIO DISPONIBLE

    if(aux != -1)
    {

        mostrarDuenio(duenio, tamDuenio, ocupado);

        mascota[aux].idDuenio = getInt("\t\t\nINGRESE ID DEL DUENIO DE LOS QUE ESTAN DISPONIBLES EN LA LISTA: ","",0,0,0);

        mascota[aux].idMascota = generarIDMascota(mascota, tamMascota, libre);

        getString(mascota[aux].nombre,"\t\t\nINGRESE EL NOMBRE DE LA MASCOTA: ");

        do
        {
            printf("\n\n\t\t>>>>>>>>>>> MENU TIPO DE MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
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
                strcpy(mascota[aux].tipo, "Gato");

                break;
            }
            case 2:
            {
                system("clear");
                strcpy(mascota[aux].tipo, "Perro");

                break;
            }
            case 3:
            {
                system("clear");
                strcpy(mascota[aux].tipo, "Raro");
                break;
            }
            default:
                printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                system("pause");
                break;
            }
        }
        while(opcion != 1 && opcion != 2 && opcion != 3);

        mostrarRaza(raza, tamRaza, ocupado);

        mascota[aux].idRaza = getInt("\t\t\nINGRESE ID DE LA RAZA, DE LOS QUE ESTAN DISPONIBLES EN LA LISTA: ","",0,0,0);

        mascota[aux].edad=getInt("\t\t\n INGRESE LA EDAD DE LA MASCOTA: ","",0,0,0);

        mascota[aux].peso=getFloat("\t\t\n INGRESE EL PESO DE LA MASCOTA: ","",0,0,0);

        do
        {
            printf("\n\n\t\t>>>>>>>>>>> MENU SEXO DE MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
            printf("\t\t_____________________________________________________________\t\t\n");
            printf("\t\t| (1) MACHO         \t\t|\n");
            printf("\t\t| (2) HEMBRA        \t\t|\n");
            printf("\t\t________________________________________________________\t\t\n\t\t|");
            fflush(stdin);
            //__fpurger(stdin);

            opcion = getInt(" ELIJA UNA OPCION DEL MENU: ",
                            "\t\t|\n\t\t| ELIJA UNA OPCION DEL MENU: ", 1, 3, 1);
            system("clear");

            switch(opcion)
            {
            case 1:
            {
                system("clear");
                strcpy(mascota[aux].sexo, "MACHO");

                break;
            }
            case 2:
            {
                system("clear");
                strcpy(mascota[aux].sexo, "HEMBRA");

                break;
            }

            default:
                printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                system("pause");
                break;
            }

        }
        while(opcion != 1 && opcion != 2);

        mascota[aux].estado = ocupado;

        printf("\t\t\n MASCOTA AGREGADA EXITOSAMENTE \n"); //NOTA ESTO ES TEMPORAL

        retorno = aux; //RETORNO DE AUX SI ESTO ES 1 SIGNIFICA QUE ESTA CORRECTO
    }
    return retorno;
}

//MODIFICA UNA MASCOTA, SU RAZA Y EL DUENIO (6)
int modificarMascotaRazaDuenio(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza,  int ocupado)
{
    int aux;
    int retorno = -1; //INCORRECTO
    int opcion;

    aux = buscarIdMascota(mascota, tamMascota, ocupado);

    if(aux != retorno)
    {
        do
        {
            printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS A MODIFICAR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
            printf("\t\t_____________________________________________________________________________________________\t\t\n");
            printf("\n\t\t| N\t ID          NOMBRE\t  TIPO             RAZA \tPAIS \tEDAD \tPESO \tSEXO|\n");
            printf("\t\t_____________________________________________________________________________________________\t\t\n");
            printf("%19d %7d %15s %10s %16s %12s %7d %7.2f %7s\n",
                   aux,
                   mascota[aux].idMascota,
                   mascota[aux].nombre,
                   mascota[aux].tipo,
                   raza[aux].nombreRaza,
                   raza[aux].pais,
                   mascota[aux].edad,
                   mascota[aux].peso,
                   mascota[aux].sexo);
            printf("\t\t_____________________________________________________________________________________________\t\t\n");

            printf("\n\n\t\t>>>> MODIFICAR DATOS DE LA MASCOTAS <<<<<<\n\n");
            printf("\t\t__________________________________________\t\t\n");
            printf("\t\t| (1) NOMBRE MASCOTA            \t\t|\n");//listo
            printf("\t\t| (2) TIPO DE MASCOTA           \t\t|\n");//listo
            printf("\t\t| (3) RAZA DE MASCOTA           \t\t|\n");
            printf("\t\t| (4) PAIS DE MASCOTA           \t\t|\n");
            printf("\t\t| (5) EDAD DE MASCOTA           \t\t|\n");//listo
            printf("\t\t| (6) PESO DE MASCOTA           \t\t|\n");//listo
            printf("\t\t| (7) SEXO DE MASCOTA           \t\t|\n");//listo
            printf("\t\t| (8) NOMBRE DEL DUENIO         \t\t|\n");
            printf("\t\t| (9) SALIR                     \t\t|\n");//listo
            printf("\t\t__________________________________________\t\t\n\t\t|");
            fflush(stdin);
            //__fpurger(stdin);

            opcion = getInt(" ELIJA UNA OPCION DEL MENU: ",
                            "\t\t|\n\t\t| ELIJA UNA OPCION DEL MENU: ", 1, 9, 1);
            system("clear");

            switch(opcion)
            {
            case 1:
                getString(mascota[aux].nombre,"\t\t\n INGRESE EL NOMBRE DE LA MASCOTA: ");
                retorno = 1; //CORRECTO
                break;
            case 2:
                do
                {
                    printf("\n\n\t\t>>>>>>>>>>> MENU TIPO DE MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
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
                        strcpy(mascota[aux].tipo, "Gato");

                        break;
                    }
                    case 2:
                    {
                        system("clear");
                        strcpy(mascota[aux].tipo, "Perro");

                        break;
                    }
                    case 3:
                    {
                        system("clear");
                        strcpy(mascota[aux].tipo, "Raro");
                        break;
                    }
                    default:
                        printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                        system("pause");
                        break;
                    }
                }
                while(opcion != 1 && opcion != 2 && opcion != 3);
                retorno = 1; //CORRECTO
                break;
            case 3:
                //mostrarRaza(raza, tamRaza, ocupado);
                //getString(raza[aux].nombreRaza, "\t\t\n INGRESE LA RAZA DE LA MASCOTA: ");
                do
                {
                    system("clear");

                    printf("\n\n\t\t>>>>>>>>>>> MENU RAZA DE MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
                    printf("\t\t_____________________________________________________________\t\t\n");
                    printf("\t\t| (1) RAZA ARRUGADO             \t\t|\n");
                    printf("\t\t| (2) RAZA CALLEGERO            \t\t|\n");
                    printf("\t\t| (3) RAZA POLICIAL             \t\t|\n");
                    printf("\t\t| (4) RAZA DOGO                 \t\t|\n");
                    printf("\t\t| (5) RAZA LAGARTO OBERO        \t\t|\n");
                    printf("\t\t| (6) RAZA CAMALEON             \t\t|\n");
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

                        strcpy(raza[aux].nombreRaza, "Arrugado");

                        break;
                    }
                    case 2:
                    {

                        strcpy(raza[aux].nombreRaza, "Callegero");

                        break;
                    }
                    case 3:
                    {

                        strcpy(raza[aux].nombreRaza, "Policial");
                        break;
                    }
                    case 4:
                    {

                        strcpy(raza[aux].nombreRaza, "Dogo");

                        break;
                    }
                    case 5:
                    {

                        strcpy(raza[aux].nombreRaza, "Lagarto Obero");

                        break;
                    }
                    case 6:
                    {

                        strcpy(raza[aux].nombreRaza, "Camaleon");
                        break;
                    }
                    default:
                        printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                        system("pause");
                        break;
                    }
                }
                while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6);
                retorno = 1; //CORRECTO
                break;
            case 4:
                //mostrarRaza(raza, tamRaza, ocupado);
                //getString(raza[aux].pais, "\t\t\n INGRESE EL PAIS DE LA MASCOTA: ");
                do
                {
                    system("clear");

                    printf("\n\n\t\t>>>>>>>>>>> MENU PAIS DE MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
                    printf("\t\t_____________________________________________________________\t\t\n");
                    printf("\t\t| (1) PAIS PERSA                        \t\t|\n");
                    printf("\t\t| (2) PAIS EGIPCIO                      \t\t|\n");
                    printf("\t\t| (3) PAIS ALEMAN                       \t\t|\n");
                    printf("\t\t| (4) PAIS ARGENTINA                    \t\t|\n");
                    printf("\t\t| (5) PAIS COLOMBIA                     \t\t|\n");
                    printf("\t\t| (6) PAIS INDIA                        \t\t|\n");
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

                        strcpy(raza[aux].pais, "Persa");

                        break;
                    }
                    case 2:
                    {

                        strcpy(raza[aux].pais, "Egipcio");

                        break;
                    }
                    case 3:
                    {

                        strcpy(raza[aux].pais, "Aleman");
                        break;
                    }
                    case 4:
                    {

                        strcpy(raza[aux].pais, "Argentina");

                        break;
                    }
                    case 5:
                    {

                        strcpy(raza[aux].pais, "Colombia");

                        break;
                    }
                    case 6:
                    {

                        strcpy(raza[aux].pais, "India");
                        break;
                    }
                    default:
                        printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                        system("pause");
                        break;
                    }
                }
                while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6);
                retorno = 1; //CORRECTO
                break;
            case 5:
                mascota[aux].edad = getInt("INGRESE LA EDAD DE LA MASCOTA: ","",0,0,0);
                retorno = 1; //CORRECTO
                break;
            case 6:
                mascota[aux].peso = getFloat("INGRESE EL PESO DE LA MASCOTA: ","",0,0,0);
                retorno = 1; //CORRECTO
                break;
            case 7:
                do
                {
                    printf("\n\n\t\t>>>>> MENU SEXO DE MASCOTAS <<<<<<<<\n\n");
                    printf("\t\t___________________________________\t\t\n");
                    printf("\t\t| (1) MACHO         \t\t|\n");
                    printf("\t\t| (2) HEMBRA        \t\t|\n");
                    printf("\t\t______________________________\t\t\n\t\t|");
                    fflush(stdin);
                    //__fpurger(stdin);

                    opcion = getInt(" ELIJA UNA OPCION DEL MENU: ",
                                    "\t\t|\n\t\t| ELIJA UNA OPCION DEL MENU: ", 1, 3, 1);
                    system("clear");

                    switch(opcion)
                    {
                    case 1:
                    {
                        system("clear");
                        strcpy(mascota[aux].sexo, "MACHO");

                        break;
                    }
                    case 2:
                    {
                        system("clear");
                        strcpy(mascota[aux].sexo, "HEMBRA");

                        break;
                    }

                    default:
                        printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                        system("pause");
                        break;
                    }

                }
                while(opcion != 1 && opcion != 2);
                retorno = 1; //CORRECTO
                break;
            case 8:
                mostrarDuenio(duenio, tamDuenio, ocupado);
                mascota[aux].idDuenio = getInt("\t\t\n INGRESE EL ID DEL DUENIO DISPONIBLE DE LA LISTA: ", "", 0, 0, 0);
                retorno = 1; //CORRECTO
                break;
            case 9:
                printf("\t\t\n MASCOTA MODIFICADA EXITOSAMENTE \n");
                break;
            }
        }
        while(opcion != 9);
    }
    return retorno;
}

//MUESTRA LOS DUENIOS CON QUE TIENEN MASCOTAS DEL MISMO SEXO. (19)
void mostrarMascotaDuenioMismoSexo(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, sRaza raza[], int tamRaza, int ocupado)
{
    int i, j, k;
    int opcion;
    char auxSexoDuenio[50];
    char auxSexoMascota[50];
    do
                {
                    printf("\n\n\t\t>>>>> MENU SEXO DE DUENIO <<<<<<<<\n\n");
                    printf("\t\t___________________________________\t\t\n");
                    printf("\t\t| (1) MASCULINO         \t\t|\n");
                    printf("\t\t| (2) FEMENINO          \t\t|\n");
                    printf("\t\t___________________________________\t\t\n\t\t|");
                    fflush(stdin);
                    //__fpurger(stdin);

                    opcion = getInt(" ELIJA UNA OPCION DEL MENU: ",
                                    "\t\t|\n\t\t| ELIJA UNA OPCION DEL MENU: ", 1, 3, 1);
                    system("clear");

                    switch(opcion)
                    {
                    case 1:
                    {
                        system("clear");
                        strcpy(auxSexoDuenio, "MASCULINO");
                        strcpy(auxSexoMascota, "MACHO");
                        break;
                    }
                    case 2:
                    {
                        system("clear");
                        strcpy(auxSexoDuenio, "FEMENINO");
                        strcpy(auxSexoMascota, "HEMBRA");
                        break;
                    }

                    default:
                        printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                        system("pause");
                        break;
                    }

                }
                while(opcion != 1 && opcion != 2);


    for(i = 0; i < tamDuenio; i++)
    {

        if(duenio[i].estado == ocupado && strcmpi(duenio[i].sexo, auxSexoDuenio) == 0)
        {
            printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DUENIOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("\n\t\t| N \tID \tNOMBRE\t APELLIDO\t LOCALIDAD\t TELEFONO\t SEXO |\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("%19d %6d %11s %10s %16s %14s %11s\n",
                   i+1,
                   duenio[i].idDuenio,
                   duenio[i].nombre,
                   duenio[i].apellido,
                   duenio[i].localidad,
                   duenio[i].telefono,
                   duenio[i].sexo
                  );

            printf("\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("\n\t\t| N          NOMBRE\t  TIPO             RAZA \tPAIS \tEDAD \tPESO \tSEXO|\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");

            for(j=0; j<tamMascota; j++)
            {

                if(mascota[j].estado == ocupado && mascota[j].idDuenio == duenio[i].idDuenio && strcmpi(mascota[j].sexo, auxSexoMascota) == 0)
                {
                    for(k = 0; k < tamRaza; k++)
                    {
                        if(raza[k].estado == ocupado && mascota[j].idRaza == raza[k].idRaza)
                        {
                            printf("%19d %15s %10s %16s %12s %7d %7.2f %7s\n",
                                   j+1,
                                   mascota[j].nombre,
                                   mascota[j].tipo,
                                   raza[k].nombreRaza,
                                   raza[k].pais,
                                   mascota[j].edad,
                                   mascota[j].peso,
                                   mascota[j].sexo);

                        }
                    }

                    printf("\t\t_____________________________________________________________________________________\t\t\n");
                }
            }
        }
    }
}










