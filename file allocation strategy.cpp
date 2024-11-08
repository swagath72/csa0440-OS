#include <stdio.h>
#include <stdlib.h>

struct Block {
    char data[256];
    struct Block* next;
};

int main() {
    struct Block *firstBlock = NULL, *lastBlock = NULL, *currentBlock;
    int blockCount = 0, blockNumber;
    char data[256], choice;

    printf("Linked Allocation Simulation\n");
    while (1) {
        printf("Enter 'W' to write, 'R' to read, 'Q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q') break;
        if (choice == 'W' || choice == 'w') {
            printf("Enter data: ");
            scanf(" %[^\n]", data);

            struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
            for (int i = 0; i < 256; i++) newBlock->data[i] = data[i];
            newBlock->next = NULL;

            if (blockCount == 0) firstBlock = newBlock;
            else lastBlock->next = newBlock;
            lastBlock = newBlock;
            blockCount++;
        } else if (choice == 'R' || choice == 'r') {
            printf("Enter block number to read (1-%d): ", blockCount);
            scanf("%d", &blockNumber);

            if (blockNumber < 1 || blockNumber > blockCount) 
                printf("Invalid block number.\n");
            else {
                currentBlock = firstBlock;
                for (int i = 1; i < blockNumber; i++) currentBlock = currentBlock->next;
                printf("Block %d Data: %s\n", blockNumber, currentBlock->data);
            }
        }
    }

    currentBlock = firstBlock;
    while (currentBlock != NULL) {
        struct Block* nextBlock = currentBlock->next;
        free(currentBlock);
        currentBlock = nextBlock;
    }
    return 0;
}
