
#include <string.h>
#include <limits.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include <glib/gmacros.h>

#include "lib/threadville_globals.h"


#include "lib/threadville_functions.h"
#include "lib/threadville_graph.h"
#include "lib/Node.h"


#include "lib/Vehicule.h"
#include "lib/Semaphores.h"

GtkWidget *window;
GtkWidget *button;
GtkWidget *buttonContar;
GtkWidget *button2;

//Buses
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

//Carros
GtkWidget *labelCarroAleatorio;
GtkWidget *labelCarroParams;
GtkWidget *labelSample;
GtkWidget *colorSelection;
GList *colorList = NULL;

GtkWidget *buttonCarroAleatorio;
GtkWidget *buttonCarroParams;

GtkWidget *inputDestinos;
    
static gint64 last_tick = 0;
static guint tick_cb = 0;
static guint size =32;

static GtkWidget *drawing;


static void on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    
    draw_background(cr);
    
    // dibujar semaforos
    draw_semaphore(cr, Larry->northLeftNode);
    //draw_semaphore(cr, Larry->northRightNode);
    //draw_semaphore(cr, Larry->southLeftNode);
    draw_semaphore(cr, Larry->southRightNode);
    
    draw_semaphore(cr, Curly->northLeftNode);
    //draw_semaphore(cr, Curly->northRightNode);
    //draw_semaphore(cr, Curly->southLeftNode);
    draw_semaphore(cr, Curly->southRightNode);    
    
    draw_semaphore(cr, Moe->northLeftNode);
    //draw_semaphore(cr, Moe->northRightNode);
    //draw_semaphore(cr, Moe->southLeftNode);
    draw_semaphore(cr, Moe->southRightNode);    
    
    draw_semaphore(cr, Shemp->northLeftNode);
    //draw_semaphore(cr, Shemp->northRightNode);
    //draw_semaphore(cr, Shemp->southLeftNode);
    draw_semaphore(cr, Shemp->southRightNode);    
    
    draw_semaphore(cr, Joe->northLeftNode);
    //draw_semaphore(cr, Joe->northRightNode);
    //draw_semaphore(cr, Joe->southLeftNode);
    draw_semaphore(cr, Joe->southRightNode);    
    
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

    gtk_widget_queue_draw_area(drawing, 0, 0, WIDTH, HEIGTH);

    last_tick = current;
    return G_SOURCE_CONTINUE;
}

static void add_vehicule(GtkWidget *widget, gpointer data) {   
    g_print("Vehicule\n");
    
    int rc;
    vehicules[contadorHilos]= createCar("v");
    
    srand(time(NULL));
    vehicules[contadorHilos]->cantidadParadas=(rand()%4+1)+2;
    vehicules[contadorHilos]->paradas=(NODE*) calloc(vehicules[contadorHilos]->cantidadParadas, sizeof(NODE));
    vehicules[contadorHilos]->paradas[0]=listaParadas[72]; 
    int i;
    for(i=1; i<vehicules[contadorHilos]->cantidadParadas-1; i++){
        int valor= rand()%9+2;
        vehicules[contadorHilos]->paradas[i]=listaParadas[valor];                       
    } // for
    vehicules[contadorHilos]->paradas[vehicules[contadorHilos]->cantidadParadas-1]=listaParadas[87];
    vehicules[contadorHilos]->x=vehicules[contadorHilos]->paradas[0]->x;
    vehicules[contadorHilos]->y=vehicules[contadorHilos]->paradas[0]->y; //0;

    rc = pthread_create(&threads[contadorHilos], NULL, update_car_position, (void *)vehicules[contadorHilos]);
    if (rc)
    {
            printf("error, return frim pthread creation\n");
            exit(4);
    }
    contadorHilos++;    
} 

