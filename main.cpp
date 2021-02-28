//
// Created by inte on 25.02.21.
//
#include "fileParser.h"
#include "transport.h"

int main(){

    string file = "../bestand1.xml";

    fileParser parsedFile;
    parsedFile.parseFile(file);
    parsedFile.uitvoer();

    transport transportSim(parsedFile);

    return 0;

}
