/*
https://programmers.co.kr/learn/courses/30/lessons/12918
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) 
{
    bool answer = true;
    int len = s.size();
    if(len == 4 || len == 6)
    {
        for(int i=0; i<len; i++)
        {
            if(isdigit(s[i])== false)
            {
                answer = false;
                break;
            }
        }
    }
    else
    {
        answer = false;
    }

    return answer;
}

int main()
{
    string input;
    bool bresult;
    cin >> input;
    
    bresult = solution(input);
    printf("%s",bresult?"true" : "false");
    //cout<< bresult ? "true" : "false"; 
}