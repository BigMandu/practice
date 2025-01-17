/*
https://programmers.co.kr/learn/courses/30/lessons/17681


입력형식
입력으로 지도의 한 변 크기 n 과 2개의 정수 배열 arr1, arr2가 들어온다.

1 ? n ? 16
arr1, arr2는 길이 n인 정수 배열로 주어진다.
정수 배열의 각 원소 x를 이진수로 변환했을 때의 길이는 n 이하이다. 즉, 0 ? x ? 2n - 1을 만족한다.


출력 형식
원래의 비밀지도를 해독하여 '#', 공백으로 구성된 문자열 배열로 출력하라.



매개변수	값
n	        5
arr1	    [9, 20, 28, 18, 11]
arr2	    [30, 1, 21, 17, 28]
출력	    ["#####","# # #", "### #", "# ##", "#####"]


매개변수	값
n	        6
arr1	    [46, 33, 33 ,22, 31, 50]
arr2	    [27 ,56, 19, 14, 14, 10]
출력	    ["######", "### #", "## ##", " #### ", " #####", "### # "]
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string binToStr(int n, int x)
{
    string str;

    while(str.size() != n)
    {
        str = ((x % 2 == 0)? ' ' : '#') +str;
        x/=2;
    }
    
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<int> tmpstore;
    vector<string> answer;

    for(int i =0; i<n; i++)
    {
        int num = (arr1[i] | arr2[i]);

        tmpstore.push_back(num);
    }

    for(int bit : tmpstore)
    {
        answer.push_back(binToStr(n, bit));
    }

    return answer;
}


int main()
{
    int n;
    vector<int>arr1;
    vector<int>arr2;
    vector<string>str;

    n = 6;
    arr1 = {46, 33, 33 ,22, 31, 50};
    arr2 = {27 ,56, 19, 14, 14, 10};

    str = solution(n,arr1,arr2);

    for(string s : str)
    {
        cout<<s<<endl;
    }
}