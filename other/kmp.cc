#include <iostream>
#include <vector>

//next[j]表示字符串p的前j个字符最长的公共前缀和后缀的长度
void gen_next(std::vector<int>& next, const std::string& p) {
	next[0] = -1;
	for (int i = 1; i < p.size(); i++) {
		int j = i - 1;
		int k = next[j];

		while (k != -1) {
			if (p[k] == p[j]) {
				next[i] = k + 1;
				break;
			}

			k = next[k];
		}
	}
}


//kmp算法的复杂度是O(m+n)
//其中m是str的长度,n是p的长度
int kmp_find(const std::string& str, const std::string& p) {
	int str_len = str.size();
	int p_len = p.size();

	if (!p_len || p_len > str_len) return -1;
	std::vector<int> next(p.size(),0);
	gen_next(next,p);

	int index = 0;
	int j = 0;

	while (index < str_len && j < p_len) {
		if (j==-1 || str[index] == p[j]) {
			index++;
			j++;
		}
		else {
			j = next[j];
		}
	}

	if (j == p_len) return index - j;
	return -1;
}



int main() {
	std::string str = "my name is spinors,great code is kmp algorithm!";
	std::string p = "great";
	std::cout << kmp_find(str,p) << std::endl;
	std::cout << str.find(p) << std::endl;
}