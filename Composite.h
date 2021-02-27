//
// Created by Marius on 2/27/2021.
//

#ifndef APDAILOSSKAICIUOKLE_COMPOSITE_H
#define APDAILOSSKAICIUOKLE_COMPOSITE_H
#include <iostream>
#include <vector>
using namespace std;

#include "Component.h"

class Composite : public virtual Component{
public:
  Composite(const string &pavadinimas);

  double GautiKaina() override;
  void AtvaizduotiInformacija() override;
  void IdetiKomponenta(Component *komponentas);
private:
  string pavadinimas;
  vector<Component*> komponentai;
};


#endif //APDAILOSSKAICIUOKLE_COMPOSITE_H