void add_bus(char *id, int cantidadParadas, int paradas[], int speed, int color){
	char *_id = id;    
	int rc;
    
        vehicules[contadorHilos]= createBus(_id, speed, color);
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
    int paradas[22] = {121, 124, 16, 17, 125, 128, 20, 21, 129, 167, 166, 58, 55, 163, 162, 54, 51, 159, 158, 50, 12, 13};
    int cantidadParadas = 22;
    char *name = "BUS-NARANJA";
    hiloBusNaranja = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 7, 7);
    
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
    int paradas[12] = {0, 6, 11, 71, 86, 119, 179, 173, 168, 108, 92, 60};
    int cantidadParadas = 12;
    char *name = "BUS-ROJO";
    hiloBusRojo = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 5, 1);

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
    int paradas[6] = {9, 59, 87, 92, 48, 2};
    int cantidadParadas = 6;
    char *name = "BUS-VERDE";
    hiloBusVerde = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 5, 3);

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
     int paradas[6] = {131, 177, 170, 120, 92, 87};
     int cantidadParadas = 6;
     char *name = "BUS-AZUL";
     hiloBusAzul = contadorHilos;
     add_bus(name, cantidadParadas, paradas, 5, 2);

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
     int paradas[6] = {65, 125, 171, 110, 50, 4};
     int cantidadParadas = 6;
     char *name = "BUS-BLANCO";
     hiloBusBlanco = contadorHilos;
     add_bus(name, cantidadParadas, paradas, 4, 5);

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
    int paradas[6] = {173, 112, 52, 6, 67, 127};
    int cantidadParadas = 6;
    char *name = "BUS-GRIS";
    hiloBusGris = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 4, 8);

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
    int paradas[6] = {54, 8, 69, 129, 175, 114};
    int cantidadParadas = 6;
    char *name = "BUS-NEGRO";
    hiloBusNegro = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 4, 4);
    
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
    int paradas[4] = {47, 36, 0, 11};
    int cantidadParadas = 4;
    char *name = "BUS-ROSA";
    hiloBusRosa = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 3, 9);
    
    //Bus Rosa> F5L1, A6, A1, F2, F5L1
}

static void add_busRosa(GtkWidget *widget, gpointer data) {
    init_busRosa();
    gtk_widget_set_sensitive(buttonBusRosa, false);
    gtk_widget_set_sensitive(buttonBusRosaOff, true);
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
    int paradas[4] = {168, 132, 143, 179};
    int cantidadParadas = 4;
    char *name = "BUS-CELESTE";
    hiloBusCeleste = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 3, 10);

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

static void validate_data(GtkWidget *widget, gpointer data){
    const gchar *destinos;
    int length;
    int active;
    destinos = gtk_entry_get_text(GTK_ENTRY(inputDestinos));
    length = gtk_entry_get_text_length(GTK_ENTRY(inputDestinos));
    active = gtk_combo_box_get_active(GTK_COMBO_BOX(colorSelection));

    if(length > 0 && active > 0){
    	gtk_widget_set_sensitive(buttonCarroParams, true);
    }else{
	gtk_widget_set_sensitive(buttonCarroParams, false);
    }
}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}


static void add_configured_car(GtkWidget *widget, gpointer data){
    const gchar *destinos;
    int length;
    int active;
    destinos = gtk_entry_get_text(GTK_ENTRY(inputDestinos));
    length = gtk_entry_get_text_length(GTK_ENTRY(inputDestinos));
    active = gtk_combo_box_get_active(GTK_COMBO_BOX(colorSelection));
    char destinosSplit[length];

    char** tokens;
    sprintf(destinosSplit, "%8s\n", destinos);
    tokens = str_split(destinosSplit, ',');

    int rc;
    vehicules[contadorHilos]= createCar("v");
    
    srand(time(NULL));
    vehicules[contadorHilos]->cantidadParadas=length;
    //Colores
    
    //Rojo 1
    //Azul 2
    //Verde 3
    //Negro 4
    //Blanco 5
    //Naranja 7
    //Gris 8
    //Rosa 9
    //Celeste 10

    if(active >= 6){
	vehicules[contadorHilos]->color = active + 1;
    }else{
	vehicules[contadorHilos]->color = active;
    }
    
    vehicules[contadorHilos]->paradas=(NODE*) calloc(vehicules[contadorHilos]->cantidadParadas, sizeof(NODE));

vehicules[contadorHilos]->paradas[0]=listaParadas[72]; 
    int position = 1;
    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            vehicules[contadorHilos]->paradas[position]=listaParadas[atoi(*(tokens + i))];
            free(*(tokens + i));
            position++;
        }
        free(tokens);
    }

    vehicules[contadorHilos]->paradas[position]=listaParadas[87];
   
    vehicules[contadorHilos]->x=vehicules[contadorHilos]->paradas[0]->x;
    vehicules[contadorHilos]->y=vehicules[contadorHilos]->paradas[0]->y; //0;
    
    rc = pthread_create(&threads[contadorHilos], NULL, update_car_position, (void *)vehicules[contadorHilos]);
    if (rc)
    {
            printf("error, return frim pthread creation\n");
            exit(4);
    }
    contadorHilos++; 

    gtk_entry_set_text(GTK_ENTRY(inputDestinos), "");
    gtk_combo_box_set_active(GTK_COMBO_BOX(colorSelection), 0);
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


