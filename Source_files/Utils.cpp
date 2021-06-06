//
// Created by inte on 08.04.21.
//

#include "../Header_files/Utils.h"
#include "../Header_files/FileParser.h"
#include "../Header_files/Distributie.h"

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

    if (elem1 == NULL){
        if (elem->FirstChildElement()->FirstChild(tagString) == NULL && isFirstchildElement == true){
            return false;
        }
        if (elem->FirstChild(tagString) == NULL && isFirstchildElement == false){
            return false;
        }
    }

    else{
        if (elem1->FirstChild(tagString) == NULL && isFirstchildElement == false) {
            return false;
        }
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

        for (unsigned int i = 0; i < 6; ++i) {
            isTags.push_back(true);
        }

        if (!isTag("type", elem, false, elem1)) {
            testOutput << "Tag \"type\" niet gevonden.\n";
            isTags[0] = false;
        }
        if (!isTag("levering", elem, false, elem1)) {
            testOutput << "Tag \"levering\" niet gevonden.\n";
            isTags[1] = false;
        }
        if (!isTag("interval", elem, false, elem1)) {
            testOutput << "Tag \"interval\" niet gevonden.\n";
            isTags[2] = false;
        }
        if (!isTag("transport", elem, false, elem1)) {
            testOutput << "Tag \"transport\" niet gevonden.\n";
            isTags[3] = false;
        }
        if (!isTag("hernieuwing", elem, false, elem1)) {
            testOutput << "Tag \"hernieuwing\" niet gevonden.\n";
            isTags[4] = false;
        }
        if (!isTag("temperatuur", elem, false, elem1)) {
            testOutput << "Tag \"temperatuur\" niet gevonden.\n";
            isTags[5] = false;
        }

    }

    else{

        for (unsigned int i = 0; i < 4; ++i) {
            isTags.push_back(true);
        }

        if (!isTag("naam", elem, false, NULL)) {
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

vector<bool> Utils::checkValues(TiXmlElement *elem, TiXmlNode *elem1, bool isVaccins, ofstream &testOutput, const vector<bool>& isTag) {

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

    for (unsigned int i = 0; i < file.getHubs().size(); i++) {

        grafischeOutput << "Hub " << i << ":\n";
        for (unsigned int j = 0; j < file.getHubs()[i]->getHubCentra().size(); j++) {

            grafischeOutput << file.getHubs()[i]->getHubCentra()[j]->getNaam() << ":\n";

            int aantalVaccinsInCentrum = 0;
            map<string, int> mapVaccins = file.getHubs()[i]->getHubCentra()[j]->getVaccinsInCentrum();
            for (map<string, int>::iterator k = mapVaccins.begin(); k != mapVaccins.end(); k++) {
                aantalVaccinsInCentrum += k->second;
            }
            double percentageVaccins = ((double) aantalVaccinsInCentrum/ (double) file.getHubs()[i]->getHubCentra()[j]->getCapaciteit());
            double percentageGevaccineerden = ((double) file.getHubs()[i]->getHubCentra()[j]->getVaccinatedSecondTime()/
                    (double) file.getHubs()[i]->getHubCentra()[j]->getInwoners());

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
    for (unsigned int i = 0; i < file.getHubs().size(); ++i) {

        OutputStat << "Hub " << i << " :\n";

        //OutputStat << ",Pfizer, Moderna, AstraZeneca, ,Gevaccineerden\n";
        for (unsigned int j = 0; j < file.getHubs()[i]->getVaccins().size(); ++j) {
            OutputStat << "," << file.getHubs()[i]->getVaccins()[j]->getType();
        }
        OutputStat << ", ,Aantal\n";

        OutputStat << "Geleverde vaccins";
        for (unsigned int j = 0; j < file.getHubs()[i]->getVaccins().size(); ++j) {
            string type = file.getHubs()[i]->getVaccins()[j]->getType();
            int aantalGeleverdeVaccins = file.getHubs()[i]->getAantalGeleverdeVaccins(type);
            OutputStat << "," << aantalGeleverdeVaccins;
        }
        int totaalAantalGevaccineerdenPerHub = 0;
        for (unsigned int j = 0; j < file.getHubs()[i]->getHubCentra().size(); j++) {
            totaalAantalGevaccineerdenPerHub += file.getHubs()[i]->getHubCentra()[j]->getVaccinatedSecondTime();
        }

        OutputStat << "\n";
        OutputStat << "Gevacineerden per hub";
        for (unsigned int j = 0; j < file.getHubs()[i]->getVaccins().size()+2; ++j) {
            OutputStat << ",";
        }
        OutputStat << totaalAantalGevaccineerdenPerHub;
        OutputStat << "\n";

        totaalAantalGevaccineerden += totaalAantalGevaccineerdenPerHub;

        OutputStat << "\n";

        if (grootsteWaarde < (unsigned int) file.getHubs()[i]->getVaccins().size()+2){
            grootsteWaarde = file.getHubs()[i]->getVaccins().size()+2;
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

void Utils::Graphics(FileParser &file, int day, Distributie* distributie, bool close) {

    if(day == 0){
        fFileList.open("../simulatieOutput/GrafischeVisualitatie/filelist");
    }

    map<string,vector<double> > kleurenMap;

    vector<double> kleurenVectorRGB;
    kleurenVectorRGB.push_back(186); // rood
    kleurenVectorRGB.push_back(33);
    kleurenVectorRGB.push_back(58);
    kleurenMap["0"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(255);
    kleurenVectorRGB.push_back(0);
    kleurenVectorRGB.push_back(0);
    kleurenMap["1"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(243);
    kleurenVectorRGB.push_back(109);
    kleurenVectorRGB.push_back(69);
    kleurenMap["2"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(242);
    kleurenVectorRGB.push_back(172);
    kleurenVectorRGB.push_back(111);
    kleurenMap["3"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(255);
    kleurenVectorRGB.push_back(165);
    kleurenVectorRGB.push_back(0);
    kleurenMap["4"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(255); // geel
    kleurenVectorRGB.push_back(255);
    kleurenVectorRGB.push_back(0);
    kleurenMap["5"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(155);
    kleurenVectorRGB.push_back(205);
    kleurenVectorRGB.push_back(131);
    kleurenMap["6"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(173);
    kleurenVectorRGB.push_back(255);
    kleurenVectorRGB.push_back(47);
    kleurenMap["7"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(0);
    kleurenVectorRGB.push_back(255);
    kleurenVectorRGB.push_back(0);
    kleurenMap["8"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();

    kleurenVectorRGB.push_back(0); // groen
    kleurenVectorRGB.push_back(128);
    kleurenVectorRGB.push_back(0);
    kleurenMap["9"] = kleurenVectorRGB;
    kleurenVectorRGB.clear();


    for (unsigned int i = 0; i < file.getHubs().size(); i++){

        if (distributie->isAllPeopleVaccinatedInHub(file, i) && !close) {
            continue;
        }

        fFileList << "hub_" << i << "_" << day << ".ini\n";

        ofstream iniFile;
        ostringstream sHub;
        ostringstream sDay;

        sHub << i;
        sDay << day;

        int aantalLadingenTotaal = 0;
        for (unsigned int j = 0; j < file.getHubs()[i]->getHubCentra().size(); ++j) {
            aantalLadingenTotaal += file.getHubs()[i]->getHubCentra()[j]->getLadingen();
        }

        string path = "../simulatieOutput/GrafischeVisualitatie/hub_" + sHub.str() + "_" + sDay.str() + ".ini";
        int figures = 9 + (2*file.getHubs()[i]->getHubCentra().size()) + aantalLadingenTotaal;
        iniFile.open(path.c_str());


        iniFile << "[General]" << endl;
        iniFile << "size =1024" << endl;
        iniFile << "backgroundcolor = (0, 0, 0)" << endl;
        iniFile << "type = \"LightedZBuffering\"" << endl;
        iniFile << "nrLights = 1" << endl;
        iniFile << "eye = (-135, 0, 75)" << endl;
        iniFile << "nrFigures = " << figures << "\n";

        iniFile << "[Light0]" << endl;
        iniFile << "infinity = TRUE" << endl;
        iniFile << "direction = (-1, -1, -1)" << endl;
        iniFile << "ambientLight = (1, 1, 1)" << "\n";
        iniFile << "diffuseLight = (1, 1, 1)" << "\n";

        double yCenter = 0.5;

        for (unsigned int j = 0; j < file.fHubs[i]->fHubCentra.size(); ++j) {

            //even
            if (j != 0  && j % 2 == 0){
                yCenter*=-1;
                yCenter+=1;
            }
                //oneven
            else if (j != 0  && j % 2 != 0){
                yCenter*=-1;
            }

            iniFile << "[Figure" <<  j << "]" << endl;
            iniFile << "type = \"Cylinder\"" << endl;
            iniFile << "height = " << 4.99 << endl;
            iniFile << "n = 36" << endl;
            iniFile << "scale = 0.25" << endl;
            iniFile << "rotateX = 0" << endl;
            iniFile << "rotateY = 0" << endl;
            iniFile << "rotateZ = 0" << endl;
            iniFile << "center = " << "(0.001, " << yCenter << ", 1)" << endl;
            iniFile << "ambientReflection = (" << 0.5 << "," << 0.5 << "," << 0.5 << ")" << endl;
            iniFile << "diffuseReflection = (" << 0.5 << "," << 0.5 << "," << 0.5 << ")" << endl;
        }

        yCenter = 0.5;


        vector<double> color; // de kleur dat het centrum voorstellende object moet hebben.
        for (unsigned int j = 0; j < file.fHubs[i]->fHubCentra.size(); j++) {

            iniFile << "[Figure" <<  j+file.fHubs[i]->fHubCentra.size() << "]" << endl;
            iniFile << "type = \"Cylinder\"" << endl;

            //even
            if (j != 0  && j % 2 == 0){
                yCenter*=-1;
                yCenter+=1;
            }
            //oneven
            else if (j != 0  && j % 2 != 0){
                yCenter*=-1;
            }


            int aantalGevaccineerden = file.fHubs[i]->fHubCentra[j]->getVaccinatedSecondTime();
            int verhouding = aantalGevaccineerden*100/file.fHubs[i]->fHubCentra[j]->getInwoners();
            ostringstream firstNumberOfVerhouding;
            firstNumberOfVerhouding << verhouding;
            string firstNumberOfVerhoudingString;
            if (firstNumberOfVerhouding.str().size() == 1) {
                firstNumberOfVerhoudingString = "0" + firstNumberOfVerhouding.str();
                firstNumberOfVerhoudingString = firstNumberOfVerhoudingString[0];
            }
            else{
                firstNumberOfVerhoudingString = firstNumberOfVerhouding.str()[0];
            }


            if (verhouding != 100) {
                color = kleurenMap[firstNumberOfVerhoudingString];
            }
            else {
                color.clear();
                color.push_back(0); // zeer donker groen als we op exact 100% zitten.
                color.push_back(100);
                color.push_back(0);
            }

            double deling = (double) verhouding/100 * 5;
            double kleur = (double) verhouding/100;


            iniFile << "height = " << deling << endl;
            iniFile << "n = 36" << endl;
            iniFile << "scale = 0.25" << endl;
            iniFile << "rotateX = 0" << endl;
            iniFile << "rotateY = 0" << endl;
            iniFile << "rotateZ = 0" << endl;
            iniFile << "center = " << "(0, " << yCenter << ", 1)" << endl;
            iniFile << "ambientReflection = (" << 1-kleur << "," << kleur << "," << 0 << ")" << endl;
            iniFile << "diffuseReflection = (" << 1-kleur << "," << kleur << "," << 0 << ")" << endl;

        }

        int allVaccinsInHub = 0;

        for (unsigned int j = 0; j < file.fHubs[i]->fVaccins.size(); ++j) {
            allVaccinsInHub += file.fHubs[i]->fVaccins[j]->getAantalVaccins();
        }

        map<int, pair<string, vector<double> > > figuren;
        kleurenVectorRGB.clear();
        kleurenVectorRGB.push_back(0.5); // oranje
        kleurenVectorRGB.push_back(0.25);
        kleurenVectorRGB.push_back(0);
        figuren[50000] = make_pair("Cube", kleurenVectorRGB);
        kleurenVectorRGB.clear();
        kleurenVectorRGB.push_back(0); // groen
        kleurenVectorRGB.push_back(0.5);
        kleurenVectorRGB.push_back(0);
        figuren[250000] = make_pair("Cone", kleurenVectorRGB);
        kleurenVectorRGB.clear();
        kleurenVectorRGB.push_back(0); // cyaan
        kleurenVectorRGB.push_back(0.5);
        kleurenVectorRGB.push_back(0.5);
        figuren[1250000] = make_pair("Sphere", kleurenVectorRGB);
        kleurenVectorRGB.clear();
        kleurenVectorRGB.push_back(0.5); // geel
        kleurenVectorRGB.push_back(0.5);
        kleurenVectorRGB.push_back(0);
        figuren[6250000] = make_pair("Torus", kleurenVectorRGB);
        kleurenVectorRGB.clear();
        kleurenVectorRGB.push_back(0.38); // paars
        kleurenVectorRGB.push_back(0);
        kleurenVectorRGB.push_back(0.38);
        figuren[31250000] = make_pair("Octahedron", kleurenVectorRGB);

        string figuur;
        vector<double> kleur;
        int aantal = 0;
        for (map<int,pair<string, vector<double> > >::iterator it = figuren.begin(); it != figuren.end(); it++) {
            if (allVaccinsInHub < it->first) {
                figuur = it->second.first;
                kleur = it->second.second;
                aantal = it->first;
                break;
            }
        }


        iniFile << "[Figure" << (2*file.fHubs[i]->fHubCentra.size()) << "]" << endl;
        iniFile << "type = \"Cylinder\"" << endl;
        iniFile << "height = 1" << endl;
        iniFile << "n = 36" << endl;
        iniFile << "scale = 1" << endl;
        iniFile << "rotateX = 0" << endl;
        iniFile << "rotateY = 0" << endl;
        iniFile << "rotateZ = 0" << endl;
        iniFile << "center = (0, 0, -3)" << endl;
        iniFile << "ambientReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
        iniFile << "diffuseReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;

        iniFile << "[Figure" << (2*file.fHubs[i]->fHubCentra.size())+1 << "]\n";
        iniFile << "type = \"Cone\"" << endl;
        iniFile << "height = 1" << endl;
        iniFile << "n = 36" << endl;
        iniFile << "scale = 1.15" << endl;
        iniFile << "rotateX = 0" << endl;
        iniFile << "rotateY = 0" << endl;
        iniFile << "rotateZ = 0" << endl;
        iniFile << "center = (0, 0, -2)" << endl;
        iniFile << "ambientReflection = (0.4, 0.2, 0.00)" << endl;
        iniFile << "diffuseReflection = (0.4, 0.2, 0.00)" << endl;

        iniFile << "[Figure" << (2*file.fHubs[i]->fHubCentra.size())+2 << "]" << endl;
        iniFile << "type = \"Torus\"" << endl;
        iniFile << "r = 1" << endl;
        iniFile << "R = 3" << endl;
        iniFile << "m = 36" << endl;
        iniFile << "n = 36" << endl;
        iniFile << "scale = 0.1" << endl;
        iniFile << "rotateX = 0" << endl;
        iniFile << "rotateY = 0" << endl;
        iniFile << "rotateZ = 0" << endl;
        iniFile << "center = (0, 2.5, -6)" << endl;
        iniFile << "ambientReflection = (0.0, 0.0, 0.00)" << endl;
        iniFile << "diffuseReflection = (0.0, 0.0, 0.00)" << endl;

        iniFile << "[Figure" << (2*file.fHubs[i]->fHubCentra.size())+3 << "]" << endl;
        iniFile << "type = \"Torus\"" << endl;
        iniFile << "r = 1" << endl;
        iniFile << "R = 3" << endl;
        iniFile << "m = 36" << endl;
        iniFile << "n = 36" << endl;
        iniFile << "scale = 0.1" << endl;
        iniFile << "rotateX = 0" << endl;
        iniFile << "rotateY = 0" << endl;
        iniFile << "rotateZ = 0" << endl;
        iniFile << "center = (0, -2.5, -6)" << endl;
        iniFile << "ambientReflection = (0.0, 0.0, 0.00)" << endl;
        iniFile << "diffuseReflection = (0.0, 0.0, 0.00)" << endl;


        unsigned int aantalFiguren = floor(allVaccinsInHub/(aantal/5));
        unsigned int nietFiguren  = 5 - floor(allVaccinsInHub/(aantal/5));

        for (unsigned int j = 0; j < aantalFiguren;j++) {
            iniFile << "[Figure" << (2*file.fHubs[i]->fHubCentra.size())+4+j << "]" << endl;

            vector<double> coord;
            coord.push_back(0);
            coord.push_back(-2+(int)j);
            coord.push_back(-5);
            if (figuur == "Cube") {
                createCube(iniFile, coord, kleur);
            }
            else if (figuur == "Cone") {
                createCone(iniFile, coord, kleur);
            }
            else if (figuur == "Sphere") {
                createSphere(iniFile, coord, kleur);
            }
            else if (figuur == "Torus") {
                createTorus(iniFile, coord, kleur);
            }
            else if (figuur == "Octahedron") {
                createOctahedron(iniFile, coord, kleur);
            }
        }


        for (unsigned int j = aantalFiguren; j < nietFiguren+aantalFiguren;j++) {
            iniFile << "[Figure" << (2*file.fHubs[i]->fHubCentra.size())+4+j << "]" << endl;

            vector<double> zwart;
            zwart.push_back(0);
            zwart.push_back(0);
            zwart.push_back(0);
            vector<double> coord;
            coord.push_back(0);
            coord.push_back(+2-(int)j);
            coord.push_back(-5);
            if (figuur == "Cube") {
                createCube(iniFile, coord, zwart);
            }
            else if (figuur == "Cone") {
                createCone(iniFile, coord, zwart);
            }
            else if (figuur == "Sphere") {
                createSphere(iniFile, coord, zwart);
            }
            else if (figuur == "Torus") {
                createTorus(iniFile, coord, zwart);
            }
            else if (figuur == "Octahedron") {
                createOctahedron(iniFile, coord, zwart);
            }
        }

        yCenter = 0.5;

        int figureNumber = 17;

        for (unsigned int j = 0; j < file.fHubs[i]->fHubCentra.size(); ++j) {

            int ladingen = file.getHubs()[i]->getHubCentra()[j]->getLadingen();
            //even
            if (j != 0  && j % 2 == 0){
                yCenter*=-1;
                yCenter+=1;
            }
                //oneven
            else if (j != 0  && j % 2 != 0){
                yCenter*=-1;
            }

            double zPos = 0.7;

            for (unsigned int k = 0; (int) k < ladingen; k++) {

                iniFile << "[Figure" << figureNumber << "]" << endl;
                iniFile << "type = \"Sphere\"" << endl;
                iniFile << "n = 3" << endl;
                iniFile << "scale = 0.05" << endl;
                iniFile << "rotateX = 0" << endl;
                iniFile << "rotateY = 0" << endl;
                iniFile << "rotateZ = 0" << endl;
                iniFile << "center = " << "(0, " << yCenter << "," << zPos - (0.2*k) << ")" << endl;
                iniFile << "ambientReflection = (0.00, 0.50, 1.0)" << endl;
                iniFile << "diffuseReflection = (0.00, 0.50, 1.0)" << endl;

                figureNumber++;
            }
        }

        iniFile.close();
    }

    if (close){
        fFileList.close();
    }
}

void Utils::createCube(ofstream &iniFile, vector<double> coord, vector<double> kleur) {
    iniFile << "type = \"Cube\"" << endl;
    iniFile << "scale = 0.25" << endl;
    iniFile << "rotateX = 0" << endl;
    iniFile << "rotateY = 0" << endl;
    iniFile << "rotateZ = 0" << endl;
    iniFile << "center = (" << coord[0] << "," << coord[1] << "," << coord[2] << ")" << endl;
    iniFile << "ambientReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
    iniFile << "diffuseReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;

}

void Utils::createCone(ofstream &iniFile, vector<double> coord, vector<double> kleur) {
    iniFile << "type = \"Cone\"" << endl;
    iniFile << "height = 2.5" << endl;
    iniFile << "n = 36" << endl;
    iniFile << "scale = 0.35" << endl;
    iniFile << "rotateX = 0" << endl;
    iniFile << "rotateY = 0" << endl;
    iniFile << "rotateZ = 0" << endl;
    iniFile << "center = (" << coord[0] << "," << coord[1] << "," << coord[2] << ")" << endl;
    iniFile << "ambientReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
    iniFile << "diffuseReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
}

void Utils::createTorus(ofstream &iniFile, vector<double> coord, vector<double> kleur) {
    iniFile << "type = \"Torus\"" << endl;
    iniFile << "r = 1" << endl;
    iniFile << "R = 3" << endl;
    iniFile << "m = 36" << endl;
    iniFile << "n = 36" << endl;
    iniFile << "scale = 0.1" << endl;
    iniFile << "rotateX = 0" << endl;
    iniFile << "rotateY = 0" << endl;
    iniFile << "rotateZ = 0" << endl;
    iniFile << "center = (" << coord[0] << "," << coord[1] << "," << coord[2] << ")" << endl;
    iniFile << "ambientReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
    iniFile << "diffuseReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
}

void Utils::createOctahedron(ofstream &iniFile, vector<double> coord, vector<double> kleur) {
    iniFile << "type = \"Octahedron\"" << endl;
    iniFile << "scale = 0.35" << endl;
    iniFile << "rotateX = 0" << endl;
    iniFile << "rotateY = 0" << endl;
    iniFile << "rotateZ = 0" << endl;
    iniFile << "center = (" << coord[0] << "," << coord[1] << "," << coord[2] << ")" << endl;
    iniFile << "ambientReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
    iniFile << "diffuseReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
}

void Utils::createSphere(ofstream &iniFile, vector<double> coord, vector<double> kleur){

    iniFile << "type = \"Sphere\" "  << endl;
    iniFile << "n = 3 " << endl;
    iniFile << "scale = 0.3 " << endl;
    iniFile << "rotateX = 0 " << endl;
    iniFile << "rotateY = 0 " << endl;
    iniFile << "rotateZ = 0 " << endl;
    iniFile << "center = (" << coord[0] << "," << coord[1] << "," << coord[2] << ")" << endl;
    iniFile << "ambientReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;
    iniFile << "diffuseReflection = (" << kleur[0] << "," << kleur[1] << "," << kleur[2] << ")" << endl;


}
