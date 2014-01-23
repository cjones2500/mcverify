////////////////////////////////////////////////////////
/// Extracts the Nhit per event histogram
///
/// 12/07/12 - New File
////////////////////////////////////////////////////////

#include <TH1D.h>
#include <TFile.h>
#include <TTree.h>
using namespace ROOT;

#include <iostream>
using namespace std;

#include <QEvent.h>
#include <QMCEvent.h>
#include <QTree.h>
#include <QMCVX.h>
#include <QPMT.h>
#include <QFit.h>

// Must do this first
//gSystem->AddIncludePath("-I$QSNO_ROOT/include");

void
ExtractMCPosition( char* lpInFile,
			 char* lpOutFile )
{
  // Load the root file first
  TFile *file = new TFile( lpInFile );
  QTree *tree = (QTree*)file->Get( "T" );
  QEvent *qEV = new QEvent();
  //QMCEvent *qMC = new QMCEvent();
  tree->SetEventAddress( qEV );
 
  time_t codeStart = time( NULL );
  TH1D* rPos = new TH1D( "rPosition", "rPosition", 6000, 0.0, 6000.0 );

  // Loop over the events
  int iLoop;
  int numMCEvents = tree->GetEntries();

  for( iLoop = 0; iLoop < numMCEvents; iLoop++ )
  {
    if( iLoop % 100 == 0 )
      cout << iLoop << " finished at " << time( NULL ) - codeStart << endl;

    //tree->GetEntry( iLoop );
    rPos->Fill(qEV->GetMCVX(iLoop)->GetX()); 
    //qEV->GetMCVX(lastMCVX)->GetNCerD20() as seen in ExtractCerenkov
    
    
  }

  TFile outFile( lpOutFile, "RECREATE" );
  outFile.cd();
  nHits->Write();
  outFile.Close();
}

