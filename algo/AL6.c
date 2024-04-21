#include <stdio.h>
#include <stdbool.h>

#define N 3 // Number of workers and jobs (adjust as needed)

// Cost matrix (example)
int cost[N][N] = {
    {2, 3, 4},
    {5, 1, 6},
    {7, 8, 9}
};

bool assigned[N]; // To track assigned jobs
int minCost = 0; // Initialize minimum cost

void assignJob(int worker, int totalCost) {
    if (worker == N) {
        // All workers assigned, update minimum cost
        if (totalCost < minCost)
            minCost = totalCost;
        return;
    }

    for (int job = 0; job < N; ++job) {
        if (!assigned[job]) {
            assigned[job] = true;
            assignJob(worker + 1, totalCost + cost[worker][job]);
            assigned[job] = false; // Backtrack
        }
    }
}

int main() {
    assignJob(0, 0); // Start with worker 0
    printf("Minimum cost: %d\n", minCost);
    return 0;
}
