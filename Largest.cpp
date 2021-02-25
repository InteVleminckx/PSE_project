//
//  main.cpp
//  SimpleCalculator
//
//  Created by Quinten Soetens on 12/02/14.
//  Copyright (c) 2014 Quinten Soetens. All rights reserved.
//

#include <iostream>
#include <limits>
#include <vector>
#include "Exceptions.h"
using namespace std;

int largest(vector<int>* list){
    int max = numeric_limits<int>::min();

    for(int i = 0; i < list->size(); i++){
        if(list->at(i) > max){
            max = list->at(i);
        }
    }
    return max;
}


int largest2(vector<int>* list) {
    if(list == nullptr) {
        throw new IllegalArgumentException("list cannot be nullptr");
    }else if(list->empty()){
        throw new IllegalArgumentException("list cannot be empty");
    }
    int max = numeric_limits<int>::min();
    for(int i = 0; i < list->size(); i++){
        if(list->at(i) > max){
            max = list->at(i);
        }
    }
    return max;
    return 0;
}

//int main(int argc, const char * argv[])
//{
//    vector<int>* listOfNumbers = new vector<int>();
//    listOfNumbers->push_back(5);
//    listOfNumbers->push_back(7);
//    listOfNumbers->push_back(3);
//    listOfNumbers->push_back(1);
//    listOfNumbers->push_back(-1);
//
//    cout << largest(listOfNumbers) << endl;
//    cout << largest2(listOfNumbers) << endl;
//    try{
//        cout << largest2(nullptr) << endl;
//    }catch(exception * e){
//        cout << e->what() << endl;
//    }
//    try{
//        cout << largest2(new vector<int>()) << endl;
//    }catch(exception * e){
//        cout << e->what() << endl;
//    }
//
//
//}

