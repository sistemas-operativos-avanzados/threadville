#include "map.h"


int regularPathWeight = 5;
int highwayWeight = 1;

int customPathWeights[V][V];


//THREADVILLE
THREADVILLE *threadville;


NODE* listaParadas[N];

//Nodos de la Y
NODE *nodeY1;
NODE *nodeY2;//Pista
NODE *nodeY3;//Pista
NODE *nodeY4;//Pista
NODE *nodeY5;//Pista
NODE *nodeY6;
NODE *nodeY7;
NODE *nodeY8;

//DEFINICION CALE DE UNA VIA
NODE *nodeA5G2;//Comparte la capacidad con G2
NODE *nodeA6G1;//Comparte la capacidad con G1
NODE *nodeM5S1;//Comparte la capacidad con M5
NODE *nodeM4S2;//Comparte la capacidad con M4
NODE *nodeB5H2;//Comparte la capacidad con H2
NODE *nodeB6H1;//Comparte la capacidad con H1
NODE *nodeO4U2;//Comparte la capacidad con U2
NODE *nodeO5U1;//Comparte la capacidad con U1
NODE *nodeN4T2;//Comparte la capacidad con T2
NODE *nodeN5T1;//Comparte la capacidad con T1
NODE *nodeC5I2;//Comparte la capacidad con I2
NODE *nodeC6I1;//Comparte la capacidad con I1
NODE *nodeD5J2;//Comparte la capacidad con J2
NODE *nodeD6J1;//Comparte la capacidad con J1
NODE *nodeP4V2;//Comparte la capacidad con V2
NODE *nodeP5V1;//Comparte la capacidad con V1
NODE *nodeE5K2;//Comparte la capacidad con K2
NODE *nodeE6K1;//Comparte la capacidad con K1
NODE *nodeQ4W2;//Comparte la capacidad con W2
NODE *nodeQ5W1;//Comparte la capacidad con W1
NODE *nodeF6L1;//Comparte la capacidad con L1
NODE *nodeF5L2;//Comparte la capacidad con L2
NODE *nodeR5X1;//Comparte la capacidad con X1
NODE *nodeR4X2;//Comparte la capacidad con X2

//Nodos de la A
NODE *nodeA1;
NODE *nodeA2;
NODE *nodeA3;
NODE *nodeA4;
NODE *nodeA7;
NODE *nodeA8;

//Nodos de l
NODE *nodeG3;
NODE *nodeG4;
NODE *nodeG5;
NODE *nodeG6;

//Nodos de l
NODE *nodeM1;
NODE *nodeM2;
NODE *nodeM3;
NODE *nodeM6;

//Nodos de l
NODE *nodeS3;
NODE *nodeS4;
NODE *nodeS5;
NODE *nodeS6;
NODE *nodeS7;
NODE *nodeS8;

//Nodos de l
NODE *nodeB1;
NODE *nodeB2;
NODE *nodeB3;
NODE *nodeB4;
NODE *nodeB7;
NODE *nodeB8;

//Nodos de l
NODE *nodeH3;
NODE *nodeH4;
NODE *nodeH5;
NODE *nodeH6;

//Nodos de l
NODE *nodeN1;
NODE *nodeN2;
NODE *nodeN3;
NODE *nodeN6;

//Nodos de l
NODE *nodeT3;
NODE *nodeT4;
NODE *nodeT5;
NODE *nodeT6;
NODE *nodeT7;
NODE *nodeT8;

//Nodos de C
NODE *nodeC1;
NODE *nodeC2;
NODE *nodeC3;
NODE *nodeC4;
NODE *nodeC7;
NODE *nodeC8;

//Nodos de I
NODE *nodeI3;
NODE *nodeI4;
NODE *nodeI5;
NODE *nodeI6;

//Nodos de O
NODE *nodeO1;
NODE *nodeO2;
NODE *nodeO3;
NODE *nodeO6;

//Nodos de U
NODE *nodeU3;
NODE *nodeU4;
NODE *nodeU5;
NODE *nodeU6;
NODE *nodeU7;
NODE *nodeU8;

//Nodos de D
NODE *nodeD1;
NODE *nodeD2;
NODE *nodeD3;
NODE *nodeD4;
NODE *nodeD7;
NODE *nodeD8;

//Nodos de J
NODE *nodeJ3;
NODE *nodeJ4;
NODE *nodeJ5;
NODE *nodeJ6;

//Nodos de P
NODE *nodeP1;
NODE *nodeP2;
NODE *nodeP3;
NODE *nodeP6;

//Nodos de V
NODE *nodeV3;
NODE *nodeV4;
NODE *nodeV5;
NODE *nodeV6;
NODE *nodeV7;
NODE *nodeV8;

//Nodos de E
NODE *nodeE1;
NODE *nodeE2;
NODE *nodeE3;
NODE *nodeE4;
NODE *nodeE7;
NODE *nodeE8;

//Nodos de K
NODE *nodeK3;
NODE *nodeK4;
NODE *nodeK5;
NODE *nodeK6;

//Nodos de Q
NODE *nodeQ1;
NODE *nodeQ2;
NODE *nodeQ3;
NODE *nodeQ6;

//Nodos de W
NODE *nodeW3;
NODE *nodeW4;
NODE *nodeW5;
NODE *nodeW6;
NODE *nodeW7;
NODE *nodeW8;

//Nodos de F
NODE *nodeF1;
NODE *nodeF2;
NODE *nodeF3;
NODE *nodeF4;
NODE *nodeF7;
NODE *nodeF8;

//Nodos de L
NODE *nodeL3;
NODE *nodeL4;
NODE *nodeL6;
NODE *nodeL5;


//Nodos de R
NODE *nodeR1;
NODE *nodeR2;
NODE *nodeR3;
NODE *nodeR6;

//Nodos de X
NODE *nodeX3;
NODE *nodeX4;
NODE *nodeX5;
NODE *nodeX6;
NODE *nodeX7;
NODE *nodeX8;

//Nodos de la Z
NODE *nodeZ1;
NODE *nodeZ2;//Pista
NODE *nodeZ3;//Pista
NODE *nodeZ4;//Pista
NODE *nodeZ5;//Pista
NODE *nodeZ6;
NODE *nodeZ7;
NODE *nodeZ8;

//Puentes Bailey
//Larry
BRIDGE *Larry;
NODE *bridgeNodeG4;//Left North
NODE *bridgeNodeH5;//Right North
NODE *bridgeNodeM2;//Left South
NODE *bridgeNodeN1;//Right South

//Curly
BRIDGE *Curly;
NODE *bridgeNodeH4;//Left North
NODE *bridgeNodeI5;//Right North
NODE *bridgeNodeN2;//Left South
NODE *bridgeNodeO1;//Right South

//Moe
BRIDGE *Moe;
NODE *bridgeNodeI4;//Left North
NODE *bridgeNodeJ5;//Right North
NODE *bridgeNodeO2;//Left South
NODE *bridgeNodeP1;//Right South

//Shemp
BRIDGE *Shemp;
NODE *bridgeNodeJ4;//Left North
NODE *bridgeNodeK5;//Right North
NODE *bridgeNodeP2;//Left South
NODE *bridgeNodeQ1;//Right South

