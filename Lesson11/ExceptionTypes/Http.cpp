#include "Http.h"

Http::Http(int port, string ip, string method) : _port(port), _ip(ip), _method(method), _response(""), _session(0)
{
    cout << "Constructor http:\t" << typeid(this).name() << "\t" << this << endl;
    if (Connected())
    {
        cout << "Connected successfully!" << endl;
    }
}
bool Http::Connected()
{
    if (_port != 8080 || !_ip._Equal("127.0.0.1"))
        throw IOHttpException("error _ip and _port");
    return true;
}
void Http::Listen(bool client)
{
    try
    {
        mutex door;
        door.lock(); // Время сессии клиента
        _session = 0;
        while (client)
        {
            if (Request(_method).length() == 0) client = false;
            cout << "Listening:\t" << _ip << ":" << _port << endl;
            cout << Request(_method) << endl;
            this_thread::sleep_for(chrono::seconds(1));
            if (_session++ == 10) client = false;
        }
        door.unlock();
        cout << "The client session is killed:\t" << "\t" << _ip << ":" << _port << endl;
    }
    catch (const IOHttpException& ex)
    {
        cerr << ex.what() << endl;
        client = false;
        return;
    }
}
string Http::Request(string method)
{
    try
    {
        Connected(); // Check connection
        // Лямбда Выражение
        transform(method.begin(), method.end(), method.begin(), // Upper Case to String
            [](unsigned char c) { return toupper(c); });

        if (method._Equal("GET"))
            _response = "GET\t/index.html\tstatus:\t200 OK";
        else if (method._Equal("POST"))
            _response = "POST\t/index.html\tstatus:\t200 OK";
        else
            throw IOHttpException("error _ip and _port", STATUS_400);
    }
    catch (const IOHttpException& ex)
    {
        cerr << ex.what() << endl;
        return "";
    }
    return _response;
}

