
#include <string.h>
#include <limits.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <glib/gmacros.h>

#include "lib/threadville_globals.h"


#include "lib/threadville_functions.h"
#include "lib/threadville_graph.h"
#include "lib/Node.h"


#include "lib/Vehicule.h"




void teardDown(){

	//RELEASE MEMORY

	//Ruta
	//Hay que liberar la memoria cuando se libera un vehicule

	//Colors
//	releaseColor(red);
//	releaseColor(blue);
//	releaseColor(green);
//	releaseColor(white);
//	releaseColor(black);
//	releaseColor(pink);
//	releaseColor(orange);
//	releaseColor(grey);
//	releaseColor(ligthBlue);

	//Nodos de Y
	releaseNode(nodeY1);
	releaseNode(nodeY2);
	releaseNode(nodeY3);
	releaseNode(nodeY4);
	releaseNode(nodeY5);
	releaseNode(nodeY6);
	releaseNode(nodeY7);
	releaseNode(nodeY8);

	//Nodos de A
	releaseNode(nodeA1);
	releaseNode(nodeA2);
	releaseNode(nodeA3);
	releaseNode(nodeA4);
	releaseNode(nodeA6G1);
	releaseNode(nodeA5G2);
	releaseNode(nodeA7);
	releaseNode(nodeA8);

	//Nodos de G
	releaseNode(nodeG3);
	releaseNode(nodeG4);
	releaseNode(nodeG5);
	releaseNode(nodeG6);

	//Nodos de M
	releaseNode(nodeM1);
	releaseNode(nodeM2);
	releaseNode(nodeM3);
	releaseNode(nodeM4S2);
	releaseNode(nodeM5S1);
	releaseNode(nodeM6);

	//Nodos de S
	releaseNode(nodeS3);
	releaseNode(nodeS4);
	releaseNode(nodeS5);
	releaseNode(nodeS6);
	releaseNode(nodeS7);
	releaseNode(nodeS8);

	//Nodos de B
	releaseNode(nodeB1);
	releaseNode(nodeB2);
	releaseNode(nodeB3);
	releaseNode(nodeB4);
	releaseNode(nodeB5H2);
	releaseNode(nodeB6H1);
	releaseNode(nodeB7);
	releaseNode(nodeB8);

	//Nodos de H
	releaseNode(nodeH3);
	releaseNode(nodeH4);
	releaseNode(nodeH5);
	releaseNode(nodeH6);

	//Nodos de N
	releaseNode(nodeN1);
	releaseNode(nodeN2);
	releaseNode(nodeN3);
	releaseNode(nodeN4T2);
	releaseNode(nodeN5T1);
	releaseNode(nodeN6);

	//Nodos de T
	releaseNode(nodeT3);
	releaseNode(nodeT4);
	releaseNode(nodeT5);
	releaseNode(nodeT6);
	releaseNode(nodeT7);
	releaseNode(nodeT8);

	//Nodos de C
	releaseNode(nodeC1);
	releaseNode(nodeC2);
	releaseNode(nodeC3);
	releaseNode(nodeC4);
	releaseNode(nodeC5I2);
	releaseNode(nodeC6I1);
	releaseNode(nodeC7);
	releaseNode(nodeC8);

	//Nodos de I
	releaseNode(nodeI3);
	releaseNode(nodeI4);
	releaseNode(nodeI5);
	releaseNode(nodeI6);

	//Nodos de O
	releaseNode(nodeO1);
	releaseNode(nodeO2);
	releaseNode(nodeO3);
	releaseNode(nodeO4U2);
	releaseNode(nodeO5U1);
	releaseNode(nodeO6);

	//Nodos de U
	releaseNode(nodeU3);
	releaseNode(nodeU4);
	releaseNode(nodeU5);
	releaseNode(nodeU6);
	releaseNode(nodeU7);
	releaseNode(nodeU8);

	//Nodos de D
	releaseNode(nodeD1);
	releaseNode(nodeD2);
	releaseNode(nodeD3);
	releaseNode(nodeD4);
	releaseNode(nodeD5J2);
	releaseNode(nodeD6J1);
	releaseNode(nodeD7);
	releaseNode(nodeD8);

	//Nodos de J
	releaseNode(nodeJ3);
	releaseNode(nodeJ4);
	releaseNode(nodeJ5);
	releaseNode(nodeJ6);

	//Nodos de P
	releaseNode(nodeP1);
	releaseNode(nodeP2);
	releaseNode(nodeP3);
	releaseNode(nodeP4V2);
	releaseNode(nodeP5V1);
	releaseNode(nodeP6);

	//Nodos de V
	releaseNode(nodeV3);
	releaseNode(nodeV4);
	releaseNode(nodeV5);
	releaseNode(nodeV6);
	releaseNode(nodeV7);
	releaseNode(nodeV8);

	//Nodos de E
	releaseNode(nodeE1);
	releaseNode(nodeE2);
	releaseNode(nodeE3);
	releaseNode(nodeE5K2);
	releaseNode(nodeE6K1);
	releaseNode(nodeE4);
	releaseNode(nodeE7);
	releaseNode(nodeE8);

	//Nodos de K
	releaseNode(nodeK3);
	releaseNode(nodeK4);
	releaseNode(nodeK5);
	releaseNode(nodeK6);

	//Nodos de Q
	releaseNode(nodeQ1);
	releaseNode(nodeQ2);
	releaseNode(nodeQ3);
	releaseNode(nodeQ5W1);
	releaseNode(nodeQ4W2);
	releaseNode(nodeQ6);

	//Nodos de W
	releaseNode(nodeW3);
	releaseNode(nodeW4);
	releaseNode(nodeW5);
	releaseNode(nodeW6);
	releaseNode(nodeW7);
	releaseNode(nodeW8);

	//Nodos de F
	releaseNode(nodeF1);
	releaseNode(nodeF2);
	releaseNode(nodeF3);
	releaseNode(nodeF6L1);
	releaseNode(nodeF5L2);
	releaseNode(nodeF4);
	releaseNode(nodeF7);
	releaseNode(nodeF8);

	//Nodos de L
	releaseNode(nodeL3);
	releaseNode(nodeL4);
	releaseNode(nodeL5);
	releaseNode(nodeL6);

	//Nodos de R
	releaseNode(nodeR1);
	releaseNode(nodeR2);
	releaseNode(nodeR3);
	releaseNode(nodeR4X2);
	releaseNode(nodeR5X1);
	releaseNode(nodeR6);

	//Nodos de X
	releaseNode(nodeX3);
	releaseNode(nodeX4);
	releaseNode(nodeX5);
	releaseNode(nodeX6);
	releaseNode(nodeX7);
	releaseNode(nodeX8);

	//Nodos de la Z
	releaseNode(nodeZ1);
	releaseNode(nodeZ2);
	releaseNode(nodeZ3);
	releaseNode(nodeZ4);
	releaseNode(nodeZ5);
	releaseNode(nodeZ6);
	releaseNode(nodeZ7);
	releaseNode(nodeZ8);

	//Nodes de Puentes
	releaseNode(bridgeNodeG4);
	releaseNode(bridgeNodeM2);
	releaseNode(bridgeNodeN1);
	releaseNode(bridgeNodeH5);
	releaseNode(bridgeNodeH4);
	releaseNode(bridgeNodeN2);
	releaseNode(bridgeNodeO1);
	releaseNode(bridgeNodeI5);
	releaseNode(bridgeNodeI4);
	releaseNode(bridgeNodeO2);
	releaseNode(bridgeNodeP1);
	releaseNode(bridgeNodeJ5);
	releaseNode(bridgeNodeJ4);
	releaseNode(bridgeNodeP2);
	releaseNode(bridgeNodeQ1);
	releaseNode(bridgeNodeK5);
	releaseNode(bridgeNodeK4);
	releaseNode(bridgeNodeQ2);
	releaseNode(bridgeNodeR1);
	releaseNode(bridgeNodeL5);

	//Puentes
	releaseBridge(Larry);
	releaseBridge(Curly);
	releaseBridge(Moe);
	releaseBridge(Joe);
	releaseBridge(Shemp);

	//Threadville
	releaseThreadville(threadville);
}

void* move(void* param){
    puts("En thread!!");

    VEHICULE *v = (VEHICULE *) param;

    int i = 0;
    for(i = 0; i < v->delay; i++){
        sleep(1);
        printf("Vehiculo: %s, color %s, delay %d \n", v->id, v->colorSpeed->color, v -> delay);
    }
    releaseVehicule(v);
    return NULL;
}

void makeBus(){
    VEHICULE *redBus = createBus("PERIFERICA-GRANDE");
    redBus -> colorSpeed = red;

    void *result;
    int s;
    /*pthread_t aThread;
    s = pthread_create(&aThread, NULL, move, redBus);
    if(s != 0){
        printf("fallo en crear thread %d", s);
    } else {
        s = pthread_join(aThread, result);
        if(s != 0){
            printf("error pthread_join %d", s);
        }
        puts("finalizo thread");
    }*/
}

void makeAmbulance(){

    VEHICULE *em = createAmbulance("> Emergencias Medicas <");
    em -> colorSpeed = white;
    em -> delay = 3;

    //pthread_t aThread;
    //pthread_create(&aThread, NULL, move, em);
}

void makeCar(){

    VEHICULE *em = createAmbulance("== Toyota ==");
    em -> colorSpeed = black;
    em -> delay = 1;

    //pthread_t aThread;
    //pthread_create(&aThread, NULL, move, em);

}




