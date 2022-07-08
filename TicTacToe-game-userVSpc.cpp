
#include <iostream>
#include <string>


using namespace std;

#define SIZE 3  

     char board[SIZE][SIZE]; 

   void fill(){
          
          int number=1;
          for(int i=0;i<SIZE;i++){
             for(int j=0;j<SIZE;j++){
           board[i][j]=to_string(number).c_str()[0];
             
             number++;
          }
       }
    }

    void printboard(){
        cout<<endl;
        cout<<endl;
        cout<<"\t***welcome to tic-tac-toe game***"<<endl;
        cout<<"\t---------------------------------"<<endl;

            cout<<"\n---A--------B----C-----\n";
            for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
            //cout<<"\t\t";
            cout<<" | "<<board[i][j]<<" | ";
            }
            cout<<"\n-----------------------\n";
        }
    }

   void ismovevalid(){
         string input;
         while(true){
           cout<<endl;
           cout<<"##   where would you like to play?  ## "<<endl;
           cout<<endl;
           cin>>input;

           if(input != "10"){
                   char login = input.c_str()[0];
                   if(login>= '1' && login<= '9'){
                           int num_user = login - '0';
                           int index = num_user - 1  ;

                           int row = index / 3;
                           int col = index % 3;

                           char Square = board[row][col];
                           if(Square== 'x' || Square == 'o'){
                           cout<<"that the position is occcupied."<<endl;
                           }else{
                               
                               
                               cout<<"the player will play \t"<<num_user;
                               
                               
                               
                               
                               
                           board[row][col]= 'x';
                           break;
                           }
                      }else{
                      cout<<"\t\n";
                      cout<<"you need to play from 1 to 9 to continue this game!"<<endl;
                   }
           }else{
              cout<<"\t\n";
              
              
              cout<<"error:the user it is invalid."<<endl;
           }
         }
      }
                                                               
   void iswinner(){
       
          const char* winning[8]={  
                              "123",
                              "456",
                              "789",
                              "147",
                              "258",
                              "369",
                              "159",
                              "357"
                              };
               for(int i=0 ;i< 8 ;i++){
                  bool winner = true;
                  char previousgrid = '0';
                  const char*win=winning[i];

                  for(int index=0 ; index < SIZE; index++){
                    char character= win[index];

                    int num_user = character - '0';
                    int gridspace = num_user - 1 ;

                    int row=gridspace / SIZE;
                    int col=gridspace % SIZE;

                    char gridchar = board[row][col];
                    
                    if(previousgrid == '0'){
                        previousgrid = gridchar;
                        \
                        }else if(previousgrid==gridchar){
                          continue;
                        }else{
                        winner=false;
                        break;
                        }
                     }
                        if( winner ){
                        
                        cout<<"\a";
                        cout<<"********** we have a winner ! ********"<<endl;
                        cout<<"###########congratulations!!##########"<<endl<<previousgrid;
                        cout<<"\t\t\t\t\t"<<exit;
                        exit(0);
                        break;
                        
                   }
               }
            }
            
   void computerplayerturn(){
       srand(time(NULL));
       while(true){
        int computerchoice=( rand() % 9 ) +1 ;

        int row =(computerchoice-1 )/3;
        int col =(computerchoice-1 )%3;

        char Square=board[row][col];

        if(Square=='x' || Square == 'o'){
                
          continue;
        }else{
        cout<<"the computer will play\t"<<computerchoice;
        board[row][col]='o';
        break;
          }
        }
    }

int main()
{
   string name;
    cout<<"enter your name:"<<endl;
    cin>>name;
    cout<<"The Player Name is:"<<" "<<name ; 
     

     fill();
     printboard();
     iswinner();

         while(true ){
            ismovevalid();
            printboard();
            iswinner();

            computerplayerturn();
            printboard();
            iswinner();
            }
            return 0;
    }




//////////////////#BY_DEVELOPER_SNAKE//////////////////




