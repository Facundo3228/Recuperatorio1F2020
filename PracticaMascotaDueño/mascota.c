#include "mascota.h"

//HARCODEO DE MASCOTA
void hardcodearMascota(sMascota mascota[], int tamM)
{
    int i;
    int idMascota[20] = {2000,2001, 2002,2003,2004, 2005,2006, 2007, 2008,2009,2010};
    int idDuenio[20] = {1000,1000, 1001,1001,1001, 1002,1002, 1003, 1004,1004,1004};
    int idRaza[20] = {100,101, 102,103,100, 103,104, 102, 100,101,103};
    char nombre[20][51] = {"Gata1000","Gata1000", "Perruno1001","Perruno1001","Gatuno1001", "Perrote1002","Godzila1002", "Perrin1003", "Gatote1004","Gatote1004","Perron1004"};
    char tipo[20][51] = {"Gato","Gato", "Perro","Perro","Gato", "Perro","Raro", "Perro", "Gato","Gato","Perro"};
    int edad[20] = {8,2,1,7,3,9,8,4,2,6,9};
    float peso[20] = {2.3,5.35,3.25,4.30,7.00,2.35,3.64,1.23,7.85,4.43,4.96};
    char sexo[20][51] = {"HEMBRA", "HEMBRA", "MACHO", "MACHO", "MACHO", "MACHO", "HEMBRA", "MACHO", "MACHO", "MACHO", "MACHO"};
    int estado[20] = {1,1,1,1,1,1,1,1,1,1,1};

    for(i = 0; i < tamM; i++)
    {
        mascota[i].idMascota = idMascota[i];
        mascota[i].idDuenio = idDuenio[i];
        mascota[i].idRaza = idRaza[i];
        mascota[i].edad = edad[i];
        mascota[i].peso = peso[i];
        strcpy(mascota[i].sexo, sexo[i]);
        mascota[i].estado = estado[i];
        strcpy(mascota[i].tipo, tipo[i]);
        strcpy(mascota[i].nombre, nombre[i]);
    }
}

//INICIAIZACION DEL ARRAY DE ESTRUCTURA DE TIPO MASCOTA
void inicializarMascota(sMascota mascota[], int tamM, int libre)
{
    int i;
    for(i = 0; i < tamM; i++)
    {
        mascota[i].estado=libre;
        mascota[i].idMascota=0;
    }
}

//MUESTRA EL ARRAY DE ESTRUCTURA DE TIPO MASCOTA (2)
void mostrarMascota(sMascota mascota[],int tamM, int ocupado)
{
    int i;
    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("\t\t_____________________________________________________________________________________\t\t\n");
    printf("\n\t\t|N \tID \t\tNOMBRE\t \tTIPO \tEDAD \tPESO \tSEXO|\n");
    printf("\t\t_____________________________________________________________________________________\t\t\n");
    for(i = 0; i < tamM; i++)
    {
        if(mascota[i].estado == ocupado)
        {
            printf("%18d %7d %19s %13s %7d %7.2f %7s %7d\n",
                   i+1,
                   mascota[i].idMascota,
                   mascota[i].nombre,
                   mascota[i].tipo,

                   mascota[i].edad,
                   mascota[i].peso,
                   mascota[i].sexo,
                   mascota[i].idDuenio);
        }
    }
}

//BUSCA UN ID EN EL ARRAY DE TIPO MASCOTA
int buscarIdMascota(sMascota mascota[], int tamM, int ocupado)
{
    int i;
    int idIngresado;

    mostrarMascota(mascota, tamM, ocupado); //LLAMADO A LA FUNCION MOSTRAR MASCOTA

    idIngresado = getInt("\nINGRESE EL ID DISPONIBLE EN LA LISTA: ",
                         "\nERROR, \nINGRESE EL ID DISPONIBLE EN LA LISTA: ", 0, 0, 0);

    for(i = 0; i < tamM; i++)
    {
        if(mascota[i].idMascota == idIngresado && mascota[i].estado == ocupado)
        {
            return i;
        }
    }
    return -1;
}


