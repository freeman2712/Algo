#include <iostream>
#include <limits.h>
#define MAXV 10
struct Node{
    int y;
    int weight;
    struct Node* next;
};
struct Graph{
    struct Node* list[MAXV + 1];
    int degree[MAXV + 1];
    int nvertices;
    int nedges;
};
int INGRAPH[MAXV];
struct Graph* GraphInit()
{
    struct Graph* temp = (struct Graph*)malloc(sizeof(struct Graph));
    for(int i = 0; i<MAXV; i++) temp->list[i] = NULL;
    for(int i = 0; i<MAXV; i++) temp->degree[i] = 0;
    temp->nvertices = 0;
    temp->nedges = 0;
    return temp;
}
int Input(int*, int*, int*);
void InsertGraph(struct Graph*, int, int, int, int);
struct Graph* PrimMST(struct Graph*, int, int*);
int main()
{
    int MSTW = 0;
    struct Graph* g = GraphInit();
    for(int i = 0; i<MAXV; i++)     INGRAPH[i] = 0;
    int u,v, w, flag;
    int minW;
    while(1)
    {
        int opt;
        std::cout << "1. Insert \n";
        std::cout << "2. Prim/'s MST\n";
        std::cout << "3. Select One Option: ";
        std::cin >> opt;
        if(opt == 1)
        {
            flag = Input(&u, &v, &w);
            InsertGraph(g, u, v, w, flag);
        }
        else if(opt == 2)
        {
            struct Graph* MinimumSpanningTree = PrimMST(g, 0, &MSTW);
            std::cout << "Min Spanning Tree weight: " << MSTW << "\n";
        }
    }
}
void InsertGraph(struct Graph* g, int u, int v, int w, int isDirected)
{
    g->degree[u]++;
    if(g->list[u] == NULL && !INGRAPH[u]){  g->nvertices++; INGRAPH[u] = 1;}
    if(isDirected && g->list[v] ==  NULL && !INGRAPH[v]){   (g->nvertices)++;   INGRAPH[v] = 1;}

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = g->list[u];
    g->list[u] = temp;
    temp->y = v;
    temp->weight = w;

    if(!isDirected) InsertGraph(g, v, u, w, 1);
    else            (g->nedges)++;
    
}
int Input(int* u, int* v, int* w)
{
    std::cout << "Enter vertices: ";
    std::cin >> (*u);
    std::cin >> (*v);
    std::cout << "Enter weight: ";
    std::cin >> (*w);
    return 0;
}
struct Graph* PrimMST(struct Graph* g, int s, int* mst_weight)
{
    struct Graph* MinSpanTree = GraphInit();
    int MSTW = 0;
    int d[g->nvertices];
    int par[g->nvertices];
    int flag[g->nvertices];
    for(int i = 0; i<g->nvertices; i++) d[i] = INT_MAX;
    for(int i = 0; i<g->nvertices; i++) par[i] = -1;
    for(int i = 0; i<g->nvertices; i++) flag[i] = 0;
    d[s] = 0;
    int v = s;
    int dist = INT_MAX;
    while(!flag[v])
    {
        int str = v;
        flag[v] = 1;
        if(v!=s)    MSTW = MSTW + dist;
        struct Node* p = g->list[v];
        while(p!=NULL)
        {
            if(!flag[p->y] && d[p->y] > p->weight)
            {
                d[p->y] = p->weight;
                par[p->y] = v;

            }
            p = p->next;
        }
        dist = INT_MAX;
        for(int i = 0; i<g->nvertices; i++)
        {
            if(!flag[i] && dist > d[i])
            {
                dist = d[i];
                v = i;
            }
        }
        InsertGraph(MinSpanTree, str, v, dist, 0);

    }
    *mst_weight = MSTW;
    return MinSpanTree;

}