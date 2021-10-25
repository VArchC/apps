#include <stdio.h>
#include <stdlib.h>

#define NUM_NODES                          num_nodes
#define NONE                               9999
#define ITERATIONS                         NUM_NODES

int num_nodes;

struct _NODE {
  int iDist;
  int iPrev;
};
typedef struct _NODE NODE;

struct _QITEM {
  int iNode;
  int iDist;
  int iPrev;
  struct _QITEM *qNext;
};

typedef struct _QITEM QITEM;

QITEM *qHead = NULL;

struct _PATH {
  int cost;
  int *path;
  int size;
};
typedef struct _PATH PATH;
     

int g_qCount = 0;
int ch;
int iPrev, iNode;
int i, iCost, iDist;

void print_path(NODE *rgnNodes, int chNode) {
  if (rgnNodes[chNode].iPrev != NONE) {
    print_path(rgnNodes, rgnNodes[chNode].iPrev);
  }
  printf (" %d", chNode);
  fflush(stdout);
}

int get_next_hop(NODE *rgnNodes, int source, int dest) {
  if (rgnNodes[dest].iPrev == NONE) {
    return NONE;
  }
  if (rgnNodes[dest].iPrev == source) {
    return dest;
  }
  return get_next_hop(rgnNodes, source, rgnNodes[dest].iPrev);
}


void enqueue (int iNode, int iDist, int iPrev) {
  QITEM *qNew = (QITEM *) malloc(sizeof(QITEM));
  QITEM *qLast = qHead;

  if (!qNew) {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
  }
  qNew->iNode = iNode;
  qNew->iDist = iDist;
  qNew->iPrev = iPrev;
  qNew->qNext = NULL;

  if (!qLast) {
    qHead = qNew;
  }
  else {
    while (qLast->qNext) qLast = qLast->qNext;
    qLast->qNext = qNew;
  }
  g_qCount++;
  //               ASSERT(g_qCount);
}


void dequeue (int *piNode, int *piDist, int *piPrev) {
  QITEM *qKill = qHead;

  if (qHead) {
  //                 ASSERT(g_qCount);
    *piNode = qHead->iNode;
    *piDist = qHead->iDist;
    *piPrev = qHead->iPrev;
    qHead = qHead->qNext;
    free(qKill);
    g_qCount--;
  }
}


int qcount (void) {
  return(g_qCount);
}

int dijkstra(int chStart, int chEnd, int iter, 
              int num_nodes, int iterations, int AdjMatrix[num_nodes][num_nodes], NODE rgnNodes[iterations][num_nodes]) {

  for (ch = 0; ch < NUM_NODES; ch++) {
    rgnNodes[iter][ch].iDist = NONE;
    rgnNodes[iter][ch].iPrev = NONE;
  }

  if (chStart == chEnd) {
    return 0;
  }
  else {
    rgnNodes[iter][chStart].iDist = 0;
    rgnNodes[iter][chStart].iPrev = NONE;

    enqueue (chStart, 0, NONE);

    while (qcount() > 0) {
      dequeue (&iNode, &iDist, &iPrev);
      for (i = 0; i < NUM_NODES; i++) {
        if ((iCost = AdjMatrix[iNode][i]) != NONE) {
          if ((NONE == rgnNodes[iter][i].iDist) || (rgnNodes[iter][i].iDist > (iCost + iDist))) {
            rgnNodes[iter][i].iDist = iDist + iCost;
            rgnNodes[iter][i].iPrev = iNode;
            enqueue (i, iDist + iCost, iNode);
          }
        }
      }
    }

    return rgnNodes[iter][chEnd].iDist;
  }
}

int main(int argc, char *argv[]) {
  int i,j,k;
  int *costs;
  FILE *fp;

  /*if (argc<2) {
    fprintf(stderr, "Usage: dijkstra <filename>\n");
    fprintf(stderr, "Only supports matrix size is #define'd.\n");
  }*/

  /* open the adjacency matrix file */
  fp = stdin;//fopen (argv[1],"r");

  fscanf(fp, "%d", &num_nodes);

  int AdjMatrix[NUM_NODES][NUM_NODES];
  NODE rgnNodes[ITERATIONS][NUM_NODES];

  /* make a fully connected matrix */
  for (i=0;i<NUM_NODES;i++) {
    for (j=0;j<NUM_NODES;j++) {
      /* make it more sparce */
      fscanf(fp, "%d",&k);
      AdjMatrix[i][j] = k;
    }
  }


  costs = malloc(NUM_NODES * sizeof(int));
  /**
  * Approximated Region
  */
  //vac_activate(VAC_APPROX_MEM_BITFLIP);
  //vac_newSection();

  /* finds 10 shortest paths between nodes */
  for (i=0,j=NUM_NODES/2; i<NUM_NODES;i++,j++) {
    j = j % NUM_NODES;
    costs[i] = dijkstra(i, j, i, num_nodes, ITERATIONS, AdjMatrix, rgnNodes);
  }

  /**
  * End of approximated region
  */
  //vac_deactivate(VAC_APPROX_MEM_BITFLIP);
  //vac_newSection();

  for (i=0; i<NUM_NODES; i++) {
    for (j=0; j<NUM_NODES; j++) {
      printf(" %d", get_next_hop(rgnNodes[i], i, j));
    }
    printf("\n");
  //for (i=0,j=NUM_NODES/2; i<NUM_NODES;i++,j++) {
    //j = j % NUM_NODES;
    /*
    if (i == j) {
      printf("Shortest path is 0 in cost. Just stay where you are.\n");
    } else {
      printf("Shortest path is %d in cost. ", rgnNodes[i][j].iDist);
      printf("Path is: ");
      print_path(rgnNodes[i], j);
      printf("\n");
    }*/
  }

  return 0;
}
