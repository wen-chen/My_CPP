#include <iostream>
using namespace std;
//ÿ�콫��ǵ��˸�Ⱦ������ǵڶ��콫Ҫ��Ⱦ���˱��
int main() {	
	int n, m;
	cin >> n;
	char a[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cin >> m;
	for (int d = 1; d <= m; d++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == '!') { //��ǰһ���ǵ��˸�Ⱦ 
					a[i][j] = '@';
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == '@') { //����Ⱦ����Χ���˱�� 
					if (i + 1 < n && a[i + 1][j] == '.') {
						a[i + 1][j] = '!';
					} 
					if (j - 1 >= 0 && a[i][j - 1] == '.') {
						a[i][j - 1] = '!';
					}
					if (j + 1 < n && a[i][j + 1] == '.') {
						a[i][j + 1] = '!';
					}
					if (i - 1 >= 0 && a[i - 1][j] == '.') {
						a[i - 1][j] = '!';
					}
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '@') {
				sum = sum + 1;
			}
		}
	} 
	cout << sum << endl;
	return 0;
}
