# Lab5
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/** \brief Ôóíêöèÿ ðåàëèçóåò Àëãîðèòì Äåéêñòðû
 *
 * \param [in] GR - ìàòðèöà ñìåæíîñòè
 * \param [in] st - ñòàðòîâàÿ âåðøèíà
 * \param [in] V - êîëè÷åñòâî âåðøèí ãðàôà
*/
void Dijkstra(int ** GR, int st, int V)
{
int distance[V], count, index, i, u, m=st+1;
bool visited[V];
for (i=0; i<V; i++) {
    distance[i]=INT_MAX; visited[i]=false;
}
distance[st]=0;
for (count=0; count<V-1; count++) {
    int min=INT_MAX;
    for (i=0; i<V; i++) {
        if (!visited[i] && distance[i]<=min) {
            min=distance[i]; index=i;
        }
    }
u=index;
visited[u]=true;
    for (i=0; i<V; i++){
        if (!visited[i] && GR[u][i] && distance[u]!=INT_MAX &&
            distance[u]+GR[u][i]<distance[i]) {
                distance[i]=distance[u]+GR[u][i];
            }
    }
}
for (i=0; i<V; i++) {
    if (distance[i]!=INT_MAX) {
        cout<<distance[i]<<" ";
    } else {
        cout<<m<<" > "<<i+1<<" = "<<"ìàðøðóò íåäîñòóïåí"<<" ";
    }
}
}
/** \brief Îñíîâíàÿ ôóíêöèÿ ïðîãðàììû
 */

int main()
{
setlocale(LC_ALL, "Rus");
int V = 0;
cin>>V;
int start;
int ** GR;
GR = (int **) malloc(sizeof(int*) * V);
for(int i = 0; i < V; i ++) {
    GR[i] = (int*) malloc(sizeof(int) * V);
    for(int j = 0; j < V; j ++) {
        cin>>GR[i][j];
    }
}
start = 1;
Dijkstra(GR, start-1, V);
return 0;
}
