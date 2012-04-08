using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

class CuttingGrass {
  public:
  int theMin(vector <int> init, vector <int> grow, int H);

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8, 58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; int Arg3 = 1; verify_case(0, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 58; int Arg3 = 0; verify_case(1, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = -1; verify_case(2, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5, 1, 6, 5, 8, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1, 1, 4, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 33; int Arg3 = 5; verify_case(3, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {49, 13, 62, 95, 69, 75, 62, 96, 97, 22, 69, 69, 52}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2, 4, 3, 6, 5, 7, 6, 5, 4, 7, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 517; int Arg3 = 8; verify_case(4, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1231, 1536, 1519, 1940, 1539, 1385, 1599, 1613, 1394, 1803,
 1763, 1706, 1863, 1452, 1818, 1914, 1386, 1954, 1496, 1722,
 1616, 1862, 1755, 1215, 1233, 1078, 1448, 1241, 1732, 1561,
 1633, 1307, 1844, 1911, 1371, 1338, 1989, 1789, 1656, 1413,
 1929, 1182, 1815, 1474, 1540, 1797, 1586, 1427, 1996, 1202}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {86, 55, 2, 86, 96, 71, 81, 53, 79, 22,
 23, 8, 69, 32, 35, 39, 30, 18, 92, 64,
 88, 1, 48, 81, 91, 75, 44, 77, 3, 33,
 9, 52, 56, 4, 19, 73, 52, 18, 8, 77,
 91, 59, 50, 62, 42, 87, 89, 24, 71, 67}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 63601; int Arg3 = 36; verify_case(5, Arg3, theMin(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

struct grass {
	int index;
	int growthRate;
	int finalHeight;
	
	grass(int i, int g, int f) : index(i), growthRate(g), finalHeight(f) {}
	
	bool operator < (const grass &t) const {
		if (finalHeight != t.finalHeight) return finalHeight > t.finalHeight;
		return growthRate > t.growthRate;
	}
};


bool works(int k, vector<int> init, vector<int> grow, int H) {
	int n = init.size();
	
	vector< grass > end;
	int total = 0;	
	For(i, 0, n){
		total += k * grow[i] + init[i];
		end.push_back(  grass(i, grow[i], k * grow[i] + init[i]) );
		//printf("After k=%d seconds grass i=%d is %d high\n", k, i, k * grow[i] + init[i]);
	}
	sort(end.begin(), end.end());
	
	// Sacar las primeras K
	vector< pair<int, int> > fastestGrowing;
	for (int i = 0; i < k; ++i) {
		int index = end[i].index;
		//printf("I need to cut grass %d\n", index);
		fastestGrowing.push_back( make_pair( grow[index], index)  );
	}
	sort(fastestGrowing.begin(), fastestGrowing.end(), less< pair<int, int> >());
	
	assert(fastestGrowing.size() == k);
	
	for (int i = 0; i < k; ++i) {
		int index = fastestGrowing[i].second;
		
		total -= (i + 1) * grow[index] + init[index];
	}

	printf("for k = %d, total = %d, H = %d\n", k, total, H);
	return total <= H;
}

int CuttingGrass::theMin(vector <int> init, vector <int> grow, int H) {
	works(5, init, grow, H);
	for (int i = 0; i <= init.size(); ++i){
		if (works(i, init, grow, H)) return i;
	}
	return -1;
}

// BEGIN CUT HERE
int main(){
    CuttingGrass ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE