/*
함수 solution은 정수 n을 매개변수로 입력받습니다. 
n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴하라.

n	    return
118372	873211

*/

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    vector<int> arr;

    while(n != 0)
    {
        arr.push_back(n%10);
        n/=10;
    }

    sort(arr.begin(), arr.end(), greater<int>());

    for(int x : arr)
    {
        answer = answer * 10 + x;
    }
    
    
    return answer;
}

int main()
{
    long long input;
    input = 118372;

    input = solution(input);

    cout << input;
}