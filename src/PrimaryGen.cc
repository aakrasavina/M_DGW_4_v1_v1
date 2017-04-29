#include <Randomize.hh>
#include <G4Electron.hh>
#include "PrimaryGen.hh"
#include "fstream"
#include "vector"
PrimaryGen::PrimaryGen() {
    gun = new G4ParticleGun(1);
    G4cout << "Primary particles generator is created successfully\t\tOK!!!" << G4endl;
    std::ifstream fin("spectrum.txt");
    vect = new std::vector<std::pair<float, float>>();
    while (!fin.eof()) {
        char buf;
        float buff1, buff2;
        fin >> buff1 >> buf >> buff2;
        vect->push_back(std::make_pair(buff1, buff2));
    }
    for (auto v : (*vect))
        if (G4Threading::G4GetThreadId() == 0)
            std::cout << v.first << " | " << v.second << "\n";
}

PrimaryGen::~PrimaryGen()
{ delete vect;}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
    gun->SetParticleDefinition(G4Electron::ElectronDefinition());
    G4double W = G4UniformRand();
    G4double e = 0;
    std::vector<std::pair<float, float>>::iterator it = vect->begin();
    for (auto v : (*vect)) {
        it++;
        if (it != vect->end() && (W < it->second && W >= v.second))
            e = v.first;
    }
    gun->SetParticleEnergy(e * MeV);
    gun->SetParticlePosition(G4ThreeVector(0 * mm, 0 * mm, 0 * mm));
    gun->SetParticleMomentumDirection(
            G4ThreeVector(2 * G4UniformRand() - 1, 2 * G4UniformRand() - 1, 2 * G4UniformRand() - 1));
    gun->GeneratePrimaryVertex(anEvent);
}