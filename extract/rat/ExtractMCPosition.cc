////////////////////////////////////////////////////////
/// Extracts the ev side nhit per event and saves into a 
/// histogram
/// C Jones <christopher.jones@physics.ox.ac.uk>
///
/// 12/07/2012 : New File
////////////////////////////////////////////////////////

#include <RAT/DS/Root.hh>
#include <RAT/DS/EV.hh>
#include <RAT/DS/Run.hh>

#include <TH1D.h>
#include <TTree.h>
#include <TFile.h>
#include <TGraph2D.h>
#include <TCanvas.h>

#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

void
LoadRootFile( const char* lpFile,
              TTree **tree,
              RAT::DS::Root **rDS,
              RAT::DS::Run **rRun );

void 
ExtractMCPosition( const char* inFile,
             const char* outFile )
{
  // Load the root file first
  RAT::DS::Root* rDS;
  RAT::DS::Run* rRun;
  TTree *tree;
  LoadRootFile( inFile, &tree, &rDS, &rRun );
  
  time_t codeStart = time( NULL );
  ofstream outFileTxt;
  outFileTxt.open("/home/jonesc/coords.txt");
  //TH1D* rPos = new TH1D( "rPosition", "rPosition", 6000, 0.0, 6000.0 );
  //TCanvas* canvas = new TCanvas("canvas");
  //TGraph2D* graph = new TGraph2D();
  
  //std::cout << "inFile: " << inFile << std::endl;

  for( int iEvent = 0; iEvent < tree->GetEntries(); iEvent++ )
    {
      try{
        tree->GetEntry(iEvent);
        RAT::DS::MC* rmc = rDS->GetMC();
        RAT::DS::MCParticle* rmcparticle = rmc->GetMCParticle(0);
        TVector3 mcpos = rmcparticle->GetPos();
      
        //std::cout << "Works before call" << std::endl;
      
        if( iEvent % 100 == 0 ){
          std::cout << "iEvent: " << iEvent << std::endl;
          std::cout << "mcpos.X(): " << mcpos.X() << std::endl;
          outFileTxt << mcpos.X() << "\t" << mcpos.Y() << "\t" << mcpos.Z() << "\n"; 
        }
      }
      catch(int e){
        std::cout << "Error" << std::endl;
      }
        //cout << iEvent << " finished at " << time( NULL ) - codeStart << endl;
        //std::cout << "Works before graph-> call" << std::endl;
        
        //graph->SetPoint(iEvent,mcpos.X(),mcpos.Y(),mcpos.Z());
        
        //std::cout << "Works after graph-> call" << std::endl;
        
        /*for( int iEV = 0; iEV < rDS->GetEVCount(); iEV++ )
          {
          RAT::DS::MC *rmc = rDS->GetMC();
          RAT::DS::MCParticle *rmcparticle = rmc->GetMCParticle(iEV);
          TVector3 mcpos = rmcparticle->GetPos();
          //rPos->Fill(mcpos.Mag());
          
          }*/
    }

  //graph->Draw("p0");
  //canvas->Update();
  //canvas->SaveAs(outFile);
  outFileTxt.close();
  
  std::cout << "Worked after loop" << std::endl;
  
  //TFile outputFile(outFile, "RECREATE" );
  //outputFile.cd();
  //rPos->Write();
  //canvas->Write();
  //canvas->SaveAs(outFile);
  //outputFile.Close();
  
  //delete canvas;
  //delete graph;
}


void
LoadRootFile( const char* lpFile,
              TTree **tree,
              RAT::DS::Root **rDS,
              RAT::DS::Run **rRun )
{
  TFile *file = new TFile( lpFile );
  (*tree) = (TTree*)file->Get( "T" );
  TTree *runTree = (TTree*)file->Get( "runT" );

  *rDS = new RAT::DS::Root();

  (*tree)->SetBranchAddress( "ds", &(*rDS) );

  *rRun = new RAT::DS::Run();

  runTree->SetBranchAddress( "run", &(*rRun) );
  runTree->GetEntry();
}
