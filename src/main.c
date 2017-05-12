#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

#include "lib/threadville_functions.h"

//COLORES
COLORSPEED *red;
COLORSPEED *blue;
COLORSPEED *green;
COLORSPEED *white;
COLORSPEED *black;
COLORSPEED *grey;
COLORSPEED *pink;
COLORSPEED *ligthBlue;
COLORSPEED *orange;

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


void init(){
    puts("Iniciando Threadville");

	red = createColor("RED", 1);
	blue = createColor("BLUE", 2);
	green = createColor("GREEN", 2);
	white = createColor("WHITE", 3);
	black = createColor("BLACK", 1);
	grey = createColor("GREY", 3);
	pink = createColor("PINK", 1);
	ligthBlue = createColor("LIGTHBLUE", 3);
	orange = createColor("ORANGE", 1);

	nodeY1 = createNode("Y1", 1);
	nodeY2 = createNode("Y2", 1);//Pista
	nodeY3 = createNode("Y3", 1);//Pista
	nodeY4 = createNode("Y4", 1);//Pista
	nodeY5 = createNode("Y5", 1);//Pista
	nodeY6 = createNode("Y6", 1);
	nodeY7 = createNode("Y7", 1);
	nodeY8 = createNode("Y8", 1);

	//DEFINICION CALE DE UNA VIA
	nodeA5G2 = createNode("A5G2", 3);//Comparte la capacidad con G2
	nodeA6G1 = createNode("A6G1", 3);//Comparte la capacidad con G1
	nodeM5S1 = createNode("M5S1", 3);//Comparte la capacidad con M5
	nodeM4S2 = createNode("M4S2", 3);//Comparte la capacidad con M4
	nodeB5H2 = createNode("B5H2", 3);//Comparte la capacidad con H2
	nodeB6H1 = createNode("B6H1", 3);//Comparte la capacidad con H1
	nodeO4U2 = createNode("O4U2", 3);//Comparte la capacidad con U2
	nodeO5U1 = createNode("O5U1", 3);//Comparte la capacidad con U1
	nodeN4T2 = createNode("N4T2", 3);//Comparte la capacidad con T2
	nodeN5T1 = createNode("N5T1", 3);//Comparte la capacidad con T1
	nodeC5I2 = createNode("C5I2", 3);//Comparte la capacidad con I2
	nodeC6I1 = createNode("C6I1", 3);//Comparte la capacidad con I1
	nodeD5J2 = createNode("D5J2", 3);//Comparte la capacidad con J2
	nodeD6J1 = createNode("D6J1", 3);//Comparte la capacidad con J1
	nodeP4V2 = createNode("P4V2", 3);//Comparte la capacidad con V2
	nodeP5V1 = createNode("P5V1", 3);//Comparte la capacidad con V1
	nodeE5K2 = createNode("E5K2", 3);//Comparte la capacidad con K2
	nodeE6K1 = createNode("E6K1", 3);//Comparte la capacidad con K1
	nodeQ4W2 = createNode("Q4W2", 3);//Comparte la capacidad con W2
	nodeQ5W1 = createNode("Q5W1", 3);//Comparte la capacidad con W1
	nodeF6L1 = createNode("F6L1", 3);//Comparte la capacidad con L1
	nodeF5L2 = createNode("F5L2", 3);//Comparte la capacidad con L2
	nodeR5X1 = createNode("R5X1", 3);//Comparte la capacidad con X1
	nodeR4X2 = createNode("R4X2", 3);//Comparte la capacidad con X2

	//Nodos de la A
	nodeA1 = createNode("A1", 3);
	nodeA2 = createNode("A2", 3);
	nodeA3 = createNode("A3", 3);
	nodeA4 = createNode("A4", 3);
	nodeA7 = createNode("A7", 3);
	nodeA8 = createNode("A8", 3);

	//Nodos de la G
	nodeG3 = createNode("G3", 3);
	nodeG4 = createNode("G4", 3);
	nodeG5 = createNode("G5", 3);
	nodeG6 = createNode("G6", 3);

	//Nodos de la M
	nodeM1 = createNode("M1", 3);
	nodeM2 = createNode("M2", 3);
	nodeM3 = createNode("M3", 3);
	nodeM6 = createNode("M6", 3);

	//Nodos de la S
	nodeS3 = createNode("S3", 3);
	nodeS4 = createNode("S4", 3);
	nodeS5 = createNode("S5", 3);
	nodeS6 = createNode("S6", 3);
	nodeS7 = createNode("S7", 3);
	nodeS8 = createNode("S8", 3);

	//Nodos de la B
	nodeB1 = createNode("B1", 3);
	nodeB2 = createNode("B2", 3);
	nodeB3 = createNode("B3", 3);
	nodeB4 = createNode("B4", 3);
	nodeB7 = createNode("B7", 3);
	nodeB8 = createNode("B8", 3);

	//Nodos de la H
	nodeH3 = createNode("H3", 3);
	nodeH4 = createNode("H4", 3);
	nodeH5 = createNode("H5", 3);
	nodeH6 = createNode("H6", 3);

	//Nodos de la N
	nodeN1 = createNode("N1", 3);
	nodeN2 = createNode("N2", 3);
	nodeN3 = createNode("N3", 3);
	nodeN6 = createNode("N6", 3);

	//Nodos de la T
	nodeT3 = createNode("T3", 3);
	nodeT4 = createNode("T4", 3);
	nodeT5 = createNode("T5", 3);
	nodeT6 = createNode("T6", 3);
	nodeT7 = createNode("T7", 3);
	nodeT8 = createNode("T8", 3);

	//Nodos de C
	nodeC1 = createNode("C1", 3);
	nodeC2 = createNode("C2", 3);
	nodeC3 = createNode("C3", 3);
	nodeC4 = createNode("C4", 3);
	nodeC7 = createNode("C7", 3);
	nodeC8 = createNode("C8", 3);

	//Nodos de I
	nodeI3 = createNode("I3", 3);
	nodeI4 = createNode("I4", 3);
	nodeI5 = createNode("I5", 3);
	nodeI6 = createNode("I6", 3);

	//Nodos de O
	nodeO1 = createNode("O1", 3);
	nodeO2 = createNode("O2", 3);
	nodeO3 = createNode("O3", 3);
	nodeO6 = createNode("O6", 3);

	//Nodos de U
	nodeU3 = createNode("U3", 3);
	nodeU4 = createNode("U4", 3);
	nodeU5 = createNode("U5", 3);
	nodeU6 = createNode("U6", 3);
	nodeU7 = createNode("U7", 3);
	nodeU8 = createNode("U8", 3);

	//Nodos de D
	nodeD1 = createNode("D1", 3);
	nodeD2 = createNode("D2", 3);
	nodeD3 = createNode("D3", 3);
	nodeD4 = createNode("D4", 3);
	nodeD7 = createNode("D7", 3);
	nodeD8 = createNode("D8", 3);

	//Nodos de J
	nodeJ3 = createNode("J3", 3);
	nodeJ4 = createNode("J4", 3);
	nodeJ5 = createNode("J5", 3);
	nodeJ6 = createNode("J6", 3);

	//Nodos de P
	nodeP1 = createNode("P1", 3);
	nodeP2 = createNode("P2", 3);
	nodeP3 = createNode("P3", 3);
	nodeP6 = createNode("P6", 3);

	//Nodos de V
	nodeV3 = createNode("V3", 3);
	nodeV4 = createNode("V4", 3);
	nodeV5 = createNode("V5", 3);
	nodeV6 = createNode("V6", 3);
	nodeV7 = createNode("V7", 3);
	nodeV8 = createNode("V8", 3);

	//Nodos de E
	nodeE1 = createNode("E1", 3);
	nodeE2 = createNode("E2", 3);
	nodeE3 = createNode("E3", 3);
	nodeE4 = createNode("E4", 3);
	nodeE7 = createNode("E7", 3);
	nodeE8 = createNode("E8", 3);

	//Nodos de K
	nodeK3 = createNode("K3", 3);
	nodeK4 = createNode("K4", 3);
	nodeK5 = createNode("K5", 3);
	nodeK6 = createNode("K6", 3);

	//Nodos de Q
	nodeQ1 = createNode("Q1", 3);
	nodeQ2 = createNode("Q2", 3);
	nodeQ3 = createNode("Q3", 3);
	nodeQ6 = createNode("Q6", 3);

	//Nodos de W
	nodeW3 = createNode("W3", 3);
	nodeW4 = createNode("W4", 3);
	nodeW5 = createNode("W5", 3);
	nodeW6 = createNode("W6", 3);
	nodeW7 = createNode("W7", 3);
	nodeW8 = createNode("W8", 3);

	//Nodos de F
	nodeF1 = createNode("F1", 3);
	nodeF2 = createNode("F2", 3);
	nodeF3 = createNode("F3", 3);
	nodeF4 = createNode("F4", 3);
	nodeF7 = createNode("F7", 3);
	nodeF8 = createNode("F8", 3);

	//Nodos de L
	nodeL3 = createNode("L3", 3);
	nodeL4 = createNode("L4", 3);
	nodeL6 = createNode("L6", 3);
	nodeL5 = createNode("L5", 3);


	//Nodos de R
	nodeR1 = createNode("R1", 3);
	nodeR2 = createNode("R2", 3);
	nodeR3 = createNode("R3", 3);
	nodeR6 = createNode("R6", 3);

	//Nodos de X
	nodeX3 = createNode("X3", 3);
	nodeX4 = createNode("X4", 3);
	nodeX5 = createNode("X5", 3);
	nodeX6 = createNode("X6", 3);
	nodeX7 = createNode("X7", 3);
	nodeX8 = createNode("X8", 3);

	//Nodos de la Z
	nodeZ1 = createNode("Z1", 1);
	nodeZ2 = createNode("Z2", 1);//Pista
	nodeZ3 = createNode("Z3", 1);//Pista
	nodeZ4 = createNode("Z4", 1);//Pista
	nodeZ5 = createNode("Z5", 1);//Pista
	nodeZ6 = createNode("Z6", 1);
	nodeZ7 = createNode("Z7", 1);
	nodeZ8 = createNode("Z8", 1);

	//DEFINICION DE RELACIONES
	//Nodos alcanzables de Y
	nodeY1->reachabledNodes = nodeY8;
	nodeY1->reachabledNodes->next = nodeG5;
	nodeY2->reachabledNodes = nodeY1;
	nodeY3->reachabledNodes = nodeY1;
	nodeY4->reachabledNodes = nodeZ4;
	nodeY5->reachabledNodes = nodeZ5;
	nodeY6->reachabledNodes = nodeY4;
	nodeY6->reachabledNodes->next = nodeY5;
	nodeY6->reachabledNodes->next->next = nodeY1;
	nodeY7->reachabledNodes = nodeY6;
	nodeY8->reachabledNodes = nodeY7;

	//Nodos alcanzables de A
	nodeA1->reachabledNodes = nodeA2;
	nodeA2->reachabledNodes = nodeA3;
	nodeA2->reachabledNodes->next = nodeB1;
	nodeA3->reachabledNodes = nodeA4;
	nodeA4->reachabledNodes = nodeA5G2;
	nodeA4->reachabledNodes->next = nodeG3;
	nodeA5G2->reachabledNodes = nodeA6G1;
	nodeA6G1->reachabledNodes = nodeA7;
	nodeA7->reachabledNodes = nodeA8;
	nodeA8->reachabledNodes = nodeA1;

	//Nodos alcanzables de G
	nodeG3->reachabledNodes = nodeG4;
	nodeG4->reachabledNodes = NULL; //Puente Bailey
	nodeG5->reachabledNodes = nodeG6;
	nodeG6->reachabledNodes = nodeA7;

	//Nodos alcanzables de M
	nodeM1->reachabledNodes = nodeY6;
	nodeM2->reachabledNodes = nodeM3;
	nodeM3->reachabledNodes = nodeS3;
	nodeM4S2->reachabledNodes = nodeS3;
	nodeM4S2->reachabledNodes->next = nodeN5T1;
	nodeM5S1->reachabledNodes = nodeM4S2;
	nodeM6->reachabledNodes = nodeM1;

	//Nodos alcanzables de S
	nodeS3->reachabledNodes = nodeS4;
	nodeS4->reachabledNodes = nodeS5;
	nodeS5->reachabledNodes = nodeS6;
	nodeS6->reachabledNodes = nodeS7;
	nodeS7->reachabledNodes = nodeS8;
	nodeS8->reachabledNodes = nodeM5S1;
	nodeS8->reachabledNodes->next = nodeM6;

	//Nodos alcanzables de B
	nodeB1->reachabledNodes = nodeB2;
	nodeB2->reachabledNodes = nodeB3;
	nodeB2->reachabledNodes->next = nodeC1;
	nodeB3->reachabledNodes = nodeB4;
	nodeB4->reachabledNodes = nodeB5H2;
	nodeB4->reachabledNodes->next = nodeH3;
	nodeB5H2->reachabledNodes = nodeB6H1;
	nodeB6H1->reachabledNodes = nodeB7;
	nodeB6H1->reachabledNodes->next = nodeA5G2;
	nodeB7->reachabledNodes = nodeB8;
	nodeB8->reachabledNodes = nodeB1;

	//Nodos alcanzables de H
	nodeH3->reachabledNodes = nodeH4;
	nodeH4->reachabledNodes = NULL;//Puente Bailey
	nodeH5->reachabledNodes = nodeH6;
	nodeH6->reachabledNodes = nodeB7;

	//Nodos alcanzables de N
	nodeN1->reachabledNodes = NULL; //Puente Bailey
	nodeN2->reachabledNodes = nodeN3;
	nodeN3->reachabledNodes = nodeT3;
	nodeN4T2->reachabledNodes = nodeT3;
	nodeN4T2->reachabledNodes->next = nodeO5U1;
	nodeN5T1->reachabledNodes = nodeN4T2;
	nodeN6->reachabledNodes = nodeN1;

	//Nodos alcanzables de T
	nodeT3->reachabledNodes = nodeT4;
	nodeT4->reachabledNodes = nodeT5;
	nodeT5->reachabledNodes = nodeT6;
	nodeT6->reachabledNodes = nodeT7;
	nodeT6->reachabledNodes->next = nodeS5;
	nodeT7->reachabledNodes = nodeT8;
	nodeT8->reachabledNodes = nodeN5T1;
	nodeT8->reachabledNodes->next = nodeN6;

	//Nodos alcanzables de C
	nodeC1->reachabledNodes = nodeC2;
	nodeC2->reachabledNodes = nodeC3;
	nodeC2->reachabledNodes->next = nodeD1;
	nodeC3->reachabledNodes = nodeC4;
	nodeC4->reachabledNodes = nodeC5I2;
	nodeC4->reachabledNodes->next = nodeI3;
	nodeC5I2->reachabledNodes = nodeC6I1;
	nodeC6I1->reachabledNodes = nodeC7;
	nodeC6I1->reachabledNodes->next = nodeB5H2;
	nodeC7->reachabledNodes = nodeC8;
	nodeC8->reachabledNodes = nodeC1;

	//Nodos alcanzables de I
	nodeI3->reachabledNodes = nodeI4;
	nodeI4->reachabledNodes = NULL;//Puente Bailey
	nodeI5->reachabledNodes = nodeI6;
	nodeI6->reachabledNodes = nodeC7;

	//Nodos alcanzables de O
	nodeO1->reachabledNodes = NULL; //Puente Bailey
	nodeO2->reachabledNodes = nodeO3;
	nodeO3->reachabledNodes = nodeU3;
	nodeO4U2->reachabledNodes = nodeU3;
	nodeO4U2->reachabledNodes->next = nodeP5V1;
	nodeO5U1->reachabledNodes = nodeO4U2;
	nodeO6->reachabledNodes = nodeO1;

	//Nodos alcanzables de U
	nodeU3->reachabledNodes = nodeU4;
	nodeU4->reachabledNodes = nodeU5;
	nodeU5->reachabledNodes = nodeU6;
	nodeU6->reachabledNodes = nodeU7;
	nodeU6->reachabledNodes->next = nodeT5;
	nodeU7->reachabledNodes = nodeU8;
	nodeU8->reachabledNodes = nodeO5U1;
	nodeU8->reachabledNodes->next = nodeO6;

	//Nodos alcanzables de D
	nodeD1->reachabledNodes = nodeD2;
	nodeD2->reachabledNodes = nodeD3;
	nodeD2->reachabledNodes->next = nodeE1;
	nodeD3->reachabledNodes = nodeD4;
	nodeD4->reachabledNodes = nodeD5J2;
	nodeD4->reachabledNodes->next = nodeJ3;
	nodeD5J2->reachabledNodes = nodeD6J1;
	nodeD6J1->reachabledNodes = nodeD7;
	nodeD6J1->reachabledNodes->next = nodeC5I2;
	nodeD7->reachabledNodes = nodeD8;
	nodeD8->reachabledNodes = nodeD1;

	//Nodos alcanzables de J
	nodeJ3->reachabledNodes = nodeJ4;
	nodeJ4->reachabledNodes = NULL;//Puente Bailey
	nodeJ5->reachabledNodes = nodeJ6;
	nodeJ6->reachabledNodes = nodeD7;

	//Nodos alcanzables de P
	nodeP1->reachabledNodes = NULL; //Puente Bailey
	nodeP2->reachabledNodes = nodeP3;
	nodeP3->reachabledNodes = nodeV3;
	nodeP4V2->reachabledNodes = nodeV3;
	nodeP4V2->reachabledNodes->next = nodeQ5W1;
	nodeP5V1->reachabledNodes = nodeP4V2;
	nodeP6->reachabledNodes = nodeP1;

	//Nodos alcanzables de V
	nodeV3->reachabledNodes = nodeV4;
	nodeV4->reachabledNodes = nodeV5;
	nodeV5->reachabledNodes = nodeV6;
	nodeV6->reachabledNodes = nodeV7;
	nodeV6->reachabledNodes->next = nodeU5;
	nodeV7->reachabledNodes = nodeV8;
	nodeV8->reachabledNodes = nodeP5V1;
	nodeV8->reachabledNodes->next = nodeP6;

	//Nodos alcanzables de E
	nodeE1->reachabledNodes = nodeE2;
	nodeE2->reachabledNodes = nodeE3;
	nodeE2->reachabledNodes->next = nodeF1;
	nodeE3->reachabledNodes = nodeE4;
	nodeE4->reachabledNodes = nodeE5K2;
	nodeE4->reachabledNodes->next = nodeK3;
	nodeE5K2->reachabledNodes = nodeE6K1;
	nodeE6K1->reachabledNodes = nodeE7;
	nodeE6K1->reachabledNodes->next = nodeD5J2;
	nodeE7->reachabledNodes = nodeE8;
	nodeE8->reachabledNodes = nodeE1;

	//Nodos alcanzables de K
	nodeK3->reachabledNodes = nodeK4;
	nodeK4->reachabledNodes = NULL;//Puente Bailey
	nodeK5->reachabledNodes = nodeK6;
	nodeK6->reachabledNodes = nodeE7;

	//Nodos alcanzables de Q
	nodeQ1->reachabledNodes = NULL; //Puente Bailey
	nodeQ2->reachabledNodes = nodeQ3;
	nodeQ3->reachabledNodes = nodeW3;
	nodeQ4W2->reachabledNodes = nodeW3;
	nodeQ4W2->reachabledNodes->next = nodeR5X1;
	nodeQ5W1->reachabledNodes = nodeQ4W2;
	nodeQ6->reachabledNodes = nodeQ1;

	//Nodos alcanzables de W
	nodeW3->reachabledNodes = nodeW4;
	nodeW4->reachabledNodes = nodeW5;
	nodeW5->reachabledNodes = nodeW6;
	nodeW6->reachabledNodes = nodeW7;
	nodeW6->reachabledNodes->next = nodeV5;
	nodeW7->reachabledNodes = nodeW8;
	nodeW8->reachabledNodes = nodeQ5W1;
	nodeW8->reachabledNodes->next = nodeQ6;

	//Nodos alcanzables de F
	nodeF1->reachabledNodes = nodeF2;
	nodeF2->reachabledNodes = nodeF3;
	nodeF3->reachabledNodes = nodeF4;
	nodeF4->reachabledNodes = nodeF5L2;
	nodeF4->reachabledNodes->next = nodeL3;
	nodeF5L2->reachabledNodes = nodeF6L1;
	nodeF6L1->reachabledNodes = nodeF7;
	nodeF6L1->reachabledNodes->next = nodeE5K2;
	nodeF7->reachabledNodes = nodeF8;
	nodeF8->reachabledNodes = nodeF1;

	//Nodos alcanzables de L
	nodeL3->reachabledNodes = nodeL4;
	nodeL4->reachabledNodes = nodeZ1;
	nodeL5->reachabledNodes = nodeL6;
	nodeL6->reachabledNodes = nodeF7;

	//Nodos alcanzables de R
	nodeR1->reachabledNodes = NULL; //Puente Bailey
	nodeR2->reachabledNodes = nodeR3;
	nodeR3->reachabledNodes = nodeX3;
	nodeR4X2->reachabledNodes = nodeX3;
	nodeR5X1->reachabledNodes = nodeR4X2;
	nodeR6->reachabledNodes = nodeR1;

	//Nodos alcanzables de X
	nodeX3->reachabledNodes = nodeX4;
	nodeX4->reachabledNodes = nodeX5;
	nodeX5->reachabledNodes = nodeX6;
	nodeX6->reachabledNodes = nodeX7;
	nodeX6->reachabledNodes->next = nodeW5;
	nodeX7->reachabledNodes = nodeX8;
	nodeX8->reachabledNodes = nodeR5X1;
	nodeX8->reachabledNodes->next = nodeR6;

	//Nodos alcanzables de Z
	nodeZ1->reachabledNodes = nodeZ2;
	nodeZ1->reachabledNodes->next = nodeZ3;
	nodeZ1->reachabledNodes->next->next = nodeZ6;
	nodeZ2->reachabledNodes = nodeY2;
	nodeZ3->reachabledNodes = nodeY3;
	nodeZ4->reachabledNodes = nodeZ6;
	nodeZ5->reachabledNodes = nodeZ6;
	nodeZ6->reachabledNodes = nodeZ7;
	nodeZ6->reachabledNodes->next = nodeN2;
	nodeZ7->reachabledNodes = nodeZ8;
	nodeZ8->reachabledNodes = nodeZ1;
}

