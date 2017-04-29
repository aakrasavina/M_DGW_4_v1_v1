#include <G4VisAttributes.hh>
#include "DetGeometry.hh"
#include "G4Tubs.hh"
#include "G4PhysicalConstants.hh"
DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");

    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);
    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){
    G4double WorkLength = 100*mm;
    G4Tubs* gas_tubs = new G4Tubs("Gas_solid", 0,WorkLength/2.,WorkLength/2,0,360);
    G4LogicalVolume* gas_tubsLog = new G4LogicalVolume(gas_tubs,world_mat,"GasLog_Tubs");
    gas_tubsLog->SetVisAttributes(G4Color(0.0, 1.0, 1.0));
    new G4PVPlacement(0,G4ThreeVector(), gas_tubsLog, "Gaspvp_Tubs", logicWorld, false, 0);
    G4Tubs* det_tubs = new G4Tubs("Det_solid", 0,WorkLength/4.,WorkLength/20,0,360);
    G4LogicalVolume* det_tubsLog = new G4LogicalVolume(det_tubs,world_mat,"Log_Tubs");
    det_tubsLog->SetVisAttributes(G4Color(1.0, 1.0, 1.0));
    new G4PVPlacement(0,G4ThreeVector(0,0,WorkLength/2+WorkLength/20), det_tubsLog, "pvp_Tubs", logicWorld, false, 0);
    return physWorld;
}


