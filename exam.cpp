/*
https://programmers.co.kr/learn/courses/30/lessons/42840

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때,
가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.
고득점자가 여럿일 경우, 오름차순으로 정렬.


answers	    return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
*/

#include <string>
#include <vector>


using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a = 1, b = 1, c = 3;
    
    int Ascore = 0, Bscore = 0, Cscore = 0;

    for(int i=0; i<answers.size(); i++)
    {
        /* 1번 학생 확인*/
        if(answers.at(i) == a)
        {
            Ascore++;
        }

        a += 1;
        if(a>5)
        {
            a = 1;
        }


        /* 2번학생 확인 */
        if((i+1)%2 ==0)
        {
            if(answers.at(i) == b)
            {
                Bscore++;
            }

            if(b == 1)
            {
                b += 2;
            }
            else
            {
                b += 1;
                if(b>5)
                {
                    b = 1;
                }
            }
        }
        else
        {
            if(answers.at(i) == 2)
            {
                Bscore++;
            }
        }

        /* 3번 학생 확인 */
        if(answers.at(i) == c)
        {
            Cscore++;
        }

        if((i+1)%2 == 0)
        {
            if(c%2 == 0)
            {
                if(c == 2) c+= 2;
                else c+=1;
            }
            else
            {
                if(c > 1) c -=2;
                else c += 1;
                
            }
        }
    }
    
    int max = Ascore > Bscore? Ascore : Bscore;
    max = max > Cscore ? max : Cscore;

    if(max == Ascore)
    {
        answer.push_back(1);
    }
    if(max == Bscore)
    {
        answer.push_back(2);
    }
    if(max == Cscore)
    {
        answer.push_back(3);
    }

    return answer;
}

int main()
{
    vector<int> inanswer;

    for(int i=0;i<10000;i++)
    {
        int input = 0;
        scanf("%d",&input);
        if(input < 0) break;

        inanswer.push_back(input);
    }

    inanswer = solution(inanswer);

    for(int i = 0; i<inanswer.size(); i++)
    {
        printf("%d",inanswer.at(i));
    }


}