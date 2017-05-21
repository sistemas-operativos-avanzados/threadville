
//#include "map.h"
#include "Nodo.h"

#define NUM_CARS 2


typedef struct {
    int carId;
    cairo_surface_t *image;
    int x, y;
    int dx, dy;
    int width, height;
    int speed;
    int espera;
    bool run;
    int cantidadParadas;
    Nodo* paradas;
    Parada* paradaInicial;
} Car;

//Car carro1;
//Car carro2;
Car cars[NUM_CARS];

static void draw_car (cairo_t * cr, Car * car) {
    if(car->run){
        cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);       
        cairo_arc(cr, car->x, car->y+10, TILESIZE/2, 0, 2*3.14);
        cairo_fill (cr);
    }
    //cairo_set_source_surface(cr, car->image, car->x, car->y);
    //cairo_paint(cr);
    
} // draw_car


bool near_car(Car *car1, Car *car2) {
        
    
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

//void *update_car_position(void * car) {
//    
//    Car* tempCar=car;
//    while(tempCar->run){
//        int i=0;
//        for(i; i<NUM_CARS; i++){
//            if(!near_car(tempCar, &cars[i])){
//                tempCar->x+=tempCar->dx;
//                tempCar->y+=tempCar->dy;
//            } // if
//            if(tempCar->x > 470){
//                tempCar->dx=0;
//                tempCar->dy=1;            
//            }
//        } // for
//       usleep(tempCar->speed*10000);
//    }
//        
//} // update_car_position

void *update_car_position(void * car)
{
    
    Car* tempCar=car;
    int p=0;
    while(tempCar->run){
        int i=0;
        for(i; i<NUM_CARS; i++){
            
            if(p<tempCar->cantidadParadas){

                if(!near_car(tempCar, &cars[i])){
                    tempCar->x+=tempCar->dx;
                    tempCar->y+=tempCar->dy;
                } // if 
                //printf("Py: %d\n", tempCar->paradas[p].y);
                //printf("Cy: %d\n", tempCar->y);
                if(tempCar->x < tempCar->paradas[p].x ){
                    tempCar->dx=1;
                    tempCar->dy=0;
                    //printf("EN1\n");
                } else if((tempCar->paradas[p].x <= tempCar->x  && tempCar->paradas[p].y > tempCar->y) && tempCar->x < tempCar->paradas[p].x+(2*TILESIZE)+10){
                    tempCar->dx=1;
                    tempCar->dy=0;
                   // printf("EN2\n");
                } else if(tempCar->paradas[p].x < tempCar->x && tempCar->y >= tempCar->paradas[p].y){
                    tempCar->dx=-1;
                    tempCar->dy=0;
                   // printf("EN3\n");
                } else if(tempCar->y < tempCar->paradas[p].y){
                    tempCar->dx=0;
                    tempCar->dy=1;
                }else{
                   // printf("Py: %d\n", tempCar->paradas[p].x);
                   // printf("Cy: %d\n", tempCar->x);
                    printf("FIN\n");
                    p++;
                    usleep(tempCar->espera*1000000);
                }
            }else{
                tempCar->run=false;
                tempCar->x=0;
                tempCar->x=0;
            }                
        } // for
       usleep(tempCar->speed*10000);
    } // while run
        
} // update_car_position


//void *update_car_position(void * car)
//{
//    
//    Car* tempCar=car;
//    Parada * ptr;
//    ptr = tempCar->paradaInicial;
//    while(tempCar->run){
//        int i=0;
//        for(i; i<NUM_CARS; i++){
////            if(!near_car(tempCar, &cars[i])){
////                tempCar->x+=tempCar->dx;
////                tempCar->y+=tempCar->dy;
////            } // if
//            //tempCar->paradas[0].x;
//            //tempCar->paradas[0].y;
////            if(tempCar->x > tempCar->paradas[0].x){
////                printf("Px: %d\n", tempCar->paradas[0].x);
////                printf("Py: %d\n", tempCar->paradas[0].y);
////                printf("-------------\n");
////                tempCar->dx=0;
////                tempCar->dy=1;            
////            }
////            tempCar->x;
////            ptr->x;
//            if(ptr != NULL){
//               // printf("Px: %d\n", ptr->x);
//                if(!near_car(tempCar, &cars[i])){
//                    tempCar->x+=tempCar->dx;
//                    tempCar->y+=tempCar->dy;
//                } // if  
//                
//                if(tempCar->x < ptr->x){
//                    tempCar->dx=1;
//                    tempCar->dy=0;
//                }else{
//                    printf("FIN\n");
//                    ptr = ptr->siguiente;
//                    //usleep(tempCar->espera*10000);
//                }
//            }else
//                tempCar->run=false;
//            
////ptr = ptr->siguiente; 
//
//        } // for
//       usleep(tempCar->speed*10000);
//    }
//        
//} // update_car_position



Car crearCarro(){
    Car car;
    car.carId=0;
    car.image=cairo_image_surface_create_from_png("c2.png");
    car.x=300;
    car.y=0;
    car.dx=1;
    car.dy=0;
    car.speed=3;
    //cars[0].width=cairo_image_surface_get_width(cars[0].image);
    //cars[0].height=cairo_image_surface_get_height(cars[0].image);
    car.width=20;
    car.height=20;    
    car.run=true;
    
//    car.paradas[0]=nodos[5];
   // car.paradas[0]=nodos[17];
    
    return car;
    
} // CrearCarro