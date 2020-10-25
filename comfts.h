#pragma once
#include <iostream>
#include <fstream>
#include <cstring>

namespace comfts
{
    void DirectoryProcess(char*, char*);
    void readDataPiece(FILE* m_dataFilePointer, int* m_dataBuffer1, int* m_dataBuffer2);
    uint32_t reverseBytes(uint32_t n);
}
