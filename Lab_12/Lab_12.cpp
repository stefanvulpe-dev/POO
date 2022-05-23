#include <iostream>
#include "catch_amalgamated.hpp"

int arr1[5] = { 1, 7, 6, 3, 5 };
int arr2[5] = { 1, 2, 3, 4, 5 };
double arr3[5] = { 3.75, 9.21, 1.54, 7.43, 6.43 };
double arr4[5] = { 1.25, 2.26, 3.27, 4.28, 6.89 };
float arr5[5] = { 9.54f, 10.24f, 5.31f, 6.34f, 6.32f };

template <typename T>
void sort_array(T* arr, int n, bool (*f)(T, T)) {
	bool ok;
	do {
		ok = true; 
		for (int i = 0; i < n - 1; ++i) {
			if (f(arr[i], arr[i + 1])) {
				std::swap(arr[i], arr[i + 1]); 
				ok = false;
			}
		}
	} while (ok == false);
}

template <typename T>
bool is_sorted(T* arr, int n) {
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool is_greater(T a, T b) {
	return a > b;
}

TEST_CASE("sort1") {
	REQUIRE(is_sorted<int>(arr1, 5));
	REQUIRE(is_sorted<int>(arr2, 5));
	REQUIRE(is_sorted<double>(arr3, 5));
	REQUIRE(is_sorted<double>(arr4, 5));
	REQUIRE(is_sorted<float>(arr5, 5));
}

TEST_CASE("sort2") {
	sort_array<int>(arr1, 5, &is_greater);
	sort_array<int>(arr2, 5, &is_greater);
	sort_array<double>(arr3, 5, &is_greater);
	sort_array<double>(arr4, 5, &is_greater);
	sort_array<float>(arr5, 5, &is_greater);
	REQUIRE(is_sorted<int>(arr1, 5));
	REQUIRE(is_sorted<int>(arr2, 5));
	REQUIRE(is_sorted<double>(arr3, 5));
	REQUIRE(is_sorted<double>(arr4, 5));
	REQUIRE(is_sorted<float>(arr5, 5));
}