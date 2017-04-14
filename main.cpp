#include <cstdlib>
#include <cstring>
#include "lab.h"
#include <iostream>
#include "fedotov.h"
#include "geroevvn.h"
#include "golovenkomv.h"
#include "gorbylevako.h"
#include "hramovaia.h"
#include "kidyaevvs.h"
#include "klyushenkovaaa.h"
#include "KulyaginaTI.h"
#include "kurbatovdi.h"
#include "kuzminnal.h"
#include "mulichevaes.h"
#include "polischukoa.h"
#include "ponkratovayv.h"
#include "sorokinai.h"
#include "zhuravlevama.h"

void print_usage(char* name);


int main(int argc, char** argv)
{
  if (argc < 3) {
    print_usage(argv[0]);
    return 0;
  }

  lab *l = NULL;
  if (strcmp(argv[1], "hramovaia") == 0) {
    l = new hramovaia();
  }
  else if (strcmp(argv[1], "fedotovvd") == 0) {
    l = new fedotov();
  }
  else if (strcmp(argv[1], "kuzminnal") == 0) {
    l = new kuzminnal();
  }
  else if (strcmp(argv[1], "geroevvn") == 0) {
    l = new geroevvn();
  }
  else if (strcmp(argv[1], "golovenkomv") == 0) {
    l = new golovenkomv();
  }
  else if (strcmp(argv[1], "gorbylevako") == 0) {
    l = new gorbylevako();
  }
  else if (strcmp(argv[1], "kidyaevvs") == 0) {
    l = new kidyaevvs();
  }
  else if (strcmp(argv[1], "klyushenkovaaa") == 0) {
    l = new klyushenkovaa();
  }
  else if (strcmp(argv[1], "kulyaginati") == 0) {
    l = new KulyaginaTI();
  }
  else if (strcmp(argv[1], "kurbatovdi") == 0) {
    l = new kurbatovdi();
  }
  else if (strcmp(argv[1], "mulichevaes") == 0) {
    l = new mulichevaes();
  }
  else if (strcmp(argv[1], "polischukoa") == 0) {
    l = new polischukoa();
  }
  else if (strcmp(argv[1], "ponkratovayv") == 0) {
    l = new ponkratovayv();
  }
  else if (strcmp(argv[1], "sorokinai") == 0) {
    l = new sorokinai();
  }
  else if (strcmp(argv[1], "zhuravlevama") == 0) {
    l = new zhuravlevama();
  }
  else
  {
    print_usage(argv[0]);
    return 0;
  }

  l->read_file();
  l->run(atoi(argv[2]));
  l->write_result();
  l->check_result();

  //delete l; // TODO: 
  return 0;
}


void print_usage(char* name)
{
  std::cout << "Usage:\n\n  " << name << " <fio> <lab_number>\n";
}
