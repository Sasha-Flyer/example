﻿
#include "pch.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <iostream>
#include <string>
#include <filesystem>

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
	Value& arr = d["array"];
	return (a.GetFloat() + arr[0].GetFloat()) / (b.GetFloat() + arr[1].GetFloat());
	
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
