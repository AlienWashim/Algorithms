#include <stdio.h>
#include <stdlib.h>

struct AjlistNode
{
	int id;
	// Vertices id
	struct AjlistNode *next;
};
struct Vertices
{
	int data;
	struct AjlistNode *next;
	struct AjlistNode *last;
};
struct Graph
{
	int size;
	struct Vertices *node;
};
//set node key value
void setData(struct Graph *g)
{
	if (g->node != NULL)
	{
		int index = 0;
		for (int index = 0; index < g->size; index++)
		{
			// Set vertic node data
			g->node[index].data = index;
			// Set NULL Value
			g->node[index].next = NULL;
			g->node[index].next = NULL;
		}
	}
	else
	{
		printf("Vertic Node is Empty");
	}
}
// Return new graph
struct Graph *newGraph(int size)
{
	if (size < 1)
	{
		printf("\n Invalid graph size ");
		exit(0);
	}
	struct Graph *g = (struct Graph *)
	malloc(sizeof(struct Graph));
	g->size = size;
	g->node = (struct Vertices *)
	malloc(sizeof(struct Vertices) *size);
	setData(g);
	return g;
}
// Connect two nodes
void connect(struct Graph *g, int start, int last)
{
	// First create Adjacency node
	struct AjlistNode *edge = (struct AjlistNode *)
	malloc(sizeof(struct AjlistNode));
	if (edge != NULL)
	{
		edge->id = last;
		edge->next = NULL;
		if (g->node[start].next == NULL)
		{
			g->node[start].next = edge;
		}
		else
		{
			// Add edge at the end
			g->node[start].last->next = edge;
		}
		// Get last edge 
		g->node[start].last = edge;
	}
	else
	{
		printf("\n Memory overflow to create edge");
	}
}
// Add Edge from Two given Nodes
void addEdge(struct Graph *g, int start, int last)
{
	if (start < g->size && last < g->size)
	{
		connect(g, start, last);
	}
	else
	{
		//not valid Vertices
		printf("Invalid Node Vertices %d  %d", start, last);
	}
}
//Display Adjacency list of vertex
void printGraph(struct Graph *g)
{
	if (g != NULL)
	{
		struct AjlistNode *temp = NULL;
		for (int index = 0; index < g->size; index++)
		{
			printf("\n Adjacency list of vertex %d  :", index);
			temp = g->node[index].next;
			while (temp != NULL)
			{
				//temp->id is graph node vertices
				//in this case temp->id is same as 
				//node[temp->id].data
				printf("  %d", g->node[temp->id].data);
				temp = temp->next;
			}
		}
	}
	else
	{
		printf("Empty Graph");
	}
}
// Detect cycle using DFS
int detectCycle(struct Graph *g, 
                int start, int point, int visit[])
{
	if (visit[start] == 1 && point == start)
	{
		// When visits a node are more than one
		// Here start and end are same
		// Contain cycle
		return 1;
	}
	else if (visit[point] == 1)
	{
		// When start and end node are not same then 
		// Allow to visit same node more than once
		return 0;
	}
	// Set visited status 1
	visit[point] = 1;
	// Get the address of first edge of  current node
	struct AjlistNode *temp = g->node[point].next;
	int status = 0;
	while (temp != NULL && !status)
	{
		status = detectCycle(g, start, temp->id, visit);
		// Visit next edge
		temp = temp->next;
	}
	return status;
}
// Method which are manage finding and detecting cycle 
// operation
void checkCycle(struct Graph *g)
{
	if (g->size <= 0)
	{
		printf("Empty Graph\n");
		return;
	}
	// Print graph element
	printGraph(g);
	// This are storing the information about 
	// Visiting node status
	int visit[g->size];
	int result = 0;
	int location = 0;
	while (location < g->size && result == 0)
	{
		// Set all visit node as 0
		for (int index = 0; index < g->size; index++)
		{
			visit[index] = 0;
		}
		// Check whether node path contains cycle or not
		result = detectCycle(g, location, location, visit);
		// Change node location
		location++;
	}
	// Display possible result
	if (result == 1)
	{
		printf("\n Result : Detect Cycle\n");
	}
	else
	{
		printf("\n Result : No Cycle\n");
	}
}
int main()
{
	// 6 implies the number of nodes in graph
	struct Graph *g = newGraph(6);
	// Connect node with an edge
	addEdge(g, 0, 1);
	addEdge(g, 0, 3);
	addEdge(g, 1, 2);
	addEdge(g, 2, 5);
	addEdge(g, 3, 4);
	addEdge(g, 4, 2);
	// Test A
	checkCycle(g);
	// Add other edge
	addEdge(g, 5, 1);
	// Test B
	checkCycle(g);
	return 0;
}