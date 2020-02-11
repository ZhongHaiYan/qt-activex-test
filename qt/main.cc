#include "foobarocx.h"

#include <QDebug>

int main(int, char *[])
{
    auto bar = new FooBarOcx::Bar;
    if (bar && !bar->isNull()) {
        FooBarOcx::IFoo *foo = nullptr;
        bar->GetFoo(&foo);
        if (foo) {
            foo->SayHello();
        }

        delete bar;
    }
    return 0;
}
