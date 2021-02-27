#include <iostream>
#include <memory>
#include "Composite.h"
#include "Leaf.h"
#include "Color.h"

using namespace std;

int main() {

  auto *apdaila = new Composite("APDAILA");

  auto *voniosKambarys = new Composite("VONIOS KAMBARYS");

  // du budai panaudoti smart pointers
  //https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-160
  unique_ptr<Composite> koridorius(new Composite("KORIDORIUS"));
  unique_ptr<Composite> sienos = make_unique<Composite>("SIENA");

  auto *virtuve = new Composite("VIRTUVE");
  auto *miegamasis = new Composite("MIEGAMASIS");
  auto *svetaine = new Composite("SVETAINE");

 // get funkcija grazina raw pointer kad suderinti su senais API arba darbui su RAW POINTERIAIS
  //https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-160
 apdaila->IdetiKomponenta(koridorius.get());



  apdaila->IdetiKomponenta(voniosKambarys);
  apdaila->IdetiKomponenta(virtuve);
  apdaila->IdetiKomponenta(miegamasis);
  apdaila->IdetiKomponenta(svetaine);

  auto *spinta = new Composite("SPINTA");

  auto *wc = new Leaf("WC", 120.45);
  auto *kriaukle = new Leaf("Kriaukle", 80.45);
  auto *vonia = new Leaf("Vonia", 220.55);

  auto *gartraukis = new Leaf("Gartraukis", 20.45);
  auto *stalas = new Leaf("Stalas", 150.45);

  auto *lova = new Leaf("Lova", 152.45);

  auto *pakaba = new Leaf("Pakaba", 170.45);
  auto *stalcius = new Leaf("Stalcius", 804.45);

  auto *tv = new Leaf("TV", 120.45);

  voniosKambarys->IdetiKomponenta(wc);
  voniosKambarys->IdetiKomponenta(vonia);
  voniosKambarys->IdetiKomponenta(kriaukle);

  virtuve->IdetiKomponenta(gartraukis);
  virtuve->IdetiKomponenta(stalas);

  spinta->IdetiKomponenta(pakaba);
  spinta->IdetiKomponenta(stalcius);

  miegamasis->IdetiKomponenta(lova);
  miegamasis->IdetiKomponenta(spinta);

  svetaine->IdetiKomponenta(tv);



  // cout << "viso: " << apdaila->GautiKaina() << endl;


  int punktas = 1;
  while (punktas != 0) {
    Color::PakeistiKonsolesTekstoSpalva(5);
    cout << "-----------------------------------" << endl;
    cout << "              MENIU                " << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Atvaizduoti apdaila." << endl;
    cout << "2. Atvaizduoti busto irengimo kaina." << endl;
    cout << "3. Prideti nauja objekta i busto irengimo plana." << endl;
    cout << "4. Pasirinkite vonia." << endl;
    cout << "0. Išeiti iš programos." << endl;

    Color::PakeistiKonsolesTekstoSpalva(8);

    cout << "Iveskite meniu punkto nr: ";
    cin >> punktas;

    switch (punktas) {
      case 1:
        apdaila->AtvaizduotiInformacija();
        break;
      case 2:
        Color::PakeistiKonsolesTekstoSpalva(4);
        cout << apdaila->GautiKaina() << endl;
        break;
      case 3: {
        cout << "Naujo produkto kurimas"<<endl;


        string kategorija;

        cout << "Nurodykite kategorijos pavadinima: ";
        cin.ignore();
        getline(cin, kategorija);


        auto *cat = new Composite(kategorija);

        string pavadinimas;
        double kaina;
        cout << "Nurodykite objekto pavadinima: ";
        getline(cin, pavadinimas);
        cout << "Nurodykite kaina: ";
        cin >> kaina;

        auto *komponentas = new Leaf(pavadinimas, kaina);
        cat->IdetiKomponenta(komponentas);
        apdaila->IdetiKomponenta(cat);

        break;
      }
      case 4:{
      //  vector<string> vonios{"Cersanit 200", "Camero 313", "Standartine vonia"};

        vector<Leaf> sarasas{
          Leaf("Cersanit 200", 412.12),
          Leaf("Camero 313", 352.12),
          Leaf("Standartine vonia", 120.21)
        };

        for (int i = 0; i < sarasas.size(); ++i) {
          cout << (i+1) << ". " << sarasas[i].GetPavadinimas() << endl;
        }
        cout << "Pasirinkite vonia: ";
        int ivestis;
        cin >> ivestis;

        auto *elem = new Leaf(sarasas[ivestis-1].GetPavadinimas(),
                              sarasas[ivestis-1].GautiKaina());

        voniosKambarys->IdetiKomponenta(elem);

        cout << "Jus pasirinkote sia vonia:" << sarasas[ivestis-1].GetPavadinimas() << endl;
        // auto* a = Leaf("Cersanit 200", 420.21),
        break;
      }
      default:
        cout << "neteisingai pasirinkote punkta iveskite kita skaiciu!" << endl;
        break;
    }


  }

  delete spinta;
  delete kriaukle;
  delete wc;
  delete tv;

  return 0;
}
