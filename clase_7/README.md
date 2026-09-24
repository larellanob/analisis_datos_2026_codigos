# ROOT data analysis

## Datasets

Colisiones pp a 14TeV generadas con Pythia8 (Onia:all(3S1) = on, PhaseSpace:pTHatMin = 20)

* 1000 eventos (~32 MB)
  * https://drive.google.com/file/d/1VBi-1uIZKkvsQAdgFRFTD5ddjl1v58Kq/view
* 10000 eventos (~320 MB)
  * https://drive.google.com/file/d/1N_S7UQuiOUQtGpsYMdEo6-FINPUU7Cni/view

## Contenidos

* ROOT interactivo
  * Clase TFile: lectura (no escritura)
  * TBrowser()
  * Clase TTree
    * Metodos Print(), Scan() y Draw()
    * Draw con argumentos
      * Draw("E")
      * Draw("E", "pid==211 && pz > 0")
    * Draw con dos variables
      * Draw("py:px") (unbinned)
      * Draw("py:px", "", "colz") (binned)
   * Todo esto fue hecho en ROOT interactivo, pero posteriormente lo organice en `basic_tree.cxx`
* Conceptos fisicos
  * Masa invariante
  * Cortes (pid, energia, etc.)
  * Loops sobre pares de particulas y calculo masa invariante del par
  * `read_tree.cxx`
 