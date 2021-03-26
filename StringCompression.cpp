/*
 "abcabcdede"와 같은 경우, 문자를 2개 단위로 잘라서 압축하면 "abcabc2de"가 되지만, 
 3개 단위로 자른다면 "2abcdede"가 되어 3개 단위가 가장 짧은 압축 방법이 됩니다. 
 이때 3개 단위로 자르고 마지막에 남는 문자열은 그대로 붙여주면 됩니다.

 압축할 문자열 s가 매개변수로 주어질 때, 
 위에 설명한 방법으로 1개 이상 단위로 문자열을 잘라 압축하여 표현한 문자열 중 
 가장 짧은 것의 길이를 return 하도록 solution 함수를 완성해주세요

 s의 길이는 1 이상 1,000 이하입니다.
s는 알파벳 소문자로만 이루어져 있습니다.

s	                        result      
"aabbaccc"	                7               1개단위로 잘랐을때 짧음
"ababcdcdababcdcd"	        9               8개단위로 잘랐을때 짧음
"abcabcdede"	            8               3개단위로 
"abcabcabcabcdededededede"	14              6개단위로 
"xababcdcdababcdcd"	        17              앞에서부터 잘라야하므로 압축이 되지않음.
*/

#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    int min = 0x7fffffff;

    for(int i = 0; i<s.size(); i++)
    {
        string stmp = s; //임시저장 문자열
        string strsub = ""; //압축 문자열을 담아두는 용도.
        int loop = 1;
        int range = i+1;
        while(stmp != "")
        {
            // i+1 (문자열 자르는 길이)가 범위를 벗어날경우, 임시저장문자열 길이로 정해둠.
           
            bool bOutRange = false;
            if(range > stmp.size()) bOutRange = true;

            string comparestr;
            if(strsub.size() !=0)
            {
                comparestr = strsub.substr(strsub.size()-range,range);
            }
            
            if(!bOutRange && comparestr == stmp.substr(0,range)) //압축문자열의 길이 - 범위를 하면 문자열 맨뒤 범위길이가 나옴.
            {
                ++loop;
                if(loop>=3)
                {
                    int lotmp = loop;
                    int pos = 0;
                    while(lotmp)
                    {
                        lotmp /=10;
                        ++pos;
                    }
                    if(loop - pow(10,pos-1) == 0)
                    {
                        --pos;
                    }
                    strsub.replace(0,pos,to_string(loop));//strsub의 맨앞문자(숫자)를 loop로 대체.
                }
                else strsub = char(loop) + strsub;
            }
            else
            {
                loop = 1;
                strsub += stmp.substr(0,range);
            }

            if(bOutRange)
            {
                range = stmp.size();
            }
            
            stmp = stmp.substr(range);
        }

        min = min>strsub.size()?  strsub.size() : min;
    }
    answer = min;
    return answer;
}

int main()
{
    int sol;
    string input = "zxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

    sol = solution(input);

    cout<<sol;
}