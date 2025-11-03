#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;
typedef long long ll;
int main(){
    fstream my_file("./hello.txt", ios::binary|ios::out);
    if (!my_file.is_open()){cerr<<"File NOT FOUND!!!\n";}
    else{
        int num = 19993432;
        string s = "19993432";
        my_file.write((s.data()), sizeof(s));
    }
    my_file.close();

    my_file.open("./hello.txt", ios::binary|ios::in);
    if (!my_file.is_open()){cerr<<"File NOT FOUND!!!\n";}
    else{
        my_file.seekg(0,ios::end);
        ll size = my_file.tellg();
        my_file.seekg(0,ios::beg);
        cout<<size<<endl;
        // int num = 199;
        vector<char> buffer(size);
        my_file.read((buffer.data()), size);
        for (char c: buffer){cout<<bitset<8>(c)<<endl;}
        cout<<"+++++++++++"<<endl;
        for (int c: buffer){cout<<bitset<32>(c)<<endl;}

        my_file.close();
        // my_file.read(reinterpret_cast<char*>(&num), to_string(num).size());
    }

}