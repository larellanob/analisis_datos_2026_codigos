void basic_tree()
{
  TFile f("events_1000.root"); // abrimos un archivo consturyendo un objeto TFile

  // Dentro del archivo hay un TTree "t", hay que agarrarlo
  // esta forma es mas moderna que lo que vimos en clases
  TTree *t { f.Get<TTree>("t") };  // Get<T> template
  // TTree *t = (TTree*)f.Get("t"); // cast estilo C, old school!

  /*
    Usar estos metodos en una sesion interactiva para ver que cosa
    tiene el TTree

    t->Print();
    t->Scan();
  */

  // tambien podemos ver graficamente (sesion interactiva) con
  //new TBrowser();

  // el TTree tiene branches "E" (energia), "px" (momentum x), etc.
  t->Draw("E"); // dibuja un histograma de la energia
  t->Draw("E", "pid == 211"); // pid: particle ID. Energia de los pi+
  /*
    Los PID estandar son publicados por el PDG (particle data
    group). Buscar "PDG monte carlo codes".  Algunos codigos comunes:

    pi+: 211, pi-: -211 (antiparticulas llevan signo -)
    e-: 11, e+: -11 (ojo, el electron (carga negativa) es +11)
    photon (gamma): 22
   */
  t->Draw("E", "pid == 211 && pz > 0"); // dos selecciones (operador &&: and)
  t->Draw("E", "pid == 211 || pid == -211"); // energia de pi+ y pi- (operador ||: or)

  // podemos hacer graficos en dos dimensiones con el operador : (colon)
  t->Draw("py:px"); // "py en funcion de px"
  // esto genera un scatter plot (datos no bineados)

  // para binear usamos opcion "colz"
  // va en el tercer argumento (segundo es seleccion)
  t->Draw("py:px", "", "colz");

  /*
    El metodo Draw() trata de elegir un rango en ejes horiz y vert que
    muestre todos los datos, y elige un binning lo mejor posible.

    Tambien usa los nombres de los Branches para los ejes, y genera un
    titulo.

    A veces estamos interesados en un rango especifico, o queremos un
    binning mas fino o mas grueso. Queremos mejorar los titulos de los
    ejes, para presentar o publicar un buen grafico

    En estos casos especificamos el binning a mano declarando un
    histograma adecuado.
  */
  TH2F h2("h2", // nombre del objeto
	  "Mi histograma 2D;Px (GeV);Py (GeV)", // titulo;ejex;ejey
	  200, -10, 10, // binning eje x: nbins, left edge, right edge
	  200, -15, 5); // binning eje y: nbins, bott edge, upper edge

  // ahora usamos el operador >> para que Draw() tire el resultado a h2
  t->Draw("py:px >> h2", "", "colz");

  /*
    En clase vimos todos estos comandos de forma
    interactiva. Estabamos jugando con los datos. Si corremos este
    macro con 'root -l -b -q basic_tree.cxx', hasta ahora, estas cosas
    se dibujan pero no quedan guardadas.

    Generalmente queremos guardar nuestros graficos a archivos .pdf o
    .png
   */

  // primero inicializamos un canvas
  TCanvas c1;
  // ahora podriamos repetir los comandos Draw que hemos hecho uno por uno
  t->Draw("E");
  c1.Print("E.pdf"); // guardamos como "E.pdf", ROOT entiende la extension

  /*
    Podemos hacer lo mismo con cada variable, guardando cada una en un
    pdf. Otra manera es hacer un pdf con varias paginas. Para eso
    hacemos un Print con [, luego hacemos un print por cada pagina,
    luego cerramos el pdf con ]
  */
  c1.Print("multi_pagina.pdf["); // al poner [ ROOT entiende que abrimos un pdf
  t->Draw("E");
  c1.Print("multi_pagina.pdf");
  // reproducimos nuestros comandos Draw() y hacemos Print despues de cada uno
  t->Draw("E", "pid == 211 || pid == -211"); // energia de pi+ y pi- (operador ||: or)
  c1.Print("multi_pagina.pdf");

  t->Draw("py:px"); // "py en funcion de px"
  c1.Print("multi_pagina.pdf");

  t->Draw("py:px", "", "colz");
  c1.Print("multi_pagina.pdf");

  t->Draw("py:px >> h2", "", "colz");
  c1.Print("multi_pagina.pdf");

  // cerramos el archivo
  c1.Print("multi_pagina.pdf]");
}
