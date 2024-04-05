#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    int min, sec, cent; // Represents time as minutes, seconds, and hundredths of a second
} Athlete;

// Function to create a vector for lane positions based on their priority
int *createLanePositionVector(int numLanes)
{
    int *lanePositions = (int *)malloc(numLanes * sizeof(int));
    int odd = numLanes % 2 == 0 ? numLanes - 1 : numLanes; // Last odd number for lanes
    int even = 2;                                          // First even number for lanes
    int index = 0;

    // Filling odd lane positions first
    for (int i = odd; i > 0; i -= 2)
    {
        lanePositions[index++] = i;
    }

    // Then, filling even lane positions
    for (int i = even; index < numLanes; i += 2)
    {
        lanePositions[index++] = i;
    }
    return lanePositions;
}

// Comparison function for qsort, comparing athletes by their times
int compare(const void *a, const void *b)
{
    Athlete *athleteA = (Athlete *)a;
    Athlete *athleteB = (Athlete *)b;

    // Prioritize athletes with a defined time
    if (athleteA->min == 0 && athleteA->sec == 0 && athleteA->cent == 0 && (athleteB->min > 0 || athleteB->sec > 0 || athleteB->cent > 0))
    {
        return 1; // Athlete A comes after B
    }
    else if (athleteB->min == 0 && athleteB->sec == 0 && athleteB->cent == 0 && (athleteA->min > 0 || athleteA->sec > 0 || athleteA->cent > 0))
    {
        return -1; // Athlete A comes before B
    }
    else
    {
        // Comparing by total time in hundredths of a second
        int totalTimeA = athleteA->min * 6000 + athleteA->sec * 100 + athleteA->cent;
        int totalTimeB = athleteB->min * 6000 + athleteB->sec * 100 + athleteB->cent;
        return totalTimeA - totalTimeB;
    }
}

// Function to distribute athletes across lanes based on their times
void distributeAthletes(Athlete athletes[], int numAthletes, int numLanes, int *lanePositions)
{
    // Sorting athletes by their times
    qsort(athletes, numAthletes, sizeof(Athlete), compare);

    // Calculating the number of series required
    int numSeries = (numAthletes + numLanes - 1) / numLanes; // Ceiling division

    printf("%d %s\n", numSeries, numSeries > 1 ? "series" : "serie");
    int remainingAthletes = numAthletes;
    for (int i = 0; i < numSeries; i++)
    {
        printf("%da. serie:\n", i + 1);

        int seriesAthletes; // Number of athletes in this series
        if ((remainingAthletes % numLanes <= 3) && (remainingAthletes % numLanes > 0) && (numAthletes > numLanes))
        {
            seriesAthletes = 3;
        }
        else if (remainingAthletes % numLanes == 0)
        {
            seriesAthletes = numLanes;
        }
        else
        {
            seriesAthletes = remainingAthletes % numLanes;
        }

        int startIdx = remainingAthletes - seriesAthletes;
        remainingAthletes -= seriesAthletes;

        // Assigning athletes to lanes based on their positions
        for (int j = startIdx; j < startIdx + seriesAthletes; j++)
        {
            for (int k = 0; k < numLanes; k++)
            {
                if (lanePositions[k] == j - startIdx + 1)
                {
                    printf("Raia %d: %s\n", k + 1, athletes[j].name);
                    break;
                }
            }
        }
    }
}

int main()
{
    int numLanes, numAthletes;
    scanf("%d %d", &numLanes, &numAthletes);

    Athlete *athletes = (Athlete *)malloc(numAthletes * sizeof(Athlete));
    for (int i = 0; i < numAthletes; i++)
    {
        scanf("%s %d %d %d", athletes[i].name, &athletes[i].min, &athletes[i].sec, &athletes[i].cent);
    }

    int *lanePositions = createLanePositionVector(numLanes);
    distributeAthletes(athletes, numAthletes, numLanes, lanePositions);

    free(athletes);
    return 0;
}
