#include <semaphore.h>

#ifndef TV_ADT


#define TV_ADT

//Estructura para crear un destino dentro de una ruta
typedef struct DESTINY{
	struct NODE *node;
	struct DESTINY *next;
}DESTINY;

//Estructura para definir un lista de destinos ordenados que resuelven un camino de una parada (STOP) a otra parada para un vehiculo
typedef struct ROUTE{
	struct DESTINY *destinations;
	struct ROUTE *next;
}ROUTE;

//Estructura de vehiculo, utilizada para crear carros, ambulancias y buses
typedef struct VEHICULE{
	char *id;
	int type; //1 carro, 2 para ambulancia, 3 para bus
	struct ROUTE *route;
	int delay;
	struct VEHICULE *next;

	bool run;
	int x, y;
	int dx, dy;
	int speed;
	int width, height;
	int cantidadParadas;
	struct NODE **paradas;

	char *nextDestiny;

}VEHICULE;

struct PATH_RULE {
	int destiny;
	int pathWeight;
};

//Estructura que define cada punto en el mapa
typedef struct NODE {
	char *name;
	int id;
	int capability;
	bool especial;
	bool allowTravel;//Indica si se puede pasar por el nodo, se utiliza cuando un nodo esta en reparaciones o es parte de un puente
	int reacheabledNodes[RN];
	struct NODE *next;
	int node_paths[V];
	struct PATH_RULE pathRules[V];
	int x, y;

}NODE;

typedef struct THREADVILLE {
	struct NODE *nodes;
}THREADVILLE;

// Estructura que define los puentes, se utiliza 4 nodos para definir la relacion en el mapa 
// de ambas vias a pesar de ser un camino de un solo carril. Cada uno de los nodos tiene 
// capacidad 3, por lo que se cumple que la capacidad de los puentes es de 6 carros
typedef struct BRIDGE {
	char *id;
	struct NODE *northLeftNode;
	struct NODE *southLeftNode;
	struct NODE *northRightNode;
	struct NODE *southRightNode;

}BRIDGE;


//ASIGNACION Y LIBERACION DE MEMORIA DE ESTRUCTURAS
THREADVILLE* createThreadville(){
	THREADVILLE *threadville = malloc(sizeof(THREADVILLE));
	threadville->nodes = NULL;
	return threadville;
}

void releaseThreadville(THREADVILLE *threadville){
	if(threadville){
		free(threadville);
	}
}

//DESTINY
DESTINY* createDestiny(){
	DESTINY *destiny = malloc(sizeof(DESTINY));
	destiny->node = NULL;
	destiny->next = NULL;
	return destiny;
}

void releaseDestiny(DESTINY *destiny){
	if(destiny){
		free(destiny);
	}
}

//ROUTES
ROUTE* createRoute(){
	ROUTE *route = malloc(sizeof(ROUTE));
	route->destinations = createDestiny();
	route->next = NULL;
	return route;
}

void releaseRoute(ROUTE *route){
	if(route){
		free(route);
	}
}

//VEHICULES
VEHICULE* createCar(char *id){

	VEHICULE *car = malloc(sizeof(VEHICULE));
	car->id = strdup(id);
	car->type = 1;
	car->delay = 3;
	car->next = NULL;
	car->route = NULL;

	car->dx=1;
	car->dy=0;
	car->width=TILESIZE;
	car->height=TILESIZE;
	car->run=true;
	srand(time(NULL));
	car->speed=rand()%7;
	car->nextDestiny = "-";
	return car;
}

VEHICULE* createBus(char *id, int speed){
	VEHICULE *bus = malloc(sizeof(VEHICULE));
	bus->id = strdup(id);
	bus->type = 2;
	bus->delay = 3;
	bus->next = NULL;
	bus->route = NULL;
        
        bus->x=0; 
        bus->y=0; 
        bus->dx=1;
        bus->dy=0;
        bus->width=TILESIZE*2;
        bus->height=TILESIZE*2;    
        bus->run=true;
        bus->speed=speed;
	return bus;
}

void releaseVehicule(VEHICULE *car){
	if(car){
		if(car->id){
			free(car->id);
		}
	    free(car);
	}
}

//NODES
NODE* createNode(int id, char *name, int capability, int reacheabledNodes[]){
	NODE *node = malloc(sizeof(NODE));
	node->id = id;
	node->name = strdup(name);
	node->capability = capability;
	node->especial=false;

	//Assignar nodo alcanzables
	for(int i = 0; i < RN; i++){
		node->reacheabledNodes[i] = reacheabledNodes[i];
	}
	return node;
}

void releaseNode(NODE *node){
	if(node){
		if(node->name){free(node->name);}
	free(node);
	}
}

//BRIDGES
BRIDGE* createBridge(char *id, NODE *southLeft_node, NODE *northLeft_node, NODE *southRight_node, NODE *northRight_node){
	BRIDGE *bridge = malloc(sizeof(BRIDGE));
	bridge->id = strdup(id);
	bridge->southLeftNode = southLeft_node;
	bridge->northLeftNode = northLeft_node;	
	bridge->southRightNode = southRight_node;
	bridge->northRightNode = northRight_node;	
	return bridge;
}

void releaseBridge(BRIDGE *bridge){
	if(bridge){
		if(bridge->id){free(bridge->id);}
	free(bridge);
	}
}


//Display structs
void displayDestinations(DESTINY *destinations){
    DESTINY *i = destinations;
    for(; i != NULL; i = i->next){
            printf("DESTINY - NODE NAME:  %s\n", i->node->name);
    }

}

void displayRoutes(ROUTE *routes){
    ROUTE *i = routes;
    for(; i != NULL; i = i->next){
            printf("NUEVA RUTA:\n");
            displayDestinations(i->destinations);
    }
}

void displayVehicules(VEHICULE *vehicules){
	VEHICULE *i = vehicules;
	for(; i != NULL; i = i->next){
		printf("Vehicule ID:  %s\n", i->id);
		printf("RUTA:\n");
		displayRoutes(i->route);
	}
}

void displayNodes(NODE *nodes){
	NODE *i = nodes;
	for(; i != NULL; i = i->next){
		printf("NODE ID:  %s\n", i->name);
	}
}

//GENERADOR DE RUTAS
//Buscar un nodo de threadville via Index
NODE* findNode(int index, THREADVILLE *threadville){
	NODE *i = threadville->nodes;
	for(; i != NULL; i = i->next){
		if(i->id == index){
			return i;			
		}
		
	}
	return NULL;
}

/*
	Semáforos del norte permiten el paso
	Semáforos del sur NO permiten el paso
*/
void semaphoresBridgeControlInit(BRIDGE *bridge){
	bridge->northLeftNode->especial=true;
	bridge->northLeftNode->allowTravel = false;

	bridge->southRightNode->especial = true;
	bridge->southRightNode->allowTravel = true;

	printf("Bridge = %s\n  North Semaphore = %d, South Semaphore = %d\n", bridge->id, bridge->northLeftNode->allowTravel , bridge->southRightNode->allowTravel );
}

/*
	Si los semáforos del norte permiten el paso, los semáforos del sur NO
	Si los semáforos del sur permiten el paso, los semáforos del norte NO 
*/
void semaphoresBridgeControlWait(BRIDGE *bridge){
	if(bridge->northLeftNode->allowTravel){
		//car needs to wait
		bridge->northLeftNode->allowTravel = false;
		bridge->southRightNode->allowTravel = true;
	}
	if(bridge->southRightNode->allowTravel){
		//car needs to wait
		bridge->northLeftNode->allowTravel = true;
		bridge->southRightNode->allowTravel = false;
	}
}

#endif


