#include <iostream>
#include <fstream>
#include <bitset>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <string.h>
#include "../cpu/cpu.cpp"
#include "../mem/mem.h"
using namespace std;

void readFile(mem&,string);

int main()
{
  mem imem,dmem;
  imem.setStartPC(0);
  dmem.setStartPC(0x10010000);
  cout << "-----------------------------------------------" << endl;
  cout << "RISCV SIMULATOR" << endl;
  readFile(imem, "imem.dat"); // LOAD INSTRUCTIONS
  readFile(dmem, "dmem.dat");

  //DEBUG
  // cout << "IMEM"<<endl;
  // for (int i = 0; i < 6; i++) 
  //   cout << bitset<32>(imem.getMem(i)) << endl; 
  // cout << "DMEM"<<endl;
  // for (int j = 0; j < 6; j++)
  //   cout << bitset<32>(dmem.getMem(j)) << endl; 
  cpu cpu(imem, dmem); // INTANTIATE & RUN CPU
  cpu.run();
  return 0;
}

// Parse .DAT file
void readFile(mem& result, string filename)
{
  string line;
  ifstream file(filename);                                  // OPEN file
  if (!file)
    cout << "ERROR. Cannot open file";
  else
  {
    cout << endl << "Loading "<< filename <<" instructions" << endl;
    string str = "";
    string binary;
    int i = 0;
    while (file >> binary)                                   // READ file
    {
      str = binary + str;
      if (str.length() == 32)
      {
        uint32_t val = bitset<32>(str).to_ulong(); // Convert string to binary
        if(val!=0){
          result.setMem(i,val);   // save instruction
          i++;
          result.incrSize();
        }
        str.clear();
      }
    }
    file.close();
    // cout << "~~ Loading complete ~~\n";
  }
}
