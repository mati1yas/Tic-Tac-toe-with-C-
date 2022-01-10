#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <stdlib.h>
void resultChecker();
void display();
void reset();
char computer();
char defend();
char attack();
void menu();
int difficulty();
using namespace std;
int p=0;  // p play counter;
int level;
char ch,side; // character for representing play position
char comp,atk,def,game; // game variable to allow the user choose between with frnd and computer
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0 ;
char dis[][3]={'a','b','c','d','e','f','g','h','i'};
int main()
{


            menu:   // as return point to redisplay menu page
            menu(); // calls  menu function wich allow the user to choose between the with frnd and with computer
        if(game=='c'||game=='C'){
           side:
        cin>>side;
         if(side!='x'&&side!='X'&&side!='O'&&side!='o')
                {  system("cls");
                cout<<"wrong entry, please try Again "<<endl;
                 cout<<setw(48)<<" choser your side   O(first) or X(second)"<<endl;
                   goto side;
                }
        level=difficulty();
        }

        system("cls");
        if((game=='c'||game=='C')||(game=='f'||game=='F'))  // only displays the initial game if the right decision of game is made
         display();

         while(p<9||ch!='T'||ch!='t'){
                //check result
                 label:  // to check after every play made in the game result may even be announce in the middle of the game

   if ((dis[0][0]=='O'&&dis[0][1]=='O'&&dis[0][2]=='O')||
      (dis[1][0]=='O'&&dis[1][1]=='O'&&dis[1][2]=='O')||
      (dis[2][0]=='O'&&dis[2][1]=='O'&&dis[2][2]=='O')||
      (dis[0][0]=='O'&&dis[1][0]=='O'&&dis[2][0]=='O')||
      (dis[0][1]=='O'&&dis[1][1]=='O'&&dis[2][1]=='O')||
      (dis[0][2]=='O'&&dis[1][2]=='O'&&dis[2][2]=='O')||
      (dis[0][0]=='O'&&dis[1][1]=='O'&&dis[2][2]=='O')||
      (dis[0][2]=='O'&&dis[1][1]=='O'&&dis[2][0]=='O')){
          cout<<endl;
          if((game=='c'||game=='C')&&(side=='O'||side=='o'))
            cout<<setw(64)<< " YOU WON!!! "<<endl;
          else if((game=='c'||game=='C')&&(side=='X'||side=='x'))
          cout<<setw(64)<< " computer won!!! "<<endl;
            else
            cout<<setw(64)<<"player one won the game "<<endl;
             cin>>ch;
          if(ch=='t'||ch=='T'){   // to cut , reset ,and display the menu in the middle of the game
                system("cls");
                  cout<<"GAME EXIT!!"<<endl;
                break;
               }

          if(ch=='r') // if choice is r the game is reset or allowed to replay
              reset();
          if(ch=='M'||ch=='m'){
                 menu(); // to redisplay the menu
                 reset();
            }
             goto label;
          break;
      }

        else   if ((dis[0][0]=='X'&&dis[0][1]=='X'&&dis[0][2]=='X')||
      (dis[1][0]=='X'&&dis[1][1]=='X'&&dis[1][2]=='X')||
      (dis[2][0]=='X'&&dis[2][1]=='X'&&dis[2][2]=='X')||
      (dis[0][0]=='X'&&dis[1][0]=='X'&&dis[2][0]=='X')||
      (dis[0][1]=='X'&&dis[1][1]=='X'&&dis[2][1]=='X')||
      (dis[0][2]=='X'&&dis[1][2]=='X'&&dis[2][2]=='X')||
      (dis[0][0]=='X'&&dis[1][1]=='X'&&dis[2][2]=='X')||
      (dis[0][2]=='X'&&dis[1][1]=='X'&&dis[2][0]=='X')){// prints the result depending on the winner
            cout<<endl;
            cout<<endl;
            if((game=='c'||game=='C')&&(side=='O'||side=='o'))
            cout <<setw(64)<< "COMPUTER WON THE GAME !! "<<endl;
            else if((game=='c'||game=='C')&&(side=='X'||side=='x'))
               cout<<setw(64)<< " YOU WON!!! "<<endl;
            else
             cout<<"player two won the game "<<endl;
             cout<<endl;
             cout<<endl;
             cin>>ch;
             if(ch=='x'){   // to cut , reset ,and display the menu in the middle of the game
                cout<<"GAME EXIT!1"<<endl;
                break;
               }
            if(ch=='r')  // reset
              reset();
            if(ch=='M'||ch=='m'){
                 menu(); // to redisplay the menu
                 reset();
            }
             goto label;
             break;

      }
         else if(p==9){
              cout<<endl;
              cout<<endl;
              cout<<setw(58)<<"The game is DRAW ,Please play again !!"<<endl;
              cout<<endl;
             cout<<endl;
             cin>>ch;
             if(ch=='t'||ch=='T'){    // to cut , reset ,and display the menu in the middle of the game
                cout<<"GAME EXIT!"<<endl;
                break;
               }
             if(ch=='r')
              reset();if(ch=='M'||ch=='m'){
                 menu(); // to redisplay the menu
                 reset();
            }

             goto label;
              break;
         }

        // to swithch between  plaer one and player two or computer
        // with freind
            if ((game=='f'||game=='F')&&p%2==0){
                   cout<<"player O(1)"<<endl;
                   cin.ignore();
                    cin >>ch;}


            else if(p%2!=0&&(game=='f'||game=='F')){
                  cout<<"player X(2)"<<endl;
                    cin >>ch;
            }


          //with computer

          if (p%2==0&&(game=='c'||game=='C')&&(side=='O'||side=='o')){  // choose to play first o
                   cout<<"player O(1)"<<endl;
                    cin >>ch;}
            else if((game=='c'||game=='C')&&p%2!=0&&(side=='O'||side=='o')) {

              cout<<"computer"<<endl;
              ch=computer();}

                //choose to play second  x

             else if((game=='c'||game=='C')&&p%2==0&&(side=='X'||side=='x')) {

              cout<<"computer"<<endl;
              ch=computer();}

              else if(p%2!=0&&(side=='X'||side=='x')&&(game=='c'||game=='C')){
                  cout<<"player X(2)"<<endl;
                    cin >>ch;
         }
              else if(game!='c'&&game!='C'&&game!='f'&&game!='F')
                {
                cout<<"wrong entry, please try Again "<<endl;
                   cin>>game;
                goto menu;

              }


       switch (ch){
            case 'a':
                if (a==0){
                p++;

                a++;

                system("cls");
                    if (p%2==0)
                    dis[0][0]='X';
                    else
                      dis[0][0]='O';


             display();
           goto label;

         }
         else
            cout<<"you entered the same twice"<<endl;

                   break;
            case 'b':
                    //new
         if(b==0){
                    b++;
                    p++;

                   system("cls");
                   if (p%2==0)
                      dis[0][1]='X';
                   else
                      dis[0][1]='O';
                      //new
          display();
        goto label;
         }
         else
            cout<<"the same twice "<<endl;
                     break;
            case 'c':
         if(c==0){
                   c++;
                    p++;

                   system("cls");
                   if (p%2==0)
                      dis[0][2]='X';
                   else
                      dis[0][2]='O';
                      //new
                display();
        goto label;
         }
         else
               cout<<"the same twice "<<endl;

                     break;

            case 'd':

                  if(d==0){
                    d++;
                    p++;

                   system("cls");
                   if (p%2==0)
                      dis[1][0]='X';
                   else
                      dis[1][0]='O';
                      //new

         display();
         goto label;
        }
             else
                     cout<<"the same twice "<<endl;

                   break;
            case 'e':
                  if(e==0){
                    e++;
                    p++;

                   system("cls");
                   if (p%2==0)
                      dis[1][1]='X';
                   else
                      dis[1][1]='O';
                      //new

         display();
        goto label;
        }
        else
             cout<<"the same twice "<<endl;

                break;

            case 'f':

                  if(f==0){
                    f++;
                    p++;

                   system("cls");
                   if (p%2==0)
                      dis[1][2]='X';
                   else
                      dis[1][2]='O';
                      //new
          display();
        goto label;
            }
            else
                 cout<<"the same twice "<<endl;
                     break;

            case 'g':
                  if(g==0){
                    g++;
                    p++;

                   system("cls");
                   if (p%2==0)
                      dis[2][0]='X';
                   else
                      dis[2][0]='O';
                      //new
            display();
         goto label;
        }
        else
             cout<<"the same twice "<<endl;
                   break;
            case 'h':
           if(h==0){
                   h++;
                    p++;

                   system("cls");
                   if (p%2==0)
                      dis[2][1]='X';
                   else
                      dis[2][1]='O';
                      //new
         display();

         goto label;


           }
           else
             cout<<"the same twice "<<endl;


                     break;
            case 'i':
                  if(i==0){
                        i++;
                    p++;

                   system("cls");
                   if (p%2==0)
                      dis[2][2]='X';
                   else
                      dis[2][2]='O';
                      //new
        display();
        goto label;
         }

         else
             cout<<"the same twice "<<endl;

                     break;
        case 'r':
        case 'R':

                reset();
                break;
        case 't':
        case 'T':
                  system("cls");
                cout<<"GAME EXIT!!"<<endl;
               goto  exit;
                break;
        case 'm':
        case 'M':
                reset(); // resets the game before displaying the menu displaye
                goto menu;

                break;

        default :
                cout<<"invalid input "<<endl;

                 break;

       }

       exit:
           if(ch=='t'||ch=='T')
         break;

}






//void resultChecker(){



  return 0;
}


