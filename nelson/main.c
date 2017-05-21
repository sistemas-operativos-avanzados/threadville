

#include <cairo.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "map.h"
#include "Car.h"


//#include "gtk-2.0/gtk/gtkdrawingarea.h"



#define FPS 60

static gint64 last_tick = 0;
static guint tick_cb = 0;
static guint size =32;

// Area de bubujado
static GtkWidget *drawing;


cairo_surface_t *imageFondo;


//->
static void on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    
    draw_background(cr, imageFondo);
    
    int i;
    for(i=0; i<NUM_CARS; i++){
        draw_car(cr, &cars[i]);
    } // for
    
} // on_draw


static gboolean on_tick (gpointer user_data) {
    gint64 current = g_get_real_time ();
    gboolean changed = FALSE;
    if ((current - last_tick) < (1000/ FPS)) {
        last_tick = current;
        return G_SOURCE_CONTINUE;
    }

    //update_car_position(&carro2);

    gtk_widget_queue_draw_area(drawing, 0, 0, WIDTH, HEIGTH);

    last_tick = current;
    return G_SOURCE_CONTINUE;
}






//******************************************************************************
// ******************* MAIN ****************************************************
//******************************************************************************


int main(int argc, char *argv[]) {

    GtkWidget *window;
    gtk_init(&argc, &argv);
    GError * error = NULL;

    if (error) {
        printf("%s\n", error->message);
    }

    imageFondo=cairo_image_surface_create_from_png("f2.png");

    //randgen = g_rand_new_with_seed (g_get_real_time());
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGTH);
    gtk_window_set_title(GTK_WINDOW(window), "SOA");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    drawing = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing);
    
    //gtk_container_set_border_width (GTK_CONTAINER(window), 12);
    
    g_signal_connect(drawing, "draw", G_CALLBACK(on_draw), NULL);
    
    //g_signal_connect (window, "key-release-event", G_CALLBACK (on_key_released), &carro1);
    
    gtk_widget_show_all(window);
    
    tick_cb = g_timeout_add(1000 / FPS / 2, (GSourceFunc) on_tick, GINT_TO_POINTER(size));
    
    cargarNodos();

    printf("********************** crear carro *****************************\n");
    
    cars[0].carId=0;
    cars[0].image=cairo_image_surface_create_from_png("c2.png");
    cars[0].x=30;
    cars[0].y=0;
    cars[0].dx=1;
    cars[0].dy=0;
    cars[0].speed=3;
    cars[0].espera=3;
    //cars[0].width=cairo_image_surface_get_width(cars[0].image);
    //cars[0].height=cairo_image_surface_get_height(cars[0].image);
    cars[0].width=20;
    cars[0].height=20;    
    cars[0].run=true;
    cars[0].cantidadParadas=2;
    cars[0].paradas=(Nodo*) calloc(cars[0].cantidadParadas, sizeof(Nodo));
    cars[0].paradas[0]=nodos[1];
    cars[0].paradas[1]=nodos[3];


/*
    cars[0].paradaInicial=NULL;
    cars[0].paradaInicial=agregarParada(nodos[5].x, nodos[5].y,cars[0].paradaInicial);
    cars[0].paradaInicial=agregarParada(nodos[17].x, nodos[17].y,cars[0].paradaInicial);
*/

    cars[1].carId=1;
    cars[1].image=cairo_image_surface_create_from_png("c2.png");
    cars[1].x=0;
    cars[1].y=0;
    cars[1].dx=1;
    cars[1].dy=0;    
    cars[1].speed=1;
    cars[1].espera=3;
    //cars[1].width=cairo_image_surface_get_width(cars[1].image);
    //cars[1].height=cairo_image_surface_get_height(cars[1].image);
    cars[1].width=20;
    cars[1].height=20;     
    cars[1].run=true;
    cars[1].cantidadParadas=3;
    cars[1].paradas=(Nodo*) calloc(cars[1].cantidadParadas, sizeof(Nodo));   
    cars[1].paradas[0]=nodos[2];
    cars[1].paradas[1]=nodos[3];
    cars[1].paradas[2]=nodos[47]; //23 47
/*
    int ta=sizeof(cars[1].paradas)/sizeof(Nodo);
    printf("Px: %d\n", ta);
    cars[1].paradaInicial=NULL;
    cars[1].paradaInicial=agregarParada(nodos[15].x, nodos[15].y,cars[1].paradaInicial);
    cars[1].paradaInicial=agregarParada(nodos[17].x, nodos[17].y,cars[1].paradaInicial);
*/
    

    pthread_t threads[2];
    int rc;
    long t;

    t = 0;
    while (t < 2)
    {
            printf("In main: creating thread %ld\n", t);
            rc = pthread_create(&threads[t], NULL, update_car_position, (void *)&cars[t]);
            if (rc)
            {
                    printf("error, return frim pthread creation\n");
                    exit(4);
            }
            t++;
    }
    

    //pthread_exit(NULL);

    gtk_main();
    
    return 0;
}



/*
#include <stdio.h>
#include "vector.h"

int main() {
  // declare and initialize a new vector
  Vector vector;
  vector_init(&vector);

  // fill it up with 150 arbitrary values
  // this should expand capacity up to 200
  int i;
  for (i = 200; i > -50; i--) {
    vector_append(&vector, i);
  }

  // set a value at an arbitrary index
  // this will expand and zero-fill the vector to fit
  vector_set(&vector, 4452, 21312984);

  // print out an arbitrary value in the vector
  printf("Heres the value at 27: %d\n", vector_get(&vector, 27));

  // we're all done playing with our vector, 
  // so free its underlying data array
  vector_free(&vector);
}
 * 
 * 
 */