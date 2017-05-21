#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <pthread.h>

#include "lib/threadville_globals.h"
#include "lib/threadville_functions.h"
#include "lib/threadville_graph.h"

//THREADVILLE
THREADVILLE *threadville;

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

void init(){
    puts("Iniciando Threadville");
	threadville = createThreadville();

//	red = createColor("RED", 1);
//	blue = createColor("BLUE", 2);
//	green = createColor("GREEN", 2);
//	white = createColor("WHITE", 3);
//	black = createColor("BLACK", 1);
//	grey = createColor("GREY", 3);
//	pink = createColor("PINK", 1);
//	ligthBlue = createColor("LIGTHBLUE", 3);
//	orange = createColor("ORANGE", 1);

	//DEFINICION CALE DE UNA VIA
	nodeA5G2 = createNode(0, "A5G2", 3);//Comparte la capacidad con G2
	nodeA6G1 = createNode(1, "A6G1", 3);//Comparte la capacidad con G1
	nodeM5S1 = createNode(2, "M5S1", 3);//Comparte la capacidad con M5
	nodeM4S2 = createNode(3, "M4S2", 3);//Comparte la capacidad con M4
	nodeB5H2 = createNode(4, "B5H2", 3);//Comparte la capacidad con H2
	nodeB6H1 = createNode(5, "B6H1", 3);//Comparte la capacidad con H1
	nodeO4U2 = createNode(6, "O4U2", 3);//Comparte la capacidad con U2
	nodeO5U1 = createNode(7, "O5U1", 3);//Comparte la capacidad con U1
	nodeN4T2 = createNode(8, "N4T2", 3);//Comparte la capacidad con T2
	nodeN5T1 = createNode(9, "N5T1", 3);//Comparte la capacidad con T1
	nodeC5I2 = createNode(10, "C5I2", 3);//Comparte la capacidad con I2
	nodeC6I1 = createNode(11, "C6I1", 3);//Comparte la capacidad con I1
	nodeD5J2 = createNode(12, "D5J2", 3);//Comparte la capacidad con J2
	nodeD6J1 = createNode(13, "D6J1", 3);//Comparte la capacidad con J1
	nodeP4V2 = createNode(14, "P4V2", 3);//Comparte la capacidad con V2
	nodeP5V1 = createNode(15, "P5V1", 3);//Comparte la capacidad con V1
	nodeE5K2 = createNode(16, "E5K2", 3);//Comparte la capacidad con K2
	nodeE6K1 = createNode(17, "E6K1", 3);//Comparte la capacidad con K1
	nodeQ4W2 = createNode(18, "Q4W2", 3);//Comparte la capacidad con W2
	nodeQ5W1 = createNode(19, "Q5W1", 3);//Comparte la capacidad con W1
	nodeF6L1 = createNode(20, "F6L1", 3);//Comparte la capacidad con L1
	nodeF5L2 = createNode(21, "F5L2", 3);//Comparte la capacidad con L2
	nodeR5X1 = createNode(22, "R5X1", 3);//Comparte la capacidad con X1
	nodeR4X2 = createNode(23, "R4X2", 3);//Comparte la capacidad con X2

	//Nodos de Y
	//int *reacheabledNodes[2] = {31, 40};
	nodeY1 = createNode(24, "Y1", 1);
	nodeY2 = createNode(25, "Y2", 1);//Pista
	nodeY3 = createNode(26, "Y3", 1);//Pista
	nodeY4 = createNode(27, "Y4", 1);//Pista
	nodeY5 = createNode(28, "Y5", 1);//Pista
	nodeY6 = createNode(29, "Y6", 1);
	nodeY7 = createNode(30, "Y7", 1);
	nodeY8 = createNode(31, "Y8", 1);


	//Nodos de la A
	nodeA1 = createNode(32, "A1", 3);
	nodeA2 = createNode(33, "A2", 3);
	nodeA3 = createNode(34, "A3", 3);
	nodeA4 = createNode(35, "A4", 3);
	nodeA7 = createNode(36, "A7", 3);
	nodeA8 = createNode(37, "A8", 3);

	//Nodos de la G
	nodeG3 = createNode(38, "G3", 3);
	nodeG4 = createNode(39, "G4", 3);
	nodeG5 = createNode(40, "G5", 3);
	nodeG6 = createNode(41, "G6", 3);

	//Nodos de la M
	nodeM1 = createNode(42, "M1", 3);
	nodeM2 = createNode(43, "M2", 3);
	nodeM3 = createNode(44, "M3", 3);
	nodeM6 = createNode(45, "M6", 3);

	//Nodos de la S
	nodeS3 = createNode(46, "S3", 3);
	nodeS4 = createNode(47, "S4", 3);
	nodeS5 = createNode(48, "S5", 3);
	nodeS6 = createNode(49, "S6", 3);
	nodeS7 = createNode(50, "S7", 3);
	nodeS8 = createNode(51, "S8", 3);

	//Nodos de la B
	nodeB1 = createNode(52, "B1", 3);
	nodeB2 = createNode(53, "B2", 3);
	nodeB3 = createNode(54, "B3", 3);
	nodeB4 = createNode(55, "B4", 3);
	nodeB7 = createNode(56, "B7", 3);
	nodeB8 = createNode(57, "B8", 3);

	//Nodos de la H
	nodeH3 = createNode(58, "H3", 3);
	nodeH4 = createNode(59, "H4", 3);
	nodeH5 = createNode(60, "H5", 3);
	nodeH6 = createNode(61, "H6", 3);

	//Nodos de la N
	nodeN1 = createNode(62, "N1", 3);
	nodeN2 = createNode(63, "N2", 3);
	nodeN3 = createNode(64, "N3", 3);
	nodeN6 = createNode(65, "N6", 3);

	//Nodos de la T
	nodeT3 = createNode(66, "T3", 3);
	nodeT4 = createNode(67, "T4", 3);
	nodeT5 = createNode(68, "T5", 3);
	nodeT6 = createNode(69, "T6", 3);
	nodeT7 = createNode(70, "T7", 3);
	nodeT8 = createNode(71, "T8", 3);

	//Nodos de C
	nodeC1 = createNode(72, "C1", 3);
	nodeC2 = createNode(73, "C2", 3);
	nodeC3 = createNode(74, "C3", 3);
	nodeC4 = createNode(75, "C4", 3);
	nodeC7 = createNode(76, "C7", 3);
	nodeC8 = createNode(77, "C8", 3);

	//Nodos de I
	nodeI3 = createNode(78, "I3", 3);
	nodeI4 = createNode(79, "I4", 3);
	nodeI5 = createNode(80, "I5", 3);
	nodeI6 = createNode(81, "I6", 3);

	//Nodos de O
	nodeO1 = createNode(82, "O1", 3);
	nodeO2 = createNode(83, "O2", 3);
	nodeO3 = createNode(84, "O3", 3);
	nodeO6 = createNode(85, "O6", 3);

	//Nodos de U
	nodeU3 = createNode(86, "U3", 3);
	nodeU4 = createNode(87, "U4", 3);
	nodeU5 = createNode(88, "U5", 3);
	nodeU6 = createNode(89, "U6", 3);
	nodeU7 = createNode(90, "U7", 3);
	nodeU8 = createNode(91, "U8", 3);

	//Nodos de D
	nodeD1 = createNode(92, "D1", 3);
	nodeD2 = createNode(93, "D2", 3);
	nodeD3 = createNode(94, "D3", 3);
	nodeD4 = createNode(95, "D4", 3);
	nodeD7 = createNode(96, "D7", 3);
	nodeD8 = createNode(97, "D8", 3);

	//Nodos de J
	nodeJ3 = createNode(98, "J3", 3);
	nodeJ4 = createNode(99, "J4", 3);
	nodeJ5 = createNode(100, "J5", 3);
	nodeJ6 = createNode(101, "J6", 3);

	//Nodos de P
	nodeP1 = createNode(102, "P1", 3);
	nodeP2 = createNode(103, "P2", 3);
	nodeP3 = createNode(104, "P3", 3);
	nodeP6 = createNode(105, "P6", 3);

	//Nodos de V
	nodeV3 = createNode(106, "V3", 3);
	nodeV4 = createNode(107, "V4", 3);
	nodeV5 = createNode(108, "V5", 3);
	nodeV6 = createNode(109, "V6", 3);
	nodeV7 = createNode(110, "V7", 3);
	nodeV8 = createNode(111, "V8", 3);

	//Nodos de E
	nodeE1 = createNode(112, "E1", 3);
	nodeE2 = createNode(113, "E2", 3);
	nodeE3 = createNode(114, "E3", 3);
	nodeE4 = createNode(115, "E4", 3);
	nodeE7 = createNode(116, "E7", 3);
	nodeE8 = createNode(117, "E8", 3);

	//Nodos de K
	nodeK3 = createNode(118, "K3", 3);
	nodeK4 = createNode(119, "K4", 3);
	nodeK5 = createNode(120, "K5", 3);
	nodeK6 = createNode(121, "K6", 3);

	//Nodos de Q
	nodeQ1 = createNode(122, "Q1", 3);
	nodeQ2 = createNode(123, "Q2", 3);
	nodeQ3 = createNode(124, "Q3", 3);
	nodeQ6 = createNode(125, "Q6", 3);

	//Nodos de W
	nodeW3 = createNode(126, "W3", 3);
	nodeW4 = createNode(127, "W4", 3);
	nodeW5 = createNode(128, "W5", 3);
	nodeW6 = createNode(129, "W6", 3);
	nodeW7 = createNode(130, "W7", 3);
	nodeW8 = createNode(131, "W8", 3);

	//Nodos de F
	nodeF1 = createNode(132, "F1", 3);
	nodeF2 = createNode(133, "F2", 3);
	nodeF3 = createNode(134, "F3", 3);
	nodeF4 = createNode(135, "F4", 3);
	nodeF7 = createNode(136, "F7", 3);
	nodeF8 = createNode(137, "F8", 3);

	//Nodos de L
	nodeL3 = createNode(138, "L3", 3);
	nodeL4 = createNode(139, "L4", 3);
	nodeL6 = createNode(140, "L6", 3);
	nodeL5 = createNode(141, "L5", 3);


	//Nodos de R
	nodeR1 = createNode(142, "R1", 3);
	nodeR2 = createNode(143, "R2", 3);
	nodeR3 = createNode(144, "R3", 3);
	nodeR6 = createNode(145, "R6", 3);

	//Nodos de X
	nodeX3 = createNode(146, "X3", 3);
	nodeX4 = createNode(147, "X4", 3);
	nodeX5 = createNode(148, "X5", 3);
	nodeX6 = createNode(149, "X6", 3);
	nodeX7 = createNode(150, "X7", 3);
	nodeX8 = createNode(151, "X8", 3);

	//Nodos de la Z
	nodeZ1 = createNode(152, "Z1", 1);
	nodeZ2 = createNode(153, "Z2", 1);//Pista
	nodeZ3 = createNode(154, "Z3", 1);//Pista
	nodeZ4 = createNode(155, "Z4", 1);//Pista
	nodeZ5 = createNode(156, "Z5", 1);//Pista
	nodeZ6 = createNode(157, "Z6", 1);
	nodeZ7 = createNode(158, "Z7", 1);
	nodeZ8 = createNode(159, "Z8", 1);

	//Puente Bailey
	//Larry
	bridgeNodeG4 = createNode(160, "bridgeNodeG4", 3);
	bridgeNodeH5 = createNode(161, "bridgeNodeH5", 3);
	bridgeNodeM2 = createNode(162, "bridgeNodeM2", 3);
	bridgeNodeN1 = createNode(163, "bridgeNodeN1", 3);
	Larry = createBridge("Larry", bridgeNodeM2, bridgeNodeG4, bridgeNodeN1, bridgeNodeH5);

	//Curly
	bridgeNodeH4 = createNode(164, "bridgeNodeH4", 3);
	bridgeNodeI5 = createNode(165, "bridgeNodeI5", 3);
	bridgeNodeN2 = createNode(166, "bridgeNodeN2", 3);
	bridgeNodeO1 = createNode(167, "bridgeNodeO1", 3);
	Curly = createBridge("Curly", bridgeNodeN2, bridgeNodeH4, bridgeNodeO1, bridgeNodeI5);

	//Moe
	bridgeNodeI4 = createNode(168, "bridgeNodeI4", 3);
	bridgeNodeJ5 = createNode(169, "bridgeNodeJ5", 3);
	bridgeNodeO2 = createNode(170, "bridgeNodeO2", 3);
	bridgeNodeP1 = createNode(171, "bridgeNodeP1", 3);
	Moe = createBridge("Moe", bridgeNodeO2, bridgeNodeI4, bridgeNodeP1, bridgeNodeJ5);

	//Shemp
	bridgeNodeJ4 = createNode(172, "bridgeNodeJ4", 3);
	bridgeNodeK5 = createNode(173, "bridgeNodeK5", 3);
	bridgeNodeP2 = createNode(174, "bridgeNodeP2", 3);
	bridgeNodeQ1 = createNode(175, "bridgeNodeQ1", 3);
	Shemp = createBridge("Shemp", bridgeNodeP2, bridgeNodeJ4, bridgeNodeQ1, bridgeNodeK5);

	//Joe
	bridgeNodeK4 = createNode(176, "bridgeNodeK4", 3);
	bridgeNodeL5 = createNode(177, "bridgeNodeL5", 3);
	bridgeNodeQ2 = createNode(178, "bridgeNodeQ2", 3);
	bridgeNodeR1 = createNode(179, "bridgeNodeR1", 3);
	Joe = createBridge("Joe", bridgeNodeQ2, bridgeNodeK4, bridgeNodeR1, bridgeNodeL5);
	
	//DEFINICION DE RELACIONES
	threadville->nodes = nodeY1;

	//Nodos de Y
	nodeY1->next = nodeY2;
	//fillGraph(nodeY1, 2);

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
	bridgeNodeG4->next = bridgeNodeN1;
	bridgeNodeN1->next = bridgeNodeH4;

	//Curly
	bridgeNodeH4->next = bridgeNodeO1;
	bridgeNodeO1->next = bridgeNodeI4;

	//Moe
	bridgeNodeI4->next = bridgeNodeP1;
	bridgeNodeP1->next = bridgeNodeJ4;

	//Shemp
	bridgeNodeJ4->next = bridgeNodeQ1;
	bridgeNodeQ1->next = bridgeNodeK4;

	//Joe
	bridgeNodeK4->next = bridgeNodeR1;
}

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

