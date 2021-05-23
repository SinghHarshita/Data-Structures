// Implementation of Dijkstra’s shortest Path finding algorithm

#include<stdio.h>
#include<stdlib.h>

#define max 5

typedef struct graph
{
    char data;
    int label;
}vertex;

vertex v[max];
int adjacency[max][max];
int stack[max];

void push();
void pop();
void dijkstra(char source, char dest);

void main()
{
    int i, j;
    char c,s,d;

    printf("\nEnter the vertices one by one: ");
    for(i=0;i<max;i++)
    {
        printf("\nEnter vertex%d: ",i+1);
        scanf("%c",&v[i].data);
        v[i].label = -1;
        scanf("%c");
    }

    printf("\nEnter the adjacency: \nEnter 1 if adjacent and 0 if not adjacent. ");

    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            printf("\nIs %c adjacent to %c: ",v[i].data,v[j].data);
            scanf("%d",&adjacency[i][j]);
        }
    }

    printf("\nEnter the source: ");
    scanf("%c",&s);
    printf("\nEnter the destination: ");
    scanf("%c",&d);
    dijkstra(s,d);
}

void dijkstra(char source, char dest)
{
    int i=0,j=0,dist,s=0,d=0,min=0;

    stack[0] = source;

    while(source!=v[s].data)
        s++;
    while(dest!=v[d].data)
        d++;
    if(v[s].label==-1)
    {
        v[s].label = 0;
    }

    while(i!=max)
    {
        printf("\nEnter the edge length of %c%c: ",v[i].data,stack[j]);
        scanf("%d",&dist);


    }
}
