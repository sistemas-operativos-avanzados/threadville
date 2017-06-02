#ifndef TV_GRAPH

#define TV_GRAPH

int graph[V][V];

//Funcion para encontrar el vertice con la distancia minima de un conjunto de vertices un no incluidos en el
//shortest path tree
int minDistance(int dist[], int sptSet[]){

    int min = INT_MAX;
    int min_index;
    int v;
    for (v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

/*
Se genera la ruta desde el nodo "from" al nodo "to". El array de "paths" contiene los nodos por donde se pasa a
partir del nodo from. paths[i] contiene el numero de nodo que precede a j dentro del camino mas corto Para hallar
el camino mas corto, se siguen los punteros de paths hacia atras, desde el destino hacia el origen.
Ejemplo:
thePath(1, 0, {9, 0, 9, 2, 1, 4, 5, 6, 7, 8}, {MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT});
Para ir del nodo 1 al 0, utilizando los punteros {9, 0, 9, 2, 1, 4, 5, 6, 7, 8}, primero se va a posicion paths[0] = 9.
Como el valor de paths[0] es diferente de "to", entonces se asignas paths[0] en result. Luego se va a posicion paths[9] = 8,
se repite la misma verificacion y se itera hasta que el valor de paths[i] = "to". Al final se le hace un "reverse" a
result.
*/
void thePath(int from, int to, int paths[], int result[]){

    //Incluir el ultimo nodo
    result[0] = to;
    int i = 1;

    //Crear path
    while(paths[to] != from){
	result[i] = paths[to];
        to = paths[to];
        i++;
    }

    //Reversa
    result[i] = from;

}

void printPath(int path[]){

    int p;
    for(p = 0; p < V; p++){
        printf("\t%d", path[p]);
    }

}

void initResultArray(int result[]){
    int result_idx;
    for(result_idx = 0; result_idx < V; result_idx++){
        result[result_idx] = INT_MAX;
    }
}

void dijkstra(int graph[V][V], int src, int paths[]){

	int dist[V]; //dist va a tener la distancia mas corta desde el origen a otro nodo

	int sptSet[V];  //sptSet[i] va ser verdadero si el vertice i esta incluodo en el shortest path tree o en la
                    //distancia mas corta desde el origen a un nodo i cuando se finaliza

    // Inicializacion de array de rutas (paths)
    int p;
    for(p = 0; p < V; p++){
        paths[p] = 0;
    }

    // Inicializar todas las distancias como "Infinito" y stpSet[] en falso
    int i;
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distancia del vertice origen a si mismo es siempre 0
    dist[src] = 0;

    // total de repeticiones que se va a correr el ciclo
    int count;

    for (count = 0; count < V-1; count++) {
        // Se escoge vertice con menor distancia del conjunto de vertices que aun no se han procesado.
        // u = siempre es igual a src en la primera iteracion
        int u = minDistance(dist, sptSet);

        // Marcar el vertice escogido como procesado
        sptSet[u] = 1;

        // Actualizar el valor de dist de los vertices adyacentes del vertice escogido
        int v;
        for (v = 0; v < V; v++) {

            // Actualizar dist[v] solo si no esta en sptSet,
            // existe una ariste desde u a v
            // y el peso total de la ruta desde src a v a traves de u es menor que el valor actual de dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                // Aqui nos dice por donde va pasando
                paths[v] = u;
            }
        }
	}
}
#endif

