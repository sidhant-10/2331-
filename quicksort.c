#include "quickSort.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(WordFrequency* a, WordFrequency* b)
{
    WordFrequency t = *a;
    *a = *b;
    *b = t;
}

int partition(WordFrequency arr[], int low, int high)
{
    // Choosing the pivot
    WordFrequency pivot = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j].frequency < pivot.frequency) {
 
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(WordFrequency arr[], int low, int high)
{
    if (low < high) {
 
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortAndSaveWordFrequency(char* inputfile, char* outputFile) {
    FILE* f;
    FILE* output;
    char line[100];
    char word[50];
    int freq;
    int capacity = 10;
    struct WordFrequency wordFrequencyMap[2000]; // Assuming a maximum of 2000 unique words
    int wordCount = 0;

    f = fopen(inputfile, "r");
    if (f == NULL) {
        printf("File open error.\n");
        return;
    }

    while (fgets(line, 1000, f)) {
        sscanf(line, "%s %d", word, &freq);
        strcpy(wordFrequencyMap[wordCount].word, word);
        wordFrequencyMap[wordCount].frequency = freq;
        wordCount++;
    }

    quickSort(wordFrequencyMap, 0, wordCount - 1);
    fclose(f);

    output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("Output file open error.\n");
        return;
    }

    for (int i = 0; i < wordCount; i++) {
        fprintf(output, "%s %d\n", wordFrequencyMap[i].word, wordFrequencyMap[i].frequency);
    }

    fclose(output);
}