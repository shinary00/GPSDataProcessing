#include "comfts.h"
#include<iostream>

void comfts::DirectoryProcess(char* directory, char* copiedDirectory)
{
    int position = 0;
    int positionTarget = 0;
    int length = strlen(directory);
    char charTemp;

    while (position <= length)
    {
        charTemp = directory[position];
        if (charTemp == '\\')
        {
            copiedDirectory[positionTarget] = '\\';
            positionTarget++;
            copiedDirectory[positionTarget] = '\\';
        }
        else
        {
            copiedDirectory[positionTarget] = charTemp;
        }
        position++;
        positionTarget++;
    }
    copiedDirectory[positionTarget] = '\0';
}

void comfts::readDataPiece(FILE* m_dataFilePointer, int* m_dataBuffer1, int* m_dataBuffer2)
{
    int position = 0;
    while (position < 9 && (EOF != fgetc(m_dataFilePointer)))
    {
        position++;
    }
    fread_s(m_dataBuffer1, 28, 4, 7, m_dataFilePointer);
    fgetc(m_dataFilePointer);
    fread_s(m_dataBuffer2, 8, 4, 2, m_dataFilePointer);

    for (position = 0; position < 7; position++)
    {
        m_dataBuffer1[position] = reverseBytes(m_dataBuffer1[position]);
    }
    for (position = 0; position < 2; position++)
    {
        m_dataBuffer2[position] = reverseBytes(m_dataBuffer2[position]);
    }
    fgetc(m_dataFilePointer);
}

uint32_t comfts::reverseBytes(uint32_t n) {
    uint32_t  res = 0;
    int i = 4;
    while (i--)
    {
        res = res << 8;
        res += n & 255;
        n = n >> 8;
    }
    return  res;
}