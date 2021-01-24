/*
https://programmers.co.kr/learn/courses/30/lessons/42584

�ʴ����� ��ϵ� �ֽİ����� ��� �迭 prices�� �Ű������� �־�����
������ �������� ���� �Ⱓ�� �������� return�϶�.
�� ���������� �̷�

�ʴ����� ��ϵ� �ֽİ�����
����������� ���ʰ� �ɷȴ���. �̰���.

prices�� �� ������ 1�̻� 10,000���� �ڿ���.
prices�� ���̴� 2�̻� 100,000 ����.

prices	            return
[1, 2, 3, 2, 3]	    [4, 3, 1, 1, 0]
[5, 8, 6, 2, 4, 1]  [3, 1, 1, 2, 1, 0]
[1, 2, 3, 2, 3, 1]  [5, 4, 1, 2, 1, 0]


*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int i=0;i<prices.size();i++)
    {
        int time = 0;
        for(int j=i+1; j<prices.size();j++)
        {
            if(j>=prices.size())
            {
                break;
            }

            if(prices[i] <= prices[j])
            {
                time++;
            }
            else
            {
                time++;
                break;
            }
        }
        answer.push_back(time);
    }

    return answer;
}

int main()
{
    vector<int> inprice;
    vector<int>answer;
    
    for(int i=0; i<100;i++)
    {
        int input = 0;
        scanf("%d",&input);
        if(input < 0) break;
        inprice.push_back(input);
    }

    answer = solution(inprice);

    for(int i=0; i<answer.size();i++)
    {
        printf("%d",answer[i]);
    }
}