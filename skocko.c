#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void guessComb(int guess[]) {
    printf("Enter four numbers from 1 to 6:\n");
    while (scanf("%d%d%d%d", &guess[0], &guess[1], &guess[2], &guess[3]) != 4) {
        printf("Invalid input! Please enter four numbers from 1 to 6:\n");
        while (getchar() != '\n');  // Clear the input buffer
    }
}

int isElement(int i, int indexRed[], int redCount) {
    for (int j = 0; j < redCount; j++) {
        if (indexRed[j] == i) {
            return 1;
        }
    }
    return 0;
}


void printColors(int guess[], int comb[]) {
    char reds[4], yellows[4];
    int yellowCount = 0;
    int redCount = 0;
    int indexRed[4];

    int numOfEach[7] = {0}; // Initialize to zero
    for (int i = 0; i < 4; i++) {
        numOfEach[comb[i]]++;
    }


    for (int i = 0; i < 4; i++) {
        if (guess[i] == comb[i]) {
            reds[redCount] = 'C';
            indexRed[redCount] = i;
            redCount++;
        }
    }
    reds[redCount] = '\0';
    if (redCount == 4) {
        printf("Congratulations! You guessed the combination.\n");
        return;
    }

    
    for (int i = 0; i < 4; i++) {
        if (isElement(i, indexRed, redCount) == 1) {
            continue;
        }
        for(int j = 0; j < 4; j++) {
            if(isElement(j, indexRed, redCount)) {
                continue;
            }
            if(comb[i] == guess[j]) {
                if (numOfEach[comb[i]] > 0) {
                    yellows[yellowCount] = 'Z';
                    numOfEach[comb[i]]--;
                    yellowCount++;
                }
            }
        }
    }
    yellows[yellowCount] = '\0';
    printf("%s%s\n", reds, yellows);
}


int isEqual(int guess[], int comb[]) {
    for (int i = 0; i < 4; i++) {
        if (guess[i] != comb[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int guess[4], comb[4];
    srand(time(0));

    for (int i = 0; i < 4; i++) {
        comb[i] = rand() % 6 + 1;
    }

    printf("Welcome to the Skocko Game!\n");

    comb[0] = 3, comb[1] = 1, comb[2] = 2, comb[3] = 3;

    do {
        guessComb(guess);
        printColors(guess, comb);
    } while (!isEqual(guess, comb));

    return 0;
}
