#pragma once
#include "DataProcessor.h"
#include"comfts.h"
//#include <regex>

using namespace std;

DataProcessor::DataProcessor(const char* datafileName, const char* targetfileName):
	m_dataBuffer1()
{
	fopen_s(&m_dataFilePointer,datafileName, "rb");
	fopen_s(&m_targetFilePointer,targetfileName, "w");
}

DataProcessor::~DataProcessor()
{
	fclose(m_targetFilePointer);
	fclose(m_dataFilePointer);
}

void DataProcessor::readData()
{
	while (!feof(m_dataFilePointer))
	{
		comfts::readDataPiece(m_dataFilePointer, m_dataBuffer1, m_dataBuffer2);
		outPutData();
	}
}

void DataProcessor::outPutData()
{	
	//showCurrentData();
	int position = 0;
	while (position <7&&!feof(m_dataFilePointer))
	{
		fprintf(m_targetFilePointer, "%12d", m_dataBuffer1[position]);
		fputc(',', m_targetFilePointer);
		position++;
	}
	position = 0;
	while (position <2&&!feof(m_dataFilePointer))
	{
		fprintf(m_targetFilePointer, "%12d", m_dataBuffer2[position]);
		fputc(',', m_targetFilePointer);
		position++;
	}
	fputc('\n', m_targetFilePointer);
}

void DataProcessor::showCurrentData()
{
	for (int position = 0; position < 7; position++)
	{
		std::cout << m_dataBuffer1[position]<<' ';
	}
	for (int position = 0; position < 2; position++)
	{
		std::cout << m_dataBuffer2[position] << ' ';
	}
	std::cout << std::endl;
}


