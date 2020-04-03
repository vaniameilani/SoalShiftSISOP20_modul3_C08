#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

//fungsi untuk mendapatkan file ekstensi
string getExt(string pathName)
	{
	    // Finds the last persiod character of the string
	    int period = pathName.find_last_of(".");
	    // I use  + 1 because I don't really need the to include the period
	    string ext = pathName.substr(period + 1);
	    return ext;
	}
int main(int argc, char *argv[]){
	printf("%s", getExt);
}
