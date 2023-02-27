#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Python.h"

using namespace std;

PyObject* pMainModule = NULL;

//呼叫輸出"Hello Python"函式
void Hello()
{
    PyObject* pFunc = PyObject_GetAttrString(pMainModule, "Hello");//呼叫的函式名
    PyObject_CallObject(pFunc, NULL);//呼叫函式,NULL表示引數為空
}

//呼叫py檔案中的Add函式,傳兩個int型引數
void Add(int a, int b)
{
    PyObject* pFunc = PyObject_GetAttrString(pMainModule, "Add");//Add:Python檔案中的函式名

    //建立引數:
    PyObject* pArgs = PyTuple_New(2);//函式呼叫的引數傳遞均是以元組的形式打包的,2表示引數個數
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", a));//0--序號,i表示建立int型變數
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", b));//1--序號

    //返回值
    PyObject* pReturn = PyObject_CallObject(pFunc, pArgs);//呼叫函式

    //將返回值轉換為int型別
    int result;
    PyArg_Parse(pReturn, "i", &result);//i表示轉換成int型變數
    cout << "a + b = " << result << endl;
}

//呼叫py檔案中的PrintPI函式
void PrintPI()
{
    PyObject* pFunc = PyObject_GetAttrString(pMainModule, "PrintPI");
    PyObject_CallObject(pFunc, NULL);
}

void ShowColorChecker()
{
    PyObject* pFunc = PyObject_GetAttrString(pMainModule, "ShowColorChecker");
    PyObject_CallObject(pFunc, NULL);
}

void ShowDonut()
{
    PyObject* pDonutModule = PyImport_ImportModule("donut");
    PyObject* pDonutFunc = PyObject_GetAttrString(pDonutModule, "draw_donut");
    PyObject_CallObject(pDonutFunc, NULL);
}

int main(int argc, char** argv)
{
    Py_SetPythonHome(L"python-3.10.10-embed-amd64");
    Py_SetPath(L"python-3.10.10-embed-amd64\\Lib\\site-packages;"
                "python-3.10.10-embed-amd64\\python310.zip;"
                "python-3.10.10-embed-amd64;");

    // Initial Python
    Py_Initialize();

    pMainModule = PyImport_ImportModule("main");//Python檔名

    cout << "呼叫main.py中的Hello函式..." << endl;
    Hello();

    cout << endl << "呼叫main.py中的Add函式..." << endl;
    Add(6, 8);

    cout << endl << "呼叫main.py中的PrintPI函式..." << endl;
    PrintPI();

    cout << endl << "呼叫main.py中的ShowColorChecker函式..." << endl;
    ShowColorChecker();

    cout << endl << "Draw Donut..." << endl;
    system("pause");
    system("cls");

    ShowDonut();

    // Close Python
    Py_Finalize();

    system("pause");
    return 0;
}
