#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void initiate(int test[4][4]){
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            test[i - 1][j - 1] = 0;
        }
    }
}

void draw(int state[4][4]){
    printf("\n-------------------------------------\n");
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){    // composing the format
            if(j==1){
                if(state[i-1][j-1]>0&&state[i-1][j-1]<10){
                    printf("|   %d    |",state[i-1][j-1]);//打印int*数据用%n
                }
                if(state[i-1][j-1]>=10&&state[i-1][j-1]<100){
                    printf("|   %d   |",state[i-1][j-1]);//打印int*数据用%n
                }
                if(state[i-1][j-1]>=100&&state[i-1][j-1]<1000){
                    printf("|  %d   |",state[i-1][j-1]);//打印int*数据用%n
                }
                if(state[i-1][j-1]>=1000){
                    printf("|  %d  |",state[i-1][j-1]);//打印int*数据用%n
                }
                if(state[i-1][j-1]==0){
                    printf("|        |");//打印int*数据用%n
                }
            }
            else{
                if(state[i-1][j-1]>0&&state[i-1][j-1]<10){
                    printf("   %d    |",state[i-1][j-1]);//打印int*数据用%n
                }
                if(state[i-1][j-1]>=10&&state[i-1][j-1]<100){
                    printf("   %d   |",state[i-1][j-1]);//打印int*数据用%n
                }
                if(state[i-1][j-1]>=100&&state[i-1][j-1]<1000){
                    printf("  %d   |",state[i-1][j-1]);//打印int*数据用%n
                }
                if(state[i-1][j-1]>=1000){
                    printf("  %d  |",state[i-1][j-1]);//打印int*数据用%n
                }
                if(state[i-1][j-1]==0){
                    printf("        |");//打印int*数据用%n
                }
            }
            if(j==4){
                //printf("\n****************************\n");
                printf("\n-------------------------------------\n");
            }
        }
    }
    printf("\n");
}

void birth(int state[4][4]){
    int b=0;
    int pos_x[16];
    int pos_y[16];
    int x=0;
    //printf("%d %d %d\n",b,c,end);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(state[i-1][j-1]==0){
                x=x+1;
                pos_x[x-1]=i-1;
                pos_y[x-1]=j-1;

            }
        }
    }
    //printf("%d\n",x);
    int a=time(NULL);
    //printf("%d\n",a);
    srand(a);
    b = rand() % x;
    state[pos_x[b]][pos_y[b]]=2;
    //printf("%d %d",b,c);
    //printf("%d %d\n",pos_x[b],pos_y[b]);
    Sleep(50);
    draw(state);
    x=0;
    for(int i=1;i<=16;i++){
        pos_x[i-1]=0;
        pos_y[i-1]=0;
    }
}

int game_over(int state[4][4]){
    int jud=0;
    for(int i=1;i<=4;i++) {
        for (int j = 1; j <= 4; j++) {
            if(state[i-1][j-1]==0){
                jud=1;
            }
        }
    }
    if(jud==0){
        return 1;
    }
}