//Joe
BRIDGE *Joe;
NODE *bridgeNodeK4;//Left North
NODE *bridgeNodeL5;//Right North
NODE *bridgeNodeQ2;//Left South
NODE *bridgeNodeR1;//Right South


void setNodePaths(THREADVILLE *threadville) {
    NODE *i = threadville -> nodes;
    for(; i != NULL; i = i->next){
        dijkstra(graph, i -> id, i -> node_paths);
    }
}

void initCustomPathWeights(){

	for(int r = 0; r < V; r++){
		for(int h = 0; h < V; h++){
			customPathWeights[r][h] = 0;
		}
	}

}

//Llenar la matriz con segun las relaciones de Threadville
void fillGraph(THREADVILLE *threadville){
	//Llenar con ceros la matriz
	for(int r = 0; r < V; r++){
		for(int h = 0; h < V; h++){
			graph[r][h] = 0;
		}
	}
	//Recorrer todos los nodos de Threadvile
	NODE *node = threadville->nodes;
	for(; node != NULL; node = node->next){
		int reacheabledNodes[RN];
		int id = node->id;

		//Assignar nodo alcanzables
		for(int y = 0; y < RN; y++){
			reacheabledNodes[y] = node->reacheabledNodes[y];
		}

		for(int i = 0; i < RN; i++){
			if(reacheabledNodes[i] != -1){
				if(customPathWeights[id][reacheabledNodes[i]] != 0){
					graph[id][reacheabledNodes[i]] = customPathWeights[id][reacheabledNodes[i]];
				} else {
					graph[id][reacheabledNodes[i]] = regularPathWeight;
				}
			}
		}
	}
}


