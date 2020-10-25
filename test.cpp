#include<iostream>
#include"DataProcessor.h"
#include"comfts.h"

using namespace std;

int main() {
    char copiedDirectory[256];
    char dataDirectory[] = \
        //"C:\\Users\\Sinoa\\Desktop\\Debug.log";
        "F:\\文档\\空间探测技术原理\\数据解译\\CSES_HPM_GPS_0041220_20181031_092856_20181031_100555_L0_0000011769.DAT";
    char targetDirectory[] = "C:\\Users\\Sinoa\\Desktop\\1.log";

    cout << dataDirectory << endl;
    comfts::DirectoryProcess(dataDirectory, copiedDirectory);
    cout << copiedDirectory << endl;
    
    DataProcessor test1(copiedDirectory,targetDirectory);
    test1.readData();
    //test1.showCurrentData();

    //test1.outPutData();
    cout << endl;

    //test1.explainData();
    //test1.showCurrentData();
    //test1.outputData();
}