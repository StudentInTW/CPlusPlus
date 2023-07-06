#include <iostream>
#include<cstdlib>

using namespace std;

int main(void){
int n2;
int start,answer=8462,times=0;
cout<<"Welcome to Bulls and Cows Guessing Game!"<<endl;
cout<<"Please press 1 to start"<<endl;
do{cin>>start;}while(
    start!=1);
int check[4]={0};
cout<<"Please guess a 'four-digit' number!"<<endl;
do{ cin>>n2;}while(!(n2>=1000&&n2<=9999));
int A=0,B=0;
while(1){
    if(n2==answer){
        times++;
        cout<<"You spent only "<<times<<" times!"<<endl;
        break;
    }
    int run[4];
for(int i=3;i>=0;i--){
    run[i]=n2%10;
    n2/=10;
}
for(int i=3;i>=0;i--){
    for(int j=3;j>=0;j--){
        if(answer%10==run[i]){
            A++;
            break;
        }else if(answer%10==run[j]){
            if(check[i]==0){
                    check[i]=1;
                    B++;
            }else{
                break;
                }
        }else{}
    }
    answer/=10;
    for(int i=0;i<4;i++){
        check[i]=0;
    }
    }
times++;
cout<<A<<"A"<<B<<"B"<<endl;
cout<<"Please guess again!"<<endl;
answer=8462;
do{ cin>>n2;}while(!(n2>=1000&&n2<=9999));
A=B=0;
}
    return 0;
}