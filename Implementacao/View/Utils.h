//
// Created by christian on 02/02/17.
//

#ifndef TRABIES_UTILS_H
#define TRABIES_UTILS_H

#include <cstdio>

class Utils {
public:
    /*
     * Código ANSI responsável por limpar a tela de um terminal
     */
    static void LimparTela();

    static char *Traduzir(const char *StringOriginal);

    static void strTrim(char *String);

    static char *strsep(char** stringp, const char* delim);

    static void clearBuffer();

    static void GerarRelatorio();
};


#endif //TRABIES_UTILS_H
