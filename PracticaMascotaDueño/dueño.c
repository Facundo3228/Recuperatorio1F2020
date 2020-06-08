#include "dueño.h"
#include "harryio.h"

//HARCODEO DUENIO
void hardcodearDuenio(sDuenio duenio[],int tamD)
{
    int idDuenio[10] = {1000, 1001, 1002, 1003, 1004};
    char nombre[10][51] = {"Juana", "Pedro", "Lila", "Ernesto", "Pepe"};
    char apellido[10][51] = {"Lala", "Lolo", "Lulu", "Lele", "Lili"};
    char localidad[10][51] = {"Monte Grande", "Lomas", "Urquiza", "Lanus", "Belgrano"};
    char telefono[10][51] = {"11111111", "22222222", "33333333", "44444444", "55555555"};
    int edad[10] = {20, 85, 18, 21, 34};
    char sexo[10][51] = {"FEMENINO", "MASCULINO", "FEMENINO", "MASCULINO", "MASCULINO"};
    int estado[10] = {1, 1, 1, 1, 1};

    int i;

    for(i = 0; i < tamD; i++)
    {
        duenio[i].idDuenio = idDuenio[i];
        strcpy(duenio[i].nombre, nombre[i]);
        strcpy(duenio[i].apellido, apellido[i]);
        strcpy(duenio[i].localidad, localidad[i]);
        strcpy(duenio[i].telefono, telefono[i]);
        duenio[i].edad = edad[i];
        strcpy(duenio[i].sexo, sexo[i]);
        duenio[i].estado = estado[i];

    }
}

//INICIALIZA EL ARRAY DUENIO
void inicializarDuenio(sDuenio duenio[], int tamD, int libre)
{
    int i;

    for(i = 0; i < tamD; i++)
    {
        duenio[i].estado = libre;
    }
}

void mostrarDuenio(sDuenio duenio[], int tamD, int ocupado)
{
    int i;

    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DUENIOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("\t\t_____________________________________________________________________________________\t\t\n");
    printf("\n\t\t| N \tID \tNOMBRE\t APELLIDO\t LOCALIDAD \tTELEFONO   EDAD\t \tSEXO|\n");
    printf("\t\t_____________________________________________________________________________________\t\t\n");

    for(i = 0; i < tamD; i++)
    {
        if(duenio[i].estado == ocupado)
        {
            printf("%19d %6d %11s %10s %16s %13s %6d %12s\n",
                   i+1,
                   duenio[i].idDuenio,
                   duenio[i].nombre,
                   duenio[i].apellido,
                   duenio[i].localidad,
                   duenio[i].telefono,
                   duenio[i].edad,
                   duenio[i].sexo);

        }
    }
}

//BUSCA UNA POSICION LIBRE EN EL ARRAY DUENIO
int buscarLibreDuenio(sDuenio duenio[], int tamD, int libre)
{
    int i;
    int retorno = -1;
    for(i = 0; i < tamD; i++)
    {
        if(duenio[i].estado == libre)
        {
            retorno = i;
            break;
        }
    }
    //printf("index %d\n", i);
    return retorno;
}

