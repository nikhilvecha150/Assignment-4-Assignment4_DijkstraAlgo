#include <iostream>
#include <vector>
#include <limits>
#include <iomanip> // For alignment
using namespace std;

// Function for implementing
void dij_algo(const vector<vector<int>>& gra_ph, int sor) {
    int var_n = gra_ph.size(); // Number of nodes in graph

    // Initialize distance, predecessor, and visited arrays
    vector<int> dis_t(var_n, numeric_limits<int>::max()), pre_v(var_n, -1);
    vector<bool> vis_ed(var_n, false);
    dis_t[sor] = 0; // Source node distance

    // Iterate n-1 times to find the smallest way
    for (int itrr_a = 0; itrr_a < var_n - 1; ++itrr_a) {
        int itrr_m = -1;

        // Find the closest not visited node
        for (int itrr_b = 0; itrr_b < var_n; ++itrr_b) {
            if (!vis_ed[itrr_b] && (itrr_m == -1 || dis_t[itrr_b] < dis_t[itrr_m])) {
                itrr_m = itrr_b; // Update the node with the smallest distance
            }
        }

        // No valid node is found, then leave the loop
        if (dis_t[itrr_m] == numeric_limits<int>::max()) break;

        vis_ed[itrr_m] = true; // Marks current node as visited

        // Update distances to neighboring nodes
        for (int itrr_n = 0; itrr_n < var_n; ++itrr_n) {
            // Check if the neighbor is not visited and has smaller path
            if (gra_ph[itrr_m][itrr_n] && !vis_ed[itrr_n] && dis_t[itrr_m] + gra_ph[itrr_m][itrr_n] < dis_t[itrr_n]) {
                dis_t[itrr_n] = dis_t[itrr_m] + gra_ph[itrr_m][itrr_n]; // Update the distance
                pre_v[itrr_n] = itrr_m; // Update the predecessor
            }
        }
    }

    // Results in the required format
    cout << left << setw(10) << "Vertex" << setw(15) << "Minimum Cost" << "Route\n";
    for (int itrr_c = 0; itrr_c < var_n; ++itrr_c) {
        if (itrr_c == sor) continue;

        // Print destination node and its cost
        cout << left << setw(10) << "A -> " + string(1, 'A' + itrr_c)
             << setw(15) << dis_t[itrr_c];

        for (int itrr_d = itrr_c; itrr_d != -1; itrr_d = pre_v[itrr_d]) {
            cout << char('A' + itrr_d);
            if (pre_v[itrr_d] != -1) cout << " -> ";
        }
        cout << endl;
    }
}

int main() {
    int itrr_n; // Number of nodes in graph
    cout << "Enter the number of nodes: ";
    cin >> itrr_n;

    // The adjacency matrix, initializing
    vector<vector<int>> graph(itrr_n, vector<int>(itrr_n));
    cout << "The adjacency matrix (0 for no edge):\n";
    for (int itrr_i = 0; itrr_i < itrr_n; ++itrr_i) {
        for (int itrr_j = 0; itrr_j < itrr_n; ++itrr_j) {
            cin >> graph[itrr_i][itrr_j];
        }
    }

    int var_sor; // Source node for Dijkstra's algorithm
    cout << "Enter the starting node: ";
    cin >> var_sor;

    // Call the function to compute
    dij_algo(graph, var_sor);
    return 0;
}
