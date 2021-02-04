/*
    https://programmers.co.kr/learn/courses/30/lessons/12903
    단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 
    단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.

    s	    return
    abcde	c
    qwer	we

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    if(len%2==0)
    {
        answer = s[len/2-1];
        answer += s[len/2];
    }
    else
    {
        answer = s[len/2];
    }

    return answer;
}

int main()
{
    string str;

    cin >> str;

    str = solution(str);

    cout << str;
}