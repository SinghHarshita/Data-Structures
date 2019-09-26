#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct Graph{
    char label;
    bool visited;
}vertex;

int stack[MAX], top = -1;
int adjMatrix[MAX][MAX] = {0}, vertexCount = 0;
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

void push(int data){
    stack[++top] = data;
}

int pop(){
    return stack[top--];
}

bool isStackEmpty(){
    return top == -1;
}

int peek()
{
    return stack[top];
}

int getAdjUnvisitedVertex(int index){

    int i;

    for(i=0;i<vertexCount;i++){
        if(adjMatrix[index][i] == 1 && lastVertices[i]->visited == false){
            return i;
        }
    }
    return -1;
}

void displayVertex(int index){
    printf("%c ",lastVertices[index]->label);
}

void dfs(){
    int i;

    lastVertices[0]->visited = true;
    displayVertex(0);
    push(0);

    int unvisited;

    while(!isStackEmpty()){
        unvisited = getAdjUnvisitedVertex(peek());

        if(unvisited == -1){
            pop();
        }
        else{
            lastVertices[unvisited]->visited = true;
            displayVertex(unvisited);
            push(unvisited);
        }
    }
}

void main(){
    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');

    addEdge(0,2);
    addEdge(0,4);
    addEdge(2,3);
    addEdge(1,4);

    dfs();
}
