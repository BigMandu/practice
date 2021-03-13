/*
https://programmers.co.kr/learn/courses/30/lessons/12899

124 ���󿡴� �ڿ����� �����մϴ�.
124 ���󿡴� ��� ���� ǥ���� �� 1, 2, 4�� ����մϴ�.

���� �� 124 ���󿡼� ����ϴ� ���ڴ� ������ ���� ��ȯ�˴ϴ�.

10����	124 ����	10����	124 ����
1	    1	        6	    14
2	    2	        7	    21
3	    4	        8	    22
4	    11      	9	    24
5	    12      	10  	41

�ڿ��� n�� �Ű������� �־��� ��, n�� 124 ���󿡼� ����ϴ� ���ڷ� �ٲ� ���� return �϶�.
(n�� 500,000,000������ �ڿ���)

3 ������, ������ ����? 
1 = 1
2 = 2
3 = 4
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

string solution(int n) 
{
    string answer = "";
    int div = 0;
    while(n != 0)
    {
        if(n%3 == 0)
        {
            answer = '4' + answer;
            --n;
        }
        else
        {
            div = n%3;
            answer = char(div+'0') + answer;
        }
        n/=3;
    }


    return answer;
}

int main()
{
    int input;
    string sol = "";
    cout<<"input : ";
    cin>>input;
    sol = solution(input);

    cout << sol;
}