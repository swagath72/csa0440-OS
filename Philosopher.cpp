#include <stdio.h>
#define NUM_PHILOSOPHERS 5
void think(int philosopher) {
    printf("Philosopher %d is thinking.\n", philosopher);
}

void eat(int philosopher) {
    printf("Philosopher %d is eating.\n", philosopher);
}

int main() {
    int state[NUM_PHILOSOPHERS] = {0}; // 0: thinking, 1: eating
    int i;

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        // Each philosopher thinks first
        think(i);
        
        // Check if philosopher can eat (basic simulation)
        if (state[(i + 4) % NUM_PHILOSOPHERS] != 1 && state[(i + 1) % NUM_PHILOSOPHERS] != 1) {
            state[i] = 1; // Philosopher starts eating
            eat(i);
            state[i] = 0; // Philosopher finishes eating
        } else {
            printf("Philosopher %d is waiting for chopsticks.\n", i);
        }
    }

    return 0;
}
