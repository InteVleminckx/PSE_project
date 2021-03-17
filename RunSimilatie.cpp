/*
 * korte beschrijving:
 * main file om de simulatie uit te voeren.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include "FileParser.h"
#include "Transport.h"

int main(){

    string file = "../bestand1.xml";
    FileParser parsedFile;
    parsedFile.parseFile(file);
    parsedFile.uitvoer();
    Transport transportSim(parsedFile);
    parsedFile.uitvoer();
    return 0;

}
