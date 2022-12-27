#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;

// Global constants
const int MAXGEN = 100; // maximum no. of generations
const int n = 10;       // population size (rows)
const int m = 10;       // population size (columns)

// Function prototypes
void initialize(bool[][m]);
void initialize2(bool[][m], int);
int countNeighbours(bool[][m], int, int);
bool allDead(bool[][m]);
void reproduce(bool[][m]);
void print(bool[][m]);

int main()
{
    bool population[n][m]; // current generation
    bool newPopulation[n][m]; // next generation

    // Initialize the population
    cout << "Enter population as a sequence of 0s and 1s:" << endl;
    initialize(population);

    // Display initial population
    cout << "Initial population:" << endl;
    print(population);

    // Simulate the game of life for MAXGEN generations
    for (int gen = 1; gen <= MAXGEN; gen++)
    {
        // Check if the population is all dead
        if (allDead(population))
        {
            cout << "The population is extinct after " << gen-1 << " generations." << endl;
            break;
        }

        // Produce the next generation
        reproduce(population);

        // Check if the population is stable (no change from the previous generation)
        bool stable = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (population[i][j] != newPopulation[i][j])
                {
                    stable = false;
                    break;
                }
        if (stable)
        {
            cout << "The population became stable after " << gen << " generations." << endl;
            break;
        }

        // Copy the next generation back to the current generation
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                population[i][j] = newPopulation[i][j];

        // Display the current population
        cout << "Generation " << gen << ":" << endl;
        print(population);
    }

    return 0;
}

// Initializes the population by reading a sequence of 0s and 1s from the user
void initialize(bool population[][m])
{
    char c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            population[i][j] = (c == '1');
        }
}

// Initializes the population randomly with a given density
void initialize2(bool population[][m], int density)
{
    srand(time(0)); // seed the random number generator with the current time
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            population[i][j