void init(){
    puts("Iniciando Threadville");
	threadville = createThreadville();
	initCustomPathWeights();

	//Array de nodos alcanzables
	int nodeA5G2Relations[RN] = {1, -1, -1};
	int nodeA6G1Relations[RN] = {36, -1, -1};
	int nodeM5S1Relations[RN] = {3, -1, -1};
	int nodeM4S2Relations[RN] = {46, 9, -1};
	int nodeB5H2Relations[RN] = {5, -1, -1};
	int nodeB6H1Relations[RN] = {56, 0, -1};
	int nodeO4U2Relations[RN] = {86, 15, -1};
	int nodeO5U1Relations[RN] = {6, -1, -1};
	int nodeN4T2Relations[RN] = {66, 7, -1};
	int nodeN5T1Relations[RN] = {8, -1, -1};
	int nodeC5I2Relations[RN] = {11, -1, -1};
	int nodeC6I1Relations[RN] = {76, 4, -1};
	int nodeD5J2Relations[RN] = {13, -1, -1};
	int nodeD6J1Relations[RN] = {96, 10, -1};
	int nodeP4V2Relations[RN] = {106, 19, -1};
	int nodeP5V1Relations[RN] = {14, -1, -1};
	int nodeE5K2Relations[RN] = {17, -1, -1};
	int nodeE6K1Relations[RN] = {116, 12, -1};
	int nodeQ4W2Relations[RN] = {126, 22, -1};
	int nodeQ5W1Relations[RN] = {18, -1, -1};
	int nodeF6L1Relations[RN] = {136, 16, -1};
	int nodeF5L2Relations[RN] = {20, -1, -1};
	int nodeR5X1Relations[RN] = {23, -1, -1};
	int nodeR4X2Relations[RN] = {146, -1, -1};

	int nodeY1Relations[RN] = {31, 40, -1};
	int nodeY2Relations[RN] = {24, -1, -1};
	int nodeY3Relations[RN] = {24, -1, -1};
	int nodeY4Relations[RN] = {155, -1, -1};
	int nodeY5Relations[RN] = {156, -1, -1};
	int nodeY6Relations[RN] = {27, 28, 24};
	int nodeY7Relations[RN] = {29, -1, -1};
	int nodeY8Relations[RN] = {30, -1, -1};

	int nodeA1Relations[RN] = {33, -1, -1};
	int nodeA2Relations[RN] = {34, 52, -1};
	int nodeA3Relations[RN] = {35, -1, -1};
	int nodeA4Relations[RN] = {0, 38, -1};
	int nodeA7Relations[RN] = {37, -1, -1};
	int nodeA8Relations[RN] = {32, -1, -1};

	int nodeG3Relations[RN] = {39, -1, -1};
	int nodeG4Relations[RN] = {160, -1, -1};
	int nodeG5Relations[RN] = {41, -1, -1};
	int nodeG6Relations[RN] = {36, -1, -1};

	int nodeM1Relations[RN] = {29, -1, -1};
	int nodeM2Relations[RN] = {44, -1, -1};
	int nodeM3Relations[RN] = {46, -1, -1};
	int nodeM6Relations[RN] = {42, -1, -1};

	int nodeS3Relations[RN] = {47, -1, -1};
	int nodeS4Relations[RN] = {48, -1, -1};
	int nodeS5Relations[RN] = {49, -1, -1};
	int nodeS6Relations[RN] = {50, -1, -1};
	int nodeS7Relations[RN] = {51, -1, -1};
	int nodeS8Relations[RN] = {2, 45, -1};

	int nodeB1Relations[RN] = {53, -1, -1};
	int nodeB2Relations[RN] = {54, 72, -1};
	int nodeB3Relations[RN] = {55, -1, -1};
	int nodeB4Relations[RN] = {4, 58, -1};
	int nodeB7Relations[RN] = {57, -1, -1};
	int nodeB8Relations[RN] = {52, -1, -1};

	int nodeH3Relations[RN] = {59, -1, -1};
	int nodeH4Relations[RN] = {164, -1, -1};
	int nodeH5Relations[RN] = {61, -1, -1};
	int nodeH6Relations[RN] = {56, -1, -1};

	int nodeN1Relations[RN] = {163, -1, -1};
	int nodeN2Relations[RN] = {64, -1, -1};
	int nodeN3Relations[RN] = {66, -1, -1};
	int nodeN6Relations[RN] = {62, -1, -1};

	int nodeT3Relations[RN] = {67, -1, -1};
	int nodeT4Relations[RN] = {68, -1, -1};
	int nodeT5Relations[RN] = {69, -1, -1};
	int nodeT6Relations[RN] = {70, 48, -1};
	int nodeT7Relations[RN] = {71, -1, -1};
	int nodeT8Relations[RN] = {9, 65, -1};

	int nodeC1Relations[RN] = {73, -1, -1};
	int nodeC2Relations[RN] = {74, 92, -1};
	int nodeC3Relations[RN] = {75, -1, -1};
	int nodeC4Relations[RN] = {10, 78, -1};
	int nodeC7Relations[RN] = {77, -1, -1};
	int nodeC8Relations[RN] = {72, -1, -1};

	int nodeI3Relations[RN] = {79, -1, -1};
	int nodeI4Relations[RN] = {168, -1, -1};
	int nodeI5Relations[RN] = {81, -1, -1};
	int nodeI6Relations[RN] = {76, -1, -1};

	int nodeO1Relations[RN] = {167, -1, -1};
	int nodeO2Relations[RN] = {84, -1, -1};
	int nodeO3Relations[RN] = {86, -1, -1};
	int nodeO6Relations[RN] = {82, -1, -1};

	int nodeU3Relations[RN] = {87, -1, -1};
	int nodeU4Relations[RN] = {88, -1, -1};
	int nodeU5Relations[RN] = {89, -1, -1};
	int nodeU6Relations[RN] = {90, 68, -1};
	int nodeU7Relations[RN] = {91, -1, -1};
	int nodeU8Relations[RN] = {7, 85, -1};

	int nodeD1Relations[RN] = {93, -1, -1};
	int nodeD2Relations[RN] = {94, 112, -1};
	int nodeD3Relations[RN] = {95, -1, -1};
	int nodeD4Relations[RN] = {12, 98, -1};
	int nodeD7Relations[RN] = {97, -1, -1};
	int nodeD8Relations[RN] = {92, -1, -1};

	int nodeJ3Relations[RN] = {99, -1, -1};
	int nodeJ4Relations[RN] = {172, -1, -1};
	int nodeJ5Relations[RN] = {101, -1, -1};
	int nodeJ6Relations[RN] = {96, -1, -1};

	int nodeP1Relations[RN] = {171, -1, -1};
	int nodeP2Relations[RN] = {104, -1, -1};
	int nodeP3Relations[RN] = {106, -1, -1};
	int nodeP6Relations[RN] = {102, -1, -1};

	int nodeV3Relations[RN] = {107, -1, -1};
	int nodeV4Relations[RN] = {108, -1, -1};
	int nodeV5Relations[RN] = {109, -1, -1};
	int nodeV6Relations[RN] = {110, 88, -1};
	int nodeV7Relations[RN] = {111, -1, -1};
	int nodeV8Relations[RN] = {15, 105, -1};

	int nodeE1Relations[RN] = {113, -1, -1};
	int nodeE2Relations[RN] = {114, 132, -1};
	int nodeE3Relations[RN] = {115, -1, -1};
	int nodeE4Relations[RN] = {16, 118, -1};
	int nodeE7Relations[RN] = {117, -1, -1};
	int nodeE8Relations[RN] = {112, -1, -1};

	int nodeK3Relations[RN] = {119, -1, -1};
	int nodeK4Relations[RN] = {176, -1, -1};
	int nodeK5Relations[RN] = {121, -1, -1};
	int nodeK6Relations[RN] = {116, -1, -1};

	int nodeQ1Relations[RN] = {175, -1, -1};
	int nodeQ2Relations[RN] = {124, -1, -1};
	int nodeQ3Relations[RN] = {126, -1, -1};
	int nodeQ6Relations[RN] = {122, -1, -1};

	int nodeW3Relations[RN] = {127, -1, -1};
	int nodeW4Relations[RN] = {128, -1, -1};
	int nodeW5Relations[RN] = {129, -1, -1};
	int nodeW6Relations[RN] = {130, 108, -1};
	int nodeW7Relations[RN] = {131, -1, -1};
	int nodeW8Relations[RN] = {19, 125, -1};

	int nodeF1Relations[RN] = {133, -1, -1};
	int nodeF2Relations[RN] = {134, -1, -1};
	int nodeF3Relations[RN] = {135, -1, -1};
	int nodeF4Relations[RN] = {21, 138, -1};
	int nodeF7Relations[RN] = {137, -1, -1};
	int nodeF8Relations[RN] = {132, -1, -1};

	int nodeL3Relations[RN] = {139, -1, -1};
	int nodeL4Relations[RN] = {152, -1, -1};
	int nodeL6Relations[RN] = {140, -1, -1};
	int nodeL5Relations[RN] = {136, -1, -1};

	int nodeR1Relations[RN] = {179, -1, -1};
	int nodeR2Relations[RN] = {144, -1, -1};
	int nodeR3Relations[RN] = {146, -1, -1};
	int nodeR6Relations[RN] = {142, -1, -1};

	int nodeX3Relations[RN] = {147, -1, -1};
	int nodeX4Relations[RN] = {148, -1, -1};
	int nodeX5Relations[RN] = {149, -1, -1};
	int nodeX6Relations[RN] = {150, 128, -1};
	int nodeX7Relations[RN] = {151, -1, -1};
	int nodeX8Relations[RN] = {22, 145, -1};

	int nodeZ1Relations[RN] = {153, 154, 157};
	int nodeZ2Relations[RN] = {25, -1, -1};
	int nodeZ3Relations[RN] = {26, -1, -1};
	int nodeZ4Relations[RN] = {157, -1, -1};
	int nodeZ5Relations[RN] = {157, -1, -1};
	int nodeZ6Relations[RN] = {143, 158, -1};
	int nodeZ7Relations[RN] = {159, -1, -1};
	int nodeZ8Relations[RN] = {152, -1, -1};

	int bridgeNodeG4Relations[RN] = {162, -1, -1};
	int bridgeNodeH5Relations[RN] = {60, -1, -1};
	int bridgeNodeM2Relations[RN] = {43, -1, -1};
	int bridgeNodeN1Relations[RN] = {161, -1, -1};

	int bridgeNodeH4Relations[RN] = {166, -1, -1};
	int bridgeNodeI5Relations[RN] = {80, -1, -1};
	int bridgeNodeN2Relations[RN] = {63, -1, -1};
	int bridgeNodeO1Relations[RN] = {165, -1, -1};

	int bridgeNodeI4Relations[RN] = {170, -1, -1};
	int bridgeNodeJ5Relations[RN] = {100, -1, -1};
	int bridgeNodeO2Relations[RN] = {83, -1, -1};
	int bridgeNodeP1Relations[RN] = {169, -1, -1};

	int bridgeNodeJ4Relations[RN] = {174, -1, -1};
	int bridgeNodeK5Relations[RN] = {120, -1, -1};
	int bridgeNodeP2Relations[RN] = {103, -1, -1};
	int bridgeNodeQ1Relations[RN] = {173, -1, -1};

	int bridgeNodeK4Relations[RN] = {178, -1, -1};
	int bridgeNodeL5Relations[RN] = {141, -1, -1};
	int bridgeNodeQ2Relations[RN] = {123, -1, -1};
	int bridgeNodeR1Relations[RN] = {177, -1, -1};

	//DEFINICION CALLE DE UNA VIA
	nodeA5G2 = createNode(0, "A5G2", 3, nodeA5G2Relations);//Comparte la capacidad con G2
	nodeA6G1 = createNode(1, "A6G1", 3, nodeA6G1Relations);//Comparte la capacidad con G1
	nodeM5S1 = createNode(2, "M5S1", 3, nodeM5S1Relations);//Comparte la capacidad con M5
	nodeM4S2 = createNode(3, "M4S2", 3, nodeM4S2Relations);//Comparte la capacidad con M4
	nodeB5H2 = createNode(4, "B5H2", 3, nodeB5H2Relations);//Comparte la capacidad con H2
	nodeB6H1 = createNode(5, "B6H1", 3, nodeB6H1Relations);//Comparte la capacidad con H1
	nodeO4U2 = createNode(6, "O4U2", 3, nodeO4U2Relations);//Comparte la capacidad con U2
	nodeO5U1 = createNode(7, "O5U1", 3, nodeO5U1Relations);//Comparte la capacidad con U1
	nodeN4T2 = createNode(8, "N4T2", 3, nodeN4T2Relations);//Comparte la capacidad con T2
	nodeN5T1 = createNode(9, "N5T1", 3, nodeN5T1Relations);//Comparte la capacidad con T1
	nodeC5I2 = createNode(10, "C5I2", 3, nodeC5I2Relations);//Comparte la capacidad con I2
	nodeC6I1 = createNode(11, "C6I1", 3, nodeC6I1Relations);//Comparte la capacidad con I1
	nodeD5J2 = createNode(12, "D5J2", 3, nodeD5J2Relations);//Comparte la capacidad con J2
	nodeD6J1 = createNode(13, "D6J1", 3, nodeD6J1Relations);//Comparte la capacidad con J1
	nodeP4V2 = createNode(14, "P4V2", 3, nodeP4V2Relations);//Comparte la capacidad con V2
	nodeP5V1 = createNode(15, "P5V1", 3, nodeP5V1Relations);//Comparte la capacidad con V1
	nodeE5K2 = createNode(16, "E5K2", 3, nodeE5K2Relations);//Comparte la capacidad con K2
	nodeE6K1 = createNode(17, "E6K1", 3, nodeE6K1Relations);//Comparte la capacidad con K1
	nodeQ4W2 = createNode(18, "Q4W2", 3, nodeQ4W2Relations);//Comparte la capacidad con W2
	nodeQ5W1 = createNode(19, "Q5W1", 3, nodeQ5W1Relations);//Comparte la capacidad con W1
	nodeF6L1 = createNode(20, "F6L1", 3, nodeF6L1Relations);//Comparte la capacidad con L1
	nodeF5L2 = createNode(21, "F5L2", 3, nodeF5L2Relations);//Comparte la capacidad con L2
	nodeR5X1 = createNode(22, "R5X1", 3, nodeR5X1Relations);//Comparte la capacidad con X1
	nodeR4X2 = createNode(23, "R4X2", 3, nodeR4X2Relations);//Comparte la capacidad con X2

	//Nodos de Y
	nodeY1 = createNode(24, "Y1", 1, nodeY1Relations);
	nodeY2 = createNode(25, "Y2", 1, nodeY2Relations);//Pista
	nodeY3 = createNode(26, "Y3", 1, nodeY3Relations);//Pista
	nodeY4 = createNode(27, "Y4", 1, nodeY4Relations);//Pista
	nodeY5 = createNode(28, "Y5", 1, nodeY5Relations);//Pista
	nodeY6 = createNode(29, "Y6", 1, nodeY6Relations);
	nodeY7 = createNode(30, "Y7", 1, nodeY7Relations);
	nodeY8 = createNode(31, "Y8", 1, nodeY8Relations);


	//Nodos de la A
	nodeA1 = createNode(32, "A1", 3, nodeA1Relations);
	nodeA2 = createNode(33, "A2", 3, nodeA2Relations);
	nodeA3 = createNode(34, "A3", 3, nodeA3Relations);
	nodeA4 = createNode(35, "A4", 3, nodeA4Relations);
	nodeA7 = createNode(36, "A7", 3, nodeA7Relations);
	nodeA8 = createNode(37, "A8", 3, nodeA8Relations);

	//Nodos de la G
	nodeG3 = createNode(38, "G3", 3, nodeG3Relations);
	nodeG4 = createNode(39, "G4", 3, nodeG4Relations);
	nodeG5 = createNode(40, "G5", 3, nodeG5Relations);
	nodeG6 = createNode(41, "G6", 3, nodeG6Relations);

	//Nodos de la M
	nodeM1 = createNode(42, "M1", 3, nodeM1Relations);
	nodeM2 = createNode(43, "M2", 3, nodeM2Relations);
	nodeM3 = createNode(44, "M3", 3, nodeM3Relations);
	nodeM6 = createNode(45, "M6", 3, nodeM6Relations);

	//Nodos de la S
	nodeS3 = createNode(46, "S3", 3, nodeS3Relations);
	nodeS4 = createNode(47, "S4", 3, nodeS4Relations);
	nodeS5 = createNode(48, "S5", 3, nodeS5Relations);
	nodeS6 = createNode(49, "S6", 3, nodeS6Relations);
	nodeS7 = createNode(50, "S7", 3, nodeS7Relations);
	nodeS8 = createNode(51, "S8", 3, nodeS8Relations);

	//Nodos de la B
	nodeB1 = createNode(52, "B1", 3, nodeB1Relations);
	nodeB2 = createNode(53, "B2", 3, nodeB2Relations);
	nodeB3 = createNode(54, "B3", 3, nodeB3Relations);
	nodeB4 = createNode(55, "B4", 3, nodeB4Relations);
	nodeB7 = createNode(56, "B7", 3, nodeB7Relations);
	nodeB8 = createNode(57, "B8", 3, nodeB8Relations);

	//Nodos de la H
	nodeH3 = createNode(58, "H3", 3, nodeH3Relations);
	nodeH4 = createNode(59, "H4", 3, nodeH4Relations);
	nodeH5 = createNode(60, "H5", 3, nodeH5Relations);
	nodeH6 = createNode(61, "H6", 3, nodeH6Relations);

	//Nodos de la N
	nodeN1 = createNode(62, "N1", 3, nodeN1Relations);
	nodeN2 = createNode(63, "N2", 3, nodeN2Relations);
	nodeN3 = createNode(64, "N3", 3, nodeN3Relations);
	nodeN6 = createNode(65, "N6", 3, nodeN6Relations);

	//Nodos de la T
	nodeT3 = createNode(66, "T3", 3, nodeT3Relations);
	nodeT4 = createNode(67, "T4", 3, nodeT4Relations);
	nodeT5 = createNode(68, "T5", 3, nodeT5Relations);
	nodeT6 = createNode(69, "T6", 3, nodeT6Relations);
	nodeT7 = createNode(70, "T7", 3, nodeT7Relations);
	nodeT8 = createNode(71, "T8", 3, nodeT8Relations);

	//Nodos de C
	nodeC1 = createNode(72, "C1", 3, nodeC1Relations);
	nodeC2 = createNode(73, "C2", 3, nodeC2Relations);
	nodeC3 = createNode(74, "C3", 3, nodeC3Relations);
	nodeC4 = createNode(75, "C4", 3, nodeC4Relations);
	nodeC7 = createNode(76, "C7", 3, nodeC7Relations);
	nodeC8 = createNode(77, "C8", 3, nodeC8Relations);

	//Nodos de I
	nodeI3 = createNode(78, "I3", 3, nodeI3Relations);
	nodeI4 = createNode(79, "I4", 3, nodeI4Relations);
	nodeI5 = createNode(80, "I5", 3, nodeI5Relations);
	nodeI6 = createNode(81, "I6", 3, nodeI6Relations);

	//Nodos de O
	nodeO1 = createNode(82, "O1", 3, nodeO1Relations);
	nodeO2 = createNode(83, "O2", 3, nodeO2Relations);
	nodeO3 = createNode(84, "O3", 3, nodeO3Relations);
	nodeO6 = createNode(85, "O6", 3, nodeO6Relations);

	//Nodos de U
	nodeU3 = createNode(86, "U3", 3, nodeU3Relations);
	nodeU4 = createNode(87, "U4", 3, nodeU4Relations);
	nodeU5 = createNode(88, "U5", 3, nodeU5Relations);
	nodeU6 = createNode(89, "U6", 3, nodeU6Relations);
	nodeU7 = createNode(90, "U7", 3, nodeU7Relations);
	nodeU8 = createNode(91, "U8", 3, nodeU8Relations);

	//Nodos de D
	nodeD1 = createNode(92, "D1", 3, nodeD1Relations);
	nodeD2 = createNode(93, "D2", 3, nodeD2Relations);
	nodeD3 = createNode(94, "D3", 3, nodeD3Relations);
	nodeD4 = createNode(95, "D4", 3, nodeD4Relations);
	nodeD7 = createNode(96, "D7", 3, nodeD7Relations);
	nodeD8 = createNode(97, "D8", 3, nodeD8Relations);

	//Nodos de J
	nodeJ3 = createNode(98, "J3", 3, nodeJ3Relations);
	nodeJ4 = createNode(99, "J4", 3, nodeJ4Relations);
	nodeJ5 = createNode(100, "J5", 3, nodeJ5Relations);
	nodeJ6 = createNode(101, "J6", 3, nodeJ6Relations);

	//Nodos de P
	nodeP1 = createNode(102, "P1", 3, nodeP1Relations);
	nodeP2 = createNode(103, "P2", 3, nodeP2Relations);
	nodeP3 = createNode(104, "P3", 3, nodeP3Relations);
	nodeP6 = createNode(105, "P6", 3, nodeP6Relations);

	//Nodos de V
	nodeV3 = createNode(106, "V3", 3, nodeV3Relations);
	nodeV4 = createNode(107, "V4", 3, nodeV4Relations);
	nodeV5 = createNode(108, "V5", 3, nodeV5Relations);
	nodeV6 = createNode(109, "V6", 3, nodeV6Relations);
	nodeV7 = createNode(110, "V7", 3, nodeV7Relations);
	nodeV8 = createNode(111, "V8", 3, nodeV8Relations);

	//Nodos de E
	nodeE1 = createNode(112, "E1", 3, nodeE1Relations);
	nodeE2 = createNode(113, "E2", 3, nodeE2Relations);
	nodeE3 = createNode(114, "E3", 3, nodeE3Relations);
	nodeE4 = createNode(115, "E4", 3, nodeE4Relations);
	nodeE7 = createNode(116, "E7", 3, nodeE7Relations);
	nodeE8 = createNode(117, "E8", 3, nodeE8Relations);

	//Nodos de K
	nodeK3 = createNode(118, "K3", 3, nodeK3Relations);
	nodeK4 = createNode(119, "K4", 3, nodeK4Relations);
	nodeK5 = createNode(120, "K5", 3, nodeK5Relations);
	nodeK6 = createNode(121, "K6", 3, nodeK6Relations);

	//Nodos de Q
	nodeQ1 = createNode(122, "Q1", 3, nodeQ1Relations);
	nodeQ2 = createNode(123, "Q2", 3, nodeQ2Relations);
	nodeQ3 = createNode(124, "Q3", 3, nodeQ3Relations);
	nodeQ6 = createNode(125, "Q6", 3, nodeQ6Relations);

	//Nodos de W
	nodeW3 = createNode(126, "W3", 3, nodeW3Relations);
	nodeW4 = createNode(127, "W4", 3, nodeW4Relations);
	nodeW5 = createNode(128, "W5", 3, nodeW5Relations);
	nodeW6 = createNode(129, "W6", 3, nodeW6Relations);
	nodeW7 = createNode(130, "W7", 3, nodeW7Relations);
	nodeW8 = createNode(131, "W8", 3, nodeW8Relations);

	//Nodos de F
	nodeF1 = createNode(132, "F1", 3, nodeF1Relations);
	nodeF2 = createNode(133, "F2", 3, nodeF2Relations);
	nodeF3 = createNode(134, "F3", 3, nodeF3Relations);
	nodeF4 = createNode(135, "F4", 3, nodeF4Relations);
	nodeF7 = createNode(136, "F7", 3, nodeF7Relations);
	nodeF8 = createNode(137, "F8", 3, nodeF8Relations);

	//Nodos de L
	nodeL3 = createNode(138, "L3", 3, nodeL3Relations);
	nodeL4 = createNode(139, "L4", 3, nodeL4Relations);
	nodeL6 = createNode(140, "L6", 3, nodeL6Relations);
	nodeL5 = createNode(141, "L5", 3, nodeL5Relations);


	//Nodos de R
	nodeR1 = createNode(142, "R1", 3, nodeR1Relations);
	nodeR2 = createNode(143, "R2", 3, nodeR2Relations);
	nodeR3 = createNode(144, "R3", 3, nodeR3Relations);
	nodeR6 = createNode(145, "R6", 3, nodeR6Relations);

	//Nodos de X
	nodeX3 = createNode(146, "X3", 3, nodeX3Relations);
	nodeX4 = createNode(147, "X4", 3, nodeX4Relations);
	nodeX5 = createNode(148, "X5", 3, nodeX5Relations);
	nodeX6 = createNode(149, "X6", 3, nodeX6Relations);
	nodeX7 = createNode(150, "X7", 3, nodeX7Relations);
	nodeX8 = createNode(151, "X8", 3, nodeX8Relations);

	//Nodos de la Z
	nodeZ1 = createNode(152, "Z1", 1, nodeZ1Relations);
	nodeZ2 = createNode(153, "Z2", 1, nodeZ2Relations);//Pista
	nodeZ3 = createNode(154, "Z3", 1, nodeZ3Relations);//Pista
	nodeZ4 = createNode(155, "Z4", 1, nodeZ4Relations);//Pista
	nodeZ5 = createNode(156, "Z5", 1, nodeZ5Relations);//Pista
	nodeZ6 = createNode(157, "Z6", 1, nodeZ6Relations);
	nodeZ7 = createNode(158, "Z7", 1, nodeZ7Relations);
	nodeZ8 = createNode(159, "Z8", 1, nodeZ8Relations);

	//Puente Bailey
	//Larry
	bridgeNodeG4 = createNode(160, "BG4", 3, bridgeNodeG4Relations);
	bridgeNodeH5 = createNode(161, "BH5", 3, bridgeNodeH5Relations);
	bridgeNodeM2 = createNode(162, "BM2", 3, bridgeNodeM2Relations);
	bridgeNodeN1 = createNode(163, "BN1", 3, bridgeNodeN1Relations);
	Larry = createBridge("Larry", bridgeNodeM2, bridgeNodeG4, bridgeNodeN1, bridgeNodeH5);
	semaphoresBridgeControlInit(Larry);
	semaphoresBridgeControlWait(Larry);

	//Curly
	bridgeNodeH4 = createNode(164, "BH4", 3, bridgeNodeH4Relations);
	bridgeNodeI5 = createNode(165, "BI5", 3, bridgeNodeI5Relations);
	bridgeNodeN2 = createNode(166, "BN2", 3, bridgeNodeN2Relations);
	bridgeNodeO1 = createNode(167, "BO1", 3, bridgeNodeO1Relations);
	Curly = createBridge("Curly", bridgeNodeN2, bridgeNodeH4, bridgeNodeO1, bridgeNodeI5);
	semaphoresBridgeControlInit(Curly);
	semaphoresBridgeControlWait(Curly);

	//Moe
	bridgeNodeI4 = createNode(168, "BI4", 3, bridgeNodeI4Relations);
	bridgeNodeJ5 = createNode(169, "BJ5", 3, bridgeNodeJ5Relations);
	bridgeNodeO2 = createNode(170, "BO2", 3, bridgeNodeO2Relations);
	bridgeNodeP1 = createNode(171, "BP1", 3, bridgeNodeP1Relations);
	Moe = createBridge("Moe", bridgeNodeO2, bridgeNodeI4, bridgeNodeP1, bridgeNodeJ5);
	semaphoresBridgeControlInit(Moe);
	semaphoresBridgeControlWait(Moe);

	//Shemp
	bridgeNodeJ4 = createNode(172, "BJ4", 3, bridgeNodeJ4Relations);
	bridgeNodeK5 = createNode(173, "BK5", 3, bridgeNodeK5Relations);
	bridgeNodeP2 = createNode(174, "BP2", 3, bridgeNodeP2Relations);
	bridgeNodeQ1 = createNode(175, "BQ1", 3, bridgeNodeQ1Relations);
	Shemp = createBridge("Shemp", bridgeNodeP2, bridgeNodeJ4, bridgeNodeQ1, bridgeNodeK5);
	semaphoresBridgeControlInit(Shemp);
	semaphoresBridgeControlWait(Shemp);

	//Joe
	bridgeNodeK4 = createNode(176, "BK4", 3, bridgeNodeK4Relations);
	bridgeNodeL5 = createNode(177, "BL5", 3, bridgeNodeL5Relations);
	bridgeNodeQ2 = createNode(178, "BQ2", 3, bridgeNodeQ2Relations);
	bridgeNodeR1 = createNode(179, "BR1", 3, bridgeNodeR1Relations);
	Joe = createBridge("Joe", bridgeNodeQ2, bridgeNodeK4, bridgeNodeR1, bridgeNodeL5);
	semaphoresBridgeControlInit(Joe);
	semaphoresBridgeControlWait(Joe);
	
	//DEFINICION DE RELACIONES
	threadville->nodes = nodeY1;

	//Nodos de Y
	nodeY1->next = nodeY2;
	nodeY2->next = nodeY3;
	nodeY3->next = nodeY4;
	nodeY4->next = nodeY5;
	nodeY5->next = nodeY6;
	nodeY6->next = nodeY7;
	nodeY7->next = nodeY8;
	nodeY8->next = nodeA1;


	//Nodos de A
	nodeA1->next = nodeA2;
	nodeA2->next = nodeA3;
	nodeA3->next = nodeA4;
	nodeA4->next = nodeA5G2;
	nodeA5G2->next = nodeA6G1;
	nodeA6G1->next = nodeA7;
	nodeA7->next = nodeA8;
	nodeA8->next = nodeG3;

	//Nodos de G
	nodeG3->next = nodeG4;
	nodeG4->next = nodeG5;
	nodeG5->next = nodeG6;
	nodeG6->next = nodeM1;

	//Nodos de M
	nodeM1->next = nodeM2;
	nodeM2->next = nodeM3;
	nodeM3->next = nodeM4S2;
	nodeM4S2->next = nodeM5S1;
	nodeM5S1->next = nodeM6;
	nodeM6->next = nodeS3;

	//Nodos de S
	nodeS3->next = nodeS4;
	nodeS4->next = nodeS5;
	nodeS5->next = nodeS6;
	nodeS6->next = nodeS7;
	nodeS7->next = nodeS8;
	nodeS8->next = nodeB1;

	//Nodos de B
	nodeB1->next = nodeB2;
	nodeB2->next = nodeB3;
	nodeB3->next = nodeB4;
	nodeB4->next = nodeB5H2;
	nodeB5H2->next = nodeB6H1;
	nodeB6H1->next = nodeB7;
	nodeB7->next = nodeB8;
	nodeB8->next = nodeH3;

	//Nodos de H
	nodeH3->next = nodeH4;
	nodeH4->next = nodeH5;
	nodeH5->next = nodeH6;
	nodeH6->next = nodeN1;

	//Nodos de N
	nodeN1->next = nodeN2;
	nodeN2->next = nodeN3;
	nodeN3->next = nodeN4T2;
	nodeN4T2->next = nodeN5T1;
	nodeN5T1->next = nodeN6;
	nodeN6->next = nodeT3;

	//Nodos de T
	nodeT3->next = nodeT4;
	nodeT4->next = nodeT5;
	nodeT5->next = nodeT6;
	nodeT6->next = nodeT7;
	nodeT7->next = nodeT8;
	nodeT8->next = nodeC1;

	//Nodos de C
	nodeC1->next = nodeC2;
	nodeC2->next = nodeC3;
	nodeC3->next = nodeC4;
	nodeC4->next = nodeC5I2;
	nodeC5I2->next = nodeC6I1;
	nodeC6I1->next = nodeC7;
	nodeC7->next = nodeC8;
	nodeC8->next = nodeI3;

	//Nodos de I
	nodeI3->next = nodeI4;
	nodeI4->next = nodeI5;
	nodeI5->next = nodeI6;
	nodeI6->next = nodeO1;

	//Nodos de O
	nodeO1->next = nodeO2;
	nodeO2->next = nodeO3;
	nodeO3->next = nodeO4U2;
	nodeO4U2->next = nodeO5U1;
	nodeO5U1->next = nodeO6;
	nodeO6->next = nodeU3;

	//Nodos de U
	nodeU3->next = nodeU4;
	nodeU4->next = nodeU5;
	nodeU5->next = nodeU6;
	nodeU6->next = nodeU7;
	nodeU7->next = nodeU8;
	nodeU8->next = nodeD1;

	//Nodos de D
	nodeD1->next = nodeD2;
	nodeD2->next = nodeD3;
	nodeD3->next = nodeD4;
	nodeD4->next = nodeD5J2;
	nodeD5J2->next = nodeD6J1;
	nodeD6J1->next = nodeD7;
	nodeD7->next = nodeD8;
	nodeD8->next = nodeJ3;

	//Nodos de J
	nodeJ3->next = nodeJ4;
	nodeJ4->next = nodeJ5;
	nodeJ5->next = nodeJ6;
	nodeJ6->next = nodeP1;

	//Nodos de P
	nodeP1->next = nodeP2;
	nodeP2->next = nodeP3;
	nodeP3->next = nodeP4V2;
	nodeP4V2->next = nodeP5V1;
	nodeP5V1->next = nodeP6;
	nodeP6->next = nodeV3;

	//Nodos de V
	nodeV3->next = nodeV4;
	nodeV4->next = nodeV5;
	nodeV5->next = nodeV6;
	nodeV6->next = nodeV7;
	nodeV7->next = nodeV8;
	nodeV8->next = nodeE1;

	//Nodos de E
	nodeE1->next = nodeE2;
	nodeE2->next = nodeE3;
	nodeE3->next = nodeE4;
	nodeE4->next = nodeE5K2;
	nodeE5K2->next = nodeE6K1;
	nodeE6K1->next = nodeE7;
	nodeE7->next = nodeE8;
	nodeE8->next = nodeK3;

	//Nodos de K
	nodeK3->next = nodeK4;
	nodeK4->next = nodeK5;
	nodeK5->next = nodeK6;
	nodeK6->next = nodeQ1;

	//Nodos de Q
	nodeQ1->next = nodeQ2;
	nodeQ2->next = nodeQ3;
	nodeQ3->next = nodeQ4W2;
	nodeQ4W2->next = nodeQ5W1;
	nodeQ5W1->next = nodeQ6;
	nodeQ6->next = nodeW3;

	//Nodos de W
	nodeW3->next= nodeW4;
	nodeW4->next = nodeW5;
	nodeW5->next = nodeW6;
	nodeW6->next = nodeW7;
	nodeW7->next = nodeW8;
	nodeW8->next = nodeF1;

	//Nodos de F
	nodeF1->next = nodeF2;
	nodeF2->next = nodeF3;
	nodeF3->next = nodeF4;
	nodeF4->next = nodeF5L2;
	nodeF5L2->next = nodeF6L1;
	nodeF6L1->next = nodeF7;
	nodeF7->next = nodeF8;
	nodeF8->next = nodeL3;

	//Nodos de L
	nodeL3->next = nodeL4;
	nodeL4->next = nodeL5;
	nodeL5->next = nodeL6;
	nodeL6->next = nodeR1;

	//Nodos de R
	nodeR1->next = nodeR2;
	nodeR2->next = nodeR3;
	nodeR3->next = nodeR4X2;
	nodeR4X2->next = nodeR5X1;
	nodeR5X1->next = nodeR6;
	nodeR6->next = nodeX3;

	//Nodos de X
	nodeX3->next = nodeX4;
	nodeX4->next = nodeX5;
	nodeX5->next = nodeX6;
	nodeX6->next = nodeX7;
	nodeX7->next = nodeX8;
	nodeX8->next = nodeZ1;

	//Nodos de Z
	nodeZ1->next = nodeZ2;
	nodeZ2->next = nodeZ3;
	nodeZ3->next = nodeZ4;
	nodeZ4->next = nodeZ5;
	nodeZ5->next = nodeZ6;
	nodeZ6->next = nodeZ7;
	nodeZ7->next = nodeZ8;
	nodeZ8->next = bridgeNodeG4;

	//Puente Bailey
	//Larry
	bridgeNodeG4->next = bridgeNodeM2;
	bridgeNodeM2->next = bridgeNodeN1;
	bridgeNodeN1->next = bridgeNodeH5;

	//Curly
	bridgeNodeH5->next = bridgeNodeH4;
	bridgeNodeH4->next = bridgeNodeN2;
	bridgeNodeN2->next = bridgeNodeO1;
	bridgeNodeO1->next = bridgeNodeI5;

	//Moe
	bridgeNodeI5->next = bridgeNodeI4;
	bridgeNodeI4->next = bridgeNodeO2;
	bridgeNodeO2->next = bridgeNodeP1;
	bridgeNodeP1->next = bridgeNodeJ5;

	//Shemp
	bridgeNodeJ5->next = bridgeNodeJ4;
	bridgeNodeJ4->next = bridgeNodeP2;
	bridgeNodeP2->next = bridgeNodeQ1;
	bridgeNodeQ1->next = bridgeNodeK5;

	//Joe
	bridgeNodeK5->next = bridgeNodeK4;
	bridgeNodeK4->next = bridgeNodeQ2;
	bridgeNodeQ2->next = bridgeNodeR1;
	bridgeNodeR1->next = bridgeNodeL5;


	//Pesos de rutas personalizadas
	customPathWeights[153][25] = highwayWeight;
	customPathWeights[154][26] = highwayWeight;
	customPathWeights[27][155] = highwayWeight;
	customPathWeights[28][156] = highwayWeight;

	fillGraph(threadville);
	setNodePaths(threadville);
} 

