//prvni radek vstupu obsahuje dve cela cisla oddelena mezerou - pocet vrcholu a pocet hran grafu
//kazdy radek reprezentuje jednu hranu grafu

#include <iostream>
#include <vector>
#include <map>     //co je to mapa
#include <set>     //co je to set
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <utility>   //tady je pair
#include <fstream>   //tady je ifstream
#include <limits.h>



int nacti_vazeny_graf(std::vector<std::vector<int>>& hrany_s_vahou, int& pocet_vrcholu, int& pocet_hran);
void vypis_vazeny_graf_do_souboru(std::vector<std::vector<int>> hrany_s_vahou, int pocet_vrcholu, int pocet_hran);
int vytvor_matici_sousednosti_vazeneho_grafu(std::vector<std::vector<int>> hrany_s_vahou, std::vector<std::vector<int>>& matice_sousednosti, int pocet_vrcholu, int pocet_hran);
void vypis_matici_sousednosti_do_souboru(std::vector<std::vector<int>> matice_sousednosti, int pocet_vrcholu);
void dijkstra(const std::vector<std::vector<int>>& graph, int src);
int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet);
void printSolution(const std::vector<int>& dist);
void save_solution_to_file(const std::vector<int>& dist, int pocet_vrcholu);
//nacti graf je jedina fce ktera meni hodnotu vektoru hrany, proto ji musim predat referenci, take meni pocet vrcholu a pocet hran, proto je predavam referenci

int main(){
    int pocet_vrcholu, pocet_hran;
    
    //toto je matice sousednosti
    std::vector<std::vector<int>> matice_sousednosti;

    //toto bude vektor, obsahujici dalse vektory, ktere budou obsahovat hrany, reprezentovane jako dvojice cisel a vaha hrany
    //kazdy podvektor tedy bude obsahovat tri cisla
    std::vector<std::vector<int>> hrany_s_vahou;

    nacti_vazeny_graf(hrany_s_vahou, pocet_vrcholu, pocet_hran);
    vypis_vazeny_graf_do_souboru(hrany_s_vahou, pocet_vrcholu, pocet_hran);
    vytvor_matici_sousednosti_vazeneho_grafu(hrany_s_vahou, matice_sousednosti, pocet_vrcholu, pocet_hran);
    vypis_matici_sousednosti_do_souboru(matice_sousednosti, pocet_vrcholu);
    dijkstra(matice_sousednosti, 0);

    //./tvuj_program < input.txt    to je k nicemu pouzivat std::ifstream
    return 0;
}

int nacti_vazeny_graf(std::vector<std::vector<int>>& hrany_s_vahou, int& pocet_vrcholu, int& pocet_hran){
    std::ifstream inputFile("graphweighted.txt");  // Otevře soubor input.txt
    if (!inputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return 1;
    }
    //nactu prvni radek
    
    inputFile >> pocet_vrcholu >> pocet_hran;
    //nactu zbytek radku
    for (int i = 0; i < pocet_hran; i++){
        int vrchol1, vrchol2, vaha_hrany;
        inputFile >> vrchol1 >> vrchol2 >> vaha_hrany;
        hrany_s_vahou.push_back({vrchol1, vrchol2, vaha_hrany});
    }
    return 0;
}

int vytvor_matici_sousednosti_vazeneho_grafu(std::vector<std::vector<int>> hrany_s_vahou, std::vector<std::vector<int>>& matice_sousednosti, int pocet_vrcholu, int pocet_hran) {
    // Inicializace matice sousednosti o rozměrech pocet_vrcholu x pocet_vrcholu
    matice_sousednosti.resize(pocet_vrcholu, std::vector<int>(pocet_vrcholu, 0));

    // Naplnění matice sousednosti na základě hran
    for (int i = 0; i < pocet_hran; i++) {
        int vrchol1 = hrany_s_vahou[i][0];
        int vrchol2 = hrany_s_vahou[i][1];
        int vaha_hrany = hrany_s_vahou[i][2];

        // Matice sousednosti je symetrická pro neorientovaný graf
        matice_sousednosti[vrchol1][vrchol2] = vaha_hrany;
        matice_sousednosti[vrchol2][vrchol1] = vaha_hrany;
    }

    return 0;
}


void vypis_vazeny_graf_do_souboru(std::vector<std::vector<int>> hrany_s_vahou, int pocet_vrcholu, int pocet_hran){
    std::ofstream outputFile("vazeny_graf.txt");
    if (!outputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return;
    }
    outputFile << pocet_vrcholu << " " << pocet_hran << std::endl;
    for (int i = 0; i < pocet_hran; i++){
        outputFile << hrany_s_vahou[i][0] << " " << hrany_s_vahou[i][1] << " " << hrany_s_vahou[i][2] << std::endl;
    }
    outputFile.close();
}

void vypis_matici_sousednosti_do_souboru(std::vector<std::vector<int>> matice_sousednosti, int pocet_vrcholu){
    std::ofstream outputFile("matici_sousednosti.txt");
    if (!outputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return;
    }
    for (int i = 0; i < pocet_vrcholu; i++){
        for (int j = 0; j < pocet_vrcholu; j++){
            outputFile << matice_sousednosti[i][j] << " ";
        }
        outputFile << std::endl;
    }
    outputFile.close();
}

int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < dist.size(); v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(const std::vector<int>& dist)
{
    std::cout << "Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < dist.size(); i++)
        std::cout << i << " \t\t\t\t" << dist[i] << std::endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(const std::vector<std::vector<int>>& graph, int src)
{
    int V = graph.size();  // Number of vertices in the graph
    std::vector<int> dist(V, INT_MAX);  // The output array. dist[i] will hold the shortest distance from src to i
    std::vector<bool> sptSet(V, false);  // sptSet[i] will be true if vertex i is included in shortest path tree

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    //printSolution(dist);
    save_solution_to_file(dist, V);
}

void save_solution_to_file(const std::vector<int>& dist, int pocet_vrcholu){
    std::ofstream outputFile("vzdalenosti.txt");
    if (!outputFile) {
        std::cerr << "Chyba: Soubor se nepodařilo otevřít!" << std::endl;
        return;
    }
    for (int i = 0; i < pocet_vrcholu; i++){
        outputFile << dist[i] << std::endl;
    }
    outputFile.close();
}
