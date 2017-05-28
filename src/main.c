
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


    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button2;
    GtkWidget *labelBuses;

    GtkWidget *buttonBusNaranja;
    GtkWidget *buttonBusNaranjaOff;

    GtkWidget *buttonBusRojo;
    GtkWidget *buttonBusRojoOff;

    GtkWidget *buttonBusVerde;
    GtkWidget *buttonBusVerdeOff;

    GtkWidget *buttonBusAzul;
    GtkWidget *buttonBusAzulOff;

    GtkWidget *buttonBusBlanco;
    GtkWidget *buttonBusBlancoOff;

    GtkWidget *buttonBusNegro;
    GtkWidget *buttonBusNegroOff;

    GtkWidget *buttonBusGris;
    GtkWidget *buttonBusGrisOff;

    GtkWidget *buttonBusRosa;
    GtkWidget *buttonBusRosaOff;

    GtkWidget *buttonBusCeleste;
    GtkWidget *buttonBusCelesteOff;

    GtkWidget *button_box;
    GtkWidget *fixed;    
    
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
        //int valor= rand () % (a-b+1) + b;   // Este está entre a y b
        vehicules[contadorHilos]->paradas[i]=listaParadas[valor];                       
        printf("valor %d\n", valor);
    } // for     
    vehicules[contadorHilos]->x=vehicules[contadorHilos]->paradas[0]->x;
    vehicules[contadorHilos]->y=vehicules[contadorHilos]->paradas[0]->y; //0;
    printf("creating thread %d\n", contadorHilos);
    rc = pthread_create(&threads[contadorHilos], NULL, update_car_position, (void *)vehicules[contadorHilos]);
    if (rc)
    {
            printf("error, return frim pthread creation\n");
            exit(4);
    }
    contadorHilos++;
  
    
} 

void add_bus(char *id, int cantidadParadas, int paradas[], int speed){
	char *_id = id;    
	int rc;
    
        g_print("CREANDO BUS %s\n", _id);
        vehicules[contadorHilos]= createBus(_id, speed);   

    srand(time(NULL));
    vehicules[contadorHilos]->cantidadParadas = cantidadParadas;
    vehicules[contadorHilos]->paradas=(NODE*) calloc(vehicules[contadorHilos]->cantidadParadas, sizeof(NODE));

	for(int i = 0; i < cantidadParadas; i++){	
             vehicules[contadorHilos]->paradas[i]=listaParadas[paradas[i]];
         }
             
    vehicules[contadorHilos]->x = listaParadas[paradas[0]]->x;
    vehicules[contadorHilos]->y = listaParadas[paradas[0]]->y;

    rc = pthread_create(&threads[contadorHilos], NULL, update_car_position, (void *)vehicules[contadorHilos]);
    if (rc)
    {
            printf("error, return frim pthread creation\n");
            exit(4);
    }
    contadorHilos++;
}
//----------------------------------BUS NARANJA
void init_busNaranja(){
    int paradas[21] = {101, 104, 108, 103, 104, 108, 20, 21, 109, 147, 146, 58, 55, 143, 54, 51, 139, 138, 12, 13, 101};
    int cantidadParadas = 21;
    char *name = "BUS-NARANJA";
    hiloBusNaranja = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 7);
    

    //Bus Lombriz - Naranja> M3, O6, C8, C3, O3, Q6, E8, E3, Q3, X4, X7, L6, J3, V4, J6, H3, T4, T7, H6, A8, A3, M3
}

static void add_busNaranja(GtkWidget *widget, gpointer data) {
    init_busNaranja();
    gtk_widget_set_sensitive(buttonBusNaranja, false);
    gtk_widget_set_sensitive(buttonBusNaranjaOff, true);
}

static void off_busNaranja(GtkWidget *widget, gpointer data) {
    vehicules[hiloBusNaranja]->run = false;
    vehicules[hiloBusNaranja]->x = 0;
    vehicules[hiloBusNaranja]->y = 0; 
    gtk_widget_set_sensitive(buttonBusNaranja, true);
    gtk_widget_set_sensitive(buttonBusNaranjaOff, false);
}


