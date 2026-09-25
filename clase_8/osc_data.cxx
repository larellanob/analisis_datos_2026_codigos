void osc_data()
{
  // path absoluto, cambiar!
  // en windows los paths son distintos!
  TFile *f = new TFile("/home/luciano/Downloads/datos_osc.root"); 

  /*
    El archivo datos_osc contiene un TTree llamado "osc", y en cada
    Entry del TTree hay dos formas de onda almacenadas en los arreglos
    "c2" y "c3", los cuales tienen 10000 valores en funcion de tiempo.

    En este macro, vamos a dibujar los primeros 20 pares de formas de
    onda y guardar en un pdf
   */

  // preparamos los Readers para leer el codigo
  TTreeReader reader("osc", f);
  TTreeReaderArray<double> c2(reader,"osc.c2");
  TTreeReaderArray<double> c3(reader,"osc.c3");
  TTreeReaderValue<double> dt(reader,"osc.dt");
  TTreeReaderValue<int> Ns(reader,"osc.Ns");

  // vamos a guardar 20 formas de onda
  // El archivo contiene 602, pero cuidado con hacer un pdf tan grande!
  const int n_waveforms {20}; 
  const int n_points {10000};
  // arreglos de TGraphs, cada uno va a contener 20 formas de ondas de 10k puntos
  TGraph tg2[n_waveforms](n_points); 
  TGraph tg3[n_waveforms](n_points);

  while ( reader.Next() ) {
    double time {-1.9200000000E-07}; // tiempo inicial
    int N {*Ns}; // la variable *Ns lleva la cuenta del numero de forma de onda
    if ( N >= n_waveforms ) {
      break;
    }
    for ( int i {0}; i < n_points; i++ ) {
      if ( i > n_points-10 && N < 1 ) {
	std::cout << N << " " << i << " " << time << " " << c3[i] << std::endl;
      }
      tg2[N].SetPoint(i,time, c2[i]);
      tg3[N].SetPoint(i,time, c3[i]);
      time += *dt;
    }
  }

  TCanvas *c1 = new TCanvas();
  c1->Print("c20.pdf[");
  for ( int i {0}; i < n_waveforms; i++ ) {
    tg2[i].Draw();
    tg2[i].SetTitle(Form("c2, waveform %i;Time",i));
    c1->Print("c20.pdf");
    gPad->Clear();
    tg3[i].Draw();
    tg3[i].SetTitle(Form("c3, waveform %i;Time",i));
    c1->Print("c20.pdf");
    gPad->Clear();
  };
  c1->Print("c20.pdf]");
}
