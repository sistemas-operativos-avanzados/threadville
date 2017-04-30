#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct COLORSPEED{
	char *color;
	int speed;
};

struct ROUTE{
	struct NODE *nodes;
};

struct CAR{
	int id;
	int status; //1 for alive and 0 for dead.
	struct COLORSPEED *colorSpeed;
	int availableRides;
	char *destinations;
	struct ROUTE *route;	
};

struct NODE {
	char *id;
	int capability;
	struct NODE *reachableNodes;
	struct CAR *cars;
};

struct THREADVILLE {
	struct NODE *nodes;

}_threadville;

int isAllowed(int capability, int cars){
	if(capability > cars){return 1;}
	else{ return 0;}	 
};

struct CAR newCar(int id, struct COLORSPEED *colorSpeed, char *destinations[]){
	struct CAR _car;
	_car.status = 0;

	//Sacar el numero de carros que estan actualmente en Y1
	if(isAllowed(_threadville.nodes[0].capability, 0) != 0){
		_car.id = id;
		_car.status = 1;
		_car.colorSpeed = malloc(1 * sizeof(*_car.colorSpeed));
		_car.colorSpeed[0] = *colorSpeed;
		//size_t destinations_size = sizeof(destinations);

		//char *destiny[] = {"G5", "G2"};		
		//memcpy(_car.destinations, destiny, 2);

		//_car.route = Hay que generar la ruta aleatoria hacia destiny .route	
	}
	return _car;
};

void go(){
	printf("avanzando \n");
}

void addCar(char *color, char *destinations[]){
//se debe buscar el color en la lista de colores registrados y sacar su velocidad y si el color no existe en la lista, crearlo con un valor default, puede ser 1 segundo
	
	struct COLORSPEED colorSpeed;
	colorSpeed.color = color;
	colorSpeed.speed = 1;

	struct COLORSPEED *_colorSpeed = &colorSpeed;

	struct CAR _car = newCar(2, _colorSpeed, destinations);	

	if(_car.status != 0){
		go();
	}else{
		printf("no hay espacio \n");
	}
}

//TODO Generador de rutas


int main(){
	
	//Include G nodes: G5
	//Include Y nodes: Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8
	_threadville.nodes = malloc(9 * sizeof(*_threadville.nodes));
	
	//**************************Y**********************************
	//Y1 es el nodo donde nacen los autos
	_threadville.nodes[0].id = "Y1";
	_threadville.nodes[0].capability = 1;
	_threadville.nodes[0].reachableNodes = malloc(2 * sizeof(*_threadville.nodes[0].reachableNodes));
	_threadville.nodes[0].reachableNodes[0].id = "Y8";
	_threadville.nodes[0].reachableNodes[1].id = "G5";

	//Y2
	_threadville.nodes[1].id = "Y2";
	_threadville.nodes[1].capability = 1;
	_threadville.nodes[1].reachableNodes = malloc(1 * sizeof(*_threadville.nodes[1].reachableNodes));
	_threadville.nodes[1].reachableNodes[0].id = "Z2";

	//Y3
	_threadville.nodes[2].id = "Y3";
	_threadville.nodes[2].capability = 1;
	_threadville.nodes[2].reachableNodes = malloc(1 * sizeof(*_threadville.nodes[2].reachableNodes));
	_threadville.nodes[2].reachableNodes[0].id = "Z3";

	//Y4
	_threadville.nodes[3].id = "Y4";
	_threadville.nodes[3].capability = 1;
	_threadville.nodes[3].reachableNodes = malloc(1 * sizeof(*_threadville.nodes[3].reachableNodes));
	_threadville.nodes[3].reachableNodes[0].id = "Z4";

	//Y5
	_threadville.nodes[4].id = "Y5";
	_threadville.nodes[4].capability = 1;
	_threadville.nodes[4].reachableNodes = malloc(1 * sizeof(*_threadville.nodes[4].reachableNodes));
	_threadville.nodes[4].reachableNodes[0].id = "Z5";

	//Y6
	_threadville.nodes[5].id = "Y6";
	_threadville.nodes[5].capability = 1;
	_threadville.nodes[5].reachableNodes = malloc(1 * sizeof(*_threadville.nodes[5].reachableNodes));
	_threadville.nodes[5].reachableNodes[0].id = "Y5";
	_threadville.nodes[5].reachableNodes[2].id = "Y4";
	_threadville.nodes[5].reachableNodes[3].id = "Y1";
	
	//Y7
	_threadville.nodes[6].id = "Y7";
	_threadville.nodes[6].capability = 1;
	_threadville.nodes[6].reachableNodes = malloc(1 * sizeof(*_threadville.nodes[6].reachableNodes));
	_threadville.nodes[6].reachableNodes[0].id = "Y6";

	//Y8
	_threadville.nodes[7].id = "Y8";
	_threadville.nodes[7].capability = 1;
	_threadville.nodes[7].reachableNodes = malloc(1 * sizeof(*_threadville.nodes[7].reachableNodes));
	_threadville.nodes[7].reachableNodes[0].id = "Y7";

	//**************************G*****************************

	//G5
	_threadville.nodes[8].id = "G5";
	_threadville.nodes[8].capability = 3;
	_threadville.nodes[8].reachableNodes = malloc(1 * sizeof(*_threadville.nodes[8].reachableNodes));
	_threadville.nodes[8].reachableNodes[0].id = "G6";


	char *destinations[] = {"G5", "G2"};
	char *color = "RED";

	addCar(color, destinations);

	return 0;
}