void display(){


       cout<<setw(58)<<"Tic Tac Toe "<<endl;
         cout<<setw(58)<<"Have fun !!"<<endl;
           cout<<endl;
           if(level==1)
           cout<<setw(58)<<"EASY LEVEL "<<endl;
            else if(level==2)
            cout<<setw(58)<<"MEDIUM  LEVEL "<<endl;
             else if(level==3)
             cout<<setw(58)<<"HARD LEVEL "<<endl;

           cout<<endl;

       cout<<setw(50)<<"   |"<<"   |   "<<endl;
      cout<<setw(48)<<dis[0][0]<<" | "<<dis[0][1]<<" | "<<dis[0][2]<<endl;
       cout<<setw(50)<<"___|"<<"___|___"<<endl;
       cout<<setw(50)<<"   |"<<"   |   "<<endl;

       cout<<setw(48)<<dis[1][0]<<" | "<<dis[1][1]<<" | "<<dis[1][2]<<endl;
       cout<<setw(50)<<"___|"<<"___|___"<<endl;
       cout<<setw(50)<<"   |"<<"   |   "<<endl;
       cout<<setw(48)<<dis[2][0]<<" | "<<dis[2][1]<<" | "<<dis[2][2]<<endl;
       cout<<setw(50)<<"   |"<<"   |   "<<endl;

          cout<<endl;
      cout<<setw(68)<<"[R]replay       [T]Exit       [M]Menu"<<endl;
}

