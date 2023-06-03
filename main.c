#include <stdio.h>
#include <math.h>

char player[11][1025] = {0};
char judge[11] = {0};
int playerNumbers = 0;
int cround;

int whoWin(int round) {
    int winer = 0, playerOne = 0, playerTwo = 0;
    if (round == 0)
        return 1;
    else if (round == 1) {
        for (int i = playerTwo + 1; i <= playerNumbers; i++) {
            if (player[round][i] > 'o' && player[round][i] < 't') {
                playerOne = i;
                break;
            }
        }
        for (int i = playerOne + 1; i <= playerNumbers; i++) {
            if (player[round][i] > 'o' && player[round][i] < 't') {
                playerTwo = i;
                break;
            }
        }
        if (player[round][playerOne] == player[round][playerTwo]) {
            switch (judge[cround - round + 1]) {
                case 's':
                    winer = playerOne;
                    break;
                case 'b':
                    winer = playerTwo;
                    break;
            }
        } else {
            switch (player[round][playerOne]) {
                case 'r':
                    switch (player[round][playerTwo]) {
                        case 'p':
                            winer = playerTwo;
                            break;
                        case 's':
                            winer = playerOne;
                            break;
                    }
                    break;
                case 'p':
                    switch (player[round][playerTwo]) {
                        case 'r':
                            winer = playerOne;
                            break;
                        case 's':
                            winer = playerTwo;
                            break;
                    }
                    break;
                case 's':
                    switch (player[round][playerTwo]) {
                        case 'p':
                            winer = playerOne;
                            break;
                        case 'r':
                            winer = playerTwo;
                            break;
                    }
                    break;
            }
        }
        return winer;
    } else {
        for (int time = (int) pow(2, round) / 2; time > 0; --time) {
            for (int i = playerTwo + 1; i <= playerNumbers; i++) {
                if (player[round][i] > 'o' && player[round][i] < 't') {
                    playerOne = i;
                    break;
                }
            }
            for (int i = playerOne + 1; i <= playerNumbers; i++) {
                if (player[round][i] > 'o' && player[round][i] < 't') {
                    playerTwo = i;
                    break;
                }
            }
            if (player[round][playerOne] == player[round][playerTwo]) {
                switch (judge[cround - round + 1]) {
                    case 's':
                        player[round - 1][playerOne] = player[round][playerOne];
                        break;
                    case 'b':
                        player[round - 1][playerTwo] = player[round][playerTwo];
                        break;
                }
            } else {
                switch (player[round][playerOne]) {
                    case 'r':
                        switch (player[round][playerTwo]) {
                            case 'p':
                                player[round - 1][playerTwo] = player[round][playerTwo];
                                break;
                            case 's':
                                player[round - 1][playerOne] = player[round][playerOne];
                                break;
                        }
                        break;
                    case 'p':
                        switch (player[round][playerTwo]) {
                            case 'r':
                                player[round - 1][playerOne] = player[round][playerOne];
                                break;
                            case 's':
                                player[round - 1][playerTwo] = player[round][playerTwo];
                                break;
                        }
                        break;
                    case 's':
                        switch (player[round][playerTwo]) {
                            case 'p':
                                player[round - 1][playerOne] = player[round][playerOne];
                                break;
                            case 'r':
                                player[round - 1][playerTwo] = player[round][playerTwo];
                                break;
                        }
                        break;
                }
            }
        }
        round--;
        return whoWin(round);
    }
}


//Rock(r) Paper(p) Scissors(s) game
int main() {
    int round = 0;
    int temp;
    scanf("%d", &playerNumbers);
    getchar();
    temp = playerNumbers;

    // Count the number of games by single elimination
    while (temp != 1) {
        temp /= 2;
        round++;
    }

    for (int i = 1; i <= playerNumbers; i++) {
        scanf("%c", &player[round][i]);
    }
    getchar();

    //If there is a tie, the one with the smaller(s) ID or the larger(b,bigger) ID wins
    for (int i = 1; i <= round; i++) {
        scanf("%c", &judge[i]);
    }
    cround = round;
    printf("%d", whoWin(round));
    return 0;
}
