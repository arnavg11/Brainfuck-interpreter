#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <stack>
using namespace std;
unsigned char tape[30000];
int main(){
    string src = "";
std::ifstream t(src+"file.txt",ios::in);
    std::ofstream o(src+"debug.txt");
std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
    t.close();
    int ptr = 0,mptr=0;
    stack<int> loops;
    int ign = 0;
    int bal =0;
    for(unsigned char i : str){
        if(i=='[')bal++;
        else if(i==']')bal--;
        if(bal<0){
            cout<<"Too many closed brackets";
            return 0;
        }
    }
    if(bal!=0){
        cout<<"Too many open brackets";
        return 0;
    }
    for(int i = 0; i<str.length();i++){
        if (str[i] == '#'){
            o<<"pointer index - "<<ptr<<"\nvalue at pointer - "<<(int)tape[ptr]<<"\nposition of string pointer - "<<i<<"\nall visited elements:\n";
            for(int i = 0; i<=mptr;i++){
                o<<i<<" "<<tape[i]<<" "<<(int)tape[i]<<"\n";
            }
            o.flush();
        }
        if(ign){
            switch (str[i]) {
                case '[':
                    ign++;
                    break;
                case ']':
                    ign--;
                    break;
            }
            if(ign==0){
                    loops.pop();
                }
            continue;
        }
        switch(str[i]){
            case '<':ptr--;if(ptr<0)ptr+=30000;break;
            case '>':ptr++;if(ptr>=30000)ptr-=30000;break;
            case '+':tape[ptr]++;break;
            case '-':tape[ptr]--;break;
            case '.':cout<<((char)tape[ptr]);break;
            case ',':tape[ptr] = getchar();break;
            case '[':if(tape[ptr]==0)ign+=1;
                 loops.push(i);
                break;
            case ']':
                i = loops.top()-1;
                loops.pop();
                break;
        }
        mptr = max(mptr,ptr);
    }
}

