{
  gROOT->ProcessLine( ".X $MCVERIFY/extract/snoman/Load.c");
  gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractCerenkov.cc+" );
  
  ExtractCerenkov( "C1.root", "CC1.root" );
  ExtractCerenkov( "C2.root", "CC2.root" );
  ExtractCerenkov( "C3.root", "CC3.root" );
  ExtractCerenkov( "C4.root", "CC4.root" );
  ExtractCerenkov( "C5.root", "CC5.root" );
  ExtractCerenkov( "C6.root", "CC6.root" );
  ExtractCerenkov( "C7.root", "CC7.root" );
  ExtractCerenkov( "C8.root", "CC8.root" );
  ExtractCerenkov( "C9.root", "CC9.root" );
  ExtractCerenkov( "C10.root", "CC10.root" );
  ExtractCerenkov( "C11.root", "CC11.root" );
  ExtractCerenkov( "C12.root", "CC12.root" );
  ExtractCerenkov( "C13.root", "CC13.root" );
  ExtractCerenkov( "C14.root", "CC14.root" );
  ExtractCerenkov( "C15.root", "CC15.root" );
  ExtractCerenkov( "C16.root", "CC16.root" );
  ExtractCerenkov( "C17.root", "CC17.root" );
  ExtractCerenkov( "C18.root", "CC18.root" );
  ExtractCerenkov( "C19.root", "CC19.root" );
  ExtractCerenkov( "C20.root", "CC20.root" );
  
  gSystem->Unload( "$MCVERIFY/extract/snoman/ExtractCerenkov_cc.so" );

  gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractRange.cc+" );
  
  ExtractRange( "C1.root", "CR1.root" );
  ExtractRange( "C2.root", "CR2.root" );
  ExtractRange( "C3.root", "CR3.root" );
  ExtractRange( "C4.root", "CR4.root" );
  ExtractRange( "C5.root", "CR5.root" );
  ExtractRange( "C6.root", "CR6.root" );
  ExtractRange( "C7.root", "CR7.root" );
  ExtractRange( "C8.root", "CR8.root" );
  ExtractRange( "C9.root", "CR9.root" );
  ExtractRange( "C10.root", "CR10.root" );
  ExtractRange( "C11.root", "CR11.root" );
  ExtractRange( "C12.root", "CR12.root" );
  ExtractRange( "C13.root", "CR13.root" );
  ExtractRange( "C14.root", "CR14.root" );
  ExtractRange( "C15.root", "CR15.root" );
  ExtractRange( "C16.root", "CR16.root" );
  ExtractRange( "C17.root", "CR17.root" );
  ExtractRange( "C18.root", "CR18.root" );
  ExtractRange( "C19.root", "CR19.root" );
  ExtractRange( "C20.root", "CR20.root" );
  
  gSystem->Unload( "$MCVERIFY/extract/snoman/ExtractRange_cc.so" ); 

  gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractNhit.cc+" );

  ExtractNhit( "C1.root", "CN1.root" );
  ExtractNhit( "C2.root", "CN2.root" );
  ExtractNhit( "C3.root", "CN3.root" );
  ExtractNhit( "C4.root", "CN4.root" );
  ExtractNhit( "C5.root", "CN5.root" );
  ExtractNhit( "C6.root", "CN6.root" );
  ExtractNhit( "C7.root", "CN7.root" );
  ExtractNhit( "C8.root", "CN8.root" );
  ExtractNhit( "C9.root", "CN9.root" );
  ExtractNhit( "C10.root", "CN10.root" );
  ExtractNhit( "C11.root", "CN11.root" );
  ExtractNhit( "C12.root", "CN12.root" );
  ExtractNhit( "C13.root", "CN13.root" );
  ExtractNhit( "C14.root", "CN14.root" );
  ExtractNhit( "C15.root", "CN15.root" );
  ExtractNhit( "C16.root", "CN16.root" );
  ExtractNhit( "C17.root", "CN17.root" );
  ExtractNhit( "C18.root", "CN18.root" );
  ExtractNhit( "C19.root", "CN19.root" );
  ExtractNhit( "C20.root", "CN20.root" );
  
  exit; 
}
