/*
https://programmers.co.kr/learn/courses/30/lessons/17682

��Ʈ ������ �� 3���� ��ȸ�� �����ȴ�.
�� ��ȸ���� ���� �� �ִ� ������ 0������ 10�������̴�.
������ �Բ� Single(S), Double(D), Triple(T) ������ �����ϰ� 
�� ���� ��÷ �� �������� 1����, 2����, 3���� (����1 , ����2 , ����3 )���� ���ȴ�.

�ɼ����� ��Ÿ��(*) , ������(#)�� ����
��Ÿ��(*) ��÷ �� �ش� ������ �ٷ� ���� ���� ������ �� 2��� �����. 
������(#) ��÷ �� �ش� ������ ���̳ʽ��ȴ�.

��Ÿ��(*)�� ù ��° ��ȸ������ ���� �� �ִ�. 
�� ��� ù ��° ��Ÿ��(*)�� ������ 2�谡 �ȴ�. (���� 4�� ����)

��Ÿ��(*)�� ȿ���� �ٸ� ��Ÿ��(*)�� ȿ���� ��ø�� �� �ִ�. 
�� ��� ��ø�� ��Ÿ��(*) ������ 4�谡 �ȴ�. (���� 4�� ����)

��Ÿ��(*)�� ȿ���� ������(#)�� ȿ���� ��ø�� �� �ִ�. 
�� ��� ��ø�� ������(#)�� ������ -2�谡 �ȴ�. (���� 5�� ����)

Single(S), Double(D), Triple(T)�� �������� �ϳ��� �����Ѵ�.

��Ÿ��(*), ������(#)�� �������� �� �� �ϳ��� ������ �� ������, �������� ���� ���� �ִ�.
0~10�� ������ ���� S, D, T, *, #�� ������ ���ڿ��� �Էµ� �� �������� ��ȯ�ϴ� �Լ��� �ۼ��϶�.


����	dartResult	answer	����
1	    1S2D*3T	    37	    1^1 * 2 + 2^2 * 2 + 3^3
2	    1D2S#10S	9	    1^2 + 2^1 * (-1) + 10^1
3	    1D2S0T	    3	    1^2 + 2^1 + 0^3
4	    1S*2T*3S	23	    1^1 * 2 * 2 + 2^3 * 2 + 3^1
5	    1D#2S*3S	5	    1^2 * (-1) * 2 + 2^1 * 2 + 3^1
6	    1T2D3D#	    -4	    1^3 + 2^2 + 3^2 * (-1)
7	    1D2S3T*	    59	    1^2 + 2^1 * 2 + 3^3 * 2

*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


bool isSDT(char ch)
{
    if(ch == 'S' || ch == 'D' || ch == 'T')
    {
        return true;
    }
    else return false;
}

bool isAsSh(char ch)
{
    if(ch == '*' || ch == '#')
    {
        return true;
    }
    else return false;
}

int solution(string dartResult) 
{
    vector<int> vec;
    int answer = 0;
    int temp = 0;
    for(char ch : dartResult)
    {
        if(isSDT(ch))
        {
            int x = vec.back();
            vec.pop_back();
            if(ch == 'S') x = pow(x,1);
            else if(ch == 'D') x = pow(x,2);
            else if(ch == 'T') x = pow(x,3);
            vec.push_back(x);
        }
        else if(isAsSh(ch))
        {
            if(ch == '*')
            {
                bool bFirst = false;
                if(vec.size() == 1)
                {
                    bFirst = true;
                }

                int x = vec.back();
                vec.pop_back();
                if(!bFirst)
                {
                    int y = vec.back();
                    vec.pop_back();
                    y *=2;
                    vec.push_back(y);
                }
                x *=2; 
                vec.push_back(x);
                
            }
            if(ch == '#')
            {
                int x = vec.back();
                vec.pop_back();
                x *=-1;
                vec.push_back(x);
            }
            
        }
        else
        {
            if((int)ch-48 == 0)
            {
                if(vec.size() != 0 && vec.back() == 1)
                {
                    vec.pop_back();
                    vec.push_back(10);
                    continue;
                }
            }
            vec.push_back(ch-48);
        }
    }

    for(int x : vec)
    {
        answer += x;
    }
    return answer;
}

int main()
{
    string str = "1D2S0T";
    int x = 0;
    x = solution(str);
    cout << x;
}