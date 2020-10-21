#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
 
int main() {
	int len1, len2;// �����ַ����ĳ���
	int i, j;      // ��������
	string str1, str2;
	//getline(cin, str1);
	//getline(cin, str2);
	str1 = "taabcdefghi";
	str2 = "sabcdeffhia";
	len1 = str1.length();
	len2 = str2.length();
	vector<vector<int> >dp(len1, vector<int>(len2));
	// dp[i][j]��ʾ������str1[i]��str2[j]��β�Ĺ����Ӵ�����󳤶ȣ�
	// Ҳ����str1[i]�������str2[j]
	
	for (i = 0; i < len1; ++i) //���㹫���Ӵ��ĳ���
	{
		if (str1[i] == str2[0])
			dp[i][0] = 1;
		else
			dp[i][0] = 0;
	}
	for (j = 0; j < len2; ++j) {
		if (str2[j] == str1[0])
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
	}
	for (i = 1; i < len1; ++i) {
		for (j = 1; j < len2; ++j) {
			if (str1[i] != str2[j]) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
	// �ó������Ӵ�����󳤶ȣ����Ҽ�¼λ��
	int pos, val = 0;
	for (i = 0; i < len1; ++i) {
		for (j = 0; j < len2; ++j) {
			if (val < dp[i][j]) {
				pos = i;
				val = dp[i][j];
			}
		}
	}
	// ������
	for (i = pos - val + 1; i <= pos; ++i) {
		cout << str1[i]; // abcdef
	}
	cout << endl;

    getchar();
}