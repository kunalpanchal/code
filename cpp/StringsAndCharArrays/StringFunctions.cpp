#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "My Random String";
    cout << str;

    str = "hello";

    //Size and length are same for string
    cout << "\nsize: " << str.size() << " length: " << str.length();

    str.append("as");
    cout << str;

    str.erase(5, 2); // (starting,size)

    for (int i = 0; i < str.size(); i++)
        cout << "\nat(i):" << str.at(i);

    cout << "\nsubstring finding :" << str.find("ell");

    str.push_back('a'); //returns void
    cout << "\nAfter pushing a : " << str;

    str.pop_back(); // returns void
    cout << "\nAfter pushing a : " << str;

    string str2 = "hello";
    cout << "\n" << str.compare(str2);
    return 0;
}