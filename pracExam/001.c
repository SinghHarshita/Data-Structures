#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct Graph{
    char label;
    bool visited;
}vertex;

int queue[MAX], rear = -1, front = 0;
int adjMatrix[MAX][MAX] = {0}, queueItemCount = 0, vertexCount = 0;
vertex *lastVertices[MAX];

void addVertex(char data){
    vertex *v = (vertex *)malloc(sizeof(vertex));

    v->label = data;
    v->visited = false;

    lastVertices[vertexCount++] = v;
}

void addEdge(int start, int end){
    adjMatrix[start][end] = adjMatrix[end][start] = 1;
}

void insert(int data){
    queue[++rear] = data;
    queueItemCount++;
}

int removeData(){
    queueItemCount--;
    return queue[front++];
}

bool isQueueEmpty(){
    return queueItemCount == 0;
}

void displayVertex(int index){
    printf("%c ", lastVertices[index]->label);
}

int getAdjUnvisitedVertex(int index){
    int i;

    for(i=0;i<vertexCount;i++){
        if(adjMatrix[index][i] == 1 && lastVertices[i]->visited == false)
            return i;
    }
    return -1;
}

void bfs(){
    int i;

    lastVertices[0]->visited = true;
    displayVertex(0);
    insert(0);

    int unvisitedVertex, tempVertex;

    while(!isQueueEmpty()){
        tempVertex = removeData();

        while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1){
            lastVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            insert(unvisitedVertex);
        }
    }

    for(i=0;i<vertexCount;i++){
        lastVertices[i]->visited  = false;
    }
}

void main(){
    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 4);

    bfs();
}
