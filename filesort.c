#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge.h"
#include "filesort.h"
int file_sort()
{  
    FILE *inputFile, *outputFile;
    char word[100];
    struct WordFrequency *words = NULL;
    int wordCount = 0;
    int capacity = 1000; // Initial capacity for the dynamic array

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("File not found.\n");
        return 1;
    }

    words = (struct WordFrequency *)malloc(capacity * sizeof(struct WordFrequency));
    if (words == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", word) != EOF) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (wordCount == capacity) {
                // If the dynamic array is full, double its capacity
                capacity *= 2;
                words = (struct WordFrequency *)realloc(words, capacity * sizeof(struct WordFrequency));
                if (words == NULL) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }
            }
            strcpy(words[wordCount].word, word);
            words[wordCount].frequency = 1;
            wordCount++;
        }
    }

    fclose(inputFile);

    mergeSort(words, 0, wordCount - 1);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = wordCount - 1; i >= 0; i--) {
        fprintf(outputFile, "%s %d\n", words[i].word, words[i].frequency);
    }

    fclose(outputFile);

    // Free the dynamically allocated memory
    free(words);

    printf("Sorted output written to 'output.txt'.\n");
    return 0; //if successful returns 0
}