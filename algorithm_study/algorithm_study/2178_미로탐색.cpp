#include <iostream>
#include <stdio.h>
#include <utility>
#include <deque>
using namespace std;

#define MAX_N 100
#define MAX_M 100

int map[MAX_N][MAX_M];
int route[MAX_N][MAX_M];
int diffx[4] = { -1,0,1,0 }; // x의 방향 정하는 도구
int diffy[4] = { 0,1,0,-1 }; // y   "    "
deque<pair<int, int>> posit; // (x,y)의 위치를 저장할 deque
deque<int> length;
int N, M;

void bfs(int i, int j)
{
	posit.push_back(pair<int, int>(1, 1)); // 현재 포지션 저장
	length.push_back(1); // 현재 이동한 길이 저장
	map[i][j] = 0; // 이미 방문함

	while (posit.size() != 0) {
		int x = posit.front().first;
		int y = posit.front().second;
		int mark = length.front();

		posit.pop_front();
		length.pop_front();
		route[x][y] = mark++; // 저장후 증가

		for (int i = 0; i < 4; ++i) {
			int nextX = x + diffx[i]; // 다음 위치 저장
			int nextY = y + diffy[i];

			if (nextX >= 1 && nextX <= N&&nextY >= 1 && nextY <= M&&map[nextX][nextY] == 1)
			{
				posit.push_back(pair<int, int>(nextX, nextY));
				length.push_back(mark);
				map[nextX][nextY] = 0; // 현재위치는 방문함을 알림.
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%1d", &map[i][j]); // 정수 하나씩 입력받아서 저장
		}
	}

	bfs(1, 1); // (1,1) 에서 출발!

	cout << route[N][M] << endl;

	return 0;
}