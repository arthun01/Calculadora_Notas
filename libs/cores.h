#ifndef CORES_H

// Códigos de reset
#define RESET          "\033[0m"    // Reseta tudo (texto e fundo)
#define RESET_BG       "\033[49m"   // Reseta apenas o fundo
#define RESET_TEXT     "\033[39m"   // Reseta apenas a cor do texto

// Códigos de cores de texto
#define BLACK          "\033[30m"
#define RED            "\033[31m"
#define GREEN          "\033[32m"
#define YELLOW         "\033[33m"
#define BLUE           "\033[34m"
#define MAGENTA        "\033[35m"
#define CYAN           "\033[36m"
#define WHITE          "\033[37m"

// Códigos de cores de fundo
#define BG_BLACK       "\033[40m"
#define BG_RED         "\033[41m"
#define BG_GREEN       "\033[42m"
#define BG_YELLOW      "\033[43m"
#define BG_BLUE        "\033[44m"
#define BG_MAGENTA     "\033[45m"
#define BG_CYAN        "\033[46m"
#define BG_WHITE       "\033[47m"

#endif