#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Header{
	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;
};

struct Pixel {
	char blue;
	char green;
	char red;
};

void readImg(string nameOfInFile, Header &fileHeader, vector<Pixel> &fileVector) {
	ifstream inFile;

	inFile.open(nameOfInFile,ios::binary);

	Header header1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&header1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&header1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&header1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&header1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&header1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&header1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&header1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&header1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&header1.width), 2);
	inFile.read(reinterpret_cast<char*>(&header1.height), 2);
	inFile.read(reinterpret_cast<char*>(&header1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&header1.imageDescriptor), 1);


	fileHeader = header1;

	int numLoop = header1.width * header1.height;

	Pixel newPix;

	for (int i = 0; i < numLoop; i++) {


		inFile.read(reinterpret_cast<char*>(&newPix.blue), 1);
		inFile.read(reinterpret_cast<char*>(&newPix.green), 1);
		inFile.read(reinterpret_cast<char*>(&newPix.red), 1);

		fileVector.push_back(newPix);
	}

	inFile.close();
}

void writeImg(string nameOfWriteFile, vector<Pixel> fileVector, Header fileHeader) {
	ofstream writeFile;
	writeFile.open(nameOfWriteFile, ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&fileHeader.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.width), 2);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.height), 2);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&fileHeader.imageDescriptor), 1);

	int numLoop = fileHeader.width * fileHeader.height;

	vector<Pixel>::iterator iter;

	for (iter = fileVector.begin(); iter != fileVector.end(); iter++) {


		writeFile.write(reinterpret_cast<char*>(&iter->blue), 1);
		writeFile.write(reinterpret_cast<char*>(&iter->green), 1);
		writeFile.write(reinterpret_cast<char*>(&iter->red), 1);

	}

	writeFile.close();
}

