/*
https://programmers.co.kr/learn/courses/30/lessons/42839

숫자가 적힌 문자열 numbers가 주어질때,
해당 숫자들로 만들 수 있는 소수가 몇개인지 return.

numbers	    return
"17"	    3
"011"	    2

입출력 설명
1. [1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

2. [0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.
    (11과 011은 같은 숫자로 취급합니다.)
*/

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

bool IsPrime(int numb)
{
    if(numb<2) return false;
    
    for(int i = 2; i<=sqrt(numb); ++i)
    {
        if(numb%i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers) 
{
    int answer = 0;
    set<int> primeset; //set으로 중복제거
    vector<char> vec;

    for(char& ch : numbers)
    {
        vec.push_back(ch);
    }

    sort(vec.begin(), vec.end());

    do{
        string str = "";

        for(char ch : vec)
        {
            str += ch;
            //cout<<ch;
            int number = stoi(str);
        
            if(IsPrime(number)) //그냥 숫자를 다 때려넣어 소수 판별시켰다. 
            //원래는 1자리 수를 따로 위에서 판별해서 넣어줬느데 
            //비슷한 코드를 두번씩 쓰니깐 그냥 다 때려넣음.
            {
                primeset.insert(number);
            }
        }
        
    }while(next_permutation(vec.begin(), vec.end()));

    answer = primeset.size();
    return answer;
}

int main()
{
    string input;
    int sol = 0;
    input = "011";

    sol = solution(input);

    cout << sol;
}