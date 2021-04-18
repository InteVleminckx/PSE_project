//
// Created by inte on 08.04.21.
//

#include "../Header_files/Utils.h"
#include "../Header_files/FileParser.h"

bool Utils::isDigit(const string &str) {

    for (unsigned int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool Utils::isAlpha(const string &str) {

    for (unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] != 32 ){
            if (!(isalpha(str[i]))) {
                return false;
            }
        }
    }
    return true;
}

bool Utils::isAlphaNum(const string &str) {

    for (unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] != 32 && str[i] != 44 && str[i] != 45) {
            if (!isalnum(str[i])) {
                return false;
            }
        }
    }
    return true;
}

bool Utils::isTag(const string &tag, TiXmlElement *elem, bool isFirstchildElement, TiXmlNode* elem1) {

    const char *tagString = tag.c_str();

    if (elem->FirstChildElement()->FirstChild(tagString) == NULL && isFirstchildElement == true){
        return false;
    }
    if (elem->FirstChild(tagString) == NULL && isFirstchildElement == false){
        return false;
    }

    return true;
}

bool Utils::isLittleAlpha(const string &str) {

    for (unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] != 32 ){
            if (str[i] < 'a' || 'z' < str[i]) {
                return false;
            }
        }
    }
    return true;
}

bool Utils::isCorrectTemperature(const string &str) {

    //negatief
    if (str[0] == '-'){
        string strN;
        for (unsigned int i = 1; i < str.size(); ++i) strN.push_back(str[i]);
        return isDigit(strN);
    }

    //positief
    else {
        return isDigit(str);
    }
}

vector<bool> Utils::checkTags(TiXmlElement *elem, bool isFirstchildElement, ofstream &testOutput, TiXmlNode* elem1) {

    vector<bool> isTags;

    if (isFirstchildElement) {

        if (!isTag("type", elem, false, elem1)) {
            testOutput << "Tag \"type\" niet gevonden.\n";
            isTags[0] = false;
        }
        if (!isTag("levering", elem, false, elem1)) {
            testOutput << "Tag \"levering\" niet gevonden.\n";
        }
        if (!isTag("interval", elem, false, elem1)) {
            testOutput << "Tag \"interval\" niet gevonden.\n";
        }
        if (!isTag("transport", elem, false, elem1)) {
            testOutput << "Tag \"transport\" niet gevonden.\n";
        }
        if (!isTag("hernieuwing", elem, false, elem1)) {
            testOutput << "Tag \"hernieuwing\" niet gevonden.\n";
        }
        if (!isTag("temperatuur", elem, false, elem1)) {
            testOutput << "Tag \"temperatuur\" niet gevonden.\n";
        }

    }

    else{
        if (!isTag("naam", elem, false)) {
            testOutput << "Tag \"naam\" niet gevonden.\n";
            isTags[0] = false;
        }
        if (!isTag("adres", elem, false, NULL)) {
            testOutput << "Tag \"adres\" niet gevonden.\n";
            isTags[1] = false;
        }
        if (!isTag("inwoners", elem, false, NULL)) {
            testOutput << "Tag \"inwoners\" niet gevonden.\n";
            isTags[2] = false;
        }
        if (!isTag("capaciteit", elem, false, NULL)) {
            testOutput << "Tag \"capaciteit\" niet gevonden.\n";
            isTags[3] = false;
        }
    }
    return isTags;
}

void Utils::checkValues(TiXmlElement *elem, TiXmlNode *elem1, bool isVaccins, ofstream &testOutput) {

    vector<bool> isValue;

    if (isVaccins){

        for (int i = 0; i < 6; ++i) {
            isValue.push_back(true);
        }

        if (isTag[0]){
            TiXmlNode* type = elem1->FirstChild("type")->FirstChild();
            if (!isAlpha(type->Value())){
                testOutput << "Type van een vaccin moet een string zijn.\n";
                isValue[0] = false;
            }
        }
        else{
            isValue[0] = false;
        }

        if (isTag[1]){
            TiXmlNode* levering = elem1->FirstChild("levering")->FirstChild();
            if (!isDigit(levering->Value())){
                testOutput << "Levering moet een positieve integer zijn.\n";
                isValue[1] = false;
            }
        }
        else{
            isValue[1] = false;
        }

        if(isTag[2]){
            TiXmlNode* interval = elem1->FirstChild("interval")->FirstChild();
            if (!isDigit(interval->Value())){
                testOutput << "Interval moet een positieve integer zijn.\n";
                isValue[2] = false;
            }
        }
        else{
            isValue[2] = false;
        }

        if (isTag[3]) {
            TiXmlNode* transport = elem1->FirstChild("transport")->FirstChild();
            if (!isDigit(transport->Value())){
                testOutput << "Transport moet een positieve integer zijn.\n";
                isValue[3] = false;
            }
        }
        else {
            isValue[3] = false;
        }

        if (isTag[4]) {
            TiXmlNode* hernieuwing = elem1->FirstChild("hernieuwing")->FirstChild();
            if (!isDigit(hernieuwing->Value())){
                testOutput << "Hernieuwing moet een positieve integer zijn.\n";
                isValue[4] = false;
            }
        }
        else {
            isValue[4] = false;
        }

        if(isTag[5]){
            TiXmlNode* temperatuur = elem1->FirstChild("temperatuur")->FirstChild();
            if (!isCorrectTemperature(temperatuur->Value())){
                testOutput << "Temperatuur moet een positieve of negatief integer zijn.\n";
                isValue[5] = false;
            }
        }
        else{
            isValue[5] = false;
        }

    }

    else{

        for (int i = 0; i < 4; ++i) {
            isValue.push_back(true);
        }

        if (isTag[0]) {
            TiXmlNode* naam = elem->FirstChild("naam")->FirstChild();
            if (!isAlpha(naam->Value())){
                testOutput << "Naam van een centrum moet een string zijn.\n";
                isValue[0] = false;
            }
        }
        else {
            isValue[0] = false;
        }

        if(isTag[1]){
            TiXmlNode* adres = elem->FirstChild("adres")->FirstChild();
            if (!isAlphaNum(adres->Value())){
                testOutput << "Adres moet bestaan uit een string (en integers).\n";
                isValue[1] = false;
            }
        }
        else{
            isValue[1] = false;
        }

        if (isTag[2]){
            TiXmlNode* inwoners = elem->FirstChild("inwoners")->FirstChild();
            if (!isDigit(inwoners->Value())){
                testOutput << "Inwoners moet een positieve integer zijn.\n";
                isValue[2] = false;
            }
        }
        else{
            isValue[2] = false;
        }

        if (isTag[3]) {
            TiXmlNode* capaciteit = elem->FirstChild("capaciteit")->FirstChild();
            if (!isDigit(capaciteit->Value())){
                testOutput << "Capaciteit moet een positieve integer zijn.\n";
                isValue[3] = false;
            }
        }
        else {
            isValue[3] = false;
        }
    }

    return isValue;
}

