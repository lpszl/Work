#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, m;// n表示行数，m表示列数
	cin >> n >> m;
	while (n > 100 || n < 1 || m < 1 || m > 100) {
		cout << "Incorrect mesh size." << endl;
		cin >> n >> m;
	}
	// 创建记录输出顺序的二维数组
	string **mesh = new string*[n];
	for (int i = 0; i < n; i++) {
		mesh[i] = new string[m];
	}
	string s;
	int total = n * m;// 总的输入个数
	while (cin >> s)
	{
		// 判断输入的无人机探测的字符串长度和探测网格大小是否一致，
		if (s.length() != total) {
			cout << "Data mismatch" << endl;
			continue;
		}
		else
		{
			int i;
			for (i = 0; i < total; i++) {
				if (s[i] == 'R' || s[i] == 'G' || s[i] == 'F') {
					continue;
				}
				else
				{
					cout << "Invalid cell type" << endl;
					break;
				}
			}
			if (i != total) {
				continue;
			}
			else
			{
				break;
			}
		}
	}
	int i = 0;
	int now = 0;
	while (i < total) {
		int line = i / m;
		if (now % 2 == 0) {
			for (int j = 0; j < m; j++)
				mesh[line][j] = s[i++];
		}
		else
		{
			for (int j = m - 1; j >= 0; j--)
				mesh[line][j] = s[i++];
		}
        now++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mesh[i][j];
		}
		cout << endl;
	}
}
