/*
https://programmers.co.kr/learn/courses/30/lessons/67256


numbers                         	hand	result
[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]	"right"	"LRLLLRLLRRL"
[7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]	"left"	"LRLLRRLLLRR"
[1, 2, 3, 4, 5, 6, 7, 8, 9, 0]	    "right"	"LLRLLRLLRL"



*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
//return@:  1 : left, 2 : right , 3: shortdist
int CheckNum(int num)
{
    if(num == 1 || num == 4 || num == 7)
    {
        return 1;
    }
    else if(num == 3 || num == 6 || num == 9)
    {
        return 2;
    }
    else return 3;
}

//업데이트 함수로 깔끔하게 만들어준다.
void Update(string& ans, int chk, int& L_lo, int& R_lo, int number)
{
    if(chk == 1)
    {
        ans+="L";
        L_lo = number;
    }
    else
    {
        ans+="R";
        R_lo = number;
    }
}

string solution(vector<int> numbers, string hand) 
{
    string answer = "";

    int LeftLo = 10;
    int RightLo = 12;
    int chk = 0;

    for(int x : numbers)
    {
        chk = CheckNum(x);
        if(chk == 3)
        {
            int LeftDist = 0;
            int RightDist = 0;
            if(x == 0) x = 11;
            
            /*
                왼손,오른손 거리를 구한다. 맨하탄거리 알고리즘의 방식을 이용함.
                x1,y1 : 시작점, x2,y2 : 종료지점
                |x1-x2| + |y1-y2| = 시작점과 종료점의 거리가 나옴.
                
                근데 좌표값을 따로 하지 않고, 단순히 숫자로만 했다.
                LeftLo가 5, RightLo는 3, x(target)가 8일 경우에

                |LeftLo - x| =  3;    |RightLo - x| = 5;
                3/3 + 3%3; = 1
                5/3 + 5%3; = 3   이 나오게 된다.

                int distance(int pos, int x)
                {
                    int dist = 0;

                    dist += abs((pos - 1) / 3 - (x - 1) / 3); // 행의 차이       
                    dist += abs((pos - 1) % 3 - (x - 1) % 3); // 열의 차이

                    return dist;
                }


            */
            LeftDist = (abs(LeftLo - x)/3 + abs(LeftLo-x)%3);
            RightDist = (abs(RightLo - x)/3 + abs(RightLo-x)%3);

            if(LeftDist < RightDist)
            {
                chk = 1;
            }
            else if(LeftDist > RightDist)
            {
                chk = 2;
            }
            else
            {
                if(hand == "right")
                {
                    chk = 2;
                }
                else
                {
                    chk = 1;
                }
            }
        }
        Update(answer,chk,LeftLo,RightLo,x);
    }

    return answer;
}

int main()
{
    vector<int>number;
    string hand;

    number = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    hand = "right";

    hand = solution(number,hand);
    cout << hand;
}