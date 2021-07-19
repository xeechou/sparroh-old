#include "application.h"

static const char *VSSource = R"(
)";

int main(int argc, char *argv[])
{
    std::unique_ptr<sparroh::Application> app = std::make_unique<sparroh::Application>();
    if (!app->Initialize())
        return -1;
    return 0;
}
