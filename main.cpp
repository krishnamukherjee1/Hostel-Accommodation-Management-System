#include "include/Application.h"
#include "external/json.hpp"

using json = nlohmann::json;
int main()
{
    Application app;

    app.run();

    return 0;
}