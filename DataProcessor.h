#pragma once
#include<iostream>
using namespace std;

class DataProcessor
{
public:
	DataProcessor(const char* datafileName, const char* targetfileName);
	~DataProcessor();
public:
	void readData();
	//void explainData();
	void showCurrentData();
private:
	void outPutData();
	FILE* m_dataFilePointer;
	FILE* m_targetFilePointer;
	//int m_dataBuffer1Time;
	int m_dataBuffer1[7];
	int m_dataBuffer2[2];
	//float m_dataExplained[9];
};

