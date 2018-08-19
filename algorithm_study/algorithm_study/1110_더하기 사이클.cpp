#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int num, ans = 0;
	int target[2], tmpnum[2], madenum[2] = { 0,0 };
	cin >> num;

	if (num < 10) {
		target[0] = 0;
		target[1] = num;
	}
	else {
		target[0] = num / 10;
		target[1] = num % 10;
	}

	/*for (int i = 0; i < 2; ++i) {
		cout << target[i];
	}
	cout << endl;*/

	/* algorithm */
	int res = 1;	// 메모리 비교 리턴값 저장
	int cnt = 0;	// 카운팅
	int tmp = 0;	// 각 자리수가 더해질 때 생기는 숫자
	memset(tmpnum, 0, sizeof(tmpnum));
	memcpy(tmpnum, target, sizeof(tmpnum));

	/*getchar();
	for (int i = 0; i < 2; ++i) {
		cout << tmpnum[i];
	}
	cout << endl;*/
	while (1)
	{
		tmp = tmpnum[0] + tmpnum[1];
		madenum[0] = tmpnum[1];
		madenum[1] = tmp % 10;

		/*cout << "tmpnum : ";
		for (int i = 0; i < 2; ++i) {
			cout << tmpnum[i];
		}
		cout << endl;
		cout << "madenum : ";
		for (int i = 0; i < 2; ++i) {
			cout << madenum[i];
		}*/

		++cnt;

		res = memcmp(target, madenum, sizeof(target));
		if (!res) { //같으면 0리턴
			break;
		}
		memcpy(tmpnum, madenum, sizeof(tmpnum));
		
		//getchar();
	}

	cout << cnt << endl;

	return 0;
}