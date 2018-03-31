#include <bits/stdc++.h>
using namespace std;

#include "hexadecimal.h"

int main(){

    vector<short> memory;

    for(int i = 0; i < 1000; i++)
        memory.push_back(rand()%256);

    int a = 1;
    cout<<"  ";
    for(int i = 0; i < memory.size(); i++){
        if(a == 16){ a = 1; cout<<endl;}
        cout<<DtoH(memory[i])<<setw(4);
        a++;
    }
    return 0;
}
