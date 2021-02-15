/*
https://programmers.co.kr/learn/courses/30/lessons/12930

���ڿ� s�� �� �� �̻��� �ܾ�� �����Ǿ� �ֽ��ϴ�. �� �ܾ�� �ϳ� �̻��� ���鹮�ڷ� ���еǾ� �ֽ��ϴ�. 

�� �ܾ��� ¦����° ���ĺ��� �빮�ڷ�, Ȧ����° ���ĺ��� �ҹ��ڷ� �ٲ� ���ڿ��� �����ϼ���.

���� ����
���ڿ� ��ü�� ¦/Ȧ�� �ε����� �ƴ϶�, �ܾ�(������ ����)���� ¦/Ȧ�� �ε����� �Ǵ��ؾ��մϴ�.
ù ��° ���ڴ� 0��° �ε����� ���� ¦����° ���ĺ����� ó���ؾ� �մϴ�.

����� ��
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