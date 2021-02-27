//
// Created by Marius on 2/27/2021.
//

#include "Color.h"

void Color::PakeistiKonsolesTekstoSpalva(int spalva) {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, spalva);
}
