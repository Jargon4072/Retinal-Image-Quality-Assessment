//# include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define SIZE 168
const double e = 2.7182818;
double theta[SIZE+3], feature[SIZE+3];
double resultVal;

void readParams(char* addr){//Reads in parameters (coefficient vector)
	ifstream fin(addr,ios::in);
	int i=0;
	while(!fin.eof()){
		fin>>theta[i++];
	}
	fin.close();
}

void readFeature(char* addr){//Reads in the feature vector
	ifstream fin(addr,ios::in);
	int i=1;
	while(!fin.eof()){
		fin>>feature[i++];
	}
	fin.close();
}

double hypothesis(){
	double z=0;
	for(int i=1;i<=SIZE;i++){
		z+=(theta[i]*feature[i]);
	}
	z+=theta[0];
	z=-z;
	return (1.0/(1.0+pow(e,z)));
}

void writeFeature(){

	fstream myfile;
  	myfile.open ("featureExtract.txt");
  	myfile << "Writing this to a file.\n";
  	for(int i=1;i<=SIZE;i++){
		myfile << feature[i];
	}

  	
  	myfile.close();
  	
}

double getResultVal()
{
	return resultVal;
}

int main(int argc,char** argv){
	
	readParams(argv[1]);
	readFeature(argv[2]);
	
	double hypo=hypothesis();
	cout << argv[3] << ",";
	cout << hypo << "," ;

	if(hypo>=0.0001) cout<<"Gradable\n";
	else cout<<"Ungradable\n";
	resultVal = hypo;
	writeFeature();
	return 0;
}