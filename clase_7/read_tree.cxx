void read_tree()
{
  TFile f("events_1000.root");
  //TTree *t = (TTree*)f.Get("t");            // cast TObject into a ttree
  TTree *t {static_cast<TTree*>(f.Get("t"))}; // cast estilo C++

  TTreeReader reader(t);
  TTreeReaderArray<double> E(reader,"E");
  TTreeReaderArray<double> px(reader,"px");
  TTreeReaderArray<double> py(reader,"py");
  TTreeReaderArray<double> pz(reader,"pz");
  TTreeReaderArray<int> pid(reader,"pid");

  int nevents {0};
  while ( reader.Next() ) {
    // loopea por todos los eventos del ttree t (que esta en f)
    std::cout << nevents << std::endl;

    int nparts {0}; // numero de particulas
    // dentro del evento, vamos a loopear sobre las particulas
    for ( int i {0}; i < E.GetSize(); i++ ) {
      nparts++;

      // pid cuts
      if ( pid[i] == 22 ) { // cut (corte): no fotones
	continue;
      }
      if ( abs(pid[i]) != 11 ) { // solo deja e+ y e-
	continue;
      }

      // masa invariante de cada particula
      double Ei {E[i]};
      double pxi {px[i]};
      double pyi {py[i]};
      double pzi {pz[i]};
      double m {sqrt(Ei*Ei - pxi*pxi - pyi*pyi - pzi*pzi)};

      TString s_particulas = Form("\tEnergia: %.6f pid es: %i, minv %.6f",
				  Ei,pid[i],m);

      std::cout << s_particulas << std::endl;
      
      // loop sobre particulas restantes (todos los pares)
      for ( int j {i}; j < E.GetSize(); j++ ) {
	double Eij = E[i]+E[j];
	double pxij = px[i]+px[j];
	double pyij = py[i]+py[j];
	double pzij = pz[i]+pz[j];
	// masa invariante del par
	double mij {sqrt(Eij*Eij - pxij*pxij - pyij*pyij - pzij*pzij)};
      }
    }
    std::cout << "nparticulas " << nparts << std::endl;
    nevents++;
  }
}
