#pragma once
#include <iostream>
#include <exception>
#include <thread>
#include <algorithm>
#include <chrono>
#include <mutex>
using namespace std;

enum Errors
{
    STATUS_100,
    STATUS_200,
    STATUS_300,
    STATUS_400,
    STATUS_500
};

class IOHttpException : exception
{
    const char* _message;
    Errors _error;
public:
    IOHttpException(const char* message, Errors error=STATUS_500) : exception(message) {
        _message = message;
        _error = error;
        cerr << "error [IOHttpException constructor]:\t" << _message << endl;
    }
    _NODISCARD virtual char const* what() const override
    {
        cerr << "error [IOHttpException virtual what]:\t" << _message << endl;
        switch (_error)
        {
            case STATUS_100: return "STATUS:\t100";
            case STATUS_200: return "STATUS:\t200";
            case STATUS_300: return "STATUS:\t300";
            case STATUS_400: return "STATUS:\t400";
            case STATUS_500: return "STATUS:\t500";
            default: return "STATUS:\t500";
        }
    }
};
class Http
{
public:
    Http(int port, string ip, string method);
    bool Connected();
    void Listen(bool client);
    string Request(string method);
private:
    string _response;
    string _ip;
    int _port;
    string _method;
    int _session;
};