/*
 * korte beschrijving:
 * main file om de simulatie uit te voeren.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 07/06/2021
 * @version: Specificatie 2.1
*/

#include "../Header_files/FileParser.h"
#include "../Header_files/Distributie.h"

int main(){

    // bestand dat wordt uitgevoerd in de main
    string file = "../test-bestanden/systemFiles/systemTest7.xml";
    FileParser parsedFile;
    parsedFile.parseFile(file);
//    parsedFile.uitvoer(); // uitvoer(bestand) aan begin van de simulatie.

    Distributie distributie(parsedFile);

    parsedFile.uitvoer(false); // uitvoer(bestand) aan einde van de simulatie.

    Utils::grafischeImpressie(parsedFile);
    Utils::statistischeVerwerking(parsedFile);
    return 0;
}
