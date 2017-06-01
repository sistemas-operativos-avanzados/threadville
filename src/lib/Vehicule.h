#include <stdbool.h>
#include "threadville_functions.h"
#include "threadville_globals.h"
#include <math.h>

#define NUM_VEHICULE 100

VEHICULE* vehicules[NUM_VEHICULE];
pthread_t threads[NUM_VEHICULE];

static void draw_car (cairo_t * cr, VEHICULE * vehicule) {   
    if(vehicule->run){
        if(vehicule->color==1)
            cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
        else if(vehicule->color==2)
            cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
        else if(vehicule->color==3)
            cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
        else if(vehicule->color==4)
            cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
        else if(vehicule->color==5)
            cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
        else if(vehicule->color==6)
            cairo_set_source_rgb (cr, 1.0, 1.0, 0.0);
        else if(vehicule->color==7)
            cairo_set_source_rgb (cr, 1.0, 0.5, 0.0);
        else if(vehicule->color==8)
            cairo_set_source_rgb (cr, 0.7, 0.7, 0.7);
        else if(vehicule->color==9)
            cairo_set_source_rgb (cr, 1.0, 0.4, 0.45);
        else if(vehicule->color==10)
            cairo_set_source_rgb (cr, 0.75, 0.9, 0.92);

        if(vehicule->type==1){
        	cairo_arc(cr, vehicule->x, vehicule->y+10, TILESIZE/2, 0, 2*3.14);
        	cairo_fill (cr);
	}else{
		cairo_rectangle(cr, vehicule->x-10, vehicule->y,TILESIZE+TILESIZE*fabs(vehicule->dx),TILESIZE+TILESIZE*fabs(vehicule->dy));
                cairo_fill (cr);
	}
        
        if(vehicule->color!=4)
            cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
        else
            cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
	
        cairo_move_to(cr, vehicule->x-8, vehicule->y+12);
        cairo_set_font_size(cr, 12);
        cairo_show_text(cr, vehicule -> nextDestiny);
        
    }
    
} // draw_car


bool near_car(VEHICULE *car1, VEHICULE *car2) {       
    int igual=memcmp(&car1, &car2, sizeof(car1));
    if(igual==0)
        return false;
    
    if((car1->x+(car1->width + 5)*fabs(car1->dx) >= car2->x && car1->x < car2->x) && (car1->y == car2->y) || (car1->y+(car1->height + 5)*fabs(car1->dy) >= car2->y && car1->y < car2->y) && (car1->x == car2->x)){
        //printf("AX %d\n", car1->x+(car1->width + 5)*fabs(car1->dx));
        return true;
    }
    
    return false;

} // near_car

void *update_car_position(void * car)
{    
    VEHICULE* tempCar=car;    
    int p=0;

    generateRoute(tempCar, tempCar->paradas[p], tempCar->paradas[p+1]);
    displayDestinations(tempCar->route->destinations);
    DESTINY *destinoActual = tempCar->route->destinations;
    destinoActual=destinoActual->next;
    tempCar -> nextDestiny = tempCar -> paradas[p + 1] -> name;

    bool mover=true;
    while(tempCar->run){
                   
        if(p < tempCar->cantidadParadas-1){
            int i=0;

            if(tempCar->x < destinoActual->node->x && tempCar->y <= destinoActual->node->y){
                tempCar->dx=1;
                tempCar->dy=0;
            }else if(tempCar->y < destinoActual->node->y ){
                tempCar->dx=0;
                tempCar->dy=1;
            }else if(tempCar->x > destinoActual->node->x){
                tempCar->dx=-1;
                tempCar->dy=0;
            }else if(tempCar->y > destinoActual->node->y){
                tempCar->dx=0;
                tempCar->dy=-1;
            }else {
                if((destinoActual=destinoActual->next) != NULL){
			;
                }else{
                    ++p;
                    if(p < tempCar->cantidadParadas-1){
                        generateRoute(tempCar, tempCar->paradas[p%tempCar->cantidadParadas], tempCar->paradas[(p+1)%tempCar->cantidadParadas]);
                        printf("--------\n");
                        displayDestinations(tempCar->route->destinations);
                        destinoActual = tempCar->route->destinations;
                        destinoActual=destinoActual->next;

                        usleep(tempCar->delay*1000000);
                        tempCar -> nextDestiny = tempCar -> paradas[p + 1] -> name;
                    }else{

                        if(tempCar->type==1){
                            tempCar->run=false;
                            tempCar->x=0;
                            tempCar->x=0;
                            usleep(tempCar->delay*1000000);
                            printf("FIN\n");
                            break;
                        }else {
                            printf("INI %d\n", p);
                            
                            generateRoute(tempCar, tempCar->paradas[p], tempCar->paradas[0]);
                            printf("--------\n");
                            displayDestinations(tempCar->route->destinations);
                            destinoActual = tempCar->route->destinations;
                            destinoActual=destinoActual->next;

                            usleep(tempCar->delay*1000000);
                            tempCar -> nextDestiny = tempCar -> paradas[0] -> name;
                            p=-1;
                            
                        }
                        
                    }
                }                    

            }
                
            for(i; i<contadorHilos; i++){
                
                    if(!near_car(tempCar, vehicules[i])){
                        mover=true;
                    }else{
                        mover=false;
                        break;
                    }
            } // for            
            if(mover){
		if(destinoActual->node->especial && destinoActual->node->allowTravel==false){
			//printf("Estoy en el puente %s\n", destinoActual->node->name);
		}else{
			tempCar->x+=tempCar->dx;
                	tempCar->y+=tempCar->dy;
		}

            }else{
		        //printf("choque \n");
                usleep(10000);
            }
                
        }else{
            if(tempCar->type==1){
                tempCar->run=false;
                tempCar->x=0;
                tempCar->y=0;
                printf("FIN\n");
            }else {
                p=0;
                printf("IN F %d\n", p);
                
            }            
        }                
        
       usleep(tempCar->speed*10000);
       //sleep(1);
       
    } // while run
        
} // update_car_position

