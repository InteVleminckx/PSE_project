/*
 * korte beschrijving:
 * Roept alle testen op.
 * Deze klasse runt alle testen.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 07/06/2021
 * @version: Specificatie 2.1
 */


#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}