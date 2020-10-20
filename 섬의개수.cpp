/** https://www.acmicpc.net/problem/4963
 *  입력
 *  첫째줄 : 0 < w, h <= 50
 *  둘째줄~h : 1 -땅, 0 - 바다
 *  입력 종료 문구 : 0 0
 *  
 *  섬의 개수 출력하면됨. 땅이 연결되어있으면 하나의 섬으로 간주함. (8 dir 탐색임)
*/

#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

int map[MAX][MAX];
bool visit[MAX][MAX];
// 상,하,좌,우, 우상,우하,좌상,좌하
int dr[] = {-1,1,0,0,-1,1,-1,1}; //행 -> h
int dc[] = {0,0,-1,1,1,1,-1,-1}; //열 -> w
int sol;

void SearchOrNot(int h, int w);
void BeginSearch(int h, int w, int MAX_h, int MAX_w);
void init();

void input()
{
    int h, w;
    while(true)
    {
        cin >> w >> h;
        if(!h && !w) break;

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }
        
        SearchOrNot(h,w);
        cout << "----------" << sol <<endl;
        init();
    }
}

int main()
{
    input();
}

void SearchOrNot(int h, int w)
{
    for(int i = 0; i< h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(map[i][j] && !visit[i][j])
            {
                sol++;
                BeginSearch(i, j, h, w);
            }
        }
    }
}

void BeginSearch(int h, int w, int MAX_h, int MAX_w)
{
    visit[h][w] = true;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(h, w));

    while(!q.empty())
    {
        h = q.front().first;
        w = q.front().second;
        q.pop();

        for(int i = 0; i< 8; i++)
        {
            int nh = h+dr[i];
            int nw = w+dc[i];

            if(nh >= 0 && nh < MAX_h && nw >=0 && nw < MAX_w)
            {
                if(map[nh][nw] && !visit[nh][nw])
                {
                    visit[nh][nw] = true;
                    q.push(pair<int,int>(nh,nw));
                }
            }
        }
    }
}

void init()
{
	fill(map[0], map[0]+MAX*MAX, 0);
	fill(visit[0], visit[0]+MAX*MAX, 0);
    sol = 0;
}