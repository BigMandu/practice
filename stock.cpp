/*
https://programmers.co.kr/learn/courses/30/lessons/42584

초단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질때
가격이 떨어지지 않은 기간은 몇초인지 return하라.
뭔 문제설명이 이래

초단위로 기록된 주식가격이
떨어지기까지 몇초가 걸렸는지. 이거임.

prices의 각 가격은 1이상 10,000이하 자연수.
prices의 길이는 2이상 100,000 이하.

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