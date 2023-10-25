#include <iostream>  
#include <cstdint>
using namespace std;
#ifndef CPU_H
#define CPU_H

class cpu{
public:
  cpu();
  void run();
private:
  void fetch();
  void decode();
  void execute();


  get_destination();
  get_register1();
  get_resgister2();



};

#endif
