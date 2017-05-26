
//#include "map.h"
//#include "Node.h"
#include <stdbool.h>
#include "threadville_functions.h"
#include "threadville_globals.h"

#define NUM_VEHICULE 100


//typedef struct {
//    int carId;
//    cairo_surface_t *image;
//    int x, y;
//    int dx, dy;
//    int width, height;
//    int speed;
//    int espera;
//    bool run;
//    int cantidadParadas;
//    Nodo* paradas;
//    Parada* paradaInicial;
//} Car;


VEHICULE* vehicules[NUM_VEHICULE];
pthread_t threads[NUM_VEHICULE];

static void draw_car (cairo_t * cr, VEHICULE * vehicule) {
    
    if(vehicule->run){
        //printf("dibujar\n");
        cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);       
        cairo_arc(cr, vehicule->x, vehicule->y+10, TILESIZE/2, 0, 2*3.14);
        cairo_fill (cr);
    }
    //cairo_set_source_surface(cr, car->image, car->x, car->y);
    //cairo_paint(cr);
    
} // draw_car


bool near_car(VEHICULE *car1, VEHICULE *car2) {
        
    
    int tw = car1->width+5; // 5
    int th = car1->height+5;
    int rw = car2->width;
    int rh = car2->height;
    if (rw <= 0 || rh <= 0 || tw <= 0 || th <= 0) {
        return false;
    }
    int tx = car1->x;
    int ty = car1->y;
    int rx = car2->x;
    int ry = car2->y;
    rw += rx;
    rh += ry;
    tw += tx;
    th += ty;
    //      overflow || intersect
    return ((rw < rx || rw > tx) &&
            (rh < ry || rh > ty) &&
            (tw < tx || tw > rx) &&
            (th < ty || th > ry));

} // near_car


void *update_car_position(void * car)
{
    
    VEHICULE* tempCar=car;
    int p=0;
    while(tempCar->run){
        
        
        
      //  printf("Py: %d\n");
        int i=0;
        //printf("cantidad para: %d\n", tempCar->cantidadParadas);
        
            
//            
            if(p<tempCar->cantidadParadas-1){
                
                for(i; i<contadorHilos; i++){
                
                generateRoute(tempCar, tempCar->paradas[p], tempCar->paradas[p+1]);
                displayDestinations(tempCar->route->destinations);
            
            //printf("contado: %d\n", contadorHilos);
//    DESTINY *i = destinations;
//    for(; i != NULL; i = i->next){
//            printf("DESTINY - NODE NAME:  %s\n", i->node->name);
//    }
                
            if(contadorHilos>1){
                
                if(!near_car(tempCar, vehicules[i])){
                    tempCar->x+=tempCar->dx;
                    tempCar->y+=tempCar->dy;
                    //printf("near\n");
                    //printf("Cx: %d\n", tempCar->x);
                    //printf("Cy: %d\n", tempCar->y);
                    
                } // if
            }else{
                    tempCar->x+=tempCar->dx;
                    tempCar->y+=tempCar->dy;
                    
                    //printf("Cx: %d\n", tempCar->x);
                    //printf("Cy: %d\n", contadorHilos);            
            }
//                //printf("Py: %d\n", tempCar->paradas[p].y);
//                //printf("Cy: %d\n", tempCar->y);
                if(tempCar->x < tempCar->paradas[p]->x ){
                    tempCar->dx=1;
                    tempCar->dy=0;
                    //printf("EN1\n");
                }else if(tempCar->y < tempCar->paradas[p]->y ){
                    tempCar->dx=0;
                    tempCar->dy=1;                    
                }else{
                    printf("EN1\n");
                } 
//                 else if((tempCar->paradas[p].x <= tempCar->x  && tempCar->paradas[p].y > tempCar->y) && tempCar->x < tempCar->paradas[p].x+(2*TILESIZE)+10){
//                    tempCar->dx=1;
//                    tempCar->dy=0;
//                   // printf("EN2\n");
//                } else if(tempCar->paradas[p].x < tempCar->x && tempCar->y >= tempCar->paradas[p].y){
//                    tempCar->dx=-1;
//                    tempCar->dy=0;
//                   // printf("EN3\n");
//                } else if(tempCar->y < tempCar->paradas[p].y){
//                    tempCar->dx=0;
//                    tempCar->dy=1;
//                }else{
//                   // printf("Py: %d\n", tempCar->paradas[p].x);
//                   // printf("Cy: %d\n", tempCar->x);
//                    printf("FIN\n");
//                    p++;
//                    usleep(tempCar->delay*100000);
//                }
                
                } // for
                
            }else{
                tempCar->run=false;
                tempCar->x=0;
               tempCar->x=0;
            }                
        
       usleep(tempCar->speed*10000);
       //sleep(1);
       
    } // while run
        
} // update_car_position


