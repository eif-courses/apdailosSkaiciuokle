//
// Created by Marius on 2/27/2021.
//

#include "Composite.h"
#include "Color.h"

Composite::Composite(const string &pavadinimas) : pavadinimas(pavadinimas) {}

double Composite::GautiKaina() {

  double viso = 0;
  for (Component* c: komponentai){
    viso += c->GautiKaina();
  }
  return viso;
}

void Composite::AtvaizduotiInformacija() {

  Color::PakeistiKonsolesTekstoSpalva(2);
  cout << "----------------------------------------" << endl;
  cout << pavadinimas << endl;
  cout << "----------------------------------------" << endl;
  Color::PakeistiKonsolesTekstoSpalva(12);
  for(Component *c: komponentai){
    c->AtvaizduotiInformacija();
  }
}

void Composite::IdetiKomponenta(Component *komponentas) {
  komponentai.emplace_back(komponentas);
}