void reset(){
         a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
         p=0;
       dis[0][0]='a';dis[0][1]='b';dis[0][2]='c' ;dis[1][0]='d' ;dis[1][1]='e' ;dis[1][2]='f';dis[2][0]='g';dis[2][1]='h';
       dis[2][2]='i';
          system("cls");

          display();
       /*
        display code is deleted from here
      */
}


char computer(){





              attack();
             if(def=='n') // if the return from attack is nothing it calls for defence function
               defend();

             comp=def;


       if(dis[1][1]=='e'){ // plays the game e position if it is not cought

        comp='e';
        srand(time(0));  // to generate random choice that depends on time
         int cent=1+rand()%3;

         if(level==2&&(cent==2||cent==1))  // if the level it takes center depending onthe random numbeer
          goto label;
         if((p==1||p==0)&&level==3)  // if the random number generated is two the computer plays center otherwise other position
          goto label;
        }






       //if(p!=1&&dis[1][1]!='e')
         //comp='f';

      if(def=='n'){ /* if there is no return from the two attack and defence function
                   the computer tries to build up a game by choosing of the four corners */
        if(level!=3){   // if the game is not level 3 the positions are choosen randomly
       swi:    // as label to back if the random choice made cought befor
        srand(time(0));  // to generate random choice that depends on time
         int num=1+rand()%8; // generates number between four and one

        switch(num){
    case 1:

        if(dis[0][0]=='a'){
                comp='a';
                break;}
            else
                goto swi;


    case 2:
            if (dis[0][2]=='c'){
                comp='c';
                break;}
            else
                goto swi;

    case 3:
            if (dis[2][2]=='i'){
                comp='i';
                break;}
            else
                goto swi;


    case 4:
            if(dis[0][1]=='b'){
                comp='b';
                 break;}
           else
                goto swi;

    case 5:
            if (dis[2][0]=='g'){
                comp='g';
                break;}
            else
                goto swi;

    case 6:
            if (dis[2][1]=='h'){
                comp='h';
                break;}
            else
                goto swi;
    case 7:
            if(dis[1][0]=='d'){
                comp='d';
                break;}
            else
                goto swi;
    case 8:
             if(dis[1][2]=='f'){
                comp='f';
                break;}
           else
                goto swi;
        }
        }

        else{  // this is played only if the level is 3 to make the game harder

           if(dis[0][0]=='a')
                comp='a';

           else if (dis[0][2]=='c')
                comp='c';

            else if (dis[2][2]=='i')
                comp='i';

            else if(dis[0][1]=='b')
                comp='b';

           else  if (dis[2][0]=='g')
                comp='g';

           else  if (dis[2][1]=='h')
                comp='h';

             else if(dis[1][0]=='d')
                comp='d';

            else  if(dis[1][2]=='f')
                comp='f';


      }

      }
     label:
      return comp;
}

