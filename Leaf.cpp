//
// Created by Marius on 2/27/2021.
//

#include "Leaf.h"

Leaf::Leaf(const string &pavadinimas, double kaina) : pavadinimas(pavadinimas), kaina(kaina) {}

double Leaf::GautiKaina() {
  return kaina;
}

void Leaf::AtvaizduotiInformacija() {
  cout << pavadinimas << ", " << kaina << endl;
}

const string &Leaf::GetPavadinimas() const {
  return pavadinimas;
}

double Leaf::GetKaina() const {
  return kaina;
}
