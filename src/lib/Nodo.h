
#include "map.h"

typedef struct parada{
    int x, y;
    struct parada *siguiente;
}Parada;

Parada* agregarParada(int x, int y, Parada *ptr){
    
    Parada *nueva;
    nueva = (Parada*)malloc(sizeof(Parada));
    nueva->x = x;
    nueva->y = y;
    nueva->siguiente = ptr;
    
    return nueva;
}

typedef struct {
    char* nombre;
    int x, y;
    int dx, dy;
} Nodo;

#define N 168//48 36
Nodo nodos[N];

void cargarNodos () {
    printf("********************** Cargar Nodos *****************************\n");

    int x, y, p=0;
    for(x=0; x<FILAS;x++){
        for(y=0; y<COLUMNAS; y++){
            if(map[x][y]==5){
                nodos[p].nombre="";
                nodos[p].x=y*TILESIZE+10;
                nodos[p].y=x*TILESIZE;
                printf("...Px: %d\n", nodos[p].x);
                printf("...Py: %d\n", nodos[p].y);
                printf("----------------\n");
                p++;
            } else if(map[x][y]==6){
                nodos[p].nombre="";
                nodos[p].x=y*TILESIZE;
                nodos[p].y=x*TILESIZE;
                nodos[p+12].x=y*TILESIZE;
                nodos[p+12].y=x*TILESIZE;
                //printf("...P: %d\n", p);
                printf("...Px: %d\n", nodos[p].x);
                printf("...Py: %d\n", nodos[p].y);
                printf("----------------\n");
                p++;
            } // if          
        } // for y
    } // for x
        
} // cargarNodos