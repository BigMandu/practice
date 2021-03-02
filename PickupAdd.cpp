/*
https://programmers.co.kr/learn/courses/30/lessons/68644

numbers에서 서로다른 두 수를 더해서 만들 수 있는 모든 수를 오름차순으로 리턴.

numbers	    result
[2,1,3,4,1]	[2,3,4,5,6,7]
[5,0,2,7]	[2,5,7,9,12]

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;
    vector<bool>chk;
    chk.resize(201);

    for(int i = 0; i<numbers.size(); i++)
    {
        for(int j= i+1; j<numbers.size();j++)
        {
            int num = numbers[i]+numbers[j];
            if(chk[num]) continue;
            chk[num] = true;
            answer.push_back(num);
        }
    }
    
    sort(answer.begin(), answer.end(), less<int>());
    
    return answer;
}

int main()
{
    vector<int>numb;
    numb = {2,1,3,4,1};

    numb = solution(numb);

    for(int x : numb)
    {
        cout<<x << " ";
    }
}