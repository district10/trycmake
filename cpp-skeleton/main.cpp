#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include <QTcpSocket>
#include "lmsclient.h"

using namespace std;

enum LMSModes { CONFIG_FREQ_ANGRES, CONFIG_ANGSTART_ANGSTOP, OPEN, CLOSE, NumOfModes };
enum LMSStates { LMS_ON, LMS_OFF };
enum {
    SIGNAL_SIZE = 50
};

void split(string src, string token, vector<string>& vect)   
{   
    int nend = 0;   
    int nbegin = 0;   
    while(nend != -1) {   
        nend = src.find_first_of(token, nbegin);   
        if(nend == -1) {
            vect.push_back(src.substr(nbegin, src.length()-nbegin));   
        } else {  
            vect.push_back(src.substr(nbegin, nend-nbegin));   
        }
        nbegin = nend + 1;   
    }   
}  


// main
int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    // qDebug() << QString("Hello World");

    double lmsAngleStart = 0.0;
    double lmsAngleResolution = 0.0;
    size_t lmsScanCount = 0.0;

    enum LMSStates lmsState = LMS_OFF;
    char lmsMode[NumOfModes][SIGNAL_SIZE] = {
        // CONFIG_FREQ_ANGRES, scan config
        { 0x02, 0x73, 0x52, 0x4E, 0x20, 0x4C, 0x4D, 0x50, 0x73, 0x63, 0x61, 0x6E, 0x63, 0x66, 0x67, 0x03 },
        // CONFIG_ANGSTART_ANGSTOP, output range
        { 0x02, 0x73, 0x52, 0x4E, 0x20, 0x4C, 0x4D, 0x50, 0x6F, 0x75, 0x74, 0x70, 0x75, 0x74, 0x52, 0x61, 0x6E, 0x67, 0x65, 0x03 },
        // OPEN, scan data 1 (turn ON)
        { 0x02, 0x73, 0x45, 0x4E, 0x20, 0x4C, 0x4D, 0x44, 0x73, 0x63, 0x61, 0x6E, 0x64, 0x61, 0x74, 0x61, 0x20, 0x31, 0x03 },
        // CLOSE, scan data 0 (turn OFF)
        { 0x02, 0x73, 0x45, 0x4E, 0x20, 0x4C, 0x4D, 0x44, 0x73, 0x63, 0x61, 0x6E, 0x64, 0x61, 0x74, 0x61, 0x20, 0x30, 0x03 } 
    };

    for (int i = 0; i < 4; ++i) {
        fprintf(stdout, "Mode%1d: %s\n", i, lmsMode[i]);
    }


    double x = 9.8;
    cout << "square of " << x << " is " << square(x) << endl;

    QDataStream in;
    
    vector<string> data ;
    // split("hello world is for every basic coding languages", " ", &data);










    app.exec();
}