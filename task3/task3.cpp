// PERF_TASK3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning(disable : 4996)

#include "document.h"
#include "prettywriter.h"
#include "filereadstream.h"
#include "filewritestream.h"
#include <iostream>
#include <fstream>

using namespace rapidjson;


void setValue( Value& v, int id, const std::string str, Document::AllocatorType& allocator) {
    int itests;
    std::string str2;
    Value s;
    char buffer[10];
    int len;
    for (Value::ValueIterator itr = v.Begin(); itr != v.End(); ++itr) {
        itests = itr->GetObject()["id"].GetInt();
        if (id == itests)
        {
            str2 = itr->GetObject()["title"].GetString();
            len = sprintf(buffer, "%s", str.c_str());
            itr->GetObject()["value"].SetString(buffer, len, allocator);
            memset(buffer, 0, sizeof(buffer));
            return;
        }
        if (itr->HasMember("values"))
        {
            Value& v2 = itr->GetObject()["values"];
            setValue(v2, id, str, allocator);
        }
    }
}

int main(int argc, char* argv[])
{
    FILE* fp = std::fopen(argv[1], "rb");
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document values;
    values.ParseStream(is);
    fclose(fp);

    fp = std::fopen(argv[2], "rb");
    FileReadStream is1(fp, readBuffer, sizeof(readBuffer));
    Document tests;
    tests.ParseStream(is1);
    fclose(fp);
    int id;
    std::string str;
    Value& v = values["values"];
    for (Value::ValueIterator itr = v.Begin(); itr != v.End(); ++itr) {
        id = itr->GetObject()["id"].GetInt();
        str = itr->GetObject()["value"].GetString();
        setValue(tests["tests"], id, str, tests.GetAllocator());
    }  

    fp = std::fopen(argv[3], "wb");
    std::ofstream out;
    out.open("C:/Users/Alina/Downloads/result.json");
    char writeBuffer[65536];
    FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
    PrettyWriter<FileWriteStream> writer(os);
    tests.Accept(writer);
    fclose(fp);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
