#include <iostream>
#include <string>
#include <sstream>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi �L�@����͂���N���X�ł��B
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		char c[4] = { 'm', 'c', 'x', 'i' };
		int v[4] = { 1000, 100, 10, 1 };

		mcxi operator + (mcxi rhs)
		{
			mcxi nm("");
			nm.value_ = this->value_ + rhs.value_;
			return nm;
		}

		mcxi(const std::string& s) : value_(0) {
			int cc = 0;
			int cs = 0;
			int d = 1;
			for (int i = 0; i < s.size(); i++) {
				for (int j = 0; j < 4; j++) {
					if (s[i] == c[j]) {
						cc = j;
						value_ += d*v[cc];
						d = 1;
					}
					else { cs++; }
					if (cs == 4) {
						d = (int)(s[i] - '0');
						cs = 0;
					}
				}
				cs = 0;
			}
		}
		std::string to_string()
		{
			std::stringstream ss;
			int q = 0;
			q = value_ / 1000;
			if (q == 1){
				ss << 'm';
			}
			if (q > 1){
				ss << q;
				ss << 'm';
			}

			q = (value_ /100) % 10;
			if (q == 1){
				ss << 'c';
			}
			if(q > 1){
				ss << q;
				ss << 'c';
			}

			q = (value_ / 10 ) % 10;
			if(q == 1){
				ss << 'x';
			}
			if(q > 1){
				ss << q;
				ss << 'x';
			}

			q = value_ % 10;
			if(q == 1){
				ss << 'i';
			}
			if(q > 1){
				ss << q;
				ss << 'i';
			}

			return ss.str();
		}
	private:
			int value_;
			int unit(char c) {
				switch (c) {
				case 'm': return 1000;
				case 'c': return 100;
				case 'x': return 10;
				case 'i': return 1;
				default : return -1;
				}
			}
	};

	std::string test(mcxi& tc, int n){
		std::string data4cmp[] = {"3x", "x", "6cx", "5m9c9x9i", "m", "9m9c9x9i", "mi", "mi", "mx", "9m9c9x9i" };

		if(tc.to_string() != data4cmp[n]){
			return "incorrect";
		}
		else{
			return  "correct";
		}
	}

} // namespace cpp2
int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	cpp2::mcxi result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() <<" " <<cpp2::test(result0,0) <<  std::endl;
	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	cpp2::mcxi result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() <<" " <<cpp2::test(result1,1) <<  std::endl;
	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	cpp2::mcxi result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << " " <<cpp2::test(result2,2) <<  std::endl;
	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	cpp2::mcxi result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << " " <<cpp2::test(result3,3) <<  std::endl;
	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	cpp2::mcxi result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() <<" " <<cpp2::test(result4,4) <<  std::endl;
	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	cpp2::mcxi result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << " " <<cpp2::test(result5,5) <<  std::endl;
	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	cpp2::mcxi result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << " " <<cpp2::test(result6,6) <<  std::endl;
	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	cpp2::mcxi result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() <<" " <<cpp2::test(result7,7) <<  std::endl;
	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	cpp2::mcxi result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << " " <<cpp2::test(result8,8) <<  std::endl;
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	cpp2::mcxi result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << " " <<cpp2::test(result9,9) <<  std::endl;

	return 0;
}
# ht19a019-cpp2