void play(int test[4][4],int* endp) {
    printf("press x to end game manually.\n");
    //printf("Use w s a d to control the movements \nI'm not yet smart enough to determain whether you lose!\nHowver, if the board is filled with numbers and you make an invalid movement, you will be considered lost.\nHave fun, my friend :)\n ");
    int inp;
    int over=game_over(test);
    int numb[4];
    int x = 0;
    int last[16];
    int change=0;
    int count=0,nun=0;
    *endp=0;
    //scanf("%s",&inp);  //确实可以在switch语句中读取输入的字符
    //printf("%d",inp);
    inp = getch();
    Sleep(50);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            last[count]=test[i-1][j-1];
            count=count+1;
        }
    }
    switch (inp) {
        case 'x':
            *endp=1;
            break;//end game manually
        case 'w':   //getch 可以不转化为数值
            //printf("%c",'w');
            for (int j = 1; j <= 4; j++) {
                for (int i = 1; i <= 4; i++) {
                    if (test[i - 1][j - 1] != 0) {
                        numb[x] = test[i - 1][j - 1];
                        x = x + 1;
                    }
                }
                for (int k = 1; k <= x; k++) {
                    test[k - 1][j - 1] = numb[k - 1];
                }
                if (x < 4) {
                    for (int k = x + 1; k <= 4; k++) {
                        test[k - 1][j - 1] = 0;
                    }
                }
                for (int k = 1; k <= 4; k++) {
                    numb[k] = 0;
                }
                x = 0;
            }
            for (int i = 2; i <= 4; i++) {
                for (int j = 1; j <= 4; j++) {
                    if (test[i - 1][j - 1] == test[i - 2][j - 1]) {
                        test[i - 2][j - 1] = 2 * test[i - 2][j - 1];
                        test[i - 1][j - 1] = 0;
                    }
                }
            }
            for (int j = 1; j <= 4; j++) {
                for (int i = 1; i <= 4; i++) {
                    if (test[i - 1][j - 1] != 0) {
                        numb[x] = test[i - 1][j - 1];
                        x = x + 1;
                    }
                }
                for (int k = 1; k <= x; k++) {
                    test[k - 1][j - 1] = numb[k - 1];
                }
                if (x < 4) {
                    for (int k = x + 1; k <= 4; k++) {
                        test[k - 1][j - 1] = 0;
                    }
                }
                for (int k = 1; k <= 4; k++) {
                    numb[k] = 0;
                }
                x = 0;
            }
            //draw(test);
            //Sleep(1000);
            for(int i=1;i<=4;i++){
                for(int j=1;j<=4;j++){
                    if(test[i-1][j-1]!=last[nun]){
                        change=1;
                        break;
                    }
                    nun=nun+1;
                }
            }
            nun=0;
            if(change==1){
                system("cls");
                birth(test);
            }
            if(change==0){
                system("cls");
                draw(test);
                if(over==1){
                    *endp=1;
                    break;    //end the game by rule
                }
            }

            break;
        case 's':
            for (int j=1;j<=4;j++){
                for(int i=4;i>=1;i--){
                    if(test[i-1][j-1]!=0){
                        numb[x]=test[i-1][j-1];
                        x=x+1;
                    }
                }
                for (int k=1;k<=x;k++){
                    test[4-k][j-1]=numb[k-1];
                }
                if(x<4){
                    for(int k=x+1;k<=4;k++){
                        test[4-k][j-1]=0;
                    }
                }

                for(int k=1;k<=4;k++){
                    numb[k]=0;
                }
                x=0;
            }
            for (int i=3;i>=1;i--){
                for (int j=1;j<=4;j++){
                    if (test[i-1][j-1]==test[i][j-1]){
                        test[i][j-1]=2*test[i-1][j-1];
                        test[i-1][j-1]=0;
                    }
                }
            }
            for (int j=1;j<=4;j++){
                for(int i=4;i>=1;i--){
                    if(test[i-1][j-1]!=0){
                        numb[x]=test[i-1][j-1];
                        x=x+1;
                    }
                }
                for (int k=1;k<=x;k++){
                    test[4-k][j-1]=numb[k-1];
                }
                if(x<4){
                    for(int k=x+1;k<=4;k++){
                        test[4-k][j-1]=0;
                    }
                }

                for(int k=1;k<=4;k++){
                    numb[k]=0;
                }
                x=0;
            }
            //draw(test);
            //Sleep(1000);
            for(int i=1;i<=4;i++){
                for(int j=1;j<=4;j++){
                    if(test[i-1][j-1]!=last[nun]){
                        change=1;
                        break;
                    }
                    nun=nun+1;
                }
            }
            nun=0;
            if(change==1){
                system("cls");
                birth(test);
            }
            if(change==0){
                system("cls");
                draw(test);
                if(over==1){
                    *endp=1;
                    break;    //end the game by rule
                }
            }

            break;
        case 'a':
            for (int i=1;i<=4;i++){
                for(int j=1;j<=4;j++){
                    if(test[i-1][j-1]!=0){
                        numb[x]=test[i-1][j-1];
                        x=x+1;
                    }
                }
                for (int k=1;k<=x;k++){
                    test[i-1][k-1]=numb[k-1];
                }
                if(x<4){
                    for(int k=x+1;k<=4;k++){
                        test[i-1][k-1]=0;
                    }
                }

                for(int k=1;k<=4;k++){
                    numb[k]=0;
                }
                x=0;
            }
            for (int j=2;j<=4;j++){
                for (int i=1;i<=4;i++){
                    if (test[i-1][j-1]==test[i-1][j-2]){
                        test[i-1][j-2]=2*test[i-1][j-1];
                        test[i-1][j-1]=0;
                    }
                }
            }
            for (int i=1;i<=4;i++){
                for(int j=1;j<=4;j++){
                    if(test[i-1][j-1]!=0){
                        numb[x]=test[i-1][j-1];
                        x=x+1;
                    }
                }
                for (int k=1;k<=x;k++){
                    test[i-1][k-1]=numb[k-1];
                }
                if(x<4){
                    for(int k=x+1;k<=4;k++){
                        test[i-1][k-1]=0;
                    }
                }

                for(int k=1;k<=4;k++){
                    numb[k]=0;
                }
                x=0;
            }
            for(int i=1;i<=4;i++){
                for(int j=1;j<=4;j++){
                    if(test[i-1][j-1]!=last[nun]){
                        change=1;
                        break;
                    }
                    nun=nun+1;
                }
            }
            nun=0;
            if(change==1){
                system("cls");
                birth(test);
            }
            if(change==0){
                system("cls");
                draw(test);
                if(over==1){
                    *endp=1;
                    break;    //end the game by rule
                }
            }

            break;
        case 'd':
            for (int i=1;i<=4;i++){
                for(int j=4;j>=1;j--){
                    if(test[i-1][j-1]!=0){
                        numb[x]=test[i-1][j-1];
                        x=x+1;
                    }
                }
                for (int k=1;k<=x;k++){
                    test[i-1][4-k]=numb[k-1];
                }
                if(x<4){
                    for(int k=x+1;k<=4;k++){
                        test[i-1][4-k]=0;
                    }
                }

                for(int k=1;k<=4;k++){
                    numb[k]=0;
                }
                x=0;
            }
            for (int j=3;j>=1;j--){
                for (int i=1;i<=4;i++){
                    if (test[i-1][j-1]==test[i-1][j]){
                        test[i-1][j]=2*test[i-1][j-1];
                        test[i-1][j-1]=0;
                    }
                }
            }
            for (int i=1;i<=4;i++){
                for(int j=4;j>=1;j--){
                    if(test[i-1][j-1]!=0){
                        numb[x]=test[i-1][j-1];
                        x=x+1;
                    }
                }
                for (int k=1;k<=x;k++){
                    test[i-1][4-k]=numb[k-1];
                }
                if(x<4){
                    for(int k=x+1;k<=4;k++){
                        test[i-1][4-k]=0;
                    }
                }

                for(int k=1;k<=4;k++){
                    numb[k]=0;
                }
                x=0;
            }
            for(int i=1;i<=4;i++){
                for(int j=1;j<=4;j++){
                    if(test[i-1][j-1]!=last[nun]){
                        change=1;
                        break;
                    }
                    nun=nun+1;
                }
            }
            nun=0;
            if(change==1){
                system("cls");
                birth(test);
            }
            if(change==0){
                system("cls");
                draw(test);
                if(over==1){
                    *endp=1;
                    break;    //end the game by rule
                }
            }
            break;
        default:
            system("cls");
            draw(test);
            break;
    }

}


int main() {
    int test[4][4];
    int sta=1;
    int* endp;
    int in;
    *endp=0;
    printf("This is 2048 V3.5.0! Enjoy a great game!\nNotice!!\n1.Please shift to English input mode before playing!\n2.Use w s a d to control the movements!\n\n");
    initiate(test);
    birth(test);
    while(*endp==0){
        play(test,endp);
    }
    printf("Game over my dear friend.\nPress 0 to exit.\n");
    Sleep(1000);
    in=getch();
    if(in==0){
        return 0;
    }
}