#ifndef MERGE_H
#define MERGE_H
struct WordFrequency {
    char word[100];
    int frequency;
};


void merge(struct WordFrequency arr[], int l, int m, int r);
// Merge sort function
void mergeSort(struct WordFrequency arr[], int l, int r) ;

// l is for left index and r is right index of the
// sub-array of arr to be sorted


// Function to print an array




#endif

