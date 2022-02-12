#include "Http.h"
#include <thread>

int main()
{
    Http clientOneHttp(8080, "127.0.0.1", "post");
    thread clientOneThread{ &Http::Listen, ref(clientOneHttp), true }; // 1 client
    clientOneThread.join();
    return 0;
}