char defend(){
       def='n';
      // defenceeee

     if (dis[0][0]=='O'&&dis[0][1]=='O'&&dis[0][2]=='c')
          def='c';
      else if (dis[0][0]=='O'&&dis[0][1]=='b'&&dis[0][2]=='O')
           def='b';
      else if (dis[0][0]=='a'&&dis[0][1]=='O'&&dis[0][2]=='O')
           def='a';

     // second row
    else if(dis[1][0]=='O'&&dis[1][1]=='O'&&dis[1][2]=='f') //has to be three
         def='f';
    else if(dis[1][0]=='O'&&dis[1][1]=='e'&&dis[1][2]=='O')
         def='e';
    else if(dis[1][0]=='d'&&dis[1][1]=='O'&&dis[1][2]=='O')
         def='d';
    // third row
      else if(dis[2][0]=='O'&&dis[2][1]=='O'&&dis[2][2]=='i')
               def='i'  ;
      else if(dis[2][0]=='O'&&dis[2][1]=='h'&&dis[2][2]=='O')
                def='h' ;
      else if(dis[2][0]=='g'&&dis[2][1]=='O'&&dis[2][2]=='O')
                 def='g' ;

   // first column
      else if(dis[0][0]=='a'&&dis[1][0]=='O'&&dis[2][0]=='O')
            def='a';
      else if(dis[0][0]=='O'&&dis[1][0]=='d'&&dis[2][0]=='O')
             def='d' ;
      else if(dis[0][0]=='O'&&dis[1][0]=='O'&&dis[2][0]=='g')
               def='g' ;
       //second column
      else if(dis[0][1]=='b'&&dis[1][1]=='O'&&dis[2][1]=='O')
                   def='b' ;
      else if(dis[0][1]=='O'&&dis[1][1]=='e'&&dis[2][1]=='O')
                   def='e' ;
      else if(dis[0][1]=='O'&&dis[1][1]=='O'&&dis[2][1]=='h')
                    def='h' ;
               //third column
      else if (dis[0][2]=='c'&&dis[1][2]=='O'&&dis[2][2]=='O')
                    def='c' ;
      else if (dis[0][2]=='O'&&dis[1][2]=='f'&&dis[2][2]=='O')
                       def='f' ;
      else if (dis[0][2]=='O'&&dis[1][2]=='O'&&dis[2][2]=='i')
                    def='i' ;
              // first diagonal
      else if (dis[0][0]=='a'&&dis[1][1]=='O'&&dis[2][2]=='O')

                   def='a' ;
      else if (dis[0][0]=='O'&&dis[1][1]=='e'&&dis[2][2]=='O')
                     def='e' ;
      else if (dis[0][0]=='O'&&dis[1][1]=='O'&&dis[2][2]=='i')
                    def='i' ;
         // second diagonal
      else if (dis[0][2]=='c'&&dis[1][1]=='O'&&dis[2][0]=='O')
                      def='c' ;
      else if (dis[0][2]=='O'&&dis[1][1]=='e'&&dis[2][0]=='O')
                       def='e' ;
      else if (dis[0][2]=='O'&&dis[1][1]=='O'&&dis[2][0]=='g')
                    def='g' ;

    return def;
}
char attack(){

         def='n';
      if (dis[0][0]=='X'&&dis[0][1]=='X'&&dis[0][2]=='c')
           def='c';
      if (dis[0][0]=='X'&&dis[0][1]=='b'&&dis[0][2]=='X')
           def='b';
      if (dis[0][0]=='a'&&dis[0][1]=='X'&&dis[0][2]=='X')
           def='a';

     // second row
    if(dis[1][0]=='X'&&dis[1][1]=='X'&&dis[1][2]=='f') //has to be three
         def='f';
    if(dis[1][0]=='X'&&dis[1][1]=='e'&&dis[1][2]=='X')
         def='e';
    if(dis[1][0]=='d'&&dis[1][1]=='X'&&dis[1][2]=='X')
         def='d';
    // third row
      if(dis[2][0]=='X'&&dis[2][1]=='X'&&dis[2][2]=='i')
               def='i'  ;
      if(dis[2][0]=='X'&&dis[2][1]=='h'&&dis[2][2]=='X')
                def='h' ;
      if(dis[2][0]=='g'&&dis[2][1]=='X'&&dis[2][2]=='X')
                 def='g' ;

   // first colume
      if(dis[0][0]=='a'&&dis[1][0]=='X'&&dis[2][0]=='X')
            def='a';
      if(dis[0][0]=='X'&&dis[1][0]=='d'&&dis[2][0]=='X')
             def='d' ;
      if(dis[0][0]=='X'&&dis[1][0]=='X'&&dis[2][0]=='g')
               def='g' ;
       //second column

      if(dis[0][1]=='b'&&dis[1][1]=='X'&&dis[2][1]=='X')
                   def='b' ;
      if(dis[0][1]=='X'&&dis[1][1]=='e'&&dis[2][1]=='X')
                   def='e' ;
      if(dis[0][1]=='X'&&dis[1][1]=='X'&&dis[2][1]=='h')
                    def='h' ;
               //third column
      if (dis[0][2]=='c'&&dis[1][2]=='X'&&dis[2][2]=='X')
                    def='c' ;
      if (dis[0][2]=='X'&&dis[1][2]=='f'&&dis[2][2]=='X')
                       def='f' ;
      if (dis[0][2]=='X'&&dis[1][2]=='X'&&dis[2][2]=='i')
                    def='i' ;
              // first diagonal
      if (dis[0][0]=='a'&&dis[1][1]=='X'&&dis[2][2]=='X')
                   def='a' ;
      if (dis[0][0]=='X'&&dis[1][1]=='e'&&dis[2][2]=='X')
                     def='e' ;
      if (dis[0][0]=='X'&&dis[1][1]=='X'&&dis[2][2]=='i')
                    def='i' ;
         // second diagonal
      if (dis[0][2]=='c'&&dis[1][1]=='X'&&dis[2][0]=='X')
                      def='c' ;
      if (dis[0][2]=='X'&&dis[1][1]=='e'&&dis[2][0]=='X')
                       def='e' ;
      if (dis[0][2]=='X'&&dis[1][1]=='X'&&dis[2][0]=='g')
                    def='g' ;



    return def;
 }