/*int generarIDMascota()
{
    static int id=0;
    id++;
    return id;
}
*/

//GENERA UN ID AUTMOATICO
int generarIDMascota(sMascota mascota[], int tamM, int libre)
{
    int i;
    int may = mascota[0].idMascota;
    for(i = 0; i < tamM; i++)
    {
        if(i == 0 || mascota[i].idMascota > may )
        {
            may = mascota[i].idMascota;
        }
    }
    return may + 1;
}

//ALTA DE MASCOTA (NULA)
int altaMascota(sMascota mascota[], int tamM, int libre, int ocupado)//NOTA: PENDIENTE sDuenio Y sRaza
{
    int aux;
    int opcion;

    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> INGRESO DE MASCOTAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");

    aux = buscarLibreMascota(mascota, tamM, libre); //LLAMO A LA FUNCION BUSCAR LIBRE

    int retorno = -1; //VARIABLE DE RETORNO SI ES -1 NO ENCONTRO ESPACIO DISPONIBLE

    if(aux != -1)
    {


        mascota[aux].idDuenio = getInt("\t\t\nIngrese ID del duenio de los que estan disponibles en la lista: ","",0,0,0);

        mascota[aux].idMascota = generarIDMascota(mascota, tamM, libre);

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

        //Nota: strcmp(const char*,const char*); compara con exactitud a
        //diferencia de strcmpi(const char*,const char*); que no distinge de mayusculas y minusculas.

        //getString(mascota[aux].raza,"Ingrese la raza de la mascota: ");

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

//BUSCA UN ESPACIO LIBRE EN EL AYRRAY DE MASCOTA SI ENCUENTRA ESPACIO RETORNA LA POCICION DE LO CONTRARIO RETORNA -1 INDICANDO QUE NO HAY ESPACIO
int buscarLibreMascota(sMascota mascota[], int tamM, int libre)
{
    int i;
    int retorno = -1;
    for(i = 0; i < tamM; i++)
    {
        if(mascota[i].estado == libre)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

//ELIMINA UNA MASCOTA DEL ARRAY DE MASCOTA (5)
int bajaMascota(sMascota mascota[], int tamM, int ocupado, int libre)
{
    int aux;
    int retorno = -1; //INCORRECTO

    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS DISPONIBLES <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    aux = buscarIdMascota(mascota, tamM, ocupado);

    if(aux != retorno)
    {
        mascota[aux].estado = libre;
        retorno = 1; //CORRECTO
    }

    return retorno;
}

//MODIFICA UNA MASCOTA (NULA)
int modificarMascota(sMascota mascota[], int tamM, int ocupado) //NOTA: MODIFICAR sRaza Y sDuenio
{
    int aux;
    int retorno = -1; //INCORRECTO
    int opcion;

    aux = buscarIdMascota(mascota, tamM, ocupado);

    if(aux != retorno)
    {
        do
        {
            printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS A MODIFICAR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("\n\t\t|  ID \t\tNOMBRE\t \tTIPO \tEDAD \tPESO \tSEXO|\n");
            printf("\t\t_____________________________________________________________________________________\t\t\n");
            printf("%21d %11s %13s %7d %7.2f %7s\n",
                   mascota[aux].idMascota,
                   mascota[aux].nombre,
                   mascota[aux].tipo,
                   mascota[aux].edad,
                   mascota[aux].peso,
                   mascota[aux].sexo);
            printf("\t\t_____________________________________________________________________________________\t\t\n");

            printf("\n\n\t\t>>>> MODIFICAR DATOS DE LA MASCOTAS <<<<<<\n\n");
            printf("\t\t__________________________________________\t\t\n");
            printf("\t\t| (1) NOMBRE MASCOTA          \t\t|\n");
            printf("\t\t| (2) TIPO DE MASCOTA         \t\t|\n");
            printf("\t\t| (3) EDAD DE MASCOTA         \t\t|\n");
            printf("\t\t| (4) PESO DE MASCOTA         \t\t|\n");
            printf("\t\t| (5) SEXO DE MASCOTA         \t\t|\n");
            printf("\t\t| (6) SALIR                   \t\t|\n");
            printf("\t\t__________________________________________\t\t\n\t\t|");
            fflush(stdin);
            //__fpurger(stdin);

            opcion = getInt(" ELIJA UNA OPCION DEL MENU: ",
                            "\t\t|\n\t\t| ELIJA UNA OPCION DEL MENU: ", 1, 6, 1);
            system("clear");

            switch(opcion)
            {
            case 1:
                getString(mascota[aux].nombre,"\t\t\n INGRESE EL NOMBRE DE LA MASCOTA ");
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
                mascota[aux].edad = getInt("INGRESE LA EDAD DE LA MASCOTA: ","",0,0,0);
                retorno = 1; //CORRECTO
                break;
            case 4:
                mascota[aux].peso=getFloat("INGRESE EL SEXO DE LA MASCOTA ","",0,0,0);
                retorno = 1; //CORRECTO
                break;
            case 5:
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
                retorno = 1; //CORRECTO
                break;
            case 6:
                printf("MODIFICACION EXITOZA\n");
                break;
            }
        }
        while(opcion != 6);
    }
    return retorno;
}

//MOSTRAR MASCOTA POR TIPO (NULA)
void mostraMascotasPorTipo(sMascota mascota[], int tamM, int ocupado)
{
    int i;
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

    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>> MASCOTAS A MODIFICAR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("\t\t_____________________________________________________________________________________\t\t\n");
    printf("\n\t\t|  ID \t\tNOMBRE\t \tTIPO \tEDAD \tPESO \tSEXO|\n");
    printf("\t\t_____________________________________________________________________________________\t\t\n");
    for(i=0; i<tamM; i++)
    {
        if(strcmpi(mascota[i].tipo, respuesta) == 0)
        {
            printf("%10d %7d %11s %13s  %7d %7.2f %7s %7d\n",
                   i+1,
                   mascota[i].idMascota,
                   mascota[i].nombre,
                   mascota[i].tipo,
                   mascota[i].edad,
                   mascota[i].peso,
                   mascota[i].sexo,
                   mascota[i].idDuenio);
        }
    }
}

//PROMEDIO POR EDAD DE MASCOTA
float promedioEdadMascota(sMascota mascota[],int tamM, int ocupado)
{
    int i;
    int contaMascota=0;
    int sumaMascota=0;

    for(i = 0; i < tamM; i++)
    {
        if(mascota[i].estado == ocupado)
        {
            contaMascota++;
            sumaMascota += mascota[i].edad;
        }
    }
    return (float)sumaMascota / contaMascota;
}

//PROMEDIO POR TIPO DE MASCOTA
float promedioEdadMascotaPorTipo(sMascota mascota[], int tamM, int ocupado)
{
    int i;
    char respuesta[10];
    int contaMascotaTipo = 0;
    int sumaMascotaTipo = 0;
    float promedioMascotaTipo;
    int opcion;

    do
    {
        printf("\n\n\t\t>>>>>>>> MOSTRAR POR TIPO DE MASCOTAS <<<<<<<<<\n\n");
        printf("\t\t____________________________________________\t\t\n");
        printf("\t\t| (1) TIPO GATO         \t\t|\n");
        printf("\t\t| (2) TIPO PERRO        \t\t|\n");
        printf("\t\t| (3) TIPO RARO         \t\t|\n");
        printf("\t\t____________________________________________\t\t\n\t\t|");
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

    for(i = 0; i < tamM; i++)
    {
        if(mascota[i].estado == ocupado && strcmpi(mascota[i].tipo, respuesta) == 0)
        {
            contaMascotaTipo++;
            sumaMascotaTipo += mascota[i].edad;
        }
    }

    return promedioMascotaTipo = (float) sumaMascotaTipo / contaMascotaTipo;

}