void projectPart1() {
	ifstream inFile;

	inFile.open("car.tga");

	inFile.seekg(0);

	Header car1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&car1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&car1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&car1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&car1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&car1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&car1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&car1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&car1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&car1.width), 2);
	inFile.read(reinterpret_cast<char*>(&car1.height), 2);
	inFile.read(reinterpret_cast<char*>(&car1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&car1.imageDescriptor), 1);

	//cout << car.height << endl;

	//cout << (int)car.idLength<<endl;
	//cout << (int)car.colorMapType << endl;
	//cout << (int)car.dataTypeCode << endl;
	//cout << (int)car.colorMapOrigin << endl;
	//cout << (int)car.colorMapLength << endl;
	//cout << (int)car.colorMapDepth << endl;
	//cout << (int)car.xOrigin << endl;
	//cout << (int)car.yOrigin << endl;
	//cout << (int)car.width << endl;
	//cout << (int)car.height << endl;
	//cout << (int)car.bitsPerPixel << endl;
	//cout << (int)car.imageDescriptor << endl;


	vector<unsigned char> pixelVector;

	//int pixelVectorLength = car.height * car.width * 3;

	//cout << pixelVectorLength << endl;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		pixelVector.push_back(BGRValue);

		//cout <<(int) pixelVector.at(i) << endl;
	}

	ofstream writeFile;
	writeFile.open("output.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&car1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&car1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&car1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&car1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&car1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&car1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&car1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&car1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&car1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&car1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&car1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&car1.imageDescriptor), 1);


	//cout << car.height << endl;
	//cout << car.width << endl;

	int pixelsRead = 0;

	for (int i = 0; i < 1500000; i++) {

		writeFile.write(reinterpret_cast<char*>(&pixelVector.at(i)), 1);

		pixelsRead++;

		//pixelVector.push_back(BGRValue);

		//cout << (int)pixelVector.at(i) << endl;
	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task1Multiply() {
	//read layer1 file
	ifstream inFile;

	inFile.open("layer1.tga",ios::binary);

	Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> layer1Vector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		layer1Vector.push_back(BGRValue);
	}

	inFile.close();

	//read pattern1 file
	inFile.open("pattern1.tga",ios::binary);

	Header pattern1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&pattern1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.width), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.height), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.imageDescriptor), 1);


	vector<unsigned char> pattern1Vector;

	//unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		pattern1Vector.push_back(BGRValue);
	}

	inFile.close();

	vector<unsigned char> combinedVector;

	//multiply both of them
	for (int i = 0; i < 786432; i++) {
		float layer1Pixel = (float)layer1Vector.at(i);
		float pattern1Pixel = (float)pattern1Vector.at(i);

		layer1Pixel /= 255;
		pattern1Pixel /= 255;

		float combinedPixel = layer1Pixel * pattern1Pixel;
		combinedPixel *= 255;
		combinedPixel += 0.5f;

		combinedVector.push_back((unsigned char)combinedPixel);
		
		//cout << "run number " << i << endl;
		//cout << layer1Pixel << endl;
		//cout << pattern1Pixel << endl;
		//cout << combinedPixel << endl;
		//cout << (int)combinedPixel << endl;
		//cout << (unsigned char)combinedPixel << endl;
	}

	//write the new values
	ofstream writeFile;
	writeFile.open("task1.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&pattern1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.imageDescriptor), 1);


	//cout << car.height << endl;
	//cout << car.width << endl;

	int pixelsRead = 0;

	for (int i = 0; i < 786432; i++) {

		writeFile.write(reinterpret_cast<char*>(&combinedVector.at(i)), 1);

		pixelsRead++;

		//pixelVector.push_back(BGRValue);

		//cout << (int)pixelVector.at(i) << endl;
	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task2Subtract() {
	//read layer2 file
	ifstream inFile;

	inFile.open("layer2.tga", ios::binary);

	Header layer2;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer2.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.imageDescriptor), 1);


	vector<unsigned char> layer2Vector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		layer2Vector.push_back(BGRValue);
	}

	inFile.close();

	//read car file
	inFile.open("car.tga",ios::binary);

	Header car;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&car.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&car.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&car.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&car.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&car.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&car.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&car.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&car.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&car.width), 2);
	inFile.read(reinterpret_cast<char*>(&car.height), 2);
	inFile.read(reinterpret_cast<char*>(&car.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&car.imageDescriptor), 1);


	vector<unsigned char> carVector;

	unsigned char newBGR;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&newBGR), 1);

		carVector.push_back(newBGR);

		//cout << (int)newBGR << endl;
	}

	inFile.close();

	vector<unsigned char> subtractedVector;

	//subtract values
	//cout << "task 2" << endl;
	for (int i = 0; i < 786532; i++) {
		float layer2Pixel = (float)layer2Vector.at(i);
		float carPixel = (float)carVector.at(i);

		float subtracted = carPixel - layer2Pixel;

		if (subtracted < 0) {
			subtracted = 0;
		}
		else if (subtracted > 255) {
			subtracted = 255;
		}
		
		//cout << carPixel << endl;
		//cout << layer2Pixel << endl;
		//cout << subtracted << endl;
		subtractedVector.push_back((unsigned char)(subtracted));
	}


	//write subtracted values
	ofstream writeFile;
	writeFile.open("task2.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&car.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&car.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&car.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&car.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&car.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&car.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&car.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&car.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&car.width), 2);
	writeFile.write(reinterpret_cast<char*>(&car.height), 2);
	writeFile.write(reinterpret_cast<char*>(&car.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&car.imageDescriptor), 1);

	int pixelsRead = 0;

	for (int i = 0; i < 786532; i++) {

		writeFile.write(reinterpret_cast<char*>(&subtractedVector.at(i)), 1);

		pixelsRead++;
	}

	writeFile.close();
}

