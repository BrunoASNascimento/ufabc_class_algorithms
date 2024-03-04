#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int min, sec, cent, totalTime;
} Athlete;

int compareAthletes(const void* a, const void* b) {
    const Athlete *athlete1 = a;
    const Athlete *athlete2 = b;
    return athlete1->totalTime - athlete2->totalTime;
}

void distributeAthletes(int lanes, Athlete* athletes, int numAthletes) {
    int series = (numAthletes + lanes - 1) / lanes;
    if (series > 1 && numAthletes % lanes < 3) {
        series -= 1; // Reduce series by 1 to avoid last series with less than 3 athletes
    }
    printf("%d %s\n", series, series > 1 ? "series" : "serie");

    for (int s = 0; s < series; s++) {
        printf("%da. serie:\n", s + 1);
        int athletesInThisSeries = s < series - 1 ? lanes : numAthletes - s * lanes;
        int offset = 0, direction = 1; // Start from the middle lane
        for (int a = 0; a < athletesInThisSeries; a++) {
            int lane = lanes / 2 + 1 + offset * direction;
            printf("Raia %d: %s\n", lane, athletes[s * lanes + a].name);
            if (direction == 1) {
                direction = -1;
            } else {
                offset++;
                direction = 1;
            }
        }
    }
}

int main() {
    int lanes, numAthletes;
    scanf("%d %d", &lanes, &numAthletes);

    Athlete* athletes = malloc(numAthletes * sizeof(Athlete));
    for (int i = 0; i < numAthletes; i++) {
        scanf("%s %d %d %d", athletes[i].name, &athletes[i].min, &athletes[i].sec, &athletes[i].cent);
        athletes[i].totalTime = (athletes[i].min * 60 + athletes[i].sec) * 100 + athletes[i].cent;
    }

    qsort(athletes, numAthletes, sizeof(Athlete), compareAthletes);
    distributeAthletes(lanes, athletes, numAthletes);

    free(athletes);
    return 0;
}


// Incorrect program output
// --- Input ---
// 8
// 10
// Maria 1 5 14
// Julia 0 58 32
// Lucia 2 0 0
// Cris 0 55 43
// Vitoria 1 0 41
// Isabela 1 15 22
// Helena 1 0 39
// Ana 0 0 0
// Leticia 0 55 10
// Floriana 0 52 8

// --- Program output ---
// 1 serie
// 1a. serie:
// Raia 4: Ana
// Raia 4: Floriana
// Raia 5: Leticia
// Raia 3: Cris
// Raia 6: Julia
// Raia 2: Helena
// Raia 7: Vitoria
// Raia 1: Maria
// Raia 8: Isabela
// Raia 0: Lucia

// --- Expected output (text)---
// 2 series
// 1a. serie:
// Raia 4: Isabela
// Raia 5: Lucia
// Raia 3: Ana
// 2a. serie:
// Raia 4: Floriana
// Raia 5: Leticia
// Raia 3: Cris
// Raia 6: Julia
// Raia 2: Helena
// Raia 7: Vitoria
// Raia 1: Maria