// ********************** cargarNodos

void asignarNodosALista(){

        listaParadas[0]=nodeA1;
        listaParadas[1]=nodeA2;
        listaParadas[2]=nodeB1;
        listaParadas[3]=nodeB2;
        listaParadas[4]=nodeC1;
        listaParadas[5]=nodeC2;
        listaParadas[6]=nodeD1;
        listaParadas[7]=nodeD2;        
        listaParadas[8]=nodeE1;
        listaParadas[9]=nodeE2;
        listaParadas[10]=nodeF1;
        
        listaParadas[11]=nodeF2;        
        listaParadas[12]=nodeA8;
        listaParadas[13]=nodeA3;
        listaParadas[14]=nodeB8;
        listaParadas[15]=nodeB3;        
        listaParadas[16]=nodeC8;
        listaParadas[17]=nodeC3;        
        listaParadas[18]=nodeD8;
        listaParadas[19]=nodeD3;
        
        listaParadas[20]=nodeE8;
        listaParadas[21]=nodeE3;
        listaParadas[22]=nodeF8;
        listaParadas[23]=nodeF3;
        listaParadas[24]=nodeA7;
        listaParadas[25]=nodeA4;
        listaParadas[26]=nodeB7;
        listaParadas[27]=nodeB4;        
        listaParadas[28]=nodeC7;
        listaParadas[29]=nodeC4;         
        
        
        listaParadas[30]=nodeD7;
        listaParadas[31]=nodeD4;
        listaParadas[32]=nodeE7;
        listaParadas[33]=nodeE4;
        listaParadas[34]=nodeF7;
        listaParadas[35]=nodeF4;
        listaParadas[36]=nodeA6G1;
        listaParadas[37]=nodeA5G2;        
	listaParadas[38]=nodeB6H1;
        listaParadas[39]=nodeB5H2;        
        
        listaParadas[40]=nodeC6I1;	
        listaParadas[41]=nodeC5I2;	
        listaParadas[42]=nodeD6J1; 
      	listaParadas[43]=nodeD5J2;
        listaParadas[44]=nodeE6K1;
        listaParadas[45]=nodeE5K2;
        listaParadas[46]=nodeF6L1;        	
        listaParadas[47]=nodeF5L2;        
        listaParadas[48]=nodeG6;
        listaParadas[49]=nodeG3;        
        
        listaParadas[50]=nodeH6;
        listaParadas[51]=nodeH3;
        listaParadas[52]=nodeI6;
        listaParadas[53]=nodeI3;         
        listaParadas[54]=nodeJ6;
        listaParadas[55]=nodeJ3;
        listaParadas[56]=nodeK6;
        listaParadas[57]=nodeK3;
        listaParadas[58]=nodeL6;                
        listaParadas[59]=nodeL3;        
        
        listaParadas[60]=nodeG5;        
        listaParadas[61]=nodeG4;        
        listaParadas[62]=nodeH5;
        listaParadas[63]=nodeH4;
        listaParadas[64]=nodeI5;
        listaParadas[65]=nodeI4;        
        listaParadas[66]=nodeJ5;
        listaParadas[67]=nodeJ4;
        listaParadas[68]=nodeK5;
        listaParadas[69]=nodeK4;        
                
        listaParadas[70]=nodeL5;
        listaParadas[71]=nodeL4;
        listaParadas[72]=nodeY8;
        listaParadas[73]=nodeY1;        
        listaParadas[74]=nodeY2;
        
        listaParadas[75]=bridgeNodeG4;
        listaParadas[76]=bridgeNodeH5;
        listaParadas[77]=bridgeNodeH4;
        listaParadas[78]=bridgeNodeI5;
        listaParadas[79]=bridgeNodeI4;        
        listaParadas[80]=bridgeNodeJ5;
        listaParadas[81]=bridgeNodeJ4;        
        listaParadas[82]=bridgeNodeK5;
        listaParadas[83]=bridgeNodeK4;
        listaParadas[84]=bridgeNodeL5;
        
        listaParadas[85]=nodeZ2;
        listaParadas[86]=nodeZ1;
        listaParadas[87]=nodeZ8;        
        listaParadas[88]=nodeY3;
        listaParadas[89]=nodeZ3;        

        listaParadas[90]=nodeY4;
        listaParadas[91]=nodeZ4;        
        listaParadas[92]=nodeY7;
        listaParadas[93]=nodeY6;        
        listaParadas[94]=nodeY5;
        listaParadas[95]=bridgeNodeM2;        
        listaParadas[96]=bridgeNodeN1;
        listaParadas[97]=bridgeNodeN2;              
        listaParadas[98]=bridgeNodeO1;
        listaParadas[99]=bridgeNodeO2;
        
        listaParadas[100]=bridgeNodeP1;
        listaParadas[101]=bridgeNodeP2;        
        listaParadas[102]=bridgeNodeQ1;
        listaParadas[103]=bridgeNodeQ2;
        listaParadas[104]=bridgeNodeR1;
        
        listaParadas[105]=nodeZ5;        
        listaParadas[106]=nodeZ6;
        listaParadas[107]=nodeZ7;
        
        listaParadas[108]=nodeM1;
        listaParadas[109]=nodeM2;        
        
        listaParadas[110]=nodeN1;
        listaParadas[111]=nodeN2;
        listaParadas[112]=nodeO1;        	
        listaParadas[113]=nodeO2;
	listaParadas[114]=nodeP1;
        listaParadas[115]=nodeP2;        	
        listaParadas[116]=nodeQ1;
	listaParadas[117]=nodeQ2;
        listaParadas[118]=nodeR1;        
        listaParadas[119]=nodeR2;	
                
        listaParadas[120]=nodeM6;	
	listaParadas[121]=nodeM3;
        listaParadas[122]=nodeN6;	
        listaParadas[123]=nodeN3;
        listaParadas[124]=nodeO6;
        listaParadas[125]=nodeO3;        
        listaParadas[126]=nodeP6;
        listaParadas[127]=nodeP3;        
        listaParadas[128]=nodeQ6;
        listaParadas[129]=nodeQ3;

        
        listaParadas[130]=nodeR6;
        listaParadas[131]=nodeR3; 
        listaParadas[132]=nodeM5S1;        
        listaParadas[133]=nodeM4S2;         
        listaParadas[134]=nodeN5T1;
        listaParadas[135]=nodeN4T2;
        listaParadas[136]=nodeO5U1;
        listaParadas[137]=nodeO4U2;       
        listaParadas[138]=nodeP5V1;
        listaParadas[139]=nodeP4V2;        
        
        listaParadas[140]=nodeQ5W1;
        listaParadas[141]=nodeQ4W2;        
        listaParadas[142]=nodeR5X1;
        listaParadas[143]=nodeR4X2;
        listaParadas[144]=nodeS8;
        listaParadas[145]=nodeS3;        
        listaParadas[146]=nodeT8;
        listaParadas[147]=nodeT3;
        listaParadas[148]=nodeU8;
        listaParadas[149]=nodeU3;        
        
        listaParadas[150]=nodeV8;
        listaParadas[151]=nodeV3;
        listaParadas[152]=nodeW8;
        listaParadas[153]=nodeW3;
        listaParadas[154]=nodeX8;        
        listaParadas[155]=nodeX3;        
        listaParadas[156]=nodeS7;
        listaParadas[157]=nodeS4;        
        listaParadas[158]=nodeT7;
        listaParadas[159]=nodeT4;
    
        listaParadas[160]=nodeU7;
        listaParadas[161]=nodeU4;
        listaParadas[162]=nodeV7;
        listaParadas[163]=nodeV4;
        listaParadas[164]=nodeW7;        
        listaParadas[165]=nodeW4;        
        listaParadas[166]=nodeX7;
        listaParadas[167]=nodeX4;        
        listaParadas[168]=nodeS6;
        listaParadas[169]=nodeS5;

        listaParadas[170]=nodeT6;
        listaParadas[171]=nodeT5;
        listaParadas[172]=nodeU6;
        listaParadas[173]=nodeU5;
        listaParadas[174]=nodeV6;        
        listaParadas[175]=nodeV5;        
        listaParadas[176]=nodeW6;
        listaParadas[177]=nodeW5;        
        listaParadas[178]=nodeX6;
        listaParadas[179]=nodeX5;        
        
    
} // asignarNodosALista

