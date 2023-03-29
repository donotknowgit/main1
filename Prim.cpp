#include<iostream>
using namespace std;

#define V 6
int G[V][V] = {
  {0, 99, 75, 0, 0, 1},
  {99, 0, 95, 19, 42, 56},
  {75, 95, 0, 51, 66, 2},
  {0, 19, 51, 0, 31, 89},
  {0, 42, 66, 31, 0, 0},
  {1, 56, 2, 89, 0, 0}
};

int main() {
    int no_edge;
    int selected[V];
    for (int i = 0; i < V; i++) { selected[i] = false; }
    no_edge = 0;
    selected[0] = true;
    int x;
    int y;
    cout << "Edge" << "     :   " << "Weight";
    cout << endl;
    while (no_edge < V - 1) {
        int min = INT_MAX;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        cout << x << " -> " << y << "   :   " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    return 0;
}