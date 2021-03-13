/*
 * korte beschrijving:
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date:
 * @version:
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