//----------------------------------BUS ROJO
void init_busRojo() {
    int paradas[11] = {0, 6, 11, 71, 87, 99, 159, 153, 148, 88, 82};
    int cantidadParadas = 11;
    char *name = "BUS-ROJO";
    hiloBusRojo = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 1);

    //Periferica Grande - Roja> A1, D1, F2, L4, Z (dandole la vuelta), R2, X5, U5, S6, M1, Y (dandole la vuelta)
}

static void add_busRojo(GtkWidget *widget, gpointer data) {
    init_busRojo();
    gtk_widget_set_sensitive(buttonBusRojo, false);
    gtk_widget_set_sensitive(buttonBusRojoOff, true);
}

static void off_busRojo(GtkWidget *widget, gpointer data) {
    vehicules[hiloBusRojo]->run = false;
    vehicules[hiloBusRojo]->x = 0;
    vehicules[hiloBusRojo]->y = 0; 
    gtk_widget_set_sensitive(buttonBusRojo, true);
    gtk_widget_set_sensitive(buttonBusRojoOff, false);
}


//----------------------------------BUS VERDE
void init_busVerde() {
    int paradas[10] = {9, 59, 11, 71, 87, 99, 74, 48, 2, 9};
    int cantidadParadas = 10;
    char *name = "BUS-VERDE";
    hiloBusVerde = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 3);

    //Periferica Norte - Verde> E2, L3*, F2, L4, Z (dandole la vuelta), toma la pista hacia el Oeste Y (dandole la vuelta), G6, B1, E2
}

static void add_busVerde(GtkWidget *widget, gpointer data) {
    init_busVerde();
    gtk_widget_set_sensitive(buttonBusVerde, false);
    gtk_widget_set_sensitive(buttonBusVerdeOff, true);
}

static void off_busVerde(GtkWidget *widget, gpointer data) {
    vehicules[hiloBusVerde]->run = false;
    vehicules[hiloBusVerde]->x = 0;
    vehicules[hiloBusVerde]->y = 0; 
    gtk_widget_set_sensitive(buttonBusVerde, true);
    gtk_widget_set_sensitive(buttonBusVerdeOff, false);
}
 

//----------------------------------BUS AZUL
void init_busAzul() {   
     int paradas[7] = {111, 157, 150, 100, 82, 77, 111};
     int cantidadParadas = 7;
     char *name = "BUS-AZUL";
     hiloBusAzul = contadorHilos;
     add_bus(name, cantidadParadas, paradas, 2);

     //Periferica Sur - Azul> R3, W5, T6, M6, Y (dandole la vuelta), toma la pista hacia el Este Z (dandole la vuelta), R3
}

static void add_busAzul(GtkWidget *widget, gpointer data) {   
     init_busAzul();
     gtk_widget_set_sensitive(buttonBusAzul, false);
     gtk_widget_set_sensitive(buttonBusAzulOff, true);
}

static void off_busAzul(GtkWidget *widget, gpointer data) {  
     vehicules[hiloBusAzul]->run = false;
     vehicules[hiloBusAzul]->x = 0;
     vehicules[hiloBusAzul]->y = 0; 
     gtk_widget_set_sensitive(buttonBusAzul, true);
     gtk_widget_set_sensitive(buttonBusAzulOff, false);
}


//----------------------------------BUS BLANCO
void init_busBlanco() {
     int paradas[7] = {65, 105, 151, 90, 50, 4, 65};
     int cantidadParadas = 7;
     char *name = "BUS-BLANCO";
     hiloBusBlanco = contadorHilos;
     add_bus(name, cantidadParadas, paradas, 5);

     //Bus Blanco> I4, O3, T5, N1, H6, C1, I4
}