void task3MultiplyScreen() {
	//read layer1 file
	ifstream inFile;

	inFile.open("layer1.tga", ios::binary);

	Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> layer1Vector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		layer1Vector.push_back(BGRValue);
	}

	inFile.close();

	//read pattern2 file
	inFile.open("pattern2.tga", ios::binary);

	Header pattern2;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&pattern2.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.width), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.height), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.imageDescriptor), 1);


	vector<unsigned char> pattern2Vector;

	//unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		pattern2Vector.push_back(BGRValue);
	}

	inFile.close();

	vector<unsigned char> combinedVector;

	//multiply both of them
	for (int i = 0; i < 786432; i++) {
		float layer1Pixel = (float)layer1Vector.at(i);
		float pattern2Pixel = (float)pattern2Vector.at(i);

		layer1Pixel /= 255;
		pattern2Pixel /= 255;

		float combinedPixel = layer1Pixel * pattern2Pixel;
		combinedPixel *= 255;
		combinedPixel += 0.5f;

		combinedVector.push_back((unsigned char)combinedPixel);
	}

	//open text.tga file
	inFile.open("text.tga", ios::binary);

	Header text;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&text.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&text.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&text.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&text.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&text.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&text.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&text.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&text.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&text.width), 2);
	inFile.read(reinterpret_cast<char*>(&text.height), 2);
	inFile.read(reinterpret_cast<char*>(&text.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&text.imageDescriptor), 1);


	vector<unsigned char> textVector;

	//unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		textVector.push_back(BGRValue);
	}

	inFile.close();

	//screen combined vector and text vector

	vector<unsigned char> combinedScreen;
	for (int i = 0; i < 786432; i++) {
		float NP1 = (float)combinedVector.at(i);
		float NP2 = (float)textVector.at(i);

		NP1 /= 255;
		NP2 /= 255;

		NP1 = 1 - NP1;
		NP2 = 1 - NP2;

		float combinedNPs = 1 - (NP1 * NP2);

		combinedNPs *= 255;
		combinedNPs += 0.5f;

		combinedScreen.push_back(combinedNPs);
	}


	//write new values
	ofstream writeFile;
	writeFile.open("task3.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&pattern2.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.width), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.height), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 786432; i++) {

		writeFile.write(reinterpret_cast<char*>(&combinedScreen.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task4MultiplySubtract() {
	ifstream inFile;

	inFile.open("layer2.tga", ios::binary);

	Header layer2;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer2.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer2.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer2.imageDescriptor), 1);


	vector<unsigned char> layer2Vector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		layer2Vector.push_back(BGRValue);
	}

	inFile.close();


	//open circles

	inFile.open("circles.tga", ios::binary);

	Header circles;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&circles.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&circles.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&circles.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&circles.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&circles.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&circles.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&circles.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&circles.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&circles.width), 2);
	inFile.read(reinterpret_cast<char*>(&circles.height), 2);
	inFile.read(reinterpret_cast<char*>(&circles.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&circles.imageDescriptor), 1);


	vector<unsigned char> circlesVector;

	//unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		circlesVector.push_back(BGRValue);
	}

	inFile.close();

	//multiply both of them

	vector<unsigned char> combinedVector;
	for (int i = 0; i < 786432; i++) {
		float layer2Pixel = (float)layer2Vector.at(i);
		float circlesPixel = (float)circlesVector.at(i);

		layer2Pixel /= 255;
		circlesPixel /= 255;

		float combinedPixel = layer2Pixel * circlesPixel;
		combinedPixel *= 255;
		combinedPixel += 0.5f;

		combinedVector.push_back((unsigned char)combinedPixel);
	}


	inFile.open("pattern2.tga", ios::binary);

	Header pattern2;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&pattern2.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.width), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.height), 2);
	inFile.read(reinterpret_cast<char*>(&pattern2.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&pattern2.imageDescriptor), 1);


	vector<unsigned char> pattern2Vector;

	//unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		pattern2Vector.push_back(BGRValue);
	}

	inFile.close();


	//subtract them

	vector<unsigned char> subVect;
	for (int i = 0; i < 786432; i++) {
		int sub1 = combinedVector.at(i);
		int sub2 = pattern2Vector.at(i);

		int subBoth = sub1 - sub2;
		if (subBoth<0) {
			subBoth = 0;
		}

		subVect.push_back(subBoth);
	}

	//write them
	ofstream writeFile;
	writeFile.open("task4.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&pattern2.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.width), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.height), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern2.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern2.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 786432; i++) {

		writeFile.write(reinterpret_cast<char*>(&subVect.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task5Overlay() {
	ifstream inFile;

	inFile.open("layer1.tga", ios::binary);

	Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> layer1Vector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		layer1Vector.push_back(BGRValue);
	}

	inFile.close();

	//read pattern1 file
	inFile.open("pattern1.tga", ios::binary);

	Header pattern1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&pattern1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.width), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.height), 2);
	inFile.read(reinterpret_cast<char*>(&pattern1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&pattern1.imageDescriptor), 1);


	vector<unsigned char> pattern1Vector;

	//unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		pattern1Vector.push_back(BGRValue);
	}

	inFile.close();


	//overlay them
	vector<unsigned char> overlayVector;
	
	for (int i = 0; i < 786432; i++) {
		float NP1 = (float)layer1Vector.at(i);
		float NP2 = (float)pattern1Vector.at(i);

		NP1 /= 255;
		NP2 /= 255;

		float newValue;

		if (NP2 <= 0.5) {
			newValue = 2 * NP1 * NP2;
		}
		else {
			NP1 = 1 - NP1;
			NP2 = 1 - NP2;
			newValue = 2 * NP1 * NP2;
			newValue = 1 - newValue;
		}

		newValue *= 255;
		newValue += 0.5f;

		overlayVector.push_back((unsigned char)newValue);
	}

	//write them
	ofstream writeFile;
	writeFile.open("task5.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&pattern1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&pattern1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&pattern1.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 786432; i++) {

		writeFile.write(reinterpret_cast<char*>(&overlayVector.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task6AddGreen() {
	ifstream inFile;

	inFile.open("car.tga", ios::binary);

	Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> carVector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		carVector.push_back(BGRValue);
	}

	inFile.close();


	//addGreen
	//int findGreen = 1;
	for (int i = 1; i < 1500000; i+=3) {
		int newVal = (int)carVector.at(i)+200;

		if (newVal > 255) {
			newVal = 255;
		}

		//cout << carVector.at(i) << endl;

		carVector.at(i) = (unsigned char)newVal;
	}

	//write them
	ofstream writeFile;
	writeFile.open("task6.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&layer1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 1500000; i++) {

		writeFile.write(reinterpret_cast<char*>(&carVector.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task7MultRedBlue() {
	ifstream inFile;

	inFile.open("car.tga", ios::binary);

	Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> carVector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		carVector.push_back(BGRValue);
	}

	inFile.close();


	//mult red
	for (int i = 2; i < 786432; i += 3) {
		float newVal = (float)carVector.at(i);
		newVal /= 255;
		newVal *= 4;
		newVal *= 255;
		newVal += 0.5f;

		if (newVal > 255) {
			newVal = 255;
		}

		carVector.at(i) = (unsigned char)newVal;
	}
	//change blue
	for (int i = 0; i < 1500000; i += 3) {
		int newVal = 0;
		carVector.at(i) = (unsigned char)newVal;
	}

	//write them
	ofstream writeFile;
	writeFile.open("task7.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&layer1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 786432; i++) {

		writeFile.write(reinterpret_cast<char*>(&carVector.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task8DiffFiles() {
	ifstream inFile;

	inFile.open("car.tga", ios::binary);

	Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> carVector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		carVector.push_back(BGRValue);
	}

	inFile.close();


	//do red
	vector<unsigned char> redVect;
	for (int i = 2; i < 786432; i += 3) {
		redVect.push_back(carVector.at(i));
		redVect.push_back(carVector.at(i));
		redVect.push_back(carVector.at(i));
	}

	//do green
	vector<unsigned char> greenVect;
	for (int i = 1; i < 786432; i += 3) {
		greenVect.push_back(carVector.at(i));
		greenVect.push_back(carVector.at(i));
		greenVect.push_back(carVector.at(i));
	}

	//do blue
	vector<unsigned char> blueVect;
	for (int i = 0; i < 786432; i += 3) {
		blueVect.push_back(carVector.at(i));
		blueVect.push_back(carVector.at(i));
		blueVect.push_back(carVector.at(i));
	}

	//write red
	ofstream writeFile;
	writeFile.open("task8r.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&layer1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 786432; i++) {

		writeFile.write(reinterpret_cast<char*>(&redVect.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();

	//write green
	writeFile.open("task8g.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&layer1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 786432; i++) {

		writeFile.write(reinterpret_cast<char*>(&greenVect.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();

	//write blue
	writeFile.open("task8b.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&layer1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 786432; i++) {

		writeFile.write(reinterpret_cast<char*>(&blueVect.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task9Combine() {
	ifstream inFile;

	//open red
	inFile.open("layer_red.tga", ios::binary);

	Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> redVector;

	unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		redVector.push_back(BGRValue);
	}

	inFile.close();

	//open green
	inFile.open("layer_green.tga", ios::binary);

	//Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> greenVector;

	//unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		greenVector.push_back(BGRValue);
	}

	inFile.close();


	//open blue
	inFile.open("layer_blue.tga", ios::binary);

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);


	vector<unsigned char> blueVector;

	//unsigned char BGRValue;

	for (int i = 0; i < 1500000; i++) {

		inFile.read(reinterpret_cast<char*>(&BGRValue), 1);

		blueVector.push_back(BGRValue);
	}

	inFile.close();


	vector<unsigned char> combinedVect;
	for (int i = 0; i < 1500000; i+=3) {
		combinedVect.push_back(blueVector.at(i));
		combinedVect.push_back(greenVector.at(i));
		combinedVect.push_back(redVector.at(i));
	}
	

	ofstream writeFile;
	writeFile.open("task9.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&layer1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);

	//int pixelsRead = 0;

	for (int i = 0; i < 1500000; i++) {

		writeFile.write(reinterpret_cast<char*>(&combinedVect.at(i)), 1);

	}

	//cout << pixelsRead << endl;
	writeFile.close();
}

void task10Flip() {
	ifstream inFile;

	//open red
	inFile.open("text2.tga", ios::binary);

	Header layer1;

	if (inFile.is_open())
	{
		cout << "opened correctly" << endl;
	}

	inFile.read(reinterpret_cast<char*>(&layer1.idLength), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.width), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.height), 2);
	inFile.read(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	inFile.read(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);

	int numLoop = layer1.width * layer1.height;

	cout << numLoop << endl;

	vector<Pixel> textVector;
	vector<Pixel>::iterator iter;

	//unsigned char BGRValue;

	Pixel p1;

	//int count = 0;

	for (int i = 0; i < numLoop; i ++) {
		inFile.read(reinterpret_cast<char*>(&p1.blue), 1);
		inFile.read(reinterpret_cast<char*>(&p1.green), 1);
		inFile.read(reinterpret_cast<char*>(&p1.red), 1);

		textVector.push_back(p1);
		//count++;
	}
	//cout << count << endl;

	inFile.close();

	//write
	ofstream writeFile;
	writeFile.open("task10.tga", ios::binary);

	if (writeFile.is_open()) {
		cout << "output opened correctly" << endl;
	}

	writeFile.write(reinterpret_cast<char*>(&layer1.idLength), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapType), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.dataTypeCode), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapLength), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.colorMapDepth), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.xOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.yOrigin), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.width), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.height), 2);
	writeFile.write(reinterpret_cast<char*>(&layer1.bitsPerPixel), 1);
	writeFile.write(reinterpret_cast<char*>(&layer1.imageDescriptor), 1);

	cout << layer1.height << endl;
	cout << layer1.width << endl;

	
	/*for (int i = numLoop; i >0; i-=3) {
		
		writeFile.write(reinterpret_cast<char*>(&textVectorBlue.at(i)), 1);
		writeFile.write(reinterpret_cast<char*>(&textVectorGreen.at(i)), 1);
		writeFile.write(reinterpret_cast<char*>(&textVectorRed.at(i)), 1);
	}*/

	Pixel p2;

	for (iter=textVector.end()-1; iter !=textVector.begin(); iter--) {
		//cout << iter->blue << endl;
		writeFile.write(reinterpret_cast<char*>(&iter->blue), 1);
		writeFile.write(reinterpret_cast<char*>(&iter->green), 1);
		writeFile.write(reinterpret_cast<char*>(&iter->red), 1);
	}

	//for (int i = numLoop; i > 0; i--) {
	//	p2 = textVector.at(i);

	//	writeFile.write(reinterpret_cast<char*>(&p2.blue), 1);
	//	writeFile.write(reinterpret_cast<char*>(&p2.green), 1);
	//	writeFile.write(reinterpret_cast<char*>(&p2.red), 1);
	//}

	////cout << pixelsRead << endl;
	//writeFile.close();

}

int main(int argc, const char** argv) {
	//projectPart1();
	//task1Multiply();
	//task2Subtract();
	//task3MultiplyScreen();
	//task4MultiplySubtract();
	//task5Overlay();
	//task6AddGreen();
	//task7MultRedBlue();
	//task8DiffFiles();
	//task9Combine();
	//task10Flip();

	Header newHeader;
	vector<Pixel> fileVect;

	if (argc > 1) {
		for (int i = 0; i < argc; i++) {
			cout << "running arg# " << i << argv[i] << endl;
		}
	}

	//readImg("car.tga", newHeader,fileVect);
	//writeImg("checkReadWrite.tga", fileVect, newHeader);

	//cout << "hello" << endl;
	return 0;
}
