/*
https://programmers.co.kr/learn/courses/30/lessons/12926

���ڿ� s�� �Ÿ� n�� �Է¹޾� s�� n��ŭ �� ��ȣ���� ����� �Լ�

���� ����
������ �ƹ��� �о �����Դϴ�.
s�� ���ĺ� �ҹ���, �빮��, �������θ� �̷���� �ֽ��ϴ�.
s�� ���̴� 8000�����Դϴ�.
n�� 1 �̻�, 25������ �ڿ����Դϴ�.

����� ��
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