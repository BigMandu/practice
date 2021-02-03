/*
https://programmers.co.kr/learn/courses/30/lessons/42840

1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��,
���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
������ڰ� ������ ���, ������������ ����.


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
        /* 1�� �л� Ȯ��*/
        if(answers.at(i) == a)
        {
            Ascore++;
        }

        a += 1;
        if(a>5)
        {
            a = 1;
        }


        /* 2���л� Ȯ�� */
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

        /* 3�� �л� Ȯ�� */
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