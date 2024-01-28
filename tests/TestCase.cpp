#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
// Vos tests
TEST_CASE("Exemple de test simple") {
    int a = 2;
    int b = 3;

    // Vérifier que a + b est égal à 5
    REQUIRE(a + b == 5);
}