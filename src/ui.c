#include <cairo.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Car.h"

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

    gtk_widget_queue_draw_area(drawing, 0, 0, WIDTH, HEIGTH);

    last_tick = current;
    return G_SOURCE_CONTINUE;
}


//******************************************************************************
// ******************* MAIN ****************************************************
//******************************************************************************


//int main(int argc, char *argv[]) {
//
//    GtkWidget *window;
//    gtk_init(&argc, &argv);
//    GError * error = NULL;
//
//    if (error) {
//        printf("%s\n", error->message);
//    }
//
//    imageFondo=cairo_image_surface_create_from_png("f2.png");
//
//    //randgen = g_rand_new_with_seed (g_get_real_time());
//    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGTH);
//    gtk_window_set_title(GTK_WINDOW(window), "SOA");
//    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//    drawing = gtk_drawing_area_new();
//    gtk_container_add(GTK_CONTAINER(window), drawing);
//
//    g_signal_connect(drawing, "draw", G_CALLBACK(on_draw), NULL);
//
//    gtk_widget_show_all(window);
//
//    tick_cb = g_timeout_add(1000 / FPS / 2, (GSourceFunc) on_tick, GINT_TO_POINTER(size));
//
//    cargarNodos();
//
//    printf("********************** crear carro *****************************\n");
//
//    cars[0].carId=0;
//    cars[0].image=cairo_image_surface_create_from_png("c2.png");
//    cars[0].x=30;
//    cars[0].y=0;
//    cars[0].dx=1;
//    cars[0].dy=0;
//    cars[0].speed=3;
//    cars[0].espera=3;
//    cars[0].width=20;
//    cars[0].height=20;
//    cars[0].run=true;
//    cars[0].cantidadParadas=2;
//    cars[0].paradas=(Nodo*) calloc(cars[0].cantidadParadas, sizeof(Nodo));
//    cars[0].paradas[0]=nodos[1];
//    cars[0].paradas[1]=nodos[3];
//
//    cars[1].carId=1;
//    cars[1].image=cairo_image_surface_create_from_png("c2.png");
//    cars[1].x=0;
//    cars[1].y=0;
//    cars[1].dx=1;
//    cars[1].dy=0;
//    cars[1].speed=1;
//    cars[1].espera=3;
//    cars[1].width=20;
//    cars[1].height=20;
//    cars[1].run=true;
//    cars[1].cantidadParadas=3;
//    cars[1].paradas=(Nodo*) calloc(cars[1].cantidadParadas, sizeof(Nodo));
//    cars[1].paradas[0]=nodos[2];
//    cars[1].paradas[1]=nodos[3];
//    cars[1].paradas[2]=nodos[47]; //23 47
//
//
//    pthread_t threads[2];
//    int rc;
//    long t;
//
//    t = 0;
//    while (t < 2)
//    {
//            printf("In main: creating thread %ld\n", t);
//            rc = pthread_create(&threads[t], NULL, update_car_position, (void *)&cars[t]);
//            if (rc)
//            {
//                    printf("error, return frim pthread creation\n");
//                    exit(4);
//            }
//            t++;
//    }
//
//    gtk_main();
//
//    return 0;
//}