static void add_busBlanco(GtkWidget *widget, gpointer data) {
     init_busBlanco();
     gtk_widget_set_sensitive(buttonBusBlanco, false);
     gtk_widget_set_sensitive(buttonBusBlancoOff, true);
}

static void off_busBlanco(GtkWidget *widget, gpointer data) {
     vehicules[hiloBusBlanco]->run = false;
     vehicules[hiloBusBlanco]->x = 0;
     vehicules[hiloBusBlanco]->y = 0; 
     gtk_widget_set_sensitive(buttonBusBlanco, true);
     gtk_widget_set_sensitive(buttonBusBlancoOff, false);
}


//----------------------------------BUS GRIS
void init_busGris() {
    int paradas[7] = {153, 92, 52, 6, 67, 107, 153};
    int cantidadParadas = 7;
    char *name = "BUS-GRIS";
    hiloBusGris = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 8);

    //Bus Gris> U5, O1, I6, D1, J4, P3, U5
}

static void add_busGris(GtkWidget *widget, gpointer data) {
    init_busGris();
    gtk_widget_set_sensitive(buttonBusGris, false);
    gtk_widget_set_sensitive(buttonBusGrisOff, true);
}

static void off_busGris(GtkWidget *widget, gpointer data) {
    vehicules[hiloBusGris]->run = false;
    vehicules[hiloBusGris]->x = 0;
    vehicules[hiloBusGris]->y = 0; 
    gtk_widget_set_sensitive(buttonBusGris, true);
    gtk_widget_set_sensitive(buttonBusGrisOff, false);
}

//----------------------------------BUS NEGRO
void init_busNegro() {
    int paradas[7] = {54, 8, 69, 109, 155, 94, 54};
    int cantidadParadas = 7;
    char *name = "BUS-NEGRO";
    hiloBusNegro = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 4);
    
    //Bus Negro> J6, E1, K4, Q3, V5, P1, J6
}

static void add_busNegro(GtkWidget *widget, gpointer data) { 
    init_busNegro();
    gtk_widget_set_sensitive(buttonBusNegro, false);
    gtk_widget_set_sensitive(buttonBusNegroOff, true);
}

static void off_busNegro(GtkWidget *widget, gpointer data) {
    vehicules[hiloBusNegro]->run = false;
    vehicules[hiloBusNegro]->x = 0;
    vehicules[hiloBusNegro]->y = 0; 
    gtk_widget_set_sensitive(buttonBusNegro, true);
    gtk_widget_set_sensitive(buttonBusNegroOff, false);
}

//----------------------------------BUS ROSA
void init_busRosa() {
    int paradas[5] = {47, 36, 0, 11, 147};
    int cantidadParadas = 5;
    char *name = "BUS-ROSA";
    hiloBusRosa = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 9);
    
    //Bus Rosa> F5L1, A6, A1, F2, F5L1
}

static void add_busRosa(GtkWidget *widget, gpointer data) {
    init_busRosa();
    gtk_widget_set_sensitive(buttonBusNegro, false);
    gtk_widget_set_sensitive(buttonBusNegroOff, true);
}

static void off_busRosa(GtkWidget *widget, gpointer data) {
    vehicules[hiloBusRosa]->run = false;
    vehicules[hiloBusRosa]->x = 0;
    vehicules[hiloBusRosa]->y = 0; 
    gtk_widget_set_sensitive(buttonBusRosa, true);
    gtk_widget_set_sensitive(buttonBusRosaOff, false);
}

//----------------------------------BUS CELESTE
void init_busCeleste() {
    int paradas[5] = {148, 112, 123, 159, 148};
    int cantidadParadas = 5;
    char *name = "BUS-CELESTE";
    hiloBusCeleste = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 10);

    //Bus Celeste> S6, M5S1, R4X2, X5, S6   
}

static void add_busCeleste(GtkWidget *widget, gpointer data) {
    init_busCeleste();  
    gtk_widget_set_sensitive(buttonBusCeleste, false);
    gtk_widget_set_sensitive(buttonBusCelesteOff, true);
}

