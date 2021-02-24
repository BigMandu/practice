/*
https://programmers.co.kr/learn/courses/30/lessons/17682

다트 게임은 총 3번의 기회로 구성된다.
각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다.
점수와 함께 Single(S), Double(D), Triple(T) 영역이 존재하고 
각 영역 당첨 시 점수에서 1제곱, 2제곱, 3제곱 (점수1 , 점수2 , 점수3 )으로 계산된다.

옵션으로 스타상(*) , 아차상(#)이 존재
스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 
아차상(#) 당첨 시 해당 점수는 마이너스된다.

스타상(*)은 첫 번째 기회에서도 나올 수 있다. 
이 경우 첫 번째 스타상(*)의 점수만 2배가 된다. (예제 4번 참고)

스타상(*)의 효과는 다른 스타상(*)의 효과와 중첩될 수 있다. 
이 경우 중첩된 스타상(*) 점수는 4배가 된다. (예제 4번 참고)

스타상(*)의 효과는 아차상(#)의 효과와 중첩될 수 있다. 
이 경우 중첩된 아차상(#)의 점수는 -2배가 된다. (예제 5번 참고)

Single(S), Double(D), Triple(T)은 점수마다 하나씩 존재한다.

스타상(*), 아차상(#)은 점수마다 둘 중 하나만 존재할 수 있으며, 존재하지 않을 수도 있다.
0~10의 정수와 문자 S, D, T, *, #로 구성된 문자열이 입력될 시 총점수를 반환하는 함수를 작성하라.


예제	dartResult	answer	설명
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