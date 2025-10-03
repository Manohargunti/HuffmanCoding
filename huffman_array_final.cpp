#include <iostream>
using namespace std;

// Structure for Huffman Tree node
struct HuffNode {
    char sign;       // character symbol
    int freqVal;     // frequency value
    int leftSide;    // index of left child
    int rightSide;   // index of right child
};

// Array to store tree nodes
HuffNode forest[200];
int totalBranches; // total nodes created

// Find two smallest frequency nodes not yet merged
void findSmallestTwo(int limit, int &small1, int &small2) {
    small1 = small2 = -1;
    for (int i = 0; i < limit; i++) {
        if (forest[i].freqVal == -1) continue; // already merged

        if (small1 == -1 || forest[i].freqVal < forest[small1].freqVal) {
            small2 = small1;
            small1 = i;
        } 
        else if (small2 == -1 || forest[i].freqVal < forest[small2].freqVal) {
            small2 = i;
        }
    }
}

// Preorder traversal to print Huffman codes (character : code)
void generateCodes(int rootIndex, char currentCode[], int depth) {
    if (rootIndex == -1) return;

    // If leaf node (actual character)
    if (forest[rootIndex].leftSide == -1 && forest[rootIndex].rightSide == -1) {
        currentCode[depth] = '\0'; // end string
        cout << forest[rootIndex].sign << ": " << currentCode << "\n";
        return;
    }

    // Go left (add '0')
    currentCode[depth] = '0';
    generateCodes(forest[rootIndex].leftSide, currentCode, depth + 1);

    // Go right (add '1')
    currentCode[depth] = '1';
    generateCodes(forest[rootIndex].rightSide, currentCode, depth + 1);
}

int main() {
    int charCount;
    cout << "Enter number of unique characters: ";
    cin >> charCount;

    char symbolList[100]; // input characters
    int freqList[100];    // input frequencies

    cout << "Enter characters: ";
    for (int i = 0; i < charCount; i++) {
        cin >> symbolList[i];
    }

    cout << "Enter their frequencies: ";
    for (int i = 0; i < charCount; i++) {
        cin >> freqList[i];
    }

    // Step 1: Initialize leaf nodes
    for (int i = 0; i < charCount; i++) {
        forest[i].sign = symbolList[i];
        forest[i].freqVal = freqList[i];
        forest[i].leftSide = -1;
        forest[i].rightSide = -1;
    }
    totalBranches = charCount;

    // Step 2: Build Huffman tree
    for (int i = 0; i < charCount - 1; i++) {
        int smallestA, smallestB;
        findSmallestTwo(totalBranches, smallestA, smallestB);

        forest[totalBranches].sign = '$'; // internal node
        forest[totalBranches].freqVal = forest[smallestA].freqVal + forest[smallestB].freqVal;
        forest[totalBranches].leftSide = smallestA;
        forest[totalBranches].rightSide = smallestB;

        forest[smallestA].freqVal = -1;
        forest[smallestB].freqVal = -1;

        totalBranches++;
    }

    int rootNode = totalBranches - 1;

    // Step 3: Print codes with character names
    cout << "\nHuffman Codes (Preorder Traversal):\n\n";
    char codeBuffer[50];
    generateCodes(rootNode, codeBuffer, 0);

    return 0;
}
