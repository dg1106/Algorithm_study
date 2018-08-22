#include <iostream>
#include <stdio.h>
#include <utility>
#include <deque>
using namespace std;

#define MAX_N 100
#define MAX_M 100

int map[MAX_N][MAX_M];
int route[MAX_N][MAX_M];
int diffx[4] = { -1,0,1,0 };
int diffy[4] = { 0,1,0,-1 };
deque<pair<int, int>> posit; // (x,y)의 위치를 저장할 deque
deque<int> length;

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &map[i][j]); // 정수 하나씩 입력받아서 저장
		}
	}

	cout << map[N][M] << endl;

	return 0;
}