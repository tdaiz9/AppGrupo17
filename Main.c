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
