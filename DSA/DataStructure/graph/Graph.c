#include <stdio.h>
#include <stdlib.h>

struct graph {
	int v;
	int e;
	int **adj;
};
typedef struct graph Graph;

Graph *adjMatrixGraph() {
	Graph *graph = (Graph *) malloc(sizeof(Graph));

	if (!graph) {
		printf("Memory error");
	}

	printf("Number of Vertices: ");
	scanf("%d", &graph->v);
	printf("Number of Edges: ");
	scanf("%d", &graph->e);

	// graph with the size of v * v
	/* graph->adj = (int **) malloc(sizeof(int) * graph->v * graph->v); */

	/* for (int i = 0; i < graph->v; i++) { */
	/* 	for (int j = 0; j < graph->v; j++) { */
	/* 		graph->adj[i][j] = 0; */
	/* 	} */
	/* } */
	// graph with the size of v * v
	graph->adj = (int **) malloc(graph->v * sizeof(int *));
	for (int row = 0; row < graph->v; row++) {
		graph->adj[row] = (int *) calloc(graph->v, sizeof(int));
	}

	// read an edge
	int u, v;
	for (int i = 0; i < graph->e; i++) {
		printf("Choose your edge\n");
		do {
			printf("First virtice: ");
			scanf("%d", &u);
			printf("Second virtice: ");
			scanf("%d", &v);

			if (graph->adj[u][v] == 1 && graph->adj[v][u] == 1) {
				printf("Da co roi\n");
			}
		} while (graph->adj[u][v] == 1 && graph->adj[v][u] == 1);

		// for undirect graph
		graph->adj[u][v] = 1;
		graph->adj[v][u] = 1;
	}

	return graph;
}

void printGraph(Graph *graph) {
	for (int i = 0; i < graph->v; i++) {
		for (int j = 0; j < graph->v; j++) {
			printf("%d ", graph->adj[i][j]);
		}
		printf("\n");
	}
}

int main() {
	Graph *graph = adjMatrixGraph();

	printGraph(graph);

	return 0;
}
