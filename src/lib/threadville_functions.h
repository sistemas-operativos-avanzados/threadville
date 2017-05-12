//TV_ADT: Threadville Abstract Data Types

#ifndef TV_ADT

#define TV_ADT

//Estructura para color y velocidad de un vehiculo
typedef struct COLORSPEED{
	char *color;
	int speed;
	struct COLORSPEED *next;
}COLORSPEED;

//Estructura para crear un destino dentro de una ruta
typedef struct DESTINY{
	struct NODE *node;
	struct DESTINY *next;
}DESTINY;

//Estructura para agregar los puntos o paradas que debe hacer un vehiculo, con estos puntos se crean las rutas
typedef struct STOP{
	struct NODE *stop;
	struct STOP *next;
}STOP;

//Estructura para definir un lista de destinos ordenados que resuelven un camino de una parada (STOP) a otra parada para un vehiculo
typedef struct ROUTE{
	struct DESTINY *destinations;
	struct ROUTE *next;
}ROUTE;

//Estructura de vehiculo, utilizada para crear carros, ambulancias y buses
typedef struct VEHICULE{
	char *id;
	int status; //1 for alive and 0 for dead.
	int type; //1 carro, 2 para ambulancia, 3 para bus
	int longCapability;
	struct COLORSPEED *colorSpeed;
	int availableRides;
	struct STOP *stops;
	struct ROUTE *route;
	int delay;
	struct VEHICULE *next;	
}VEHICULE;

//Estructura que define cada punto en el mapa
typedef struct NODE {
	char *id;
	int capability;
	struct NODE *reachabledNodes;
	struct NODE *next;
	struct VEHICULE *vehicules;
}NODE;

//ASIGNACION Y LIBERACION DE MEMORIA DE ESTRUCTURAS
//STOPS
STOP* createStop(){
	STOP *stop = malloc(sizeof(STOP));
	stop->stop = NULL;
	stop->next = NULL;
	return stop;
}

void releaseStop(STOP *stop){
	if(stop){
		free(stop);
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

//COLOR SPEED 
COLORSPEED* createColor(char *color, int speed){
	COLORSPEED *colorSpeed = malloc(sizeof(COLORSPEED));
	colorSpeed->color = strdup(color);
	colorSpeed->speed = speed;
	colorSpeed->next = NULL;
	return colorSpeed;
}

void releaseColor(COLORSPEED *colorSpeed){
	if(colorSpeed){
		if(colorSpeed->color){free(colorSpeed->color);}
	free(colorSpeed);
	}
}


//NODES
NODE* createNode(char *id, int capability){
	NODE *node = malloc(sizeof(NODE));
	node->id = strdup(id);
	node->capability = capability;
	node->reachabledNodes = NULL;
	return node;
}

void releaseNode(NODE *node){
	if(node){
		if(node->id){free(node->id);}
	free(node);
	}
}

//VEHICULES
VEHICULE* createCar(char *id){
	VEHICULE *car = malloc(sizeof(VEHICULE));
	car->id = strdup(id);
	car->status = 0;
	car->type = 1;
	car->longCapability = 1;
	//car->availableRides = 2;
	car->delay = 3;
	car->next = NULL;
	car->colorSpeed = NULL;
	car->route = NULL;
	car->stops = NULL;

	return car;
}

VEHICULE* createAmbulance(char *id){
	VEHICULE *ambulance = malloc(sizeof(VEHICULE));
	ambulance->id = strdup(id);
	ambulance->status = 0;
	ambulance->type = 2;
	ambulance->longCapability = 1;
	//ambulance->availableRides = 2;
	ambulance->delay = 8;
	ambulance->next = NULL;
	ambulance->colorSpeed = NULL;
	ambulance->route = NULL;
	ambulance->stops = NULL;

	return ambulance;
}

VEHICULE* createBus(char *id){
	VEHICULE *bus = malloc(sizeof(VEHICULE));
	bus->id = strdup(id);
	bus->status = 0;
	bus->type = 2;
	bus->longCapability = 2;
	//bus->availableRides = 2;
	bus->delay = 5;
	bus->next = NULL;
	bus->colorSpeed = NULL;
	bus->route = NULL;
	bus->stops = NULL;

	return bus;
}

void releaseVehicule(VEHICULE *car){
	if(car){
		if(car->id){free(car->id);}
	free(car);
	}
}

//Display structs
void displayDestinations(DESTINY *destinations){
	DESTINY *i = destinations;
	for(; i != NULL; i = i->next){
		printf("DESTINY ID:  %s\n", i->node->id);
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
		printf("Vehicule ID:  %s color: %s\n", i->id, i->colorSpeed->color);
		printf("RUTA:\n");
		displayRoutes(i->route);
	}
}

void displayNodes(NODE *nodes){
	NODE *i = nodes;
	for(; i != NULL; i = i->next){
		printf("NODE ID:  %s\n", i->id);
	}
}

void displayStops(STOP *stops){
	STOP *i = stops;
	for(; i != NULL; i = i->next){
		printf("STOP -> NODE ID:  %s\n", i->stop->id);
	}
}

//GENERADOR DE RUTAS
void generateRoute(NODE *from, NODE *to, DESTINY *destinations){
	NODE *start = from;
	if(from != NULL && to != NULL){

		if(strcmp(start->id, to->id) == 0){
			return;
		}
		else{	
		DESTINY *destiny = createDestiny();
	
	
		if(start->reachabledNodes->next == NULL){
			destiny->node = start->reachabledNodes;
			destinations->next = destiny;
			generateRoute(start->reachabledNodes, to, destinations->next);
		}else{
			destiny->node = start->reachabledNodes->next;
			destinations->next = destiny;
			generateRoute(start->reachabledNodes->next, to, destinations->next);
		}
	}
	}	
};

ROUTE* newRoute(STOP *cStop){
	STOP *currentStop = cStop;
	ROUTE *newRoute = createRoute();
	DESTINY *destinations = createDestiny();

	newRoute->destinations = destinations;
	destinations->node = currentStop->stop;	
	if(currentStop->next != NULL){
		generateRoute(currentStop->stop, currentStop->next->stop, newRoute->destinations);
	}
	return newRoute;
}

void addRoute(VEHICULE *vehicule){
	VEHICULE *y = vehicule;
	STOP *i = vehicule->stops;
	ROUTE *busyRoute = y->route;

	//Por cada parada en el mapa
	/*for(; i != NULL; i = i->next){
		//En el caso de que sea la ultima para
		if(i->next != NULL){
			for(; busyRoute != NULL; busyRoute = busyRoute->next){}
			ROUTE *newGeneratedRoute = newRoute(i);
			busyRoute = createRoute();
			busyRoute = newGeneratedRoute;			
		}	
	}*/

	//RUTA 1
	y->route = createRoute();
	y->route = newRoute(i);

	//RUTA 2
	y->route->next = createRoute();
	y->route->next = newRoute(i->next);

	//RUTA 3
	y->route->next->next = createRoute();
	y->route->next->next = newRoute(i->next->next);

};


void addStop(VEHICULE *vehicule, NODE *stop){
	STOP *newStop = createStop();
	newStop->stop = stop;

	STOP *currentStops = vehicule->stops;
	
	while(currentStops != NULL){
		currentStops = currentStops->next;
	}

	currentStops = createStop();	
	currentStops = newStop;
}


int someNumber(){
	return 11;
}

#endif