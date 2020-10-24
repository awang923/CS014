//
// Created by jerrywang on 2020/4/29.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#include "PrintJob.h"

PrintJob::PrintJob ( int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){}
int PrintJob::getPriority ( ){
    return priority;
}

int PrintJob::getJobNumber ( ){
    return jobNumber;
}

int PrintJob::getPages ( ){
    return numPages;
}
void PrintJob::createHole() {
    priority = 0;
}
