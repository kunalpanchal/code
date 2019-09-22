#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    //To make cin and cout faster for larger inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin,s);
    int flag=1;
    int jo=s.size();
    for(int j=0;j<(jo)&& flag==1;j++){
        flag=0;
        for(int i=0;i<(s.size()-1);i++){
            if(s.size()==0)
                break;
            if(s.at(i)==s.at(i+1))
            {  flag=1;
                if(s.size()>2)
                    s=s.substr(0,i)+s.substr(i+2,s.size());
                else s="";
            }
        }
    }
    if(s!="")
        cout<<s;
    else
        cout<<"Empty String";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}