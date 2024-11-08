#include <stdio.h>
#include <stdlib.h>

struct Record {
    int blockNumber;
    char data[256];
};

int main() {
    FILE *file;
    struct Record record;
    int blockNumber;

    file = fopen("sequential_file.txt", "w");
    if (file == NULL) return 1;

    printf("Enter records (Enter '0' as block number to exit):\n");
    while (1) {
        printf("Block Number: ");
        scanf("%d", &record.blockNumber);
        if (record.blockNumber == 0) break;
        printf("Data: ");
        scanf(" %[^\n]", record.data);
        fwrite(&record, sizeof(struct Record), 1, file);
    }
    fclose(file);

    file = fopen("sequential_file.txt", "r");
    if (file == NULL) return 1;

    while (1) {
        printf("Enter the block number to read (0 to exit): ");
        scanf("%d", &blockNumber);
        if (blockNumber == 0) break;

        while (fread(&record, sizeof(struct Record), 1, file)) {
            if (record.blockNumber == blockNumber) {
                printf("Block Number: %d\nData: %s\n", record.blockNumber, record.data);
                break;
            }
        }
        rewind(file);
    }
    fclose(file);
    return 0;
}
