#include<iostream>
using namespace std;
char TicTacTao (char *player);
void checkWin(char *player,char board[3][3],char winner,int count,int &breakloop);
int main(){
int start;
cout<<"\nWelcome to the Mega Tic-Tac-Toe game! Let me introduce the rules to you."<<endl<<endl;
cout<<"We will have a 3x3 grid, where each grid itself is another 3x3 Tic-Tac-Toe board. Within each small Tic-Tac-Toe board, players play the regular Tic-Tac-Toe game"<<endl<<endl;
cout<<"Let's see what it looks like! "<<endl<<endl;
for(int l=0;l<3;l++){
    for(int k=0;k<3;k++){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<"_ ";
            }
        if(i==2) continue;
        cout<<"| ";
        }
    cout<<endl;
    }
cout<<" "<<endl;
}
cout<<endl<<endl;
cout<<"The winner of each small board will place their symbol on the corresponding position in the big grid. The first player to connect a line on the big grid wins the game. If there's no winner in small grid the symbol will be X."<<endl;
cout<<"Please let the players play the game of rock-paper-scissors first to decide who goes first and which part of the boards to play first."<<endl;
cout<<"The player who loses the game will  determine which grid they would like to play in for the next round and will make the first move."<<endl;
cout<<"Tip: If you win three consecutive games, you'd definetly be the winner!"<<endl<<endl;
cout<<"The number of each grid is"<<endl;
cout<<"1 2 3 \n4 5 6 \n7 8 9"<<endl<<endl;
cout<<"When you are ready, please press 1!"<<endl<<endl;

do{cin>>start;}while(start!=1);
int grid;
char winner;
char biggerGrid[3][3]={{'_','_','_'},{'_','_','_'},{'_','_','_'}};
int index[9][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
char player='A';
int breakloop=0;


for(int i=0;i<9;i++){
    cout<<"Please enter a number to decide which grid you want to start "<<endl;
    do{
    cin>>grid;}while(!(grid>0&&grid<10));
    while(biggerGrid[ index[ grid-1 ][0] ][ index[ grid-1 ][1] ]!='_'){
        cout<<"You choose the grid that has the result already! Please choose another one!"<<endl;
        cin>>grid;
    }
    winner=TicTacTao(&player);
    biggerGrid[ index[ grid-1 ][0] ][ index[ grid-1 ][1] ]=winner;
    checkWin(&player,biggerGrid,winner,i+1,breakloop);
    
    cout<<"Let's take a look at the whole big grid!"<<endl<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<biggerGrid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    if(breakloop){
        break;
    }
    if(breakloop!=1){
        cout<<"Let's move on to the next grid! "<<endl<<endl;
    }
}
  return 0;
}



char TicTacTao (char *player){
int count=0;
char board[3][3]={{'_','_','_'},{'_','_','_'},{'_','_','_'}};
int indexX,indexY;

while(true){

if(*player=='A'){
  cout<<"Please player A enter coordinates "<<endl;
  cin>>indexX>>indexY;
  while(!(board[indexX-1][indexY-1]=='_')){
    cout<<"You can't choose that place!!! Please try another one"<<endl;
    cin>>indexX>>indexY;
  };
  board[indexX-1][indexY-1]='O';
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cout<<board[i][j]<<" ";
      }
      cout<<endl;
    }
  *player='B';
  count++;

}else if(*player=='B'){

  cout<<"Please player B enter coordinates "<<endl;
  cin>>indexX>>indexY;
  while(!(board[indexX-1][indexY-1]=='_')){
    cout<<"You can't choose that place!!!  Please try another one"<<endl;
    cin>>indexX>>indexY;
  };
  board[indexX-1][indexY-1]='X';
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cout<<board[i][j]<<" ";
      }
      cout<<endl;
    }
  *player='A';
  count++;

}

if( (  board[0][0]!='_' &&((board[0][0]==board[0][1])&&(board[0][1]==board[0][2]) ) ||  board[1][0]!='_' &&( (board[1][0]==board[1][1])&&(board[1][1]==board[1][2]) )||  board[2][0]!='_' &&( (board[2][0]==board[2][1]) && (board[2][1]==board[2][2]) ) )){
    
    if(*player=='A'){
      cout<<"Player B won this grid!!"<<endl<<endl;
      return 'B';
    }else{
      cout<<"Player A won this grid!!"<<endl<<endl;
      return 'A';
    }
    
  }else if((  board[0][0]!='_' &&((board[0][0]==board[1][0])&&(board[1][0]==board[2][0])) || board[0][1]!='_' &&(board[0][1]==board[1][1])&&(board[1][1]==board[2][1]) || (board[0][2]!='_' )&&((board[0][2]==board[1][2])&&(board[1][2]==board[2][2])))){
   
    if(*player=='A'){
      cout<<"Player B won this grid!!"<<endl<<endl;
      return 'B';
    }else{
      cout<<"Player A won this grid!!"<<endl<<endl;
      return 'A';
    }
    
  }else if(( board[0][0]!='_' &&((board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))|| board[0][2]!='_' &&((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])))){
    
    if(*player=='A'){
      cout<<"Player B won this grid!!"<<endl<<endl;
      return 'B';
    }else{
      cout<<"Player A won this grid!!"<<endl<<endl;
      return 'A';
    }

  }else if(count==9){
    cout<<"\n\n\nThat's amazing... No one won the game... The big grid will be marked X "<<endl<<endl;
    return 'X';
  }

}

}





void checkWin(char *player,char board[3][3],char winner,int count,int &breakloop){

if( (  (board[0][0]!='_'&&board[0][0]!='X') &&((board[0][0]==board[0][1])&&(board[0][1]==board[0][2]) ) ||  (board[1][0]!='_'&&board[1][0]!='X') &&( (board[1][0]==board[1][1])&&(board[1][1]==board[1][2]) )||  (board[2][0]!='_'&&board[2][0]!='X') &&( (board[2][0]==board[2][1]) && (board[2][1]==board[2][2]) ) )){
    
    if(*player=='A'){
      cout<<"Congraduations!! Player B won!!"<<endl<<endl;
      breakloop=1;
      return ;
    }else{
      cout<<"Congraduations!! Player A won!!"<<endl<<endl;
      breakloop=1;
      return ;
    }
    
  }else if((  (board[0][0]!='_'&&board[0][0]!='X') &&((board[0][0]==board[1][0])&&(board[1][0]==board[2][0]))|| (board[0][1]!='_'&&board[0][0]!='X') &&(board[0][1]==board[1][1])&&(board[1][1]==board[2][1])|| (board[0][2]!='_'&&board[0][0]!='X') &&((board[0][2]==board[1][1])&&(board[1][1]==board[2][2])))){
   
   if(*player=='A'){
      cout<<"Congraduations!! Player B won!!"<<endl<<endl;
      breakloop=1;
      return ;
    }else{
      cout<<"Congraduations!! Player A won!!"<<endl<<endl;
      breakloop=1;
      return ;
    }
    
  }else if(( (board[0][0]!='_'&&board[0][0]!='X') &&((board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))||( board[0][2]!='_'&&board[0][2]!='X') &&((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])))){
    
    if(*player=='A'){
      cout<<"Congraduations!! Player B won!!"<<endl<<endl;
      breakloop=1;
      return ;
    }else{
      cout<<"Congraduations!! Player A won!!"<<endl<<endl;
      breakloop=1;
      return ;
    }

  }else if(count==9){
    
    cout<<"\n\nThat was amazing! Through out 9 games... No one won the game! What an intensive fight!"<<endl;
    breakloop=1;
    return ;

  }

}