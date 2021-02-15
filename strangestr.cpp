/*
https://programmers.co.kr/learn/courses/30/lessons/12930

문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 

각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하세요.

제한 사항
문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야합니다.
첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.

입출력 예
s	                return
try hello world	    TrY HeLlO WoRlD
012 01234 01234

*/
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int el = 0;

    for(char ch : s)
    {
        if(ch != ' ')
        {
            if(el == 0 || el%2 ==0)
            {
                if(ch >= 'a' && ch <= 'z')
                {
                    answer.push_back(ch-32);
                }
                else
                {
                    answer.push_back(ch);
                }
            }
            else
            {
                if(ch >='A' && ch <= 'Z')
                {
                    answer.push_back(ch+32);
                }
                else
                {
                    answer.push_back(ch);
                }
            }
            el++;
        }
        else
        {
            answer.push_back(' ');
            el = 0;
        }
            
    }
    return answer;
}

int main()
{
    string input = "try hello world";

    input = solution(input);

    cout << input;
}