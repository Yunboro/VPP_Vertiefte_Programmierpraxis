#include "soundex.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <cstring>
//#include <ctype.h> // Methode isalpha() prüft, ob char im alphabet. Wenn falschd dann 0

std::string soundex(char wort[], char code[]){
    size_t length = strlen(wort) +1; //Länge des Wortes +1 für NULL-Byte
    int pos = 1;
    char* wort_cpy = new char[length]; //Kopier das Wort in ein lokales Feld
    for(int i=0;i<4;++i){ //Sezte das Codewort leer, da Artifakte beim Einlesen
        code[i] = ' '; //Achtung: Keine Gänsefüßchen. Sondern Apostrophe
    }
    strcpy(wort_cpy, wort);
    std::cout << wort_cpy << std::endl;
    std::cout << code << std::endl;
    kleinNachGross(wort_cpy);
    code[0] = wort_cpy[0];
    int i = 1; //Deklaration innerhalb geht nicht, sonst verliert man Sie nach jeder Iteration
    while(pos < 4 && wort_cpy[i] != '\0'){
        char zeichen = zeichenCode(wort_cpy[i]);
        if((zeichen != '0') && (zeichen != code[i-1])){
            code[pos] = zeichen;
            pos++;
        }
        i++;
    }

    //Vorsicht int i iteriert hier nur durch das array
    //Bildet nicht die jeweilige Stelle ab, wo es abgespeichert werden soll
    //Am letzten Buchstaben ist i > 4. Dann wird es nicht innerhalb von code0123 zugewiesen
    /*for(int i = pos; i < int(length); ++i) {
        char zeichen = zeichenCode(wort_cpy[i]);
        //std::cout << "- zeichenCode(): " << zeichen << std::endl;
        //std::cout << "zeichen: " << wort_cpy[i] << std::endl;
        if( (zeichen != '0') && (zeichen != code[i-1]) ){
            code[pos] = zeichen;
            std::cout<<"pos: "<<pos;
            pos++;
            std::cout<<" Zeichen "<<zeichen;
            std::cout<<" in code[pos] "<<code[pos]<<zeichen<<std::endl;
        }
        if(pos>=4) break;
    }*/

    while(pos < 4){
        code[pos] = '0';
        pos++;
    }

    code[pos] = '\0'; //Array beginnt mit 0. Also ist mit 5 Feldern code[4] da letzte Feld
    //Könnt auch von Anfang an gesetzt werden zu Sicherheit
    //delete[] wort_cpy;
    //Freigabe des arrays, welches nur zum kopieren des Wortes benutzt wurde.
    return code;
}

void kleinNachGross(char wort[]){
    for (int i=0; wort[i] != '\0'; ++i){
    if (wort[i] >= 'a' && wort[i] <= 'z') {
            wort[i] = wort[i] - 32;
        }
    }
}

char zeichenCode(char c){
    switch(c)
    {
        /*
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'H':
        case 'W':
        case 'Y':
            return '0';*/
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G':
        case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}


int mmain(){
    char wort1[] = "Britney";
    char code[5] = "    ";
    soundex(wort1, code);
    std::cout << "|Wort: " << wort1 << " |Code: " << code << std::endl;

    char wort2[] = "Spears";
    soundex(wort2, code);
    std::cout << "|Wort: " << wort2 << " |Code: " << code << std::endl;

    char wort3[] = "Superzicke";
    soundex(wort3, code);
    std::cout << "|Wort: " << wort3 << " |Code: " << code << std::endl;

    return 0;
}