void Utils::grafischeImpressie(FileParser &file) {

    ofstream grafischeOutput;
    grafischeOutput.open("../simulatieOutput/grafischeOutput.txt");

    for (unsigned int i = 0; i < file.fHubs.size(); i++) {

        grafischeOutput << "Hub " << i << ":\n";
        for (unsigned int j = 0; j < file.fHubs[i]->fHubCentra.size(); j++) {

            grafischeOutput << file.fHubs[i]->fHubCentra[j]->getNaam() << ":\n";

            int aantalVaccinsInCentrum = 0;
            map<string, int> mapVaccins = file.fHubs[i]->fHubCentra[j]->getVaccinsInCentrum();
            for (map<string, int>::iterator k = mapVaccins.begin(); k != mapVaccins.end(); k++) {
                aantalVaccinsInCentrum += k->second;
            }
            double percentageVaccins = ((double) aantalVaccinsInCentrum/ (double) file.fHubs[i]->fHubCentra[j]->getCapaciteit());
            double percentageGevaccineerden = ((double) file.fHubs[i]->fHubCentra[j]->getVaccinatedSecondTime()/
                    (double) file.fHubs[i]->fHubCentra[j]->getInwoners());

            string laadbalk;
            laadbalk = "[";
            for (unsigned int l = 0; l < 20; l++) { // tot 20 want in het voorbeeld is het aantal '='.
                if (l < round(20*percentageVaccins)) {
                    laadbalk+="=";
                }
                else {
                    laadbalk+=" ";
                }
            }
            laadbalk += "]";
            grafischeOutput << "\t- vaccins\t\t    " << laadbalk << round(percentageVaccins*100) << "%\n";

            laadbalk = "[";
            for (unsigned int l = 0; l < 20; l++) {
                if (l < round(20*percentageGevaccineerden)) {
                    laadbalk+="=";
                }
                else {
                    laadbalk+=" ";
                }
            }
            laadbalk += "]";

            grafischeOutput << "\t- gevaccineerden\t" << laadbalk << round(percentageGevaccineerden*100) << "%\n";
        }
        grafischeOutput << "\n";
    }
}

void Utils::statistischeVerwerking(FileParser &file) {

    ofstream OutputStat;
    unsigned int grootsteWaarde = 0;

    OutputStat.open("../simulatieOutput/overzichtStatischeVerwerking.cvs");
    OutputStat << "Statistische gegevens\n";
    int totaalAantalGevaccineerden = 0;
    for (unsigned int i = 0; i < file.fHubs.size(); ++i) {

        OutputStat << "Hub " << i << " :\n";

        //OutputStat << ",Pfizer, Moderna, AstraZeneca, ,Gevaccineerden\n";
        for (unsigned int j = 0; j < file.fHubs[i]->fVaccins.size(); ++j) {
            OutputStat << "," << file.fHubs[i]->fVaccins[j]->getType();
        }
        OutputStat << ", ,Aantal\n";

        OutputStat << "Geleverde vaccins";
        for (unsigned int j = 0; j < file.fHubs[i]->fVaccins.size(); ++j) {
            string type = file.fHubs[i]->fVaccins[j]->getType();
            int aantalGeleverdeVaccins = file.fHubs[i]->getAantalGeleverdeVaccins(type);
            OutputStat << "," << aantalGeleverdeVaccins;
        }
        int totaalAantalGevaccineerdenPerHub = 0;
        for (unsigned int j = 0; j < file.fHubs[i]->fHubCentra.size(); j++) {
            totaalAantalGevaccineerdenPerHub += file.fHubs[i]->fHubCentra[j]->getVaccinatedSecondTime();
        }

        OutputStat << "\n";
        OutputStat << "Gevacineerden per hub";
        for (unsigned int j = 0; j < file.fHubs[i]->fVaccins.size()+2; ++j) {
            OutputStat << ",";
        }
        OutputStat << totaalAantalGevaccineerdenPerHub;
        OutputStat << "\n";

        totaalAantalGevaccineerden += totaalAantalGevaccineerdenPerHub;

        OutputStat << "\n";

        if (grootsteWaarde < (unsigned int) file.fHubs[i]->fVaccins.size()+2){
            grootsteWaarde = file.fHubs[i]->fVaccins.size()+2;
        }

    }

    OutputStat << "\n";
    OutputStat << "Totaal aantal gevaccineerden: ";

    for (unsigned int i = 0; i < grootsteWaarde; ++i) {
        OutputStat << ",";
    }

    OutputStat << totaalAantalGevaccineerden;

    OutputStat.close();
}
