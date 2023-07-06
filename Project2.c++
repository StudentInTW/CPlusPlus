#include <iostream>
#include<cstdlib>
#include <ctime>
using namespace std;
int randomNumberGenetor(int ,int );
int main(void){

cout<<"Welcome to Game 3! It's the game no one has ever desiged before. Please have fun!"<<endl;
cout<<"Please enter 1 when you are ready!"<<endl;

int start;
do{cin>>start;}while(
    start!=1);
cout<<endl<<endl;
int max=100,min=1,answer,guess,times=0;
cout<<"Range is "<<min<<"-"<<max<<endl;
  answer=randomNumberGenetor(max, min);

cout<<"Answer has beem set. Now it's your turn to guess number!"<<endl;
cout<<endl<<endl;

cout<<"Your answer is  ";
do{cin>>guess;}while(
    !(guess>=min&&guess<=max));
int storeMax,storeMin;
int check[2]={0};
while (1){   
    if (times==0){
        if(guess > answer){
        check[1]=1;
        storeMax=max;
        max=guess-1;
        times++;
        }else if(guess < answer){
        check[0]=1;
        storeMin=min;
        min=guess+1;
        times++;
        }else{
            cout<<"Correct answer!"<<endl;
            times++;
            cout<<"You have only guessed "<<times<<" times!"<<endl;
            break;
        }
    cout<<"Sorry! You didn't get it right! Now the range is "<<min<<" - "<<max<<endl<<endl;
    cout<<"Please guess again!"<<endl<<endl;
    
    cout<<"Your answer is  ";
    do{cin>>guess;}while(
    !(guess>=min&&guess<=max));
    cout<<endl<<endl;
    }
  
    






    if(guess > answer){
        if(check[1]==0){
            if(min!=1){
                min=storeMin;
                check[0]=0;
                
                times++;
            }
            
            check[1]=1;
            storeMax=max;
            max=guess-1;
            times++;    
           
                answer=randomNumberGenetor(max, min);
        }else{
            storeMax=max;
            max=guess-1;
            times++;
        }

    }else if(guess < answer){
        
        if(check[0]==0){
        if(max!=100){
            max=storeMax;
            check[1]=0;
            answer=randomNumberGenetor(max, min);
        }
        check[0]=1;
         storeMin=min+1;
            min=guess;
            times++;
                  
                    
        }else{
            storeMin=min;
            min=guess+1;
            times++;
        }
        
    }else{
            cout<<"Correct answer!"<<endl;
            times++;
             cout<<"You have only guessed "<<times<<" times!"<<endl;
             cout<<"By the way, one who can get it correct within 5 times is said to be a genius!";
            break;
        }
    
    
    cout<<"Sorry! You didn't get it right! Now the range is  "<<min<<" - "<<max<<endl<<endl;
    
    cout<<"Please guess again!"<<endl<<endl;;
    
    cout<<"Your answer is ";
    do{cin>>guess;}while(
    !(guess>=min&&guess<=max));
    cout<<endl<<endl;
    }
    
    
    return 0;}

int randomNumberGenetor(int max,int min){
  int num,range =max-min+ 1;
  srand(time(0));
   num = (rand() % range) + min;
    return num;
}

