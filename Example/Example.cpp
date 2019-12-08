// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma warning(suppress : 4996)
#include "pch.h"
#include "rapidjson/document.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include <cstdio>
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filewritestream.h"
#include <iostream>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <sstream>
#include<stdio.h> 
#include <filesystem>
#include<stdio.h> 

using namespace rapidjson;
using namespace std;
namespace fs = std::experimental::filesystem;

string filename = "data.json";

inline bool json_exists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
float read_data(string filename) {
	char readBuffer[65536];
	FILE* fp = fopen(filename.c_str(), "rb");
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	Document d;
	d.ParseStream(is);
	Value& a = d["a"];
	Value& b = d["b"];
	return a.GetFloat() / b.GetFloat();
}
int main()
{
	if (json_exists(filename)) {
		float c = read_data(filename);
		cout << c;
	}
	else {
		cout << "Файл не существует или внутри не JSON строка";
	}
	}
