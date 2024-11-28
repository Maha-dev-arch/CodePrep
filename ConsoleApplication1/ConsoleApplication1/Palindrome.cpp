#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//int main()
//{
//	string s;
//	getline(cin, s);
//
//	//char* c = (char*) s.c_str();
//	//int len = s.length();
//	//bool notPali = false;
//
//	/*for (int i = 0, j=len-1; i < len/2; i++, j--) {
//		if (c[i] != c[j]) {
//			notPali = true;
//			break;
//		}
//	}*/
//	transform(s.begin(), s.end(), s.begin(), tolower);
//	string rev = s;
//	reverse(rev.begin(), rev.end());
//
//	if (s != rev)
//		cout << "Not a Palindrome:" << s << endl;
//	else
//		cout << "It's a Palindrome:" << s << endl;
//	return 0;
//}