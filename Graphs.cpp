#include<iostream>
#include<climits>
#include <vector>
using namespace std;

int minimumDist(int dist[], bool Tset[])
{
	int minn = INT_MAX, index;

	for (int i = 0; i < 5; i++)
	{
		if (Tset[i] == false && dist[i] <= minn)
		{
			minn = dist[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(int graph[5][5], int src)
{
	int dist[5];
	bool Tset[5];
	for (int i = 0; i < 5; i++)
	{
		dist[i] = INT_MAX;
		Tset[i] = false;
	}
	dist[src] = 0;
	for (int i = 0; i < 5; i++)
	{
		int m = minimumDist(dist, Tset);
		Tset[m] = true;
		for (int i = 0; i < 5; i++)
		{
			if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
				dist[i] = dist[m] + graph[m][i];
		}
	}
	cout << "Vertex\t\tDistance from source" << endl;
	for (int i = 0; i < 5; i++)
	{
		char str = 65 + i;
		cout << str << "\t\t\t" << dist[i] << endl;
	}
	cout << endl;
}

void BellmanFord(int graph[][3], int V, int E, int src)
{
	int* dis;
	dis = new int[V];
	for (int i = 0; i < V; i++) {
		dis[i] = INT_MAX;
	}
	dis[src] = 0;
	for (int i = 0; i < V - 1; i++) {
		for (int j = 0; j < E; j++) {
			if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) {
				dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
			}
		}
	}
	for (int i = 0; i < E; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (dis[x] != INT_MAX && dis[x] + weight < dis[y]) {
			cout << "Graph contains negative weight cycle" << endl;
		}
	}
	cout << "Vertex\t\tDistance from Source" << endl;
	for (int i = 0; i < V; i++) { cout << char(65 + i) << "\t\t\t" << dis[i] << endl; }
	cout << endl;
}

void ToEdges(int graph[5][5], int lst[7][3]) {
	int n = 0;
	for (int u = 0; u < 4; u++) {
		for (int v = u + 1; v < 5; v++) {
			if (graph[u][v] != 0) { lst[n][0] = u; lst[n][1] = v; lst[n][2] = graph[u][v]; n++; }
			if (n == 7) { break; }
		}
		if (n == 7) { break; }
	}
}

void FloydWarshall(int graph[5][5]) {
	cout << "Shortest paths matrix" << endl;
	int distance[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			distance[i][j] = graph[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		distance[i][i] = 0;
	}
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (distance[i][j] > distance[i][k] + distance[k][j]) {
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << distance[i][j] << '\t';;
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int graph[5][5] = {
		{0, 10, 20, 0, 0},
		{10, 0, 0, 50, 10},
		{20, 0, 0, 20, 33},
		{0, 50, 20, 0, 20},
		{0, 10, 33, 20, 0} };
	int edges[7][3] = {
		{0, 0, 0}, {0, 0, 0}, {0, 0, 0},
		{0, 0, 0}, {0, 0, 0}, {0, 0, 0},
		{0, 0, 0} };
	Dijkstra(graph, 0);
	ToEdges(graph, edges);
	BellmanFord(edges, 5, 7, 0);
	FloydWarshall(graph);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			cout << edges[i][j] << ", ";
		}
		cout << endl;
	}
	return 0;
}
