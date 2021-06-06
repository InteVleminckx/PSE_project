/*
 * korte beschrijving:
 * (SimulatieUtils), bevat twee functies: DirectoryExists en FileCompare die we nodig hebben voor de testen.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 07/06/2021
 * @version: Specificatie 2.1
 * @bron: TicTacToe19
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_SIMULATIEUTILS_H
#define PROJECT_SOFTWARE_ENGENEERING_SIMULATIEUTILS_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>

/*
 * @functie : DirectoryExists (overgenomen uit TicTacToe19)
 * Deze functie kijkt na of de directory bestaat.
 * @param dirname : string, pad van de directory.
 * @return : bool, true als de directoty bestaat, false als deze niet bestaat.
 */
bool DirectoryExists(const std::string dirname);


/*
 * @functie : FileCompare (overgenomen uit TicTacToe19)
 * Deze functie kijkt na of de inhoud van 2 bestanden hetzelfde is.
 * @param leftFileName : string, pad van het eerste bestand.
 * @param rightFileName : string, pad van het tweede bestand.
 * @return : bool, true als de bestanden indentiek zijn, false als dat niet zo is.
 */
bool FileCompare(const std::string leftFileName, const std::string rightFileName);


#endif //PROJECT_SOFTWARE_ENGENEERING_SIMULATIEUTILS_H