static void off_busCeleste(GtkWidget *widget, gpointer data) {
    vehicules[hiloBusCeleste]->run = false;
    vehicules[hiloBusCeleste]->x = 0;
    vehicules[hiloBusCeleste]->y = 0; 
    gtk_widget_set_sensitive(buttonBusCeleste, true);
    gtk_widget_set_sensitive(buttonBusCelesteOff, false); 
}

void initBuses(){
   	init_busNaranja();
	init_busRojo();
	init_busVerde();
	init_busAzul();
	init_busBlanco();
	init_busNegro();
	init_busGris();
	init_busRosa();
	init_busCeleste();
}


static void add_Ambulance(GtkWidget *widget, gpointer data) {
    
    g_print("Ambulance\n");
    
} // print_helloz

//******************************************************************************
// ******************* MAIN ****************************************************
//*****************************************************************************



int main(int argc, char *argv[]) {

	init();
	asignarNodosALista();
	cargarCordenadasNodos();
	initBuses();

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
    
    button = gtk_button_new_with_label("Vehiculo");
    gtk_fixed_put(GTK_FIXED(fixed), button, 1000, 10);
    gtk_widget_set_size_request(button, 80, 30);  
    g_signal_connect(button, "clicked", G_CALLBACK(add_vehicule), NULL);

    //Buses
    labelBuses = gtk_label_new("Buses");
    gtk_fixed_put(GTK_FIXED(fixed), labelBuses, 1000, 70);
    gtk_widget_set_size_request(labelBuses, 80, 30); 

    //BOTONES BUS NARANJA
    buttonBusNaranja = gtk_button_new_with_label("Naranja");
    gtk_widget_set_sensitive(buttonBusNaranja, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusNaranja, 1000, 100);
    gtk_widget_set_size_request(buttonBusNaranja, 80, 30);  
    g_signal_connect(buttonBusNaranja, "clicked", G_CALLBACK(add_busNaranja), NULL);

    buttonBusNaranjaOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusNaranjaOff, 1080, 100);
    gtk_widget_set_size_request(buttonBusNaranjaOff, 20, 30);  
    g_signal_connect(buttonBusNaranjaOff, "clicked", G_CALLBACK(off_busNaranja), NULL);  
    
    //BOTONES BUS VERDE
    buttonBusVerde = gtk_button_new_with_label("Verde");
    gtk_widget_set_sensitive(buttonBusVerde, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusVerde, 1000, 130);
    gtk_widget_set_size_request(buttonBusVerde, 80, 30);  
    g_signal_connect(buttonBusVerde, "clicked", G_CALLBACK(add_busVerde), NULL);

    buttonBusVerdeOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusVerdeOff, 1080, 130);
    gtk_widget_set_size_request(buttonBusVerdeOff, 20, 30);  
    g_signal_connect(buttonBusVerdeOff, "clicked", G_CALLBACK(off_busVerde), NULL);  
    
    //BOTONES BUS ROJO
    buttonBusRojo = gtk_button_new_with_label("Rojo");
    gtk_widget_set_sensitive(buttonBusRojo, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusRojo, 1000, 160);
    gtk_widget_set_size_request(buttonBusRojo, 80, 30);  
    g_signal_connect(buttonBusRojo, "clicked", G_CALLBACK(add_busRojo), NULL);

    buttonBusRojoOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusRojoOff, 1080, 160);
    gtk_widget_set_size_request(buttonBusRojoOff, 20, 30);  
    g_signal_connect(buttonBusRojoOff, "clicked", G_CALLBACK(off_busRojo), NULL);  
    
    //BOTONES BUS AZUL
    buttonBusAzul = gtk_button_new_with_label("Azul");
    gtk_widget_set_sensitive(buttonBusAzul, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusAzul, 1000, 190);
    gtk_widget_set_size_request(buttonBusAzul, 80, 30);  
    g_signal_connect(buttonBusAzul, "clicked", G_CALLBACK(add_busAzul), NULL);

    buttonBusAzulOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusAzulOff, 1080, 190);
    gtk_widget_set_size_request(buttonBusAzulOff, 20, 30);  
    g_signal_connect(buttonBusAzulOff, "clicked", G_CALLBACK(off_busAzul), NULL);  
    
    //BOTONES BUS BLANCO
    buttonBusBlanco = gtk_button_new_with_label("Blanco");
    gtk_widget_set_sensitive(buttonBusBlanco, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusBlanco, 1000, 220);
    gtk_widget_set_size_request(buttonBusBlanco, 80, 30);  
    g_signal_connect(buttonBusBlanco, "clicked", G_CALLBACK(add_busBlanco), NULL);

    buttonBusBlancoOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusBlancoOff, 1080, 220);
    gtk_widget_set_size_request(buttonBusBlancoOff, 20, 30);  
    g_signal_connect(buttonBusBlancoOff, "clicked", G_CALLBACK(off_busBlanco), NULL);  
    
    //BOTONES BUS NEGRO 
    buttonBusNegro = gtk_button_new_with_label("Negro");
    gtk_widget_set_sensitive(buttonBusNegro, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusNegro, 1000, 250);
    gtk_widget_set_size_request(buttonBusNegro, 80, 30);  
    g_signal_connect(buttonBusNegro, "clicked", G_CALLBACK(add_busNegro), NULL);

    buttonBusNegroOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusNegroOff, 1080, 250);
    gtk_widget_set_size_request(buttonBusNegroOff, 20, 30);  
    g_signal_connect(buttonBusNegroOff, "clicked", G_CALLBACK(off_busNegro), NULL);  
    
    //BOTONES BUS GRIS 
    buttonBusGris = gtk_button_new_with_label("Gris");
    gtk_widget_set_sensitive(buttonBusGris, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusGris, 1000, 390);
    gtk_widget_set_size_request(buttonBusGris, 80, 30);  
    g_signal_connect(buttonBusGris, "clicked", G_CALLBACK(add_busGris), NULL);

    buttonBusGrisOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusGrisOff, 1080, 390);
    gtk_widget_set_size_request(buttonBusGrisOff, 20, 30);  
    g_signal_connect(buttonBusGrisOff, "clicked", G_CALLBACK(off_busGris), NULL);  
    
    //BOTONES BUS ROSA    
    buttonBusRosa = gtk_button_new_with_label("Rosa");
    gtk_widget_set_sensitive(buttonBusRosa, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusRosa, 1000, 420);
    gtk_widget_set_size_request(buttonBusRosa, 80, 30);  
    g_signal_connect(buttonBusRosa, "clicked", G_CALLBACK(add_busRosa), NULL);

    buttonBusRosaOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusRosaOff, 1080, 420);
    gtk_widget_set_size_request(buttonBusRosaOff, 20, 30);  
    g_signal_connect(buttonBusRosaOff, "clicked", G_CALLBACK(off_busRosa), NULL);  
    
    //BOTONES BUS CELESTE
    buttonBusCeleste = gtk_button_new_with_label("Celeste");
    gtk_widget_set_sensitive(buttonBusCeleste, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusCeleste, 1000, 450);
    gtk_widget_set_size_request(buttonBusCeleste, 80, 30);  
    g_signal_connect(buttonBusCeleste, "clicked", G_CALLBACK(add_busCeleste), NULL);

    buttonBusCelesteOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusCelesteOff, 1080, 450);
    gtk_widget_set_size_request(buttonBusCelesteOff, 20, 30);  
    g_signal_connect(buttonBusCelesteOff, "clicked", G_CALLBACK(off_busCeleste), NULL);

    gtk_widget_show_all(window);
    
    tick_cb = g_timeout_add(1000 / FPS / 2, (GSourceFunc) on_tick, GINT_TO_POINTER(size)); 
    

    
    gtk_main();
    
    return 0;

} 
