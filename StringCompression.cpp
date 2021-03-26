/*
 "abcabcdede"�� ���� ���, ���ڸ� 2�� ������ �߶� �����ϸ� "abcabc2de"�� ������, 
 3�� ������ �ڸ��ٸ� "2abcdede"�� �Ǿ� 3�� ������ ���� ª�� ���� ����� �˴ϴ�. 
 �̶� 3�� ������ �ڸ��� �������� ���� ���ڿ��� �״�� �ٿ��ָ� �˴ϴ�.

 ������ ���ڿ� s�� �Ű������� �־��� ��, 
 ���� ������ ������� 1�� �̻� ������ ���ڿ��� �߶� �����Ͽ� ǥ���� ���ڿ� �� 
 ���� ª�� ���� ���̸� return �ϵ��� solution �Լ��� �ϼ����ּ���

 s�� ���̴� 1 �̻� 1,000 �����Դϴ�.
s�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.

s	                        result      
"aabbaccc"	                7               1�������� �߶����� ª��
"ababcdcdababcdcd"	        9               8�������� �߶����� ª��
"abcabcdede"	            8               3�������� 
"abcabcabcabcdededededede"	14              6�������� 
"xababcdcdababcdcd"	        17              �տ������� �߶���ϹǷ� ������ ��������.
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
        string stmp = s; //�ӽ����� ���ڿ�
        string strsub = ""; //���� ���ڿ��� ��Ƶδ� �뵵.
        int loop = 1;
        int range = i+1;
        while(stmp != "")
        {
            // i+1 (���ڿ� �ڸ��� ����)�� ������ ������, �ӽ����幮�ڿ� ���̷� ���ص�.
           
            bool bOutRange = false;
            if(range > stmp.size()) bOutRange = true;

            string comparestr;
            if(strsub.size() !=0)
            {
                comparestr = strsub.substr(strsub.size()-range,range);
            }
            
            if(!bOutRange && comparestr == stmp.substr(0,range)) //���๮�ڿ��� ���� - ������ �ϸ� ���ڿ� �ǵ� �������̰� ����.
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
                    strsub.replace(0,pos,to_string(loop));//strsub�� �Ǿչ���(����)�� loop�� ��ü.
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