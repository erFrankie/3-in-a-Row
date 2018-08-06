#include <stdio.h>
#include <windows.h>

void initializeM(char M[3][3]);
void Showboard(char M[3][3],int current_player);
int AskforMove(char M[3][3], int turn,int current_player, int* correct_move);
int Comprobation(char M[3][3], int turn);




int main(){
    char M[3][3];
    int winner = 0;// winner==0 => we are still playing ; winner==1 => player 1 wins ; winner==2 => player 2 wins ; winner==3 => Ties
    int turn = 0,current_player = 1,correct_move = 0,counter,i;// player will be 1 or 2 ; counter is used to show a message if the position selected is not valid
        //i is just loop variable
    initializeM(M);

   while(winner == 0){
        counter = 0;
       do{
            system("cls");
            if(counter == 1 ){
                printf("Select a valid position\n");
            }

            Showboard(M,current_player);
            correct_move = 0;
            turn = AskforMove(M,turn,current_player,&correct_move);
            counter = 1;
       }while( correct_move == 1);



       if(turn >= 5){
            winner = Comprobation(M,turn);
       }

       if(winner == 0){
            if(current_player == 1){
                current_player = 2;
            }else{
                current_player = 1;
            }
       }else if(winner != 3){
            for(i = 0; i < 3 ; i++){
                system("cls");
                Sleep(250);
                Showboard(M,current_player);
                Sleep(500);
            }
       }
        system("cls");
   }

        switch(winner){
            case 1: printf("Player 1 wins!");break;
            case 2: printf("Player 2 wins!");break;
            case 3: printf("Tie");break;
        }
        printf("\n\n\n\n\n");

system("pause");
return 0;
}

//When we start the game, all the possitions are ' '
void initializeM(char M[3][3]){

    int i,j;

    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            M[i][j] = ' ';
        }
    }

}

void Showboard(char M[3][3],int current_player){

    printf("              Player %i turn\n",current_player);
    printf("     Column 1    Column 2     Column 3\n");
    printf("  |-----------|------------|-----------|\n");
    printf("  |           |            |           |\n");
    printf("  |     %c     |     %c      |     %c     |  Row 1\n",M[0][0],M[0][1],M[0][2]);
    printf("  |           |            |           |\n");
    printf("  |-----------|------------|-----------|\n");
    printf("  |           |            |           |\n");
    printf("  |     %c     |     %c      |     %c     |  Row 2\n",M[1][0],M[1][1],M[1][2]);
    printf("  |           |            |           |\n");
    printf("  |-----------|------------|-----------|\n");
    printf("  |           |            |           |\n");
    printf("  |     %c     |     %c      |     %c     |  Row 3\n",M[2][0],M[2][1],M[2][2]);
    printf("  |           |            |           |\n");
    printf("  |-----------|------------|-----------|\n");

}
int AskforMove(char M[3][3], int turn,int current_player, int* correct_move){
    int Row,Col;

    printf("Introduce your choice\n");

    printf("Row: ");
    scanf("%i",&Row);

    printf("Column: ");
    scanf("%i",&Col);

    if(M[Row-1][Col-1] != ' '){
        *correct_move = 1; //Not correct
    }else{
        switch (current_player){
            case 1: M[Row-1][Col-1] = 'X';break;
            case 2: M[Row-1][Col-1] = 'O';break;
        }
        turn++;
    }

return turn;
}

int Comprobation(char M[3][3], int turn){
    int winner = 0;

    //Comprobation number 1
        if(M[0][0] != ' '){

            if((M[0][0] == M[0][1] && M[0][0] == M[0][2] )  || ( M[0][0] == M[1][0] && M[0][0] == M[2][0])){

                switch(M[0][0]){
                    case 'X': winner = 1;break;
                    case 'O': winner = 2;break;
                }
            }

        }


    //Comprobation Number 2
        if(winner == 0){

            if(M[2][2] != ' '){
                if((M[2][2] == M[2][1] && M[2][2] == M[2][0]) || (M[2][2] == M[1][2] && M[2][2] == M[0][2])){
                    switch(M[2][2]){
                        case 'X': winner = 1;break;
                        case 'O': winner = 2;break;
                    }
                }


            }
        }
     //Comprobation Number 3

        if(winner == 0){

            if(M[1][1] != ' '){

                if((M[1][1] == M[0][1] && M[1][1] == M[2][1]) || (M[1][1] == M[1][0] && M[1][1] == M[1][2]) || (M[1][1] == M[2][0] &&  M[1][1] == M[0][2]) || (M[1][1] == M[0][0] && M[1][1] == M[2][2]) ){
                    switch(M[1][1]){
                        case 'X': winner = 1;break;
                        case 'O': winner = 2;break;
                    }
                }
            }

        }
        if(winner == 0 && turn == 9){
            winner = 3;
        }




return winner;
}


