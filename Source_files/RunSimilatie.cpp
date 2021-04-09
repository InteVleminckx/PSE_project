/*
 * korte beschrijving:
 * main file om de simulatie uit te voeren.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include "../Header_files/FileParser.h"
//#include "../Header_files/Transport.h"
#include "../Header_files/Distributie.h"

int main(){

    // bestand dat wordt uitgevoerd in de main
    string file = "../testbestandVaccins.xml";
    FileParser parsedFile;
    parsedFile.parseFile(file);
//    parsedFile.uitvoer(); // uitvoer(bestand) aan begin van de simulatie.

    Distributie distributie(parsedFile);

//    parsedFile.uitvoer(false); // uitvoer(bestand) aan einde van de simulatie.

    return 0;
}
