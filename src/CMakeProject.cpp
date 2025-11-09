// CMakeProject.cpp : définit le point d'entrée de l'application.
//

#include "CMakeProject.h"
#include "Source.cpp"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	Truc truc;
	cout << truc.JAJ();
	return 0;
}

//#include <catch2/catch_test_macros.hpp>

//TEST_CASE("Verifications sur un vector")
//{
//	std::vector<int> v(5);
//
//	REQUIRE(v.size() == 5);
//
//	CHECK(v[0] == 0);
//	CHECK(v[1] == 0);
//	CHECK(v[2] == 0);
//}

//SCENARIO("Les vectors peuvent être dimensionnés et redimensionnés", "[vector]"){
//	GIVEN("Un vector avec quelques éléments"){
//		std::vector<int> v(5);
//		REQUIRE(v.size() == 5);
//
//		WHEN("La taille est augmentée") {
//			v.resize(10);
//			THEN("La taille et la capacité changent"){
//				REQUIRE(v.size() == 10);
//				REQUIRE(v.capacity() >= 10);
//			}
//		}
//		WHEN("Le vector est vidé") {
//			v.clear();
//			THEN("La taille est zéro mais la capacité est inchangée"){
//				REQUIRE(v.size() == 0);
//				REQUIRE(v.capacity() >= 5);
//			}
//		}
//	}
//}
