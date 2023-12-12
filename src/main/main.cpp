#include <iostream>
#include <fstream>
#include <bitset>
// #include <ctime>
// #include <vector>
#include <unistd.h>
#include <string.h>
#include "../cpu/cpu.cpp"
#include "../mem/mem.h"
using namespace std;

void readFile(mem&,string);

// void writeFile();
// void displayOptions();
// void userInput();
// void clockStart();
// void clockStop();
// clock_t timer;
// int totalTime = 0;
// uint32_t breakpoints[5] = {0xFFFFFFFF}; // initialize to FF (never reached)

int main()
{
  mem imem,dmem;
  imem.setStartPC(0);
  dmem.setStartPC(0x10010000);
  cout << "RISCV SIMULATOR\n";
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

  // bool cpu_is_running = true;
  // while (true)
  // {
  // clockStart();
  // cpu.fetch();
  // writeFile();
  // cpu.execute();
  // clockStop();
  // if (cpu.getPC() == 0) //check if end
  //     break;
  // }

  // DISPLAY TIME
  // cout << "\nTotal Time:" << totalTime;
  // clockStart();
  // sleep(10);
  // clockStop();
  // cout << fixed << "\nTotal Time:" << (float)totalTime / CLOCKS_PER_SEC << " sec" << scientific;

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
    cout << "~~ Loading "<< filename <<" instructions ~~\n";
    string str = "";
    string binary;
    int i = 0;
    while (file >> binary)                                   // READ file
    {
      str = binary + str;
      if (str.length() == 32)
      {
        uint32_t val = bitset<32>(str).to_ulong(); // Convert string to binary
        result.setMem(i,val);   // save instruction
        i++;
        result.incrSize();
        str.clear();
      }
    }
    file.close();
    cout << "~~ Loading complete ~~\n";
  }
}
