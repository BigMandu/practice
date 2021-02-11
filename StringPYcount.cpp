#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCnt = 0;
    int yCnt = 0;
    for(char& ch : s)
    {
        if(ch == 'p' || ch == 'P')
        {
            pCnt++;
        }
        else if(ch == 'y' || ch == 'Y')
        {
            yCnt++;
        }
    }


    answer = pCnt==yCnt? true : false;

    return answer;
}

int main()
{
    string instr;
    cin>> instr;

    cout<<solution(instr) <<endl;
}