//BUSCA UN ID DE DUENIO EN EL ARRAY
int buscarIdDuenio(sDuenio duenio[], int tamD, int ocupado)
{
    int i;
    int idIngresado;

    mostrarDuenio(duenio, tamD, ocupado); //LLAMADO A LA FUNCION MOSTRAR DUENIOS

    idIngresado = getInt("\nINGRESE EL ID DISPONIBLE EN LA LISTA: ",
                         "\nERROR, \nINGRESE EL ID DISPONIBLE EN LA LISTA: ", 0, 0, 0);

    for(i = 0; i < tamD; i++)
    {
        if(duenio[i].idDuenio == idIngresado && duenio[i].estado == ocupado)
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

//GENERA UN ID AUTOMATICO
int generarIDDuenio(sDuenio duenio[], int tamD, int libre)
{
    int i;
    int may = duenio[0].idDuenio;
    for(i = 0; i < tamD; i++)
    {
        if(i == 0 || duenio[i].idDuenio > may )
        {
            may = duenio[i].idDuenio;

        }
    }
    return may + 1;
}

//DA DE ALTA UN CLIENTE O DUENIO DE UNA MASCOTA (7)
int altaDuenio(sDuenio duenio[], int tamD, int libre, int ocupado)
{
    int aux;
    int opcion;
    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> INGRESO DE DUENIO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    aux=buscarLibreDuenio(duenio, tamD, libre); //LLAMADA A LA FUNCION BUSCAR LIBRE

    int retorno = -1; //VARIABLE DE RETORNO SI ES -1 NO ENCONTRO ESPACIO DISPONIBLE

    if(aux != -1)
    {
        duenio[aux].idDuenio = generarIDDuenio(duenio, tamD, libre);

        getString(duenio[aux].nombre, "\t\t INGRESE EL NOMBRE: ");
        getString(duenio[aux].apellido, "\t\t INGRESE EL APELLIDO: ");
        getString(duenio[aux].localidad, "\t\t INGRESE LA LOCALIDAD: ");
        getString(duenio[aux].telefono, "\t\t INGRESE EL TELEFONO: ");
        duenio[aux].edad = getInt("\t\t INGRESE LA EDAD: ", "",0,0,0);

        do
        {
            printf("\n\n\t\t>>>> MENU SEXO DUENIO <<<<\n\n");
            printf("\t\t_______________________________________\t\t\n");
            printf("\t\t| (1) MASCULINO         \t\t|\n");
            printf("\t\t| (2) FEMENINO          \t\t|\n");
            printf("\t\t__________________________________\t\t\n\t\t|");
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
                strcpy(duenio[aux].sexo, "MASCULINO");

                break;
            }
            case 2:
            {
                system("clear");
                strcpy(duenio[aux].sexo, "FEMENINO");

                break;
            }

            default:
                printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                system("pause");
                break;
            }

        }
        while(opcion != 1 && opcion != 2);

        duenio[aux].estado = ocupado;

        printf("\t\t\n DUENIO AGREGADA EXITOSAMENTE \n"); //NOTA ESTO ES TEMPORAL

        retorno = aux; //RETORNO DE AUX SI ESTO ES 1 SIGNIFICA QUE ESTA CORRECTO
    }
    return retorno;
}