void teardDown(){

	//RELEASE MEMORY

	//Ruta
	//Hay que liberar la memoria cuando se libera un vehicule

	//Colors
	releaseColor(red);
	releaseColor(blue);
	releaseColor(green);
	releaseColor(white);
	releaseColor(black);
	releaseColor(pink);
	releaseColor(orange);
	releaseColor(grey);
	releaseColor(ligthBlue);

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

}

void singleRun(){

	//BUSES
	//Periferica Grande - Roja
	//A1, D1, F2, L4, Z (dandole la vuelta), R2, X5, U5, S6, M1, Y (dandole la vuelta)
	VEHICULE *redBus = createBus("PERIFERICA-GRANDE");
	redBus->colorSpeed = red;


	//Periferica Norte - Verde
	//E2, L3*, F2, L4, Z (dandole la vuelta), toma la pista hacia el Oeste Y (dandole la vuelta), G6, B1, E2
	VEHICULE *greenBus = createBus("PERIFERICA-NORTE");
	greenBus->colorSpeed = green;

	//Periferica Sur - Azul
	//R3, W5, T6, M6, Y (dandole la vuelta), toma la pista hacia el Este Z (dandole la vuelta), R3
	VEHICULE *blueBus = createBus("PERIFERICA-SUR");
	blueBus->colorSpeed = blue;

	//Bus Blanco
	//I4, O3, T5, N1, H6, C1, I4
	VEHICULE *whiteBus = createBus("BUS-BLANCO");
	whiteBus->colorSpeed = white;

	//Bus Gris
	//U5, O1, I6, D1, J4, P3, U5
	VEHICULE *greyBus = createBus("BUS-GRIS");
	greyBus->colorSpeed = grey;

	//Bus Negro
	//J6, E1, K4, Q3, V5, P1, J6
	VEHICULE *blackBus = createBus("BUS-NEGRO");
	blackBus->colorSpeed = black;

	//Bus Rosa
	//F5L1, A6, A1, F2, F5L1
	VEHICULE *pinkBus = createBus("BUS-ROSA");
	pinkBus->colorSpeed = pink;

	//Bus Celeste
	//S6, M5S1, R4X2, X5, S6
	VEHICULE *ligthBlueBus = createBus("BUS-CELESTE");
	ligthBlueBus->colorSpeed = ligthBlue;

	//Bus Lombriz - Naranja
	//M3, O6, C8, C3, O3, Q6, E8, E3, Q3, X4, X7, L6, J3, V4, J6, H3, T4, T7, H6, A8, A3, M3
	VEHICULE *orangeBus = createBus("BUS-NARANJA");
	orangeBus->colorSpeed = orange;

	//Crear una paradas - Destinos
	//addStop(orangeBus, nodeM3);
	STOP *stopM3 = createStop();
	stopM3->stop = nodeM3;
	orangeBus->stops = stopM3;

	//addStop(orangeBus, nodeO6);
	STOP *stopO6 = createStop();
	stopO6->stop = nodeO6;
	orangeBus->stops->next = stopO6;

	//addStop(orangeBus, nodeC8);
	STOP *stopC8 = createStop();
	stopC8->stop = nodeC8;
	orangeBus->stops->next->next = stopC8;
    displayStops(orangeBus->stops);

    //Crear la Ruta
    //Agregar ruta utilizando todos los stops ordenados
    //addRoute(orangeBus);
    //displayVehicules(orangeBus);

    DESTINY *routaM2M3 = createDestiny();
    routaM2M3->node = nodeM2;
    generateRoute(nodeM2, nodeM1, routaM2M3);
    displayDestinations(routaM2M3);

    //Bus
    releaseVehicule(redBus);
    releaseVehicule(blueBus);
    releaseVehicule(greenBus);
    releaseVehicule(whiteBus);
    releaseVehicule(blackBus);
    releaseVehicule(pinkBus);
    releaseVehicule(orangeBus);
    releaseVehicule(greyBus);
    releaseVehicule(ligthBlueBus);
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
    pthread_t aThread;

    s = pthread_create(&aThread, NULL, move, redBus);
    if(s != 0){
        printf("fallo en crear thread %d", s);
    } else {
        s = pthread_join(aThread, result);
        if(s != 0){
            printf("error pthread_join %d", s);
        }
        puts("finalizo thread");
    }
}

void makeAmbulance(){

    VEHICULE *em = createAmbulance("> Emergencias Medicas <");
    em -> colorSpeed = white;
    em -> delay = 3;

    pthread_t aThread;
    pthread_create(&aThread, NULL, move, em);
}

void makeCar(){

    VEHICULE *em = createAmbulance("== Toyota ==");
    em -> colorSpeed = black;
    em -> delay = 1;

    pthread_t aThread;
    pthread_create(&aThread, NULL, move, em);

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
                singleRun();
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


int main(int argc, char *argv[]) {

    int opt;

    while ((opt = getopt(argc, argv, ":x")) != -1) {

        printf("opt = %d \n", opt);

        switch (opt) {
            case 'x':
                puts("levantar UI");
                break;
            default:
                puts("Mensaje de ayuda");
                break;
        }
        return 0;
    }

    headless();
    return 0;
}
