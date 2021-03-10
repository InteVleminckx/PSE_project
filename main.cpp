//
// Created by inte on 25.02.21.
//
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
