#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

//-------------------------------------------------------------------
// Acciones
//-------------------------------------------------------------------
//Permite escribir los datos actualizados en el csv.
void reewrite(FILE *the_file, libro dato[], int cantidad){
    fprintf(the_file, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
    for (int i=1; i<cantidad+2; i++){
        fprintf(the_file, "\"%s\",%s,%d,%d,%s,%d,%s,%s",dato[i].titulo, dato[i].autor, dato[i].ano, dato[i].estante_numero, dato[i].estante_seccion, dato[i].piso, dato[i].edificio, dato[i].sede);
    }
}

//Permite editar un libro, preguntandole al usuario los campos que desea modificar.
void edit(libro dato[], int cantidad){
    char titulo[60];
    char *ret;
    int campo;
    char str[2] = "\n";
    int decision;
    int key = 0;
    printf("\nQue libro desea modificar?: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            while(key==0){
                printf("\nQue campo desea modificar? \n");
                printf("\n(1) Titulo\n");
                printf("(2) Autor\n");
                printf("(3) Ano\n");
                printf("(4) Numero de estante\n");
                printf("(5) Seccion\n");
                printf("(6) Piso\n");
                printf("(7) Edificio\n");
                printf("(8) Sede\n");
                printf("\nIngrese opcion: ");
                scanf("%d", &campo);
                if (campo==1){
                    char new_title[60];
                    printf("\nIngrese nuevo titulo: ");
                    scanf("%s", &new_title);
                    strcpy(dato[i].titulo, new_title);
                }
                else if (campo==2){
                    char new_autor[60];
                    printf("\nIngrese nuevo autor: ");
                    scanf("%s", &new_autor);
                    strcpy(dato[i].autor, new_autor);
                }
                else if (campo==3){
                    char new_ano[60];
                    printf("\nIngrese nuevo ano: ");
                    scanf("%s", &new_ano);
                    dato[i].ano = atoi(new_ano);
                }
                else if (campo==4){
                    char new_estante[60];
                    printf("\nIngrese nuevo numero de estante: ");
                    scanf("%s", &new_estante);
                    dato[i].estante_numero = atoi(new_estante);
                }
                else if (campo==5){
                    char new_sec[60];
                    printf("\nIngrese nueva seccion de estante: ");
                    scanf("%s", &new_sec);
                    strcpy(dato[i].estante_seccion, new_sec);
                }
                else if (campo==6){
                    char new_piso[60];
                    printf("\nIngrese nuevo numero de piso: ");
                    scanf("%s", &new_piso);
                    dato[i].piso = atoi(new_piso);
                }
                else if (campo==7){
                    char new_edificio[60];
                    printf("\nIngrese nuevo edificio: ");
                    scanf("%s", &new_edificio);
                    strcpy(dato[i].edificio, new_edificio);
                }
                else if (campo==8){
                    char new_sede[60];
                    printf("\nIngrese nueva sede: ");
                    scanf("%s", &new_sede);
                    strncat(new_sede, &str, 2);
                    strcpy(dato[i].sede, new_sede);
                }
                int decision;
                printf("\nDesea modificar nuevamente? (Si (1) / No (2)): ");
                scanf("%d", &decision);
                if(decision==2){
                    key++;
                }
            }
        }
    }
}

//Permite cambiar sede, seccion o piso segun el usuario desee.
void search_change(libro dato[], int cambio, int cantidad){
    char titulo[60];
    char *ret;
    char sede[60];
    char sec[60];
    char piso[20];
    char str[2] = "\n";
    printf("\nIngrese titulo del libro: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            if (cambio == 1){
                printf("\nIngrese nueva Sede: ");
                scanf("%s", &sede);
                strncat(sede, &str, 2);
                strcpy(dato[i].sede, sede);
            }
            else if (cambio == 2){
                printf("\nIngrese nueva Seccion: ");
                scanf("%s", &sec);
                strcpy(dato[i].estante_seccion, sec);
            }
            else if (cambio == 3){
                printf("\nIngrese nuevo Piso: ");
                scanf("%s", &piso);
                dato[i].piso = atoi(piso);
            }
        }
    }
}

//Pregunta al usuario que opcion desea cambiar.
void change(libro dato[], int eleccion2, int cantidad){
    int cambio;
    char libro[60];
    if (eleccion2 == 1){
        //Cambiar SEDE
        search_change(dato, eleccion2, cantidad);
    }
    else if (eleccion2 == 2){
        //Cambiar SECCIÓN
        search_change(dato, eleccion2, cantidad);
    }
    else if (eleccion2 == 3){
        //Cambiar PISO
        search_change(dato, eleccion2, cantidad);
    }
}

//Permite buscar un libro de la biblioteca para obtener su informacion
void find(libro dato[], int cantidad){
    char titulo[60];
    char *ret;
    printf("\nIngrese titulo del libro: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            printf("\nLibro: %s\n", dato[i].titulo);
            printf("Autor: %s\n", dato[i].autor);
            printf("Ano: %d\n", dato[i].ano);
            printf("Numero de estante: %d\n", dato[i].estante_numero);
            printf("Seccion: %s\n", dato[i].estante_seccion);
            printf("Piso: %d\n", dato[i].piso);
            printf("Edificio: %s\n", dato[i].edificio);
            printf("Sede: %s\n", dato[i].sede);
        }
    }
}

//Permite agregar un nuevo libro a la biblioteca.
void agregar_libro(libro dato[], int cantidad){
    char str[2] = "\n";
    char new_titulo[60];
    printf("\nIngrese titulo del libro: ");
    scanf("%s", &new_titulo);
    char new_autor[60];
    printf("\nIngrese autor del libro: ");
    scanf("%s", &new_autor);
    char new_ano[60];
    printf("\nIngrese ano del libro: ");
    scanf("%s", &new_ano);
    char new_estante_numero[60];
    printf("\nIngrese número del estante del libro: ");
    scanf("%s", &new_estante_numero);
    char new_estante_seccion[60];
    printf("\nIngrese seccion del estante del libro: ");
    scanf("%s", &new_estante_seccion);
    char new_piso[60];
    printf("\nIngrese piso del libro: ");
    scanf("%s", &new_piso);
    char new_edificio[60];
    printf("\nIngrese edificio del libro: ");
    scanf("%s", &new_edificio);
    char new_sede[60];
    printf("\nIngrese sede del libro: ");
    scanf("%s", &new_sede);

    int nro = cantidad + 1;
    strcpy(dato[nro].titulo, new_titulo);
    strcpy(dato[nro].autor, new_autor);
    dato[nro].ano = atoi(new_ano);
    dato[nro].estante_numero = atoi(new_estante_numero);
    strcpy(dato[nro].estante_seccion, new_estante_seccion);
    dato[nro].piso = atoi(new_piso);
    strcpy(dato[nro].edificio, new_edificio);
    strncat(new_sede, &str, 2);
    strcpy(dato[nro].sede, new_sede);
}
