#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
char s[3][3];
int x,y;
void Display()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%2c ",s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void User(char user)
{
    int j;
    printf("Enter your position : ");
    scanf("%d",&x);
    while(*(s[0]+x-1)!='_')
    {
        printf("This position is already in use!!!\nPlease Enter Some other position : ");
        scanf("%d",&x);
        j=0;
        continue;
    }
    *(s[0]+x-1) = user;
}
void Comp(char comp,char user)
{
    int j,k=0;
    printf("Wait computer is moving its move\n");
    Sleep(1000);
    for(j=0;j<3;j++)
    {

        if(s[j][0]==user && s[j][1]==user && s[j][2]!=comp && s[j][2]!=user && k==0)
        {
            s[j][2] = comp;
            k=1;
            break;
        }
        else if(s[j][0]==user && s[j][2]==user && s[j][1]!=comp && s[j][1]!=user && k==0)
        {
            s[j][1] = comp;
            k=1;
            break;
        }
        else if(s[j][1]==user && s[j][2]==user && s[j][0]!=comp && s[j][0]!=user && k==0)
        {
            s[j][0] = comp;
            k=1;
            break;
        }
        else if(s[0][j]==user && s[1][j]==user && s[2][j]!=comp && s[2][j]!=user && k==0)
        {
             s[2][j] = comp;
             k=1;
             break;
        }
        else if(s[0][j]==user && s[2][j]==user && s[1][j]!=comp && s[1][j]!=user && k==0)
        {
             s[1][j] = comp;
             k=1;
             break;
        }
        else if(s[1][j]==user && s[2][j]==user && s[0][j]!=comp && s[0][j]!=user && k==0)
        {
             s[0][j] = comp;
             k=1;
             break;
        }
    }
    for(j=0;j<3;j++)
    {
        if(s[0][j]==comp && s[1][j]==comp && s[2][j]!=comp && s[2][j]!=user && k==0)
        {
            s[2][j]=comp;
            k=1;
            break;
        }
        else if(s[0][j]==comp && s[2][j]==comp && s[1][j]!=comp && s[1][j]!=user && k==0)
        {
            s[1][j]=comp;
            k=1;
            break;
        }
        else if(s[1][j]==comp && s[2][j]==comp && s[0][j]!=user && s[0][j]!=user && k==0)
         {
             s[0][j]=comp;
             k=1;
             break;
         }
        else if(s[j][0]==comp && s[j][1]==comp && s[j][2]!=user && s[j][2]!=comp && k==0)
          {
             s[j][2]=comp;
             k=1;
             break;
          }
        else if(s[j][0]==comp && s[j][2]==comp && s[j][1]!=comp && s[j][1]!=user && k==0)
          {
             s[j][1]=comp;
             k=1;
             break;
          }
        else if(s[j][1]==comp && s[j][2]==comp && s[j][0]!=comp && s[j][0]!=user && k==0)
           {
             s[j][0]=comp;
             k=1;
             break;
           }
    }
    if(s[0][0]==comp && s[1][1]==comp && s[2][2]=='_' && k==0)
     {
         s[2][2]=comp;
         k=1;
     }
    else if(s[0][0]==comp && s[2][2]==comp && s[1][1]=='_' && k==0)
      {
         s[1][1]=comp;
         k=1;
      }
    else if(s[2][2]==comp && s[1][1]==comp && s[0][0]=='_' && k==0)
        {
            s[0][0]=comp;
            k=1;
        }
    else if(s[0][3]==comp && s[1][1]==comp && s[2][0]=='_' && k==0)
       {
         s[2][0]=comp;
         k=1;
       }
    else if(s[0][0]==comp && s[2][0]==comp && s[1][1]=='_' && k==0)
       {
            s[1][1]=comp;
            k==1;
       }
    else if(s[2][0]==comp && s[1][1]==comp && s[0][2]=='_' && k==0)
       {
         s[0][2]=comp;
         k=1;
       }
    if(s[0][0]==user && s[1][1]==user && s[2][2]=='_' && k==0) //////////////////////////////////////
     {
         s[2][2]=comp;
         k=1;
     }
    else if(s[0][0]==user && s[2][2]==user && s[1][1]=='_' && k==0)
      {
         s[1][1]=comp;
         k=1;
      }
    else if(s[2][2]==user && s[1][1]==user && s[0][0]=='_' && k==0)
        {
            s[0][0]=comp;
            k=1;
        }
    else if(s[0][3]==user && s[1][1]==user && s[2][0]=='_' && k==0)
       {
         s[2][0]=comp;
         k=1;
       }
    else if(s[0][0]==user && s[2][0]==user && s[1][1]=='_' && k==0)
       {
            s[1][1]=comp;
            k==1;
       }
    else if(s[2][0]==user && s[1][1]==user && s[0][2]=='_' && k==0)
       {
         s[0][2]=comp;
         k=1;
       }
    if(k==0)
    {
        srand(time(0));
        y = (rand()%(8-1+1))+1;
        while(*(s[0]+y-1)!='_')
        {
            srand(time(0));
            y = (rand()%(8-1+1))+1;
        }
        *(s[0]+y-1)=comp;
    }
}
int winner (char X,char Y)
{
    int i;
    if((s[0][0]==X && s[0][1]==X && s[0][2]==X) || (s[1][0]==X && s[1][1]==X && s[1][2]==X) || (s[2][0]==X && s[2][1]==X && s[2][2]==X) || (s[0][0]==X && s[1][0]==X && s[2][0]==X) || (s[0][1]==X && s[1][1]==X && s[2][1]==X)||(s[0][2]==X &&s[1][2]==X && s[2][2]==X))
        return 2;
    else if((s[0][0]==Y && s[0][1]==Y && s[0][2]==Y) || (s[1][0]==Y && s[1][1]==Y && s[1][2]==Y) || (s[2][0]==Y && s[2][1]==Y && s[2][2]==Y) || (s[0][0]==Y && s[1][0]==Y && s[2][0]==Y) || (s[0][1]==Y && s[1][1]==Y && s[2][1]==Y)||(s[0][2]==Y && s[1][2]==Y && s[2][2]==Y))
        return 1;
    else if((s[0][0]==X && s[1][1]==X && s[2][2]==X)||(s[0][2]==X && s[1][1]==X && s[2][0]==X))
        return 2;
    else if((s[0][0]==Y && s[1][1]==Y && s[2][2]==Y)||(s[0][2]==Y && s[1][1]==Y && s[2][0]==Y))
        return 1;
    else{
        int i,j=0;
        for(i=0;i<9;i++)
        {
            if(*(s[0]+i)=='_')
                j++;
        }
        if(9-j==9)
            return 3;
        else
            return 0;
    }
}
void winnerList(int l,char *me,char *you){
    static int i=0;
    int j,k,m;
    char name[100][3][100];
    strcpy(name[i][0],me);
    strcpy(name[i][1],you);
    i++;
    printf("-------------->>>>>>>>>>>>>> LEADERBOARD <<<<<<<<<<<<<-------------\n\n");
    printf("Player 1                      Player 2                      Winner\n\n");
    for(j=0;j<i;j++)
    {
        for(k=0;k<3;k++)
        {
            if(k==2 && j==i-1)
            {
                if(l==1)
                {
                    strcpy(name[j][2],name[j][1]);
                    printf("%s",name[j][1]);
                }
                else if(l==2)
                {
                    strcpy(name[j][2],name[j][0]);
                    printf("%s",name[j][0]);
                }
                else
                {
                     name[j][2][0]='T';
                     name[j][2][1]='i';
                     name[j][2][2]='e';
                     printf("%s",name[j][2]);
                }
             }
             else
                printf("%-30s",name[j][k]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    char ch,comp,user,user2,c,A,Y;
    int i,k=0,a,b,d,l=0;
    do{
    system("cls");
    printf("----------------------->>>>>>>>>>>>>>>>>>>>>>> Tic-Tac-Toe  <<<<<<<<<<<<<<<<<<<<<<<<-------------------------\n\n");
    printf("Welcome To The Most Played 2D Game And a Sort Of For Using X And O\n\n");
    printf("Rules of the Game are : \n1)Each Player will be entering the numbering to put respective X and O in the desired position.\n2)Player who gets a combination of 3 same characters either diagonal or horizontally or vertically will be declared as the winner.\n\n");
    printf("Enjoy The Game! Be a Winner!");
    printf("\nLet's Start the game\n\n");
    printf("To start the game Press any key : ");
    scanf("%c",&ch);
    printf("\n");
    printf("Initial position Board for Tic-Tac-Toe\n\n");
    int j;
    char d='1';
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            s[i][j]=d;
            d++;
        }
    }
    Display();
    printf("Tic Tac Toe board initially \n\n");
    for(i=0;i<9;i++)
    {
        *(s[0]+i)='_';
    }
    Display();
    printf("Press '*' to play with other person\nPress 'C' to play with computer\n");
    scanf(" %c",&user2);
    if(user2=='C' || user2=='c')
    {
        char me[100],you[]={"Computer"};
        printf("Enter your name : ");
        fflush(stdin);
        gets( me);
        printf("Please Tell what you want to take O or X : ");
        scanf(" %c",&user);
        if(user == 'X')
            comp = 'O';
        else
            comp = 'X';
        printf("\nPress 1 to do the Toss for 1st player to start its move\nPress 2 To Start computer 1st time\nPress any other key To Direct Start : ");
        scanf("%d",&a);
        printf("\n");
        if(a==1)
        {
            srand(time(0));
            b = (rand()%(2-1+1))+1;
            if(b==1)
            {
                printf("You won the Toss\n");
                printf("Enter your position according to the board : ");
                scanf("%d",&x);
                *(s[0]+x-1)=user;
                Display();
                printf("Wait computer is moving its move\n");
                Sleep(1000);
                srand(time(0));
                y = (rand()%(8-1+1))+1;
                while(y==x)
                {
                    srand(time(0));
                    y = (rand()%(8-1+1))+1;
                }
                *(s[0]+y-1)=comp;
                Display();
            }
            else
            {
                printf("Computer won the Toss\n");
                srand(time(0));
                y = (rand()%(8-1+1))+1;
                *(s[0]+y-1)=comp;
                Display();
                printf("Enter your position according to the board : ");
                scanf("%d",&x);
                while(x==y)
                {
                    printf("This position is in use\nEnter another position : ");
                    scanf("%d",&x);
                    continue;
                }
                *(s[0]+x-1)=user;
                Display();
            }
        }
        else if(a==2)
        {
            printf("You choose to start 1st time\n");
            srand(time(0));
            y = (rand()%(8-1+1))+1;
            *(s[0]+y-1)=comp;
            Display();
            printf("Enter your position according to the board : ");
            scanf("%d",&x);
            while(x==y)
            {
                printf("This position is in use\nEnter another position : ");
                scanf("%d",&x);
                continue;
            }
            *(s[0]+x-1)=user;
            Display();
        }
        else{
            printf("You have decide to start 1st\n");
            printf("Enter your position according to the board : ");
            scanf("%d",&x);
            *(s[0]+x-1)=user;
            Display();
            printf("Wait computer is moving its move\n");
            Sleep(1000);
            srand(time(0));
            y = (rand()%(8-1+1))+1;
            while(y==x)
            {
                srand(time(0));
                y = (rand()%(8-1+1))+1;
            }
            *(s[0]+y-1)=comp;
            Display();
        }
        while(l==0)
        {
            if(b==1)
            {
                User(user);
                Display();
                l = winner(user,comp);
                if(l!=0)
                    break;
                Comp(comp,user);
                Display();
                l = winner(user,comp);
                if(l!=0)
                    break;
            }
            else{
                Comp(comp,user);
                Display();
                l = winner(user,comp);
                if(l!=0)
                    break;
                User(user);
                Display();
                l = winner(user,comp);
                if(l!=0)
                    break;
            }
        }

        if(l==1)
            printf("%s win the game\n",you);
        else if(l==2)
            printf("%s win the game\n",me);
        else
            printf("Match is tie\n");
        printf("Press L to see the LEADERBOARD else Press any other key : ");
        fflush(stdin);
        scanf("%c",&Y);
        if(Y=='L' || Y=='l');
            winnerList(l,me,you);
    }
    else if(user2=='*')
    {
        char me[100],you[100];
        printf("Enter name of 1st player : ");
        fflush(stdin);
        gets( me);
        printf("Enter name of 2nd player : ");
        fflush(stdin);
        gets( you);
        printf("\nChoose your symbol( O or X ) respective to the player1 : ");
        scanf(" %c",&user);
        if(user=='X' || user=='x')
            comp = 'O';
        else if(user=='O' || user=='o')
            comp = 'X';
        else
            printf("\nPlease choose either X or O to play\n");
        printf("Any player Please enter any single digit to do the toss : ");
        fflush(stdin);
        scanf("%c",&A);
        printf("\n");
        srand(time(0));
        b = (rand()%(2-1+1))+1;
        if(b==1)
        {
            printf("%s won the toss\n",me);
            while(l==0)
            {
                printf("%s Enter your position according to the board : ",me);
                scanf("%d",&x);
                while(*(s[0]+x-1)!='_')
                {
                    printf("Sorry this position is in use\nPlease Enter some other position\n");
                    scanf("%d",&x);
                }
                *(s[0]+x-1)=user;
                Display();
                l=winner(user,comp);
                if(l!=0)
                    break;
                printf("%s Enter your position according to the board : ",you);
                scanf("%d",&y);
                while(*(s[0]+y-1)!='_')
                {
                    printf("Sorry this position is in use\nPlease Enter some other position\n");
                    scanf("%d",&y);
                }
                *(s[0]+y-1)=comp;
                Display();
                l= winner(user,comp);
                if(l!=0)
                    break;
            }
            if(l==1 || l==2 || l==3)
            {
                if(l==1)
                    printf("%s win the game\n",you);
                else if(l==2)
                    printf("%s win the game\n",me);
                else
                    printf("Match is tie\n");
                printf("Press L to see the LEADERBOARD else Press any other key : ");
                fflush(stdin);
                scanf("%c",&Y);
                if(Y=='L' || Y=='l');
                    winnerList(l,me,you);
            }
        }
    }
    else
        printf("Please choose correct option!! ThankYou\n\n");
    printf("Press Y to play again else any key\n");
    fflush(stdin);
    scanf(" %c",&c);
    l=0;
    }while(c=='Y' || c=='y');
    return 0;
}
