#include <iostream>
namespace Avg {
	float Calculate(float x, float y) {
		using namespace std;
		cout << "Calculating..." << endl;
		return (x + y) / 2;
	}
}

namespace Basic {
	float Calculate(float x, float y) {
		using namespace std;
		cout << "Calculating..." << endl;
		return x + y;
	}
}

namespace Sort {
	void Quicksort() {

	}
	void Insertionsort() {

	}
	void Mergesort() {

	}
	namespace Comparison {
		void Less() {

		}
		void Greater() {

		}
	}
}

namespace {
	void InternalFunction() {

	}
}

int main() {
	using std::cout;

	float result = Avg::Calculate(3.1f, 5.2f);
	cout << result << std::endl;

	result = Basic::Calculate(3.1f, 5.2f);
	cout << result << std::endl;

	Sort::Comparison::Less();

	// can only be used in this file
	InternalFunction();

	return 0;
}