#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 2 // Size of the matrix for 3x3 Hill Cipher

void encrypt(int keyMatrix[][SIZE], int vector[], int result[]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            result[i] += keyMatrix[i][j] * vector[j];
        }
        result[i] %= 26; // Modulo 26 to keep within the range of letters
    }
}

int main() {
    int keyMatrix[SIZE][SIZE];
    printf("Enter the key matrix (3x3):\n");
    for (int i =0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }

    char plaintext[100];
    printf("Enter plaintext (uppercase letters only): ");
    scanf("%s", plaintext);

    int len = strlen(plaintext);
    int paddedLen = len;

    while (paddedLen % SIZE != 0) {
        paddedLen++;
    }

    int vector[SIZE], encryptedVector[SIZE];
    printf("Encrypted text: ");
    for (int i = 0; i < paddedLen; i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            vector[j] = (i + j < len) ? plaintext[i + j] - 'A' : 0;
        }

        encrypt(keyMatrix, vector, encryptedVector);

        for (int j = 0; j < SIZE; j++) {
            printf("%c", encryptedVector[j] + 'A');
        }
    }
    printf("\n");

    return 0;
}
