1.	#include <iostream>
2.	#include <vector>
3.	#include <cerrno>
4.
5.	#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。 
6.
7.	bool IsPrime(int num)
8.	{
	9.		if (num < 2) return false;
	10.		else if (num == 2) return true;
	11.		else if (num % 2 == 0) return false;
	12.
		13.		double sqrtNum = sqrt(num);
	14.		for (int i = 3; i <= sqrtNum; i += 2)
		15.		{
		16.			if (num % i == 0)
			17.			{
			18.				return false;
			19.			}
		20.		}
	21.
		22.		return true;
	23.	}
24.	/* --------------------------------------------------------------- */
25.	/*
	26.	 *  nth_prime
	27.	 *
	28.	 *  与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
	29.	 *  素数を返す。
	30.	 *
	31.	 *  TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
	32.	 *  ファイルを作成せよ。
	33.	 */
	34.	 /* -------------------------------------------------------------- */
	35.	int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	36.		if (n <= 0 || (a <= 0 || d <= 0)) {
		37.			std::cerr << "invalid arguments";
		38.			exit(EXIT_FAILURE);
		39.
	}
	40.
		41.		uint32_t* prime;
	42.		prime = (uint32_t *)malloc(sizeof(uint32_t) * n);
	43.
		44.		uint32_t prime_index = 0;
	45.		uint32_t num = a;
	46.
		47.		for (int i = 1; i < CPP2_PRIME_UPPER_LIMIT; i++) {
		48.			if (IsPrime(num) == true) {
			49.				prime[prime_index] = num;
			50.				prime_index++;
			51.				if (prime_index > n) {
				52.					break;
				53.
			}
			54.
		}
		55.			num += d;
		56.
	}
	57.		return prime[n - 1];
	58.
};
59.
60.	int main() {
	61.		std::cout << nth_prime(367, 186, 151) << std::endl;
	62.		std::cout << nth_prime(179, 10, 203) << std::endl;
	63.		std::cout << nth_prime(271, 37, 39) << std::endl;
	64.		std::cout << nth_prime(103, 230, 1) << std::endl;
	65.		std::cout << nth_prime(27, 104, 185) << std::endl;
	66.		std::cout << nth_prime(253, 50, 85) << std::endl;
	67.		std::cout << nth_prime(1, 1, 1) << std::endl;
	68.		std::cout << nth_prime(9075, 337, 210) << std::endl;
	69.		std::cout << nth_prime(307, 24, 79) << std::endl;
	70.		std::cout << nth_prime(331, 221, 177) << std::endl;
	71.		std::cout << nth_prime(259, 170, 40) << std::endl;
	72.		std::cout << nth_prime(269, 58, 102) << std::endl;
	73.
		74.		return 0;
}# ht19a019-cpp2
