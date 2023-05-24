#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int numVertices;
    bool isDirected;
    bool hasWeight;
    std::vector<std::vector<int> > adjacencyList;
    std::vector<std::vector<int> > adjacencyMatrix;

public:
    Graph(std::string options) : numVertices(0), isDirected(false), hasWeight(false) {
        for (char option : options) {
            if (option == '+') continue;

            if (option == 'D') isDirected = true;
            if (option == 'W') hasWeight = true;
        }
    }

    int addVertex() {
        adjacencyList.push_back(std::vector<int>());
        numVertices++;
        return numVertices - 1;
    }

    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
        if (!isDirected) adjacencyList[destination].push_back(source);
    }

    void deleteEdge(int source, int destination) {
        auto it = std::find(adjacencyList[source].begin(), adjacencyList[source].end(), destination);
        if (it != adjacencyList[source].end()) {
            adjacencyList[source].erase(it);
        }
        if (!isDirected) {
            it = std::find(adjacencyList[destination].begin(), adjacencyList[destination].end(), source);
            if (it != adjacencyList[destination].end()) {
                adjacencyList[destination].erase(it);
            }
        }
    }

    void deleteVertex(int vertex) {
        if (vertex >= numVertices) return;

        for (int i = 0; i < numVertices; i++) {
            deleteEdge(i, vertex);
        }

        adjacencyList.erase(adjacencyList.begin() + vertex);
        numVertices--;
    }

    void printDFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        DFS(startVertex, visited);
    }

    void printBFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        BFS(startVertex, visited);
    }

    void printAdjacencyList() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (int vertex : adjacencyList[i]) {
                std::cout << vertex << " ";
            }
            std::cout << std::endl;
        }
    }

    void printAdjacencyMatrix() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (std::find(adjacencyList[i].begin(), adjacencyList[i].end(), j) != adjacencyList[i].end()) {
                    std::cout << "1 ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }

    void printIncidenceMatrix() {
        std::cout << "Incidence Matrix:" << std::endl;
        std::vector<std::vector<int> > incidenceMatrix(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; i++) {
            for (int vertex : adjacencyList[i]) {
                incidenceMatrix[i][vertex] = 1;
                if (!isDirected) incidenceMatrix[vertex][i] = 1;
            }
        }
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << incidenceMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Método para imprimir o menor caminho entre dois vértices
    // Utilize o algoritmo de Dijkstra para encontrar o caminho mais curto

private:
    void DFS(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";

        for (int adjacentVertex : adjacencyList[vertex]) {
            if (!visited[adjacentVertex]) {
                DFS(adjacentVertex, visited);
            }
        }
    }

    void BFS(int startVertex, std::vector<bool>& visited) {
        std::queue<int> queue;
        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            std::cout << currentVertex << " ";
            queue.pop();

            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    queue.push(adjacentVertex);
                }
            }
        }
    }
    
    void shortestPath(int startVertex, int endVertex) {
        std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
        distances[startVertex] = 0;

        std::vector<int> parent(numVertices, -1);

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, startVertex));

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentDistance = pq.top().first;
            pq.pop();

            if (currentVertex == endVertex) {
                break;
            }

            if (currentDistance > distances[currentVertex]) {
                continue;
            }

            for (const auto& edge : adjacencyList[currentVertex]) {
                int neighbor = edge.first;
                int weight = edge.second;
                int distance = currentDistance + weight;

                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    parent[neighbor] = currentVertex;
                    pq.push(std::make_pair(distance, neighbor));
                }
            }
        }

        if (distances[endVertex] != std::numeric_limits<int>::max()) {
            std::cout << "Shortest path from vertex " << startVertex << " to vertex " << endVertex << ":" << std::endl;
            std::vector<int> path;
            int currentVertex = endVertex;
            while (currentVertex != -1) {
                path.insert(path.begin(), currentVertex);
                currentVertex = parent[currentVertex];
            }
            for (int i = 0; i < path.size(); i++) {
                std::cout << path[i];
                if (i != path.size() - 1) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl;
            std::cout << "Total distance: " << distances[endVertex] << std::endl;
        } else {
            std::cout << "No path found from vertex " << startVertex << " to vertex " << endVertex << std::endl;
        }
    }
};


int main() {
    // Cria um grafo direcionado sem pesos
    Graph graph("+D");

    // Adiciona vértices
    int vertexA = graph.addVertex();
    int vertexB = graph.addVertex();
    int vertexC = graph.addVertex();
    int vertexD = graph.addVertex();

    // Adiciona arestas
    graph.addEdge(vertexA, vertexB);
    graph.addEdge(vertexB, vertexC);
    graph.addEdge(vertexB, vertexD);


    // Imprime a travessia DFS
    std::cout << "DFS traversal: "<<graph.printDFS(vertexA)<<std::cout << std::endl;

    // Imprime a travessia BFS
    std::cout << "BFS traversal: "<<graph.printBFS(vertexA)<<std::cout << std::endl;

    // Imprime a lista de adjacência
    graph.printAdjacencyList();

    // Imprime a matriz de adjacência
    graph.printAdjacencyMatrix();

    // Imprime a matriz de incidência
    graph.printIncidenceMatrix();

    graph.shortestPath(vertexA,vertexD);

    // Deleta uma aresta
    graph.deleteEdge(vertexA, vertexB);

    // Deleta um vértice
    graph.deleteVertex(vertexC);

    return 0;
}