void singleRun(){

//	//BUSES
//	//Periferica Grande - Roja
//	//A1, D1, F2, L4, Z (dandole la vuelta), R2, X5, U5, S6, M1, Y (dandole la vuelta)
//	VEHICULE *redBus = createBus("PERIFERICA-GRANDE");
//	redBus->colorSpeed = red;
//
//
//	//Periferica Norte - Verde
//	//E2, L3*, F2, L4, Z (dandole la vuelta), toma la pista hacia el Oeste Y (dandole la vuelta), G6, B1, E2
//	VEHICULE *greenBus = createBus("PERIFERICA-NORTE");
//	greenBus->colorSpeed = green;
//
//	//Periferica Sur - Azul
//	//R3, W5, T6, M6, Y (dandole la vuelta), toma la pista hacia el Este Z (dandole la vuelta), R3
//	VEHICULE *blueBus = createBus("PERIFERICA-SUR");
//	blueBus->colorSpeed = blue;
//
//	//Bus Blanco
//	//I4, O3, T5, N1, H6, C1, I4
//	VEHICULE *whiteBus = createBus("BUS-BLANCO");
//	whiteBus->colorSpeed = white;
//
//	//Bus Gris
//	//U5, O1, I6, D1, J4, P3, U5
//	VEHICULE *greyBus = createBus("BUS-GRIS");
//	greyBus->colorSpeed = grey;
//
//	//Bus Negro
//	//J6, E1, K4, Q3, V5, P1, J6
//	VEHICULE *blackBus = createBus("BUS-NEGRO");
//	blackBus->colorSpeed = black;
//
//	//Bus Rosa
//	//F5L1, A6, A1, F2, F5L1
//	VEHICULE *pinkBus = createBus("BUS-ROSA");
//	pinkBus->colorSpeed = pink;
//
//	//Bus Celeste
//	//S6, M5S1, R4X2, X5, S6
//	VEHICULE *ligthBlueBus = createBus("BUS-CELESTE");
//	ligthBlueBus->colorSpeed = ligthBlue;
//
//	//Bus Lombriz - Naranja
//	//M3, O6, C8, C3, O3, Q6, E8, E3, Q3, X4, X7, L6, J3, V4, J6, H3, T4, T7, H6, A8, A3, M3
//	VEHICULE *orangeBus = createBus("BUS-NARANJA");
//	orangeBus->colorSpeed = orange;
//
//	//Crear una paradas - Destinos
//	//addStop(orangeBus, nodeM3);
//	STOP *stopM3 = createStop();
//	stopM3->stop = nodeM3;
//	orangeBus->stops = stopM3;
//
//	//addStop(orangeBus, nodeO6);
//	STOP *stopO6 = createStop();
//	stopO6->stop = nodeO6;
//	orangeBus->stops->next = stopO6;

	//addStop(orangeBus, nodeC8);
//	STOP *stopC8 = createStop();
//	stopC8->stop = nodeC8;
//	orangeBus->stops->next->next = stopC8;
//    	displayStops(orangeBus->stops);


    //Bus
//    releaseVehicule(redBus);
//    releaseVehicule(blueBus);
//    releaseVehicule(greenBus);
//    releaseVehicule(whiteBus);
//    releaseVehicule(blackBus);
//    releaseVehicule(pinkBus);
//    releaseVehicule(orangeBus);
//    releaseVehicule(greyBus);
//    releaseVehicule(ligthBlueBus);
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


// Esta funcion es para mostrar como funciona las funciones de rutas. Se puede borrar luego
void dijkstra_test(){

    int paths[V];

    dijkstra(graph, 1, paths);

    printf("\n\n-- \n");
    int p1[V];
    initResultArray(p1);
    thePath(1, 0, paths, p1);

    printf("\n");
    int p2[V];
    initResultArray(p2);
    thePath(1, 4, paths, p2);

    printf("\n");
    int p3[V];
    initResultArray(p3);
    thePath(1, 5, paths, p3);

    printf("\n");
    int p4[V];
    initResultArray(p4);
    thePath(1, 6, paths, p4);
}


int main(int argc, char *argv[]) {
	init();
	//dijkstra_test();

	VEHICULE *orangeBus = createBus("BUS-NARANJA");
	orangeBus->colorSpeed = orange;
	orangeBus->route = createRoute();
	puts("RUTA DE M2 a M1 = [M2, M3, S3, S4, S5, S6, S7, S8, M6, M1]");

	DESTINY *destinyM2 = createDestiny();
	destinyM2->node = nodeM2;

	DESTINY *destinyM3 = createDestiny();
	destinyM3->node = nodeM3;

	DESTINY *destinyS3 = createDestiny();
	destinyS3->node = nodeS3;

	DESTINY *destinyS4 = createDestiny();
	destinyS4->node = nodeS4;

	DESTINY *destinyS5 = createDestiny();
	destinyS5->node = nodeS5;

	DESTINY *destinyS6 = createDestiny();
	destinyS6->node = nodeS6;

	DESTINY *destinyS7 = createDestiny();
	destinyS7->node = nodeS7;

	DESTINY *destinyS8 = createDestiny();
	destinyS8->node = nodeS8;

	DESTINY *destinyM6 = createDestiny();
	destinyM6->node = nodeM6;

	DESTINY *destinyM1 = createDestiny();
	destinyM1->node = nodeM1;

	orangeBus->route->destinations = destinyM2;
	orangeBus->route->destinations->next = destinyM3;
	orangeBus->route->destinations->next->next = destinyS3;
	orangeBus->route->destinations->next->next->next = destinyS4;
	orangeBus->route->destinations->next->next->next->next = destinyS5;
	orangeBus->route->destinations->next->next->next->next->next = destinyS6;
	orangeBus->route->destinations->next->next->next->next->next->next = destinyS7;
	orangeBus->route->destinations->next->next->next->next->next->next->next = destinyS8;
	orangeBus->route->destinations->next->next->next->next->next->next->next->next = destinyM6;
	orangeBus->route->destinations->next->next->next->next->next->next->next->next->next = destinyM1;

	displayDestinations(orangeBus->route->destinations);

    return 0;
//
//	init();
//	singleRun();
//	teardDown();

    // int opt;

    // while ((opt = getopt(argc, argv, ":x")) != -1) {

    //     printf("opt = %d \n", opt);

    //     switch (opt) {
    //         case 'x':
    //             puts("levantar UI");
    //             break;
    //         default:
    //             puts("Mensaje de ayuda");
    //             break;
    //     }
    //     return 0;
    // }

    // headless();
//    return 0;
}
