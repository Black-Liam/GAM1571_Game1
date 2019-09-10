#include <Windows.h>

#include "../../Libraries/Framework/Source/FrameworkPCH.h"

using namespace fw;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Framework* pFramework = new Framework();

    pFramework->Init(600, 600);
    pFramework->Run();
    pFramework->Shutdown();

    delete pFramework;
}
