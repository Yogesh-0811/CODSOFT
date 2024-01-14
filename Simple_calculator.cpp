#include <iostream>
using namespace std;

void calculator(){
    char choice;
    float n1, n2;

    cin >> n1 >> choice >> n2;

  
    switch (choice) {
  
    case '+':
        cout << "Addition : "<<n1 + n2<<endl;
        break;

    case '-':
        cout << "Subtraction : "<<n1 - n2<<endl;
        break;

    case '*':
        cout << "Multiplication : "<<n1 * n2<<endl;
        break;

    case '/':
        cout << "Division : "<<n1 / n2<<endl;
        break;

    default:
        cout << "Invalid Operation. "<<endl;
    }
    cout<<"Press C to start again"<<endl;
}


int main()
{   
    cout<<"Enter in format : number1 'operation' number2"<<endl;
    cout<<"\nChoose :\n '+' for addition\n '-' for subtraction\n '*' for multiplication\n '/' for division"<<endl;
    calculator();
    char ch;
    cin>>ch;
    while(ch == 'C'||'c'){
        calculator();
        cin>>ch;
    }
    cout<<"--------END--------"<<endl;

    return 0;
}