void cargarCordenadasNodos () {
    printf("********************** Cargar Nodos *****************************\n");

    int x, y, p=0, t=0;
    for(x=0; x<FILAS2;x++){
        for(y=0; y<COLUMNAS2; y++){
            if(map2[x][y]==5){
                listaParadas[p]->x=y*TILESIZE+10;
                listaParadas[p]->y=x*TILESIZE;
                p++;
                t++;
            } else if(map2[x][y]==6){
                listaParadas[p]->x=y*TILESIZE;
                listaParadas[p]->y=x*TILESIZE;
                p++;
                t++;
            }else if(map2[x][y]==8){
                listaParadas[p]->x=y*TILESIZE;
                listaParadas[p]->y=x*TILESIZE;
                p++;
                t++;
            }else if(map2[x][y]==9){
                listaParadas[p]->x=y*TILESIZE+10; // 20
                listaParadas[p]->y=x*TILESIZE;
                p++;
                t++;
            }         
        } // for y
    } // for x
    printf("...T: %d\n", t);    
} // cargarNodos

// ************** ruta entre dos nodos ************

void generateRoute(VEHICULE *vehicule, NODE *start, NODE *end){
	vehicule->route = createRoute();
	int startID = start->id;
	int endID = end->id;
    	int path[V];
	NODE *node = start;
    	initResultArray(path);
    	thePath(startID, endID, node->node_paths, path);

	ROUTE *route = createRoute();
	route->destinations = createDestiny();
	DESTINY *destiny = route->destinations;

	for(int k = V - 1; k >= 0; k--){
		if(path[k] != INT_MAX){
			destiny->node = findNode(path[k], threadville);			
			destiny->next = createDestiny();
			
			//Si es el ultimo nodo de la ruta, setear en NULL
			if(k == 0){
				destiny->next = NULL;
			}else{
				destiny = destiny->next;
			}
		}		
	}

	vehicule->route = route;
}
