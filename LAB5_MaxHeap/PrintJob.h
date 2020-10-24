//
// Created by jerrywang on 2020/4/29.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#ifndef __PRINTJOB_H
#define __PRINTJOB_H

//using namespace std;

class PrintJob {
private:
    int priority;
    int jobNumber;
    int numPages;

public:
    PrintJob ( int, int, int);
    int getPriority ( );
    int getJobNumber ( );
    int getPages ( );
    void createHole();
    //You can add additional functions here
};
#endif//LAB5_MAXHEAP_PRINTJOB_H