void carrosEnPuente(){
    int c=count_car(listaParadas[112], listaParadas[124]);
    printf("CANTIDAD DE CARROS %d\n", c);
} // carrosEnPuente 

void initSemaphoreBridges(){
    semaphoresBridgeControlWait(Larry);
   	semaphoresBridgeControlWait(Curly);
    semaphoresBridgeControlWait(Moe);
    semaphoresBridgeControlWait(Shemp);
    semaphoresBridgeControlWait(Joe);
}



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
    
    //Carros
    //Aleatorios
    labelCarroAleatorio = gtk_label_new("Carro aleatorio");
    gtk_fixed_put(GTK_FIXED(fixed), labelCarroAleatorio, 1000, 10);
    gtk_widget_set_size_request(labelCarroAleatorio, 80, 30);

    buttonCarroAleatorio = gtk_button_new_with_label("Crear");
    gtk_fixed_put(GTK_FIXED(fixed), buttonCarroAleatorio, 1020, 40);
    gtk_widget_set_size_request(buttonCarroAleatorio, 80, 30);  
    g_signal_connect(buttonCarroAleatorio, "clicked", G_CALLBACK(add_vehicule), NULL);

    //Parametros
    labelCarroParams = gtk_label_new("Carro configurable [min:0, max:179]");
    gtk_fixed_put(GTK_FIXED(fixed), labelCarroParams, 1120, 10);
    gtk_widget_set_size_request(labelCarroParams, 80, 30);

    inputDestinos = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixed), inputDestinos, 1120, 40);
    gtk_widget_set_size_request(inputDestinos, 80, 30);
    gtk_entry_set_placeholder_text(GTK_ENTRY(inputDestinos), "ei. 1,3,67,2,45");
    g_signal_connect(inputDestinos, "changed", G_CALLBACK(validate_data), NULL);
    
    colorSelection = gtk_combo_box_text_new_with_entry();
    gtk_fixed_put(GTK_FIXED(fixed), colorSelection, 1120, 70);
    gtk_widget_set_size_request(colorSelection, 80, 30);  
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Seleccione un color");

    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Rojo");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Azul");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Verde");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Negro");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Blanco");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Naranja");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Gris");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Rosa");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(colorSelection),"Celeste");
    gtk_combo_box_set_active(GTK_COMBO_BOX(colorSelection), 0);
    g_signal_connect(colorSelection, "changed", G_CALLBACK(validate_data), NULL);

    buttonCarroParams = gtk_button_new_with_label("Crear");
    gtk_widget_set_sensitive(buttonCarroParams, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonCarroParams, 1120, 100);
    gtk_widget_set_size_request(buttonCarroParams, 80, 30);  
    g_signal_connect(buttonCarroParams, "clicked", G_CALLBACK(add_configured_car), NULL);    

    buttonContar = gtk_button_new_with_label("Contar");
    gtk_fixed_put(GTK_FIXED(fixed), buttonContar, 1020, 80);
    gtk_widget_set_size_request(buttonContar, 80, 30);  
    g_signal_connect(buttonContar, "clicked", G_CALLBACK(carrosEnPuente), NULL); 

    //Buses
    labelBuses = gtk_label_new("Buses");
    gtk_fixed_put(GTK_FIXED(fixed), labelBuses, 1000, 160);
    gtk_widget_set_size_request(labelBuses, 80, 30); 

    //BOTONES BUS NARANJA
    buttonBusNaranja = gtk_button_new_with_label("Naranja");
    gtk_widget_set_sensitive(buttonBusNaranja, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusNaranja, 1120, 250);
    gtk_widget_set_size_request(buttonBusNaranja, 80, 30);  
    g_signal_connect(buttonBusNaranja, "clicked", G_CALLBACK(add_busNaranja), NULL);

    buttonBusNaranjaOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusNaranjaOff, 1200, 250);
    gtk_widget_set_size_request(buttonBusNaranjaOff, 20, 30);  
    g_signal_connect(buttonBusNaranjaOff, "clicked", G_CALLBACK(off_busNaranja), NULL);  
    
    //BOTONES BUS VERDE
    buttonBusVerde = gtk_button_new_with_label("Verde");
    gtk_widget_set_sensitive(buttonBusVerde, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusVerde, 1120, 220);
    gtk_widget_set_size_request(buttonBusVerde, 80, 30);  
    g_signal_connect(buttonBusVerde, "clicked", G_CALLBACK(add_busVerde), NULL);

    buttonBusVerdeOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusVerdeOff, 1200, 220);
    gtk_widget_set_size_request(buttonBusVerdeOff, 20, 30);  
    g_signal_connect(buttonBusVerdeOff, "clicked", G_CALLBACK(off_busVerde), NULL);  
    
    //BOTONES BUS ROJO
    buttonBusRojo = gtk_button_new_with_label("Rojo");
    gtk_widget_set_sensitive(buttonBusRojo, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusRojo, 1120, 190);
    gtk_widget_set_size_request(buttonBusRojo, 80, 30);  
    g_signal_connect(buttonBusRojo, "clicked", G_CALLBACK(add_busRojo), NULL);

    buttonBusRojoOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusRojoOff, 1200, 190);
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
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusGris, 1240, 190);
    gtk_widget_set_size_request(buttonBusGris, 80, 30);  
    g_signal_connect(buttonBusGris, "clicked", G_CALLBACK(add_busGris), NULL);

    buttonBusGrisOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusGrisOff, 1320, 190);
    gtk_widget_set_size_request(buttonBusGrisOff, 20, 30);  
    g_signal_connect(buttonBusGrisOff, "clicked", G_CALLBACK(off_busGris), NULL);  
    
    //BOTONES BUS ROSA    
    buttonBusRosa = gtk_button_new_with_label("Rosa");
    gtk_widget_set_sensitive(buttonBusRosa, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusRosa, 1240, 220);
    gtk_widget_set_size_request(buttonBusRosa, 80, 30);  
    g_signal_connect(buttonBusRosa, "clicked", G_CALLBACK(add_busRosa), NULL);

    buttonBusRosaOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusRosaOff, 1320, 220);
    gtk_widget_set_size_request(buttonBusRosaOff, 20, 30);  
    g_signal_connect(buttonBusRosaOff, "clicked", G_CALLBACK(off_busRosa), NULL);  
    
    //BOTONES BUS CELESTE
    buttonBusCeleste = gtk_button_new_with_label("Celeste");
    gtk_widget_set_sensitive(buttonBusCeleste, false);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusCeleste, 1240, 250);
    gtk_widget_set_size_request(buttonBusCeleste, 80, 30);  
    g_signal_connect(buttonBusCeleste, "clicked", G_CALLBACK(add_busCeleste), NULL);

    buttonBusCelesteOff = gtk_button_new_with_label("X");
    gtk_fixed_put(GTK_FIXED(fixed), buttonBusCelesteOff, 1320, 250);
    gtk_widget_set_size_request(buttonBusCelesteOff, 20, 30);  
    g_signal_connect(buttonBusCelesteOff, "clicked", G_CALLBACK(off_busCeleste), NULL);

    gtk_widget_show_all(window);
    
    tick_cb = g_timeout_add(1000 / FPS / 2, (GSourceFunc) on_tick, GINT_TO_POINTER(size)); 
        
    //initSemaphoreBridges();

    gtk_main();

    
    return 0;
} 
