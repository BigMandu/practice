/*
https://programmers.co.kr/learn/courses/30/lessons/12926

문자열 s와 거리 n을 입력받아 s를 n만큼 민 암호문을 만드는 함수

제한 조건
공백은 아무리 밀어도 공백입니다.
s는 알파벳 소문자, 대문자, 공백으로만 이루어져 있습니다.
s의 길이는 8000이하입니다.
n은 1 이상, 25이하인 자연수입니다.

입출력 예
s	    n	result
AB	    1	BC
z	    1	a
a B z	4	e F d
*/

#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
    string answer = "";
    int shiftch;
    for(char ch : s)
    {
        if(ch >= 'A' && ch <= 'Z')
        {
            shiftch = (int)ch + n;
            if((char)shiftch > 'Z') shiftch -= 26;
        }
        else if(ch >='a' && ch <= 'z')
        {
            shiftch = (int)ch + n;
            if(shiftch > 122) shiftch -= 26;
        }
        else shiftch = (int)ch;
        
        answer += (char)shiftch;
       
    }

    return answer;
}

int main()
{
    string str = "z";//"a B z";
    int n = 20;

    str = solution(str, n);

    cout << str;
}