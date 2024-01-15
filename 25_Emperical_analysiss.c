
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHARS 256

// Node structure for Huffman tree
struct Node {
    int freq;
    char data;
    struct Node *left, *right;
};

// Priority queue (min heap) implementation
struct MinHeap {
    int size;
    int capacity;
    struct Node** array;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return minHeap;
}

void swapMinHeapNode(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct Node* extractMin(struct MinHeap* minHeap) {
    if (isSizeOne(minHeap)) {
        return minHeap->array[0];
    }

    struct Node* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to create a Huffman tree
struct Node* createHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->left = node->right = NULL;
        node->data = data[i];
        node->freq = freq[i];
        insertMinHeap(minHeap, node);
    }

    // Build the Huffman tree
    struct Node *left, *right, *top;
    for (int i = 0; i < size - 1; ++i) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = (struct Node*)malloc(sizeof(struct Node));
        top->freq = left->freq + right->freq;
        top->data = '\0';  // Internal node doesn't hold a character
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);  // Root of the Huffman tree
}

// Function to generate Huffman codes
void generateCodes(struct Node* root, char arr[], int top)
 
{
    if (root->left) {
        arr[top] = '0';
        generateCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = '1';
        generateCodes(root->right, arr, top + 1);
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, arr);
    }
}

int main() {
    char data[MAX_CHARS]; // Input data
    int freq[MAX_CHARS] = {0};
    int size;

    printf("Enter a string: ");
    fgets(data, MAX_CHARS, stdin);  // Get input from user
    size = strlen(data) - 1;   
    
    // Calculate character frequencies
    for (int i = 0; i < size; ++i) {
        ++freq[data[i]];
    }

    // Measure runtime
    clock_t start = clock();

    // Create Huffman tree
    struct Node* root = createHuffmanTree(data, freq, size);

    // Generate Huffman codes
    char arr[MAX_CHARS];
    generateCodes(root, arr, 0);

    clock_t end = clock();
    double runtime = ((double)(end - start)*1000) / CLOCKS_PER_SEC;

    printf("Runtime: %f Miliseconds\n", runtime);

    return 0;
}
