/*
 * korte beschrijving:
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date:
 * @version:
*/
#include "fileParser.h"
#include "transport.h"

int main(){

    string file = "../bestand2.xml";

    fileParser parsedFile;
    parsedFile.parseFile(file);
    parsedFile.uitvoer();

    transport transportSim(parsedFile);

    parsedFile.uitvoer();

    return 0;

}