//MODIFICACION DE UN DUENIO (10)
int modificarDuenio(sDuenio duenio[], int tamD, int ocupado)
{
    int aux;
    int retorno = -1; //INCORRECTO
    int opcion;
    printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>> DUENIOS DISPOIBRES <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    aux = buscarIdDuenio(duenio, tamD, ocupado);
    do
    {
        printf("\n\n\t\t>>>>>>>>>>>>>>>>>>>>>>>> DUENIO A MODIFICAR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
        printf("\t\t_____________________________________________________________________________________\t\t\n");
        printf("\n\t\t| N \tID \tNOMBRE\t APELLIDO\t LOCALIDAD \tTELEFONO   EDAD\t \tSEXO|\n");
        printf("\t\t_____________________________________________________________________________________\t\t\n");

        printf("%19d %6d %11s %10s %16s %13s %6d %12s\n",
               aux,
               duenio[aux].idDuenio,
               duenio[aux].nombre,
               duenio[aux].apellido,
               duenio[aux].localidad,
               duenio[aux].telefono,
               duenio[aux].edad,
               duenio[aux].sexo);

        printf("\t\t_____________________________________________________________________________________\t\t\n");

        printf("\n\n\t\t>>>> MODIFICAR DATOS DEL DUENIO <<<<<<\n\n");
        printf("\t\t__________________________________________\t\t\n");
        printf("\t\t| (1) NOMBRE DIENIO                 \t\t|\n");
        printf("\t\t| (2) APELLIDO DUENIO               \t\t|\n");
        printf("\t\t| (3) LOCALIDAD DEL DUENIO          \t\t|\n");
        printf("\t\t| (4) TELEFONO DEL DUENIO           \t\t|\n");
        printf("\t\t| (5) EDAD DEL DUENIO               \t\t|\n");
        printf("\t\t| (6) SEXO DEL DUENIO               \t\t|\n");
        printf("\t\t| (7) SALIR                         \t\t|\n");
        printf("\t\t__________________________________________\t\t\n\t\t|");
        fflush(stdin);
        //__fpurger(stdin);

        opcion = getInt(" ELIJA UNA OPCION DEL MENU: ",
                        "\t\t|\n\t\t| ELIJA UNA OPCION DEL MENU: ", 1, 7, 1);
        system("clear");

        switch(opcion)
        {
        case 1:
            getString(duenio[aux].nombre, "\t\t\n INGRESE EL NOMBRE DEL DUENIO: ");
            retorno = 1;//correcto
            break;
        case 2:
            getString(duenio[aux].apellido, "\t\t\n INGRESE EL APELLIDO DEL DUENIO: ");
            retorno = 1;//correcto
            break;
        case 3:
            getString(duenio[aux].localidad, "\t\t\n INGRESE LA LOCALIDAD DEL DUENIO: ");
            retorno = 1;//correcto
            break;
        case 4:
            getString(duenio[aux].telefono, "\t\t\n INGRESE EL TELEFONO DEL DUENIO: ");
            retorno = 1;//correcto
            break;
        case 5:
            duenio[aux].edad=getInt("\t\t\n INGRESE LA EDAD DEL DUENIO: ","",0,0,0);
            retorno = 1;//correcto
            break;
        case 6:
            do
            {
                printf("\n\n\t\t>>>> MENU SEXO DUENIO <<<<\n\n");
                printf("\t\t_______________________________________\t\t\n");
                printf("\t\t| (1) MASCULINO         \t\t|\n");
                printf("\t\t| (2) FEMENINO          \t\t|\n");
                printf("\t\t__________________________________\t\t\n\t\t|");
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
                    strcpy(duenio[aux].sexo, "MASCULINO");

                    break;
                }
                case 2:
                {
                    system("clear");
                    strcpy(duenio[aux].sexo, "FEMENINO");

                    break;
                }

                default:
                    printf("\t\t\n OPCION NO IMPLEMENTADA ELIJA UNA OPCION DEL MENU");
                    system("pause");
                    break;
                }

            }
            while(opcion != 1 && opcion != 2);
            retorno = 1;//correcto
            break;
        case 7:
            printf("MODIFICACION EXITOZA\n");
            retorno = 1;//correcto
            break;
        }
    }
    while(opcion!=7);
    return retorno;
}

//PROMEDIO DE HOMBRES Y MUJERES (18)
void promediodevaronesYMujeres(sDuenio duenio[], int tamD, int ocupado)
{
    int i;
    int sumaToal = 0;
    int contadorSexoM = 0;
    int contadorSexoF = 0;
    float promedioM;
    float promedioF;


    for(i = 0; i < tamD; i++)
    {
        if(duenio[i].estado == ocupado && strcmp(duenio[i].sexo, "MASCULINO") == 0)
        {
            contadorSexoM++;
        }

        if(duenio[i].estado == ocupado && strcmp(duenio[i].sexo, "FEMENINO") == 0)
        {
            contadorSexoF++;
        }
    }

    sumaToal = contadorSexoM + contadorSexoF;

    promedioM = (float) sumaToal / contadorSexoM;
    printf("\nEL PROMEDIO DE HOMBRES ES: (%d / %d = %.2f )\n ", sumaToal, contadorSexoM, promedioM);
    promedioF = (float) sumaToal / contadorSexoF;
    printf("\nEL PROMEDIO DE MUJERES ES: (%d / %d = %.2f )\n ", sumaToal, contadorSexoF, promedioF);

}


//PORCENTAJE DE MUJERES SOBRE EL TOTAL DE CLIENTES (1818)
void porcentajeMujeres(sDuenio duenio[], int tamD, int ocupado)
{
    int i;

    int contadorSexoF = 0;
    int contadorTotal = 0;
    float porcentajeF;


    for(i = 0; i < tamD; i++)
    {
        if(duenio[i].estado == ocupado)
        {
            contadorTotal++;
            if(strcmp(duenio[i].sexo, "FEMENINO") == 0)
            {
                contadorSexoF++;
            }
        }

    }
    porcentajeF = (float)(contadorSexoF * contadorTotal) / 100;

    printf("\nEL PORCENTAJE DE MUJERES ES: ( (%d * %d) / 100 ) = %.2f \n ", contadorSexoF, contadorTotal, porcentajeF);
}














