#pragma once

void AddToOutputCashe(const char Value);


void ClearOuputCashe();


/*
* Return Values
* 0 = failed
* 1 = directory and file existed
* 2 = direcotry existed and file was created
* 3 = directory and file were created
*/
int CreateOutputCashe();


const char* ReadOuptutCashe();