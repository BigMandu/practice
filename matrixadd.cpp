/*
https://programmers.co.kr/learn/courses/30/lessons/12950

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;

    answer.resize(arr1.size());
    
    for(int i = 0; i< arr1.size(); i++)
    {
        for(int j = 0; j<arr1[0].size(); j++)
        {
            int x;
            x = arr1.at(i).at(j) + arr2.at(i).at(j);
            answer[i].push_back(x);
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>>vec1;
    vector<vector<int>>vec2;

    vec1 = {{1,2}, {2,3}};
    vec2 = {{3,4}, {5,6}};

    vec1 = solution(vec1, vec2); //4,6 7,9
    
    for(int i = 0; i< vec1.size(); i++)
    {
        for(int j = 0; j<vec1[0].size(); j++)
        {
            cout << vec1[i][j];
        }
    }
}