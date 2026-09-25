void osc_multigraph()
{
  TFile *f = new TFile("/home/luciano/Downloads/datos_osc.root");

  TTreeReader reader("osc", f);
  TTreeReaderArray<double> c2(reader,"osc.c2");
  TTreeReaderArray<double> c3(reader,"osc.c3");
  TTreeReaderValue<double> dt(reader,"osc.dt");
  TTreeReaderValue<int> Ns(reader,"osc.Ns");

  const int n_waveforms {600};
  const int n_points {10000};
  double arr_time[n_points]; // tiempo en forma de arreglo

  double time0 {-1.9200000000E-07};
  double timestep {1e-10};
  for ( int i {0}; i < n_points; i++ ) {
    arr_time[i] = time0 + i*timestep;
  }

  TMultiGraph *mtgr2 = new TMultiGraph();
  TMultiGraph *mtgr3 = new TMultiGraph();

  while ( reader.Next() ) {
    if ( *Ns >= n_waveforms ) {
      break;
    }
    if ( *Ns % 10 != 0 ) continue; // guardamos una de cada 10 formas de onda
    mtgr2->Add(new TGraph(n_points, arr_time, &c2[0]));
    mtgr3->Add(new TGraph(n_points, arr_time, &c3[0]));
  }

  std::cout << "graphs added (c2): " << mtgr2->GetListOfGraphs() << std::endl;
  std::cout << "graphs added (c3): " << mtgr3->GetListOfGraphs() << std::endl;

  auto c1 = new TCanvas();
  c1->Print("multigraph.pdf[");
  mtgr2->Draw("A L PLC"); // A: axis, L: lines, PLC: palette color
  c1->Print("multigraph.pdf");
  gPad->Clear();
  mtgr3->Draw("A L PLC");
  c1->Print("multigraph.pdf");
  c1->Print("multigraph.pdf]");
}
