#include <iostream>
#include <vector>
using namespace std;

bool AND(bool a, bool b){ return a && b; }
bool OR(bool a, bool b){ return a || b; }
bool NOT(bool a){ return !a; }

void truthTable() {
    cout << "\nA B | A&B | A|B | !A\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<i<<" "<<j<<" | "
                <<AND(i,j)<<"   | "
                <<OR(i,j)<<"   | "
                <<NOT(i)<<"\n";
        }
    }
}

void tautologyCheck() {
    int alwaysTrue = 1, alwaysFalse = 1;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            bool result = (i || j);
            if(!result) alwaysTrue = 0;
            if(result) alwaysFalse = 0;
        }
    }

    if(alwaysTrue) cout<<"Tautology\n";
    else if(alwaysFalse) cout<<"Contradiction\n";
    else cout<<"Neither\n";
}

void predicateLogic() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) cin>>arr[i];

    int universal = 1, existential = 0;

    for(int i=0;i<n;i++){
        if(arr[i] % 2 != 0) universal = 0;
        if(arr[i] % 2 == 0) existential = 1;
    }

    cout<<"All even (∀): "<<universal<<"\n";
    cout<<"At least one even (∃): "<<existential<<"\n";
}

void FSM() {
    string s;
    cout<<"Enter binary string: ";
    cin>>s;

    int state = 0;

    for(char c : s){
        if(state == 0){
            if(c == '0') state = 0;
            else state = 1;
        }
        else{
            if(c == '0') state = 1;
            else state = 0;
        }
    }
    if(state == 0) cout<<"Accepted (Even number of 1s)\n";
    else cout<<"Rejected\n";
}
int main() {
    int choice;
    while(true){
        cout<<"\n1.Truth Table\n2.Tautology\n3.Predicate Logic\n4.FSM\n5.Exit\nChoice: ";
        cin>>choice;
        switch(choice){
            case 1: truthTable(); break;
            case 2: tautologyCheck(); break;
            case 3: predicateLogic(); break;
            case 4: FSM(); break;
            case 5: return 0;
            default: cout<<"Invalid\n";
        }
    }
}
