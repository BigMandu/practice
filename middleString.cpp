/*
    https://programmers.co.kr/learn/courses/30/lessons/12903
    �ܾ� s�� ��� ���ڸ� ��ȯ�ϴ� �Լ�, solution�� ����� ������. 
    �ܾ��� ���̰� ¦����� ��� �α��ڸ� ��ȯ�ϸ� �˴ϴ�.

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