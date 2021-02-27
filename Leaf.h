//
// Created by Marius on 2/27/2021.
//

#ifndef APDAILOSSKAICIUOKLE_LEAF_H
#define APDAILOSSKAICIUOKLE_LEAF_H

#include <iostream>
#include "Component.h"
using namespace std;
class Leaf : public virtual Component{
public:
  Leaf(const string &pavadinimas, double kaina);
  double GautiKaina() override;
  void AtvaizduotiInformacija() override;

  const string &GetPavadinimas() const;

  double GetKaina() const;

private:
  string pavadinimas;
  double kaina;
};


#endif //APDAILOSSKAICIUOKLE_LEAF_H
