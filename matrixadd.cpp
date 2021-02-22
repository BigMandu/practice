/*
https://programmers.co.kr/learn/courses/30/lessons/12950

*/
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;
    
    for(int i = 0; i< arr1.size(); i++)
    {
        for(int j = 0; j<arr1[0].size(); j++)
        {
            vector<int> x;
            x.push_back(arr1.at(i).at(j) + arr2.at(i).at(j));
            answer.push_back(x);
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>>vec1;
    vector<vector<int>>vec2;

    vec1 = {{1,2,3}, {2,3,3}};
    vec2 = {{3,4}, {5,6}};

    vec1 = solution(vec1, vec2);
    
    for(int i = 0; i< vec1.size(); i++)
    {
        for(int j = 0; j<vec1[0].size(); j++)
        {
             printf("%d ", vec1.at(0).at(i));
        }
    }
}