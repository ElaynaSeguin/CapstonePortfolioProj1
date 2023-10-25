#include <iostream>
#include <fstream>
#include <bitset>
#include <ctime>
#include <unistd.h>
// #include "cpu.h"
using namespace std;

void readFile();
void writeFile();
void displayOptions();
void userInput();
void clockStart();
void clockStop();
clock_t timer;
int totalTime = 0;
// CPU cpu;

int main()
{
    readFile();

    // INTANTIATE & RUN CPU

    //REQUEST USER INPUT
    userInput();  

    //DISPLAY TIME
    cout << "\nTotal Time:" << totalTime;
    clockStart();
    sleep(10);
    clockStop();
    cout << fixed << "\nTotal Time:" << (float)totalTime / CLOCKS_PER_SEC << " sec" << scientific;

    writeFile();

    return 0;
}

// Parse .DAT file
void readFile()
{
    // OPEN file
    string line, input = "input.dat";
    ifstream file(input);
    vector<uint32_t> arr;
    if (!file)
    {
        cout << "ERROR. Cannot open file";
        return;
    }
    cout << "\n~~ Loading instructions ~~\n";

    // READ file
    while (getline(file, line))
    {
        uint32_t val = bitset<32>(line).to_ulong(); // Convert the binary string to uint32_t
        arr.push_back(val);
        // cout << val << "\n";         // 255       int
        cout << bitset<8>(val) << "\n"; // 11111111  binary

        //read every 4 lines = 1 instruction
    }
    file.close();

    cout << "~~ Loading complete ~~\n";
}

// Write to .ASM file for Debugging
void writeFile()
{
    string output = "output.asm";
    ofstream file(output,ios::app); //append
    if (!file)
    {
        cout << "ERROR. Cannot open file";
        return;
    }

    // get translated instruction from CPU.decode() ???
    file << "HELLO" << endl;
    file.close();
}

void clockStart()
{
    timer = clock();
}

void clockStop()
{
    timer = clock() - timer;
    totalTime += timer;
}

void displayOptions(){
    cout  << "\n" << "Enter a command: \n"
          << "\n" << "r     - run entire program"
          << "\n" << "s     - run next instruction"
          << "\n" << "x0    - view content in this register"
          << "\n" << "0x12345678 - view content at this address"
          << "\n" << "pc    - view PC value"
          << "\n" << "insn  - view next instruction"
          << "\n" << "b[pc] - set breakpoint"
          << "\n" << "c     - continue execution";
}

void userInput(){
    string input=" ";
    displayOptions();
    // getline(cin,input);

//     //convert input to option type

//     switch(input){
//         case "r":

//             break;
//         case "s":

//             break;
//         case "pc":

//             break;
//         case "insn":

//             break;
//         case "c":

//             break;
//         case "x0":

//             break;
//         case "0x12345678":

//             break;
//         case "b [pc]":

//             break;
//         default:
//             cout <<"Invalid input";
//     }
}