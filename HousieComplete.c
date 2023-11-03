#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3
#define M 9

int i,j,k;

int main(){
    int nextNumber, player1Won = 0, player2Won = 0, speed;
    int player1[3][9] = {0}, player2[3][9] = {0};
    int numbers[100] = {0};

    printf("WELCOME TO PLAY HOUSIE..........\n");
    printf("Press Enter Twice to start the game");
    getchar();
    //printTicket(player1);
    //printTicket(player2);

    initializePlayersTicket(player1);
    initializePlayersTicket(player2);

    printf("Player 1's Ticket:- \n");
    printTicket(player1);
    printf("Player 2's Ticket:- \n");
    printTicket(player2);

    printf("Enter speed from 1 (Fastest) to 10 (Slowest): ");
    scanf("%d", &speed);
    if(speed<0 || speed>10){
        speed = 1;
        printf("Invalid speed. Taking speed 1 by default.....\n");
    }

    printf("Enter Enter Twice to start calling the numbers.....\n");

    while(!(player1Won || player2Won)){
         //nextNumber = getValidRandomNumber( numbers );
         //printf("Current Number: %d \n\n", nextNumber);
         printf("caller enter current valid no. :");
         scanf("%d",&nextNumber);
         numbers[nextNumber-1] = 1;

        crossNumber(nextNumber, player1);
        crossNumber(nextNumber, player2);

        printf("Player 1's Ticket:- \n");
        printTicket(player1);
        printf("Player 2's Ticket:- \n");
        printTicket(player2);

        printCrossedNumbers(numbers);


        player1Won = didPlayerWin(player1);
        player2Won = didPlayerWin(player2);


        if(player1Won && player2Won){
            printf("DRAW...");
        }
        else if(player1Won){
            printf("Player 1 Won....");
        }
        else if(player2Won){
            printf("Player 2 Won....");
        }

        Sleep(speed*100);
    }






    return 0;
}

void printCrossedNumbers(int numbers[100]){
    printf("Numbers already crossed:- ");
    for(i=0;i<100;i++){
        if(numbers[i] == 1){
            printf("%d ", i+1);
        }
    }
    printf("\n\n");
}

void printTicket(int player[N][M]){
    printf("\n");
    for(k=0;k<46;k++){
        printf("-");
    }
    printf("\n");
    for(i=0;i<N;i++){
        printf("|");
        for(j=0;j<M;j++){
            if(player[i][j] == -1){
                printf("  X |");
            }
            else if(player[i][j] == 0){
                printf("    |");
            }
            else{
                printf("%3d |", player[i][j]);
            }
        }
        printf("\n");
        for(k=0;k<46;k++){
            printf("-");
        }
        printf("\n");
    }
    printf("\n");
}

int didPlayerWin(int player[N][M]){
    int count = 0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(player[i][j]>0)      count++;
        }
    }
    if(count == 0)  return 1;
    return 0;
}


void initializePlayersTicket(int player[N][M]){
    printf("Creating new ticket...\n");
    int x, numberOfValues;

    for(j=0;j<9;j++){
        numberOfValues = (getRandomNumber()%2);
        if(numberOfValues==0){
            player[1][j] = getRandomNumberInRange(j*10, (j*10) + 9);
        }
        else{
            player[0][j] = getRandomNumberInRange(j*10, (j*10) + 9);
            player[2][j] = getRandomNumberInRange(j*10, (j*10) + 9);

            while(player[0][j] == player[2][j]){
                player[0][j] = getRandomNumberInRange(j*10, (j*10) + 9);
                player[2][j] = getRandomNumberInRange(j*10, (j*10) + 9);
            }

        }
    }

}

void crossNumber(int target, int player[N][M]){
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if( target == player[i][j]){
                player[i][j] = -1;

            }
        }
    }
}

int getRandomNumberInRange(int lower, int upper){
    int x = getRandomNumber();
    while(!(lower<=x && x<=upper)){
        x -= 10;
    }
    return x;
}

int getValidRandomNumber( int numbers[100] ){
    int index = getRandomNumber();
    while(numbers[index] == 1){
        index++;
        if(index>=100){
            index -= 100;
        }
    }
    return index+1;

}

int getRandomNumber() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    Sleep(100);
    return milliseconds%100;
}
