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

