#include <cstdlib>
#include <cstring>
#include "lab.h"
#include <iostream>
#include "geroevvn.h"
#include "golovenkomv.h"
#include "gorbylevako.h"
#include "hramovaia.h"
#include "kuzminnal.h"
#include "sorokinai.h"

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
  else if (strcmp(argv[1], "sorokinai") == 0) {
    l = new sorokinai();
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

  delete l;
  return 0;
}


void print_usage(char* name)
{
  std::cout << "Usage:\n\n  " << name << " <fio> <lab_number>\n";
}
