//
// Created by inte on 25.02.21.
//

#include "fileParser.h"

int fileParser::parseFile(string &file) {

    if(!doc.LoadFile(file.c_str())) {std::cerr << doc.ErrorDesc() << std::endl; return 1;}

    root = doc.FirstChildElement();

    if(root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }

    parseXML();
    return 0;
}

void fileParser::parseXML() {

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();


        if(elemName == "HUB") {
            TiXmlNode* attr1 = elem->FirstChild("levering")->FirstChild();
            TiXmlNode* attr2 = elem->FirstChild("interval")->FirstChild();
            TiXmlNode* attr3 = elem->FirstChild("transport")->FirstChild();

            if(attr1 != NULL && attr2 != NULL && attr3 != NULL){
                leveringen = atoi(attr1->Value());
                interval = atoi(attr2->Value());
                transport = atoi(attr3->Value());
            }

//            for (TiXmlNode *element = elem->FirstChild("CENTRA"); element != NULL; element = elem->NextSibling()){
//
//                cout << element->Value()<< endl;
//
//            }
        }

        else if (elemName == "VACCINATIECENTRUM"){



        }
    }
}