#include "loader.hh"

G4Loader::G4Loader(int argc, char** argv){
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    CLHEP::HepRandom::setTheSeed(time(NULL));

#ifdef G4MULTITHREADED
    runManager = new G4MTRunManager;
#else
    runManager = new G4RunManager;
#endif
    std::cout<<"Number of cores = "<<G4Threading::G4GetNumberOfCores()<<std::endl;
    runManager->SetVerboseLevel(0);
//Set mandatory initialization classes
    detGeom = new DetGeometry();
    runManager->SetUserInitialization(detGeom);
    G4VModularPhysicsList* physicsList = new QBBC;
    runManager->SetUserInitialization(physicsList);
    runManager->SetUserInitialization(new ActionInit());

    std::ofstream   fout("/dev/null");
    std::streambuf* cout_sbuf = std::cout.rdbuf();
    G4cout.rdbuf(fout.rdbuf());
    runManager->Initialize();
    G4cout.rdbuf(cout_sbuf);
#ifdef G4VIS_USE
    // Initialize visualization
    visManager = new G4VisExecutive;
    visManager->Initialize();
#endif
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if (argc!=1) {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else {
        // interactive mode : define UI session
#ifdef G4UI_USE
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
        UImanager->ApplyCommand("/control/execute init_vis.mac");
#else
        UImanager->ApplyCommand("/control/execute init.mac");
#endif
        ui->SessionStart();
        delete ui;
#endif
    }
}

G4Loader::~G4Loader(){
#ifdef G4VIS_USE
    delete visManager;
#endif
    delete runManager;
}
