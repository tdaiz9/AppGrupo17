struct libros {
  int nro;
  char titulo[1000];
  char autor[1000];
  int ano;
  int estante_numero;
  char estante_seccion[500];
  int piso;
  char edificio[500];
  char sede[500];
};

typedef struct libros libro;