void menu(){

         system("cls");
          cout<<endl;
         cout<<endl;
         cout<<setw(65)<<"Tic Tac Toe "<<endl;
         cout<<setw(65)<<"Have fun !!"<<endl;
           cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<setw(58)<<"**********************"<<"     "<<"****************************"<<endl;
         cout<<setw(58)<<"*  [F] with friend   *"<<"     "<<"*   [C] with computer      *"<<endl;
         cout<<setw(58)<<"**********************"<<"     "<<"****************************"<<endl;
          cout<<setw(58);
          cin>>game;
          system("cls");
           cout<<endl;
           cout<<endl;

        cout<<endl;
           cout<<endl;
          cout<<setw(48)<<" choser your side   O(first) or X(second)"<<endl;





}

int difficulty(){



               system("cls");
              enter:
          cout<<setw(48)<<"**********************"<<endl;
          cout<<setw(48)<<"*  choose difficulty *"<<endl;
          cout<<setw(48)<<"**********************"<<endl;
          cout<<setw(45)<<" 1. Easy   "<<endl;
          cout<<setw(45)<<" 2. Medium "<<endl;
          cout<<setw(45)<<" 3. Hard   "<<endl;


            cin>>level;
          if(level==1||level==2||level==3)
            return level;
          else {
                system("cls");
              cout<<"please enter the difficulty Again!!"<<endl;
               cin>>level;
          }
          cin.clear();
             cin.ignore(10000,'\n');
             goto enter;


}















