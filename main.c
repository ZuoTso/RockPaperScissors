#include <stdio.h>
#include <math.h>

char player[11][1025]={0};
char judge[11]={0};
int player_num = 0;
int cround;

int who_win (int round) {
    int winer = 0, one = 0, two = 0;
    if(round==0)return 1;
    if (round == 1) {
        for (int i = two + 1; i <= player_num; i++) {
            if (player[round][i] > 'o' && player[round][i] < 't') {
                one = i;
                break;
            }
        }
        for (int i = one + 1; i <= player_num; i++) {
            if (player[round][i] > 'o' && player[round][i] < 't') {
                two = i;
                break;
            }
        }
        if (player[round][one] == player[round][two]) {
            switch (judge[cround-round+1]) {
                case 's':
                    winer = one;
                    break;
                case 'b':
                    winer = two;
                    break;
            }
        } else {
            switch (player[round][one]) {
                case 'r':
                    switch (player[round][two]) {
                        case 'p':
                            winer = two;
                            break;
                        case 's':
                            winer = one;
                            break;
                    }
                    break;
                case 'p':
                    switch (player[round][two]) {
                        case 'r':
                            winer = one;
                            break;
                        case 's':
                            winer = two;
                            break;
                    }
                    break;
                case 's':
                    switch (player[round][two]) {
                        case 'p':
                            winer = one;
                            break;
                        case 'r':
                            winer = two;
                            break;
                    }
                    break;
            }
        }
        return winer;
    } else {
        for (int time = (int)pow(2, round) / 2; time > 0; --time) {
            for (int i = two + 1; i <= player_num; i++) {
                if (player[round][i] > 'o' && player[round][i] < 't') {
                    one = i;
                    break;
                }
            }
            for (int i = one + 1; i <= player_num; i++) {
                if (player[round][i] > 'o' && player[round][i] < 't') {
                    two = i;
                    break;
                }
            }
            if (player[round][one] == player[round][two]) {
                switch (judge[cround - round + 1]) {
                    case 's':
                        player[round - 1][one] = player[round][one];
                        break;
                    case 'b':
                        player[round - 1][two] = player[round][two];
                        break;
                }
            } else {
                switch (player[round][one]) {
                    case 'r':
                        switch (player[round][two]) {
                            case 'p':
                                player[round - 1][two] = player[round][two];
                                break;
                            case 's':
                                player[round - 1][one] = player[round][one];
                                break;
                        }
                        break;
                    case 'p':
                        switch (player[round][two]) {
                            case 'r':
                                player[round - 1][one] = player[round][one];
                                break;
                            case 's':
                                player[round - 1][two] = player[round][two];
                                break;
                        }
                        break;
                    case 's':
                        switch (player[round][two]) {
                            case 'p':
                                player[round - 1][one] = player[round][one];
                                break;
                            case 'r':
                                player[round - 1][two] = player[round][two];
                                break;
                        }
                        break;
                }
            }
        }
        round--;
        return who_win(round);
    }
}
int main() {
    int round = 0;
    int temp;
    scanf("%d", &player_num);
    getchar();
    temp=player_num;
    while (temp != 1) {
        temp /= 2;
        round++;
    }
    for (int i = 1; i <= player_num ; i++) {
        scanf("%c", &player[round][i]);
    }
    getchar();
    for (int i = 1; i <= round ; i++) {
        scanf("%c", &judge[i]);
    }
    cround=round;
    printf("%d", who_win(round));
    return 0;
}
