#include <QtTest>
#include <QCoreApplication>
#include "testLoadSamples.h"
#include "testMassCalculator.h"
#include "testCSVReports.h"
#include "testPeakDetection.h"
#include "testMzSlice.h"
#include "testLoadDB.h"
#include "testScan.h"
#include "testEIC.cpp"
#include "testbase64.h"
#include "testMzFit.h"
#include "testMzAligner.h"
#include "testCLI.h"
#include "testCharge.h"
#include "testSRMList.h"
#include "testIsotopeLogic.h"

int readLog(QString);

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);

    printf("started main.cpp\n");
    int result = 0;

    if (freopen("testLoadSamples.xml", "w", stdout))
        result |= QTest::qExec(new TestLoadSamples, argc, argv);
    result|=readLog("testLoadSamples.xml");

    printf("Test#1 done: %d\n",result);

    if (freopen("testMassCalculator.xml", "w", stdout))
        result |= QTest::qExec(new TestMassCalculator, argc, argv);
    result|=readLog("testMassCalculator.xml");
    
    printf("Test#2 done: %d\n",result);

    if(freopen("testCLI.xml",  "w", stdout))
        result |= QTest::qExec(new TestCLI, argc, argv);
    result|=readLog("testCLI.xml");

    printf("Test#3 done: %d\n",result);

    if (freopen("testPeakDetection.xml", "w", stdout))
        result |= QTest::qExec(new TestPeakDetection, argc, argv);
    result|=readLog("testPeakDetection.xml");

    printf("Test#4 done: %d\n",result);

    if(freopen("testCharge.xml",  "w", stdout))
        result |= QTest::qExec(new TestCharge, argc, argv);
    result|=readLog("testCharge.xml");

    printf("Test#5 done: %d\n",result);

    if (freopen("testLoadDB.xml", "w", stdout))
        result |= QTest::qExec(new TestLoadDB, argc, argv);
    result|=readLog("testLoadDB.xml");

    printf("Test#6 done: %d\n",result);

    if (freopen("testMzSlice.xml", "w", stdout))
        result |= QTest::qExec(new TestMzSlice, argc, argv);
    result|=readLog("testMzSlice.xml");

    printf("Test#7 done: %d\n",result);

    if (freopen("testScan.xml", "w", stdout))
        result |= QTest::qExec(new TestScan, argc, argv);
    result|=readLog("testScan.xml");

    printf("Test#8 done: %d\n",result);

    if(freopen("testEIC.xml",  "w", stdout))
        result |= QTest::qExec(new TestEIC, argc, argv);
    result|=readLog("testEIC.xml");

    printf("Test#9 done: %d\n",result);

    if(freopen("testbase64.xml",  "w", stdout))
        result |= QTest::qExec(new Testbase64, argc, argv);
    result|=readLog("testbase64.xml");

    printf("Test#10 done: %d\n",result);

    if(freopen("testMzFit.xml",  "w", stdout))
        result |= QTest::qExec(new TestMzFit, argc, argv);
    result|=readLog("testMzFit.xml");

    printf("Test#11 done: %d\n",result);

    if (freopen("testCSVReports.xml", "w", stdout))
        result |= QTest::qExec(new TestCSVReports, argc, argv);
    result|=readLog("testCSVReports.xml");

    printf("Test#12 done: %d\n",result);

    if (freopen("testSRMList.xml", "w", stdout))
        result |= QTest::qExec(new TestSRMList, argc, argv);
    result|=readLog("testSRMList.xml");

    printf("Test#13 done: %d\n",result);

    if (freopen("testIsotopeLogic.xml", "w", stdout))
        result |= QTest::qExec(new TestIsotopeLogic, argc, argv);
    result|=readLog("testIsotopeLogic.xml");

    printf("Test#14 done: %d\n",result);


    printf("inside main.cpp : %d\n", result);
    return result;
}


int readLog(QString filename){

    QFile file(filename);
    int result=0;
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QXmlStreamReader xsr(&file);
        xsr.readNext();

        while(!xsr.atEnd()){
            if(xsr.attributes().value("type")=="fail"){
                QString file=xsr.attributes().value("file").toString();
                int line=xsr.attributes().value("line").toInt();
                while(xsr.name()!="Description"){
                    xsr.readNext();
                }
                result=1;
                std::cerr<<"\n\ntest case failed: file-"<<file.toStdString()<<", line-"<<line<<", error info: "<<xsr.readElementText().toStdString()<<"\n";
            }
            xsr.readNext();
            
        }
        file.close();
    }
    return result;
}
