Cat acCats[] = { Cat("Fred"), Cat("Tyson"), Cat("Zeke") };
Dog acDogs[] = { Dog("Garbo"), Dog("Pooky"), Dog("Truffle") };

for (int iii=0; iii < 3; iii++)
    cout << acCats[iii].GetName() << " says " << acCats[iii].Speak() << endl;

for (int iii=0; iii < 3; iii++)
    cout << acDogs[iii].GetName() << " says " << acDogs[iii].Speak() << endl;