void headless(){
    init();
    char userOpt[3];
    do{
        printf("\n\n\n\n");
        puts("==> ThreadVille <===");
        puts("[i] Iniciar TV");
        puts("[a] Crear Ambulancia");
        puts("[b] Crear Bus");
        puts("[c] Crear Carro");
        puts("[s] Salir");
        puts("Opcion: ");
        scanf("%2s", userOpt);

        switch (userOpt[0]){
            case 'i':
                break;
            case 'a':
                makeAmbulance();
                break;
            case 'b':
                makeBus();
                break;
            case 'c':
                makeCar();
                break;
            case 's':
                break;
            default:
                puts("Opcion invalida");
        }

    } while (userOpt[0] != 's');
    teardDown();
    exit(0);
}

//******************************************************************************

static gint64 last_tick = 0;
static guint tick_cb = 0;
static guint size =32;

// Area de bubujado
static GtkWidget *drawing;


static void on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    
    draw_background(cr);
   
    int i;
    for(i=0; i<contadorHilos; i++){
        draw_car(cr, vehicules[i]);
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



static void add_vehicule(GtkWidget *widget, gpointer data) {
    
    g_print("Vehicule\n");
    
    int rc;
    vehicules[contadorHilos]= createCar("v");
    
    srand(time(NULL));
    vehicules[contadorHilos]->cantidadParadas=rand()%4+2;
    vehicules[contadorHilos]->paradas=(NODE*) calloc(vehicules[contadorHilos]->cantidadParadas, sizeof(NODE));
    int i;
    for(i=0; i<vehicules[contadorHilos]->cantidadParadas; i++){
        int valor= rand()%9+2;
        vehicules[contadorHilos]->paradas[i]=listaParadas[valor];                       
        printf("valor %d\n", valor);
    } // for     
    
    printf("creating thread %d\n", contadorHilos);
    rc = pthread_create(&threads[contadorHilos], NULL, update_car_position, (void *)vehicules[contadorHilos]);
    if (rc)
    {
            printf("error, return frim pthread creation\n");
            exit(4);
    }
    contadorHilos++;
  
    
} // print_hello

static void add_Ambulance(GtkWidget *widget, gpointer data) {
    
    g_print("Ambulance\n");
    
} // print_hello

//******************************************************************************
// ******************* MAIN ****************************************************
//*****************************************************************************



int main(int argc, char *argv[]) {

	init();
	asignarNodosALista();
	cargarCordenadasNodos();


    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button2;
    GtkWidget *button_box;
    GtkWidget *fixed;


    gtk_init(&argc, &argv);
    GError * error = NULL;

	if (error) {
		printf("%s\n", error->message);
	}

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGTH);
	gtk_window_set_title(GTK_WINDOW(window), "SOA");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);


	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	drawing = gtk_drawing_area_new();
	gtk_fixed_put(GTK_FIXED(fixed), drawing, 0, 0);
	gtk_widget_set_size_request(drawing, WIDTH_DA, HEIGTH_DA);
	g_signal_connect(drawing, "draw", G_CALLBACK(on_draw), NULL);

	button = gtk_button_new_with_label("Vehicule");
	gtk_fixed_put(GTK_FIXED(fixed), button, 1000, 50);
	gtk_widget_set_size_request(button, 80, 30);
	g_signal_connect(button, "clicked", G_CALLBACK(add_vehicule), NULL);

	button2 = gtk_button_new_with_label("Ambulance");
	gtk_fixed_put(GTK_FIXED(fixed), button2, 1000, 100);
	gtk_widget_set_size_request(button2, 80, 30);
	g_signal_connect(button2, "clicked", G_CALLBACK(add_Ambulance), NULL);


	gtk_widget_show_all(window);

	tick_cb = g_timeout_add(1000 / FPS / 2, (GSourceFunc) on_tick, GINT_TO_POINTER(size));



    gtk_main();

    return 0;

} // main