#include <iostream>
#include <ctime>
using namespace std;

void game(){
    cout<<"####  GUESS THE NUMBER  ####"<<endl;
    int lb,hb;
    cout<<"\nProvide with the range in which you want to guess the number"<<endl;
    cout<<"The lowerbound : ";
    cin>>lb;
    cout<<"The higherbound : ";
    cin>>hb;

    srand(time(0)); 
    int random = lb + (rand()%(hb-lb+1)) ;
    
    //cout<<"random number generated : "<<random<<endl;
    
    int attempt;
    cout<<"Enter the number of attempts for your guesses : ";
    cin>>attempt;
    int chance=attempt;
    
    cout<<"Guess the Number between "<<lb<<" and "<<hb<<endl;

    for(int i=0;i<attempt;i++){
        int guess;
        cin>>guess;
        if(!cin){
            cout<<"Invalid integer input"<<endl;
            break;
        }
        else{
            if(guess > random){
                cout<<"The number you guessed is higher"<<endl;
            }
            else if(guess < random){
                cout<<"The number you guessed is lower"<<endl;
            }
            else{
                cout<<"Hurray!! You guessed it right !!"<<endl;
                break;
            }
            cout<<"----  "<<chance-1<<" guesses left  ----"<<endl;
            chance--;
            
        }
        if(i==(attempt-1)){
            cout<<"Better Luck next time"<<endl;
        }
    }
    cout<<"\nPress 1 to start again or press any other key to Exit "<<endl;
}

int main() {
    // Write C++ code here
    game();
    int play;
    cin>>play;
    while(play==1){
        game();
        cin>>play;
    }
    cout<<"Game Ended !!";
    return 0;
}
