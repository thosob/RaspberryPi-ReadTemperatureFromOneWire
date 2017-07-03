/* 
 * File:   ReadTemperature.cpp
 * Author: tsobieroy
 *
 * Created on July 3, 2017, 12:05 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>   
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <inttypes.h> 
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

/*
 * @brief simple function to parse temperature from one wire via c++
 * @return write temperature string in xml to console
 */
int main(int argc, char* argv[]) {

    string line;
    string tmp;    
    float ret = 0.0;
    if(argc == 2){                 
        //Open File
        std::ifstream in(argv[1]);   

        //search for t=
        while(getline(in, line)){
            tmp = "";
            if(strstr(line.c_str(), "t=")){
                tmp = strstr(line.c_str(), "t=");
                tmp.erase(0,2);
                if(tmp.length() > 1){
                    in.close();
                    ret = strtof(tmp.c_str(),NULL)/1000;
                }
            }
        }
        in.close();
        printf("<Temperature>%f</Temperature>", ret );
        return 0;
    }
}

