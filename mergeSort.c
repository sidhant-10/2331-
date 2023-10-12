#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure to store word and its frequency
typedef struct {
    char* word;
    int frequency;
} WordInfo;

// Function to merge two sorted arrays of WordInfo structs
void merge(WordInfo array[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    WordInfo Left[n1];
    WordInfo Right[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        Left[i] = array[left + i];
    for (j = 0; j < n2; j++)
        Right[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (Left[i].frequency < Right[j].frequency || (Left[i].frequency == Right[j].frequency && strcmp(Left[i].word, Right[j].word) > 0)) {
            array[k] = Left[i];
            i++;
        } else {
            array[k] = Right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        array[k] = Left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        array[k] = Right[j];
        j++;
        k++;
    }
}

// Merge sort function for sorting an array of WordInfo structs
void mergeSort(WordInfo array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    // Open the input file
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening the input file");
        return 1;
    }

    int max_size = 1000; // Adjust this based on your input file size
    WordInfo words[max_size];
    char word[100]; // Adjust the size as needed

    int num = 0;
    while (fscanf(file, "%99s", word) != EOF) { //"%99s" is used to read a string (sequence of characters) 
        // Check if the word is already in the array
        int found = -1;
        for (int i = 0; i < num; i++) {
            if (strcmp(words[i].word, word) == 0) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            // Word found, update its frequency
            words[found].frequency++;
        } else {
            // Word not found, add it to the array
            words[num].word = strdup(word);
            words[num].frequency = 1;
            num++;
        }
    }

    fclose(file);

    // Perform merge sort on the array of WordInfo structs
    mergeSort(words, 0, num - 1);

    // Open the output file for writing
    FILE* output_file = fopen("result.txt", "w");
    if (output_file == NULL) {
        perror("Error opening the output file");
        return 1;
    }

    // Write the sorted words and their frequencies to the output file
    for (int i = 0; i < num; i++) {
        fprintf(output_file, "%s (%d)\n", words[i].word, words[i].frequency);
        free(words[i].word); // Free memory allocated by strdup
    }

    fclose(output_file);

    printf("Sorting completed. Sorted data saved in 'result.txt'\n");

    return 